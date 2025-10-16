Secret recipte
Joe -> waiter (menu)
steve -> chef (recipe)

Oracle Database

`ssh hacker@ip`
mypasswordisstrongerthanyours

10.10.64.186

//localhost:1521/FREEPDB1

---
Need to use frida

Making a call to a Oracle Database
(OCI)

Find how id is being excluded
```
hacker@tryhackme-2404:~$ strings main
/lib64/ld-linux-x86-64.so.2
__gmon_start__
OCIErrorGet
OCIHandleFree
OCIAttrSet
OCIEnvCreate
OCIServerDetach
OCIStmtFetch
OCIServerAttach
OCIDefineByPos
OCISessionBegin
OCIStmtPrepare
OCIHandleAlloc
OCISessionEnd
OCIStmtExecute
...
SET ROLE waiter
SELECT * FROM SYS.MENU

```


**OCIStmtFetch**
```
`Connected to Oracle database successfully. Welcome back, joe`
`ID: 1, Name: Pizza, Description: A delicious cheese and tomato pizza`
`ID: 2, Name: Pasta, Description: Creamy fettuccine alfredo pasta`
`ID: 4, Name: Salad, Description: Fresh garden salad with dressing`
           `/* TID 0x35af */`
  `6684 ms  OCIStmtFetch()`
  `6684 ms  stmnt: 0x5be6008ab180`
  `6684 ms  OCIStmtFetch()`
  `6684 ms  stmnt: 0x5be6008ab180`
  `6684 ms  OCIStmtFetch()`
  `6684 ms  stmnt: 0x5be6008ab180`
  `6684 ms  OCIStmtFetch()`
  `6684 ms  stmnt: 0x5be6008ab180`
  `6684 ms  OCIStmtFetch()`
  `6684 ms  stmnt: 0x5be6008ab180`
`Process terminated`



```
Looks like we fetch all 4 / 5?



```
hacker@tryhackme-2404:~$ frida/venv/bin/frida-trace -i "OCIDefineBy*" ./main
Instrumenting...                                                        
OCIDefineByPos: Loaded handler at "/home/hacker/__handlers__/libclntsh.so.23.1/OCIDefineByPos.js"
OCIDefineByPos2: Auto-generated handler at "/home/hacker/__handlers__/libclntsh.so.23.1/OCIDefineByPos2.js"
Started tracing 2 functions. Web UI available at http://localhost:36735/
Enter username: joe
Enter password: 
Connected to Oracle database successfully. Welcome back, joe
ID: 1, Name: Pizza, Description: A delicious cheese and tomato pizza
ID: 2, Name: Pasta, Description: Creamy fettuccine alfredo pasta
ID: 4, Name: Salad, Description: Fresh garden salad with dressing
           /* TID 0x3989 */
  5719 ms  OCIDefineByPos()
  5719 ms  OCIDefineByPos()
  5719 ms  OCIDefineByPos()
Process terminated
```

```
           /* TID 0x12f1 */
  5869 ms  OCIDefineByPos()
  5869 ms  Stored:
buf: 0x7fff72a89e84
size: 4

  5869 ms  OCIDefineByPos()
  5869 ms  Stored:
buf: 0x7fff72a89f80
size: 50

  5869 ms  OCIDefineByPos()
  5869 ms  Stored:
buf: 0x7fff72a89fc0
size: 4000
```
ID 4 bytes
Name 50 bytes
Descr 4000 bytes

Note: Each call of OCIStmtFetch over write the buffer

Idea:
Store the address for each buffer.
When OCIStmtFetch is called inspect each buffer.


Hook OCIDefineByPos
```
if (!globalThis.defineBuffers) {
  globalThis.defineBuffers = [];
}

defineHandler({
  onEnter(log, args, state) {
    log('OCIDefineByPos()');
    const buf = args[4];
    const size = args[5].toInt32();
    globalThis.defineBuffers.push({ buf, size });
  log('Stored:\nbuf: ' + buf + '\nsize: ' + size + '\n');
  },

  onLeave(log, retval, state) {
  }
});
```

```
let fields = [];
fields.push('id');
fields.push('name');
fields.push('description');

defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtFetch()');
  },
onLeave(log, retval, state) {
  for (let i = 0; i < globalThis.buffers.length; i++) {
    const { buf, size } = globalThis.buffers[i];
    const field = fields[i];

    let value; 

    try {
      value = Memory.readUtf8String(buf, size);
    } catch (_) {
      value = hexdump(buf, { length: size, header: false, ansi: false });
    }

    log(`${field}: ${value}`);
  }
}

});

```

```
OCIStmtFetch()
  8933 ms  id: 7fff5d132604  03 00 00 00                                      ....
  8933 ms  name: 7fff5d132700  43 68 61 6c 6c 65 6e 67 65 29 13 5d ff 7f 00 00  Challenge).]....
7fff5d132710  00 00 00 00 00 00 00 00 94 64 a2 eb ff 0f 00 00  .........d......
7fff5d132720  28 6e 43 00 00 00 00 00 70 df 03 b4 c4 7e 00 00  (nC.....p....~..
7fff5d132730  38 d1                                            8.
  8933 ms  descripti: CTF{FridaItsFun!} alfredo past
```

Flag
`CTF{FridaIsFun!}`

Chal2
```
Connected to Oracle database successfully. Welcome back, steve
Error - Code: 1924, Message: ORA-01924: Role "WAITER" not granted or does not exist.
```

``SET ROLE waiter`` → Error (1924)
steve is a cook

Hook into OCIStmtExecute, OCIStmtPrepare, OCIDefineByPos and OCIStmtFetch

`frida/venv/bin/frida-trace -i "OCIStmtExecute" -i "OCIStmtPrepare" -i "OCIDefineByPos" -i "OCIStmtFetch" ./main`

Set retval.replace(0) in OCIStmtExecute;

```
  6065 ms  OCIStmtPrepare()
  6065 ms  OCIStmtExecute()
  6072 ms  OCIStmtPrepare()
  6073 ms  OCIStmtExecute()
  6087 ms  OCIDefineByPos()
  6087 ms  OCIDefineByPos()
  6087 ms  OCIDefineByPos()
  6087 ms  OCIStmtFetch()
```

```
7813 ms  OCIStmtPrepare()
  7813 ms  sql: SET ROLE waiter
  7813 ms  OCIStmtExecute()
  7819 ms  OCIStmtPrepare()
  7819 ms  sql: SELECT * FROM SYS.MENU
  7819 ms  OCIStmtExecute()
  7821 ms  OCIDefineByPos()
  7821 ms  OCIDefineByPos()
  7821 ms  OCIDefineByPos()
  7821 ms  OCIStmtFetch()
```

SELECT * FROM SYS.MENU
Returns a row with 3 columns (OCIDefineByPos)
Returns 1 data entry (OCIStmtFetch)

```
Connected to Oracle database successfully. Welcome back, steve
           /* TID 0xb66 */
  7086 ms  OCIStmtPrepare()
  7086 ms  sql: SET ROLE waiter
  7086 ms  OCIStmtExecute()
  7092 ms  OCIStmtPrepare()
  7092 ms  sql: SELECT * FROM SYS.MENU
  7092 ms  OCIStmtExecute()
  7094 ms  OCIDefineByPos()
  7094 ms  Stored:
buf: 0x7fff1f9debb4
size: 4

  7094 ms  OCIDefineByPos()
  7094 ms  Stored:
buf: 0x7fff1f9decb0
size: 50

  7094 ms  OCIDefineByPos()
  7094 ms  Stored:
buf: 0x7fff1f9decf0
size: 4000

  7094 ms  OCIStmtFetch()
Process terminated
```

```
Enter username: steve
Enter password: 
Connected to Oracle database successfully. Welcome back, steve
           /* TID 0x1222 */
  6869 ms  OCIStmtPrepare()
  6869 ms  sql: SET ROLE waiter
  6869 ms  OCIStmtExecute()
  6877 ms  OCIStmtPrepare()
  6877 ms  sql: SELECT * FROM SYS.MENU
  6877 ms  OCIStmtExecute()
  6878 ms  OCIDefineByPos()
  6878 ms  Stored:
buf: 0x7ffd83030794
size: 4

  6878 ms  OCIDefineByPos()
  6878 ms  Stored:
buf: 0x7ffd83030890
size: 50

  6878 ms  OCIDefineByPos()
  6878 ms  Stored:
buf: 0x7ffd830308d0
size: 4000

  6878 ms  OCIStmtFetch()
  6878 ms  DataType: 3
  6878 ms  =====================
value:
 7ffd83030794  00 00 00 00 20 26 64 ba 89 5d 00 00 a0 4d 65 ba  .... &d..]...Me.
7ffd830307a4  89 5d 00 00                                      .]..
  6878 ms  DataType: 1
  6878 ms  =====================
value:
 7ffd83030890  00 00 00 00 00 00 00 00 98 0a 03 83 fd 7f 00 00  ................
7ffd830308a0  00 00 00 00                                      ....
  6878 ms  DataType: 1
  6878 ms  =====================
value:
 7ffd830308d0  06 00 00 00 05 00 00 00 30 06 03 83 fd 7f 00 00  ........0.......
7ffd830308e0  01 03 01 00                                      ....
Process terminated

```


Replace `SELECT * FROM SYS.MENU`
With `SELECT table_name FROM user_tables;`
or `SELECT owner, table_name FROM all_tables;`


OCIStmtPrepare.js
```
if(!globalThis.rolehandle){globalThis.rolehandle = "";}

defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtPrepare()');

    const stmtp = args[0];
    const sqlPtr = ptr(args[2]);
    const sqlLen = args[3].toInt32();
    const originalSql = Memory.readUtf8String(sqlPtr, sqlLen);
    log('sql: ' + originalSql);

          if(originalSql == "SET ROLE waiter"){
                  log('Storing handle for role statement');
                  globalThis.rolehandle = stmtp;
          }
          else if (originalSql === "SELECT * FROM SYS.MENU"){
                  const newSql = "SELECT * FROM all_tables";
            const newSqlBuffer = Memory.allocUtf8String(newSql);
            args[2] = newSqlBuffer;
            args[3] = ptr(newSql.length);
            globalThis.sqlBuffer = newSqlBuffer;
            log('New sql: ' + newSql);
          }else{globalThis.rolehandle = "";}

          if(globalThis.sqlBuffer){
                  log('sql arg after injection: ' + Memory.readUtf8String(args[2], args[3].toInt32()));
          }

}});
```

CIStmtExecute.js
```
if(!globalThis.exechandle){globalThis.exechandle = "";}

defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtExecute()');
          let stmtp = args[1];
          globalThis.exechandle = stmtp;
  },

  onLeave(log, retval, state) {
          let returnval = retval.toInt32();

          if(returnval != 0){
          log('OCIStmtExecute return  value: ' + returnval);

          if(globalThis.exechandle.equals(globalThis.rolehandle)){
                  log('Setting return value to 0 for role sql');
                  retval.replace(0);

          } else if (globalThis.sqlBuffer) {
            log('Setting return value to 0 for modified SELECT sql');
            retval.replace(0);
        }

  }}
});
```

OCIDefineByPos.js
```
globalThis.buffers = []

defineHandler({
  onEnter(log, args, state) {
    log('OCIDefineByPos()');
  const buf = args[4];
    const size = args[5].toInt32();
          const dt = args[6].toInt32();
    globalThis.buffers.push({ buf, size, dt });
  log('Stored:\nbuf: ' + buf + '\nsize: ' + size + '\n');
  },

  onLeave(log, retval, state) {
  }
});
```

OCIStmtFetch.js
```
defineHandler({
  onEnter(log, args, state) {
    log('OCIStmtFetch()');
  },

  onLeave(log, retval, state) {
          for(let i = 0; i < globalThis.buffers.length; i++){
                  const {buf, size, dt} = globalThis.buffers[i];
                  let value;
                  log('DataType: ' + dt);

                  try{
                        value = Memory.readUtf8string(buf, size);
                  } catch(_){
                        value = hexdump(buf, {length: size, header: false, ansi: false});
                  }

                  log(`=====================\nvalue:\n ${value}`);
          }
  }
});
```

```
           /* TID 0x2eb6 */
  5893 ms  OCIStmtPrepare()
  5893 ms  sql: SET ROLE waiter
  5893 ms  Storing handle for role statement
  5893 ms  OCIStmtExecute()
  5900 ms  OCIStmtExecute return  value: -1
  5900 ms  Setting return value to 0 for role sql
  5900 ms  OCIStmtPrepare()
  5900 ms  sql: SELECT * FROM SYS.MENU
  5900 ms  New sql: SELECT * FROM all_tables
  5900 ms  sql arg after injection: SELECT * FROM all_tables
  5900 ms  OCIStmtExecute()
  8228 ms  OCIDefineByPos()
  8228 ms  Stored:
buf: 0x7ffd5e0b4124
size: 4

  8228 ms  OCIDefineByPos()
  8228 ms  Stored:
buf: 0x7ffd5e0b4220
size: 50

  8228 ms  OCIDefineByPos()
  8228 ms  Stored:
buf: 0x7ffd5e0b4260
size: 4000

  8229 ms  OCIStmtFetch()
  8229 ms  DataType: 3
  8229 ms  =====================
value:
 7ffd5e0b4124  00 00 00 00                                      ....
  8229 ms  DataType: 1
  8229 ms  =====================
value:
 7ffd5e0b4220  00 00 00 00 00 00 00 00 28 44 0b 5e fd 7f 00 00  ........(D.^....
7ffd5e0b4230  00 00 00 00 00 00 00 00 f8 67 c1 ab ff 0f 00 00  .........g......
7ffd5e0b4240  28 6e 43 00 00 00 00 00 70 af 90 49 40 7c 00 00  (nC.....p..I@|..
7ffd5e0b4250  38 d1                                            8.
  8229 ms  DataType: 1
  8229 ms  =====================
value:
 7ffd5e0b4260  06 00 00 00 05 00 00 00 c0 3f 0b 5e fd 7f 00 00  .........?.^....
7ffd5e0b4270  01 03 01 00 00 00 00 00 07 05 00 00 00 00 00 00  ................
7ffd5e0b4280  01 03 01 00 00 00 00 00 07 05 00 00 00 00 00 00  ................
7ffd5e0b4290  01 00 00 00 00 00 00 00 ed 81 00 00 00 00 00 00  ................
7ffd5e0b42a0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b42b0  60 21 46 00 00 00 00 00 00 10 00 00 00 00 00 00  `!F.............
7ffd5e0b42c0  18 23 00 00 00 00 00 00 36 09 82 68 00 00 00 00  .#......6..h....
7ffd5e0b42d0  37 ee d5 24 00 00 00 00 ab a2 7e 68 00 00 00 00  7..$......~h....
7ffd5e0b42e0  99 d3 3c 0d 00 00 00 00 ab a2 7e 68 00 00 00 00  ..<.......~h....
7ffd5e0b42f0  99 d3 3c 0d 00 00 00 00 00 00 00 00 00 00 00 00  ..<.............
7ffd5e0b4300  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4310  ed 84 6e 25 00 00 00 00 38 d1 3b 44 40 7c 00 00  ..n%....8.;D@|..
7ffd5e0b4320  50 f2 93 49 40 7c 00 00 c4 f3 94 49 40 7c 00 00  P..I@|.....I@|..
7ffd5e0b4330  59 90 a2 42 40 7c 00 00 00 30 8f 49 40 7c 00 00  Y..B@|...0.I@|..
7ffd5e0b4340  40 47 0b 5e fd 7f 00 00 a4 c3 94 49 40 7c 00 00  @G.^.......I@|..
7ffd5e0b4350  01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4360  d0 43 0b 5e fd 7f 00 00 00 00 00 00 00 00 00 00  .C.^............
7ffd5e0b4370  23 d1 3b 44 40 7c 00 00 00 00 00 00 00 00 00 00  #.;D@|..........
7ffd5e0b4380  00 00 00 00 00 00 00 00 38 d1 3b 44 00 00 00 00  ........8.;D....
7ffd5e0b4390  00 30 8f 49 40 7c 00 00 01 00 00 00 00 00 00 00  .0.I@|..........
7ffd5e0b43a0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b43b0  00 00 00 00 40 7c 00 00 01 00 00 00 00 00 00 00  ....@|..........
7ffd5e0b43c0  00 00 00 00 00 00 00 00 70 af 90 49 40 7c 00 00  ........p..I@|..
7ffd5e0b43d0  50 53 0b 5e fd 7f 00 00 01 00 00 00 00 00 00 00  PS.^............
7ffd5e0b43e0  40 03 00 00 00 00 00 00 7f 45 4c 46 02 01 01 00  @........ELF....
7ffd5e0b43f0  00 00 00 00 00 00 00 00 03 00 3e 00 01 00 00 00  ..........>.....
7ffd5e0b4400  00 c8 04 00 00 00 00 00 40 00 00 00 00 00 00 00  ........@.......
7ffd5e0b4410  60 19 46 00 00 00 00 00 00 00 00 00 40 00 38 00  `.F.........@.8.
7ffd5e0b4420  0a 00 40 00 20 00 1f 00 01 00 00 00 04 00 00 00  ..@. ...........
7ffd5e0b4430  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4440  00 00 00 00 00 00 00 00 60 43 04 00 00 00 00 00  ........`C......
7ffd5e0b4450  60 43 04 00 00 00 00 00 00 10 00 00 00 00 00 00  `C..............
7ffd5e0b4460  01 00 00 00 05 00 00 00 00 50 04 00 00 00 00 00  .........P......
7ffd5e0b4470  00 50 04 00 00 00 00 00 00 50 04 00 00 00 00 00  .P.......P......
7ffd5e0b4480  52 41 35 00 00 00 00 00 52 41 35 00 00 00 00 00  RA5.....RA5.....
7ffd5e0b4490  00 10 00 00 00 00 00 00 01 00 00 00 04 00 00 00  ................
7ffd5e0b44a0  00 a0 39 00 00 00 00 00 00 a0 39 00 00 00 00 00  ..9.......9.....
7ffd5e0b44b0  00 a0 39 00 00 00 00 00 a0 fd 07 00 00 00 00 00  ..9.............
7ffd5e0b44c0  a0 fd 07 00 00 00 00 00 00 10 00 00 00 00 00 00  ................
7ffd5e0b44d0  01 00 00 00 06 00 00 00 80 a8 41 00 00 00 00 00  ..........A.....
7ffd5e0b44e0  80 b8 41 00 00 00 00 00 80 b8 41 00 00 00 00 00  ..A.......A.....
7ffd5e0b44f0  20 a6 00 00 00 00 00 00 a8 b5 01 00 00 00 00 00   ...............
7ffd5e0b4500  00 10 00 00 00 00 00 00 02 00 00 00 06 00 00 00  ................
7ffd5e0b4510  00 ff 41 00 00 00 00 00 00 0f 42 00 00 00 00 00  ..A.......B.....
7ffd5e0b4520  00 0f 42 00 00 00 00 00 20 02 00 00 00 00 00 00  ..B..... .......
7ffd5e0b4530  20 02 00 00 00 00 00 00 08 00 00 00 00 00 00 00   ...............
7ffd5e0b4540  04 00 00 00 04 00 00 00 70 02 00 00 00 00 00 00  ........p.......
7ffd5e0b4550  70 02 00 00 00 00 00 00 70 02 00 00 00 00 00 00  p.......p.......
7ffd5e0b4560  24 00 00 00 00 00 00 00 24 00 00 00 00 00 00 00  $.......$.......
7ffd5e0b4570  04 00 00 00 00 00 00 00 07 00 00 00 04 00 00 00  ................
7ffd5e0b4580  80 a8 41 00 00 00 00 00 80 b8 41 00 00 00 00 00  ..A.......A.....
7ffd5e0b4590  80 b8 41 00 00 00 00 00 00 00 00 00 00 00 00 00  ..A.............
7ffd5e0b45a0  20 b1 00 00 00 00 00 00 20 00 00 00 00 00 00 00   ....... .......
7ffd5e0b45b0  50 e5 74 64 04 00 00 00 1c 21 3c 00 00 00 00 00  P.td.....!<.....
7ffd5e0b45c0  1c 21 3c 00 00 00 00 00 1c 21 3c 00 00 00 00 00  .!<......!<.....
7ffd5e0b45d0  44 7a 00 00 00 00 00 00 44 7a 00 00 00 00 00 00  Dz......Dz......
7ffd5e0b45e0  04 00 00 00 00 00 00 00 51 e5 74 64 06 00 00 00  ........Q.td....
7ffd5e0b45f0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4600  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4610  00 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00  ................
7ffd5e0b4620  52 e5 74 64 04 00 00 00 be 23 94 49 40 7c 00 00  R.td.....#.I@|..
7ffd5e0b4630  98 4e 0b 5e fd 7f 00 00 05 00 00 00 00 00 00 00  .N.^............
7ffd5e0b4640  00 00 00 00 00 00 00 00 00 d0 16 5e fd 7f 00 00  ...........^....
7ffd5e0b4650  33 00 00 00 00 00 00 00 f0 06 00 00 00 00 00 00  3...............
7ffd5e0b4660  10 00 00 00 00 00 00 00 ff fb 8b 17 00 00 00 00  ................
7ffd5e0b4670  06 00 00 00 00 00 00 00 00 10 00 00 00 00 00 00  ................
7ffd5e0b4680  11 00 00 00 00 00 00 00 64 00 00 00 00 00 00 00  ........d.......
7ffd5e0b4690  03 00 00 00 00 00 00 00 40 d0 62 ae a4 55 00 00  ........@.b..U..
7ffd5e0b46a0  04 00 00 00 00 00 00 00 38 00 00 00 00 00 00 00  ........8.......
7ffd5e0b46b0  05 00 00 00 00 00 00 00 0d 00 00 00 00 00 00 00  ................
7ffd5e0b46c0  07 00 00 00 00 00 00 00 00 30 94 49 40 7c 00 00  .........0.I@|..
7ffd5e0b46d0  08 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b46e0  09 00 00 00 00 00 00 00 80 f5 62 ae a4 55 00 00  ..........b..U..
7ffd5e0b46f0  0b 00 00 00 00 00 00 00 e9 03 00 00 00 00 00 00  ................
7ffd5e0b4700  0c 00 00 00 00 00 00 00 e9 03 00 00 00 00 00 00  ................
7ffd5e0b4710  0d 00 00 00 00 00 00 00 e9 03 00 00 00 00 00 00  ................
7ffd5e0b4720  0e 00 00 00 00 00 00 00 e9 03 00 00 00 00 00 00  ................
7ffd5e0b4730  17 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4740  19 00 00 00 00 00 00 00 99 55 0b 5e fd 7f 00 00  .........U.^....
7ffd5e0b4750  1a 00 00 00 00 00 00 00 02 00 00 00 00 00 00 00  ................
7ffd5e0b4760  1f 00 00 00 00 00 00 00 f1 6f 0b 5e fd 7f 00 00  .........o.^....
7ffd5e0b4770  0f 00 00 00 00 00 00 00 a9 55 0b 5e fd 7f 00 00  .........U.^....
7ffd5e0b4780  1b 00 00 00 00 00 00 00 1c 00 00 00 00 00 00 00  ................
7ffd5e0b4790  1c 00 00 00 00 00 00 00 20 00 00 00 00 00 00 00  ........ .......
7ffd5e0b47a0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b47b0  00 aa 90 49 40 7c 00 00 10 a5 90 49 40 7c 00 00  ...I@|.....I@|..
7ffd5e0b47c0  d0 9f 90 49 40 7c 00 00 80 9a 90 49 40 7c 00 00  ...I@|.....I@|..
7ffd5e0b47d0  40 95 90 49 40 7c 00 00 00 90 90 49 40 7c 00 00  @..I@|.....I@|..
7ffd5e0b47e0  30 02 94 49 40 7c 00 00 b0 ba 97 49 40 7c 00 00  0..I@|.....I@|..
7ffd5e0b47f0  09 00 00 00 00 00 00 00 38 d1 3b 44 40 7c 00 00  ........8.;D@|..
7ffd5e0b4800  00 00 20 8f 16 bc fa ff 00 00 00 00 00 00 00 00  .. .............
7ffd5e0b4810  08 00 00 00 00 00 00 00 23 d1 3b 44 40 7c 00 00  ........#.;D@|..
7ffd5e0b4820  00 00 60 8f 16 bc fa ff 00 00 00 00 00 00 00 00  ..`.............
7ffd5e0b4830  06 00 00 00 00 00 00 00 f0 47 0b 5e fd 7f 00 00  .........G.^....
7ffd5e0b4840  00 00 a0 8f 16 bc fa ff 00 00 00 00 00 00 00 00  ................
7ffd5e0b4850  80 47 0b 5e fd 7f 00 00 72 9b 94 49 40 7c 00 00  .G.^....r..I@|..
7ffd5e0b4860  00 00 e0 8f 16 bc fa ff 0e 00 00 00 00 00 00 00  ................
7ffd5e0b4870  0e 00 00 00 00 00 00 00 e0 38 8f 49 40 7c 00 00  .........8.I@|..
7ffd5e0b4880  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4890  80 4f 0b 5e fd 7f 00 00 05 65 94 49 40 7c 00 00  .O.^.....e.I@|..
7ffd5e0b48a0  01 00 00 00 00 00 00 00 00 30 8f 49 40 7c 00 00  .........0.I@|..
7ffd5e0b48b0  00 00 00 00 00 00 00 00 67 5e 94 49 40 7c 00 00  ........g^.I@|..
7ffd5e0b48c0  01 00 00 00 00 00 00 00 b0 ba 97 49 40 7c 00 00  ...........I@|..
7ffd5e0b48d0  a0 48 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .H.^....g^.I@|..
7ffd5e0b48e0  01 00 00 00 00 00 00 00 50 aa 90 49 40 7c 00 00  ........P..I@|..
7ffd5e0b48f0  c0 48 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .H.^....g^.I@|..
7ffd5e0b4900  01 00 00 00 00 00 00 00 10 a5 90 49 40 7c 00 00  ...........I@|..
7ffd5e0b4910  e0 48 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .H.^....g^.I@|..
7ffd5e0b4920  01 00 00 00 00 00 00 00 d0 9f 90 49 40 7c 00 00  ...........I@|..
7ffd5e0b4930  00 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .I.^....g^.I@|..
7ffd5e0b4940  01 00 00 00 00 00 00 00 80 9a 90 49 40 7c 00 00  ...........I@|..
7ffd5e0b4950  20 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00   I.^....g^.I@|..
7ffd5e0b4960  01 00 00 00 00 00 00 00 40 95 90 49 40 7c 00 00  ........@..I@|..
7ffd5e0b4970  40 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  @I.^....g^.I@|..
7ffd5e0b4980  01 00 00 00 00 00 00 00 00 90 90 49 40 7c 00 00  ...........I@|..
7ffd5e0b4990  60 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  `I.^....g^.I@|..
7ffd5e0b49a0  01 00 00 00 00 00 00 00 70 07 94 49 40 7c 00 00  ........p..I@|..
7ffd5e0b49b0  80 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .I.^....g^.I@|..
7ffd5e0b49c0  01 00 00 00 00 00 00 00 30 02 94 49 40 7c 00 00  ........0..I@|..
7ffd5e0b49d0  a0 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .I.^....g^.I@|..
7ffd5e0b49e0  01 00 00 00 00 00 00 00 f0 fc 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b49f0  c0 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .I.^....g^.I@|..
7ffd5e0b4a00  01 00 00 00 00 00 00 00 a0 f7 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b4a10  e0 49 0b 5e fd 7f 00 00 67 5e 94 49 40 7c 00 00  .I.^....g^.I@|..
7ffd5e0b4a20  01 00 00 00 00 00 00 00 c3 d4 94 49 40 7c 00 00  ...........I@|..
7ffd5e0b4a30  00 4a 0b 5e fd 7f 00 00 30 02 94 49 40 7c 00 00  .J.^....0..I@|..
7ffd5e0b4a40  7d 67 7e f8 00 00 00 00 e0 95 a0 43 40 7c 00 00  }g~........C@|..
7ffd5e0b4a50  c0 94 a0 43 40 7c 00 00 c0 bd a1 43 40 7c 00 00  ...C@|.....C@|..
7ffd5e0b4a60  50 4b 0b 5e fd 7f 00 00 c3 d4 94 49 40 7c 00 00  PK.^.......I@|..
7ffd5e0b4a70  0d 0c 00 00 00 00 00 00 a0 f7 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b4a80  ae 37 ef 5a 00 00 00 00 b8 92 e0 43 40 7c 00 00  .7.Z.......C@|..
7ffd5e0b4a90  a8 7b e0 43 40 7c 00 00 38 e0 e2 43 40 7c 00 00  .{.C@|..8..C@|..
7ffd5e0b4aa0  90 4b 0b 5e fd 7f 00 00 c9 d8 94 49 40 7c 00 00  .K.^.......I@|..
7ffd5e0b4ab0  cc 12 00 00 00 00 00 00 38 e0 e2 43 40 7c 00 00  ........8..C@|..
7ffd5e0b4ac0  a0 f7 93 49 40 7c 00 00 58 4b 0b 5e fd 7f 00 00  ...I@|..XK.^....
7ffd5e0b4ad0  54 4b 0b 5e fd 7f 00 00 c0 bd a1 43 40 7c 00 00  TK.^.......C@|..
7ffd5e0b4ae0  d0 4b 0b 5e fd 7f 00 00 c3 d4 94 49 40 7c 00 00  .K.^.......I@|..
7ffd5e0b4af0  99 02 00 00 00 00 00 00 0e 00 00 00 00 00 00 00  ................
7ffd5e0b4b00  58 39 8f 49 40 7c 00 00 00 00 00 00 40 7c 00 00  X9.I@|......@|..
7ffd5e0b4b10  28 4c 0b 5e fd 7f 00 00 30 4c 0b 5e fd 7f 00 00  (L.^....0L.^....
7ffd5e0b4b20  54 4b 0b 5e fd 7f 00 00 2e 00 00 00 40 7c 00 00  TK.^........@|..
7ffd5e0b4b30  de bc 6b 01 00 00 00 00 d8 55 e2 43 40 7c 00 00  ..k......U.C@|..
7ffd5e0b4b40  ae 37 ef 5a 40 7c 00 00 5c 2c e4 43 40 7c 00 00  .7.Z@|..\,.C@|..
7ffd5e0b4b50  d4 4b 0b 5e 00 00 00 00 00 00 00 00 00 00 00 00  .K.^............
7ffd5e0b4b60  94 4b 0b 5e fd 7f 00 00 a0 3d 8f 49 40 7c 00 00  .K.^.....=.I@|..
7ffd5e0b4b70  40 fb 93 49 40 7c 00 00 5c 2c e4 43 40 7c 00 00  @..I@|..\,.C@|..
7ffd5e0b4b80  ae 37 ef 5a 00 00 00 00 b0 4c 0b 5e fd 7f 00 00  .7.Z.....L.^....
7ffd5e0b4b90  90 4c 0b 5e fd 7f 00 00 fc e1 94 49 40 7c 00 00  .L.^.......I@|..
7ffd5e0b4ba0  02 00 00 00 00 00 00 00 c3 d4 94 49 40 7c 00 00  ...........I@|..
7ffd5e0b4bb0  01 00 00 00 00 00 00 00 a0 f7 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b4bc0  c9 d6 be 87 00 00 00 00 b8 92 e0 43 40 7c 00 00  ...........C@|..
7ffd5e0b4bd0  78 36 e0 43 40 7c 00 00 38 e0 e2 43 40 7c 00 00  x6.C@|..8..C@|..
7ffd5e0b4be0  d0 4c 0b 5e fd 7f 00 00 c3 d4 94 49 40 7c 00 00  .L.^.......I@|..
7ffd5e0b4bf0  80 01 00 00 00 00 00 00 30 02 94 49 40 7c 00 00  ........0..I@|..
7ffd5e0b4c00  3d ad 39 0d 00 00 00 00 e0 95 a0 43 40 7c 00 00  =.9........C@|..
7ffd5e0b4c10  c4 80 a0 43 40 7c 00 00 c0 bd a1 43 40 7c 00 00  ...C@|.....C@|..
7ffd5e0b4c20  10 4d 0b 5e fd 7f 00 00 c9 d8 94 49 40 7c 00 00  .M.^.......I@|..
7ffd5e0b4c30  0e 07 00 00 00 00 00 00 c0 bd a1 43 40 7c 00 00  ...........C@|..
7ffd5e0b4c40  30 02 94 49 40 7c 00 00 d8 4c 0b 5e fd 7f 00 00  0..I@|...L.^....
7ffd5e0b4c50  d4 4c 0b 5e fd 7f 00 00 70 4d 0b 5e fd 7f 00 00  .L.^....pM.^....
7ffd5e0b4c60  94 4c 0b 5e fd 7f 00 00 ff d3 94 49 40 7c 00 00  .L.^.......I@|..
7ffd5e0b4c70  5b fb 1e 02 00 00 00 00 f0 fc 93 49 40 7c 00 00  [..........I@|..
7ffd5e0b4c80  3d 92 6a 83 00 00 00 00 e0 ba 90 49 40 7c 00 00  =.j........I@|..
7ffd5e0b4c90  8c ba 90 49 40 7c 00 00 10 d0 90 49 40 7c 00 00  ...I@|.....I@|..
7ffd5e0b4ca0  90 4d 0b 5e fd 7f 00 00 c9 d8 94 49 40 7c 00 00  .M.^.......I@|..
7ffd5e0b4cb0  ce 00 00 00 00 00 00 00 10 d0 90 49 40 7c 00 00  ...........I@|..
7ffd5e0b4cc0  f0 fc 93 49 40 7c 00 00 58 4d 0b 5e fd 7f 00 00  ...I@|..XM.^....
7ffd5e0b4cd0  54 4d 0b 5e fd 7f 00 00 00 00 00 00 00 00 00 00  TM.^............
7ffd5e0b4ce0  02 00 00 00 00 00 00 00 80 42 8f 49 40 7c 00 00  .........B.I@|..
7ffd5e0b4cf0  40 fb 93 49 40 7c 00 00 0e 00 00 00 00 00 00 00  @..I@|..........
7ffd5e0b4d00  58 39 8f 49 40 7c 00 00 00 00 00 00 fd 7f 00 00  X9.I@|..........
7ffd5e0b4d10  28 4e 0b 5e fd 7f 00 00 30 4e 0b 5e fd 7f 00 00  (N.^....0N.^....
7ffd5e0b4d20  54 4d 0b 5e fd 7f 00 00 3d 00 00 00 40 7c 00 00  TM.^....=...@|..
7ffd5e0b4d30  48 aa 0d 02 00 00 00 00 20 d9 24 44 40 7c 00 00  H....... .$D@|..
7ffd5e0b4d40  3d 92 6a 83 00 00 00 00 18 50 32 44 40 7c 00 00  =.j......P2D@|..
7ffd5e0b4d50  a0 f7 93 49 00 00 00 00 00 00 00 00 00 00 00 00  ...I............
7ffd5e0b4d60  40 b0 07 44 40 7c 00 00 00 00 00 00 00 00 00 00  @..D@|..........
7ffd5e0b4d70  f0 f5 93 49 40 7c 00 00 18 50 32 44 40 7c 00 00  ...I@|...P2D@|..
7ffd5e0b4d80  3d 92 6a 83 00 00 00 00 b0 4e 0b 5e fd 7f 00 00  =.j......N.^....
7ffd5e0b4d90  90 4e 0b 5e fd 7f 00 00 fc e1 94 49 40 7c 00 00  .N.^.......I@|..
7ffd5e0b4da0  03 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4db0  01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4dc0  01 00 00 00 00 00 00 00 50 f2 93 49 40 7c 00 00  ........P..I@|..
7ffd5e0b4dd0  30 4e 0b 5e fd 7f 00 00 fc 5b 95 49 40 7c 00 00  0N.^.....[.I@|..
7ffd5e0b4de0  01 00 00 00 00 00 00 00 a0 f7 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b4df0  00 00 00 00 00 00 00 00 f0 f5 93 49 40 7c 00 00  ...........I@|..
7ffd5e0b4e00  d4 19 94 49 40 7c 00 00 73 22 94 49 40 7c 00 00  ...I@|..s".I@|..
7ffd5e0b4e10  30 50 0b 5e fd 7f 00 00 28 4e 0b 5e fd 7f 00 00  0P.^....(N.^....
7ffd5e0b4e20  01 00 00 00 00 00 00 00 dd 10 a2 43 40 7c 00 00  ...........C@|..
7ffd5e0b4e30  f0 52 b2 43 40 7c 00 00 02 02 93 49 40 7c 00 00  .R.C@|.....I@|..
7ffd5e0b4e40  18 31 63 ae a4 55 00 00 60 51 0b 5e fd 7f 00 00  .1c..U..`Q.^....
7ffd5e0b4e50  c0 51 0b 5e fd 7f 00 00 00 10 00 00 00 00 00 00  .Q.^............
7ffd5e0b4e60  30 50 0b 5e fd 7f 00 00 93 1d 94 49 40 7c 00 00  0P.^.......I@|..
7ffd5e0b4e70  00 00 00 00 00 00 00 00 bf 17 94 49 40 7c 00 00  ...........I@|..
7ffd5e0b4e80  a0 f9 87 49 40 7c 00 00 e0 c2 97 49 40 7c 00 00  ...I@|.....I@|..
7ffd5e0b4e90  f0 4e 0b 5e fd 7f 00 00 40 d0 62 ae a4 55 00 00  .N.^....@.b..U..
7ffd5e0b4ea0  38 00 0d 00 00 00 00 00 00 30 94 49 40 7c 00 00  8........0.I@|..
7ffd5e0b4eb0  02 00 00 00 40 7c 00 00 28 c1 97 49 40 7c 00 00  ....@|..(..I@|..
7ffd5e0b4ec0  20 58 94 49 40 7c 00 00 00 00 a0 43 40 7c 00 00   X.I@|.....C@|..
7ffd5e0b4ed0  01 00 00 00 00 00 00 00 58 53 0b 5e fd 7f 00 00  ........XS.^....
7ffd5e0b4ee0  68 53 0b 5e fd 7f 00 00 e0 c2 97 49 40 7c 00 00  hS.^.......I@|..
7ffd5e0b4ef0  a0 52 0b 5e fd 7f 00 00 6e 83 95 49 40 7c 00 00  .R.^....n..I@|..
7ffd5e0b4f00  88 19 09 49 40 7c 00 00 68 53 0b 5e fd 7f 00 00  ...I@|..hS.^....
7ffd5e0b4f10  60 0b 8c 49 40 7c 00 00 60 0b 8c 49 40 7c 00 00  `..I@|..`..I@|..
7ffd5e0b4f20  88 19 09 49 40 7c 00 00 20 3b c0 43 40 7c 00 00  ...I@|.. ;.C@|..
7ffd5e0b4f30  00 00 00 00 00 00 00 00 38 43 07 44 40 7c 00 00  ........8C.D@|..
7ffd5e0b4f40  20 ab fe 43 40 7c 00 00 00 00 00 00 00 00 00 00   ..C@|..........
7ffd5e0b4f50  04 a6 fe 43 40 7c 00 00 80 1f 00 00 ff ff 02 00  ...C@|..........
7ffd5e0b4f60  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4f70  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b4f80  70 43 07 44 40 7c 00 00 98 43 07 44 40 7c 00 00  pC.D@|...C.D@|..
7ffd5e0b4f90  70 43 07 44 40 7c 00 00 98 43 07 44 40 7c 00 00  pC.D@|...C.D@|..
7ffd5e0b4fa0  10 43 07 44 40 7c 00 00 38 43 07 44 40 7c 00 00  .C.D@|..8C.D@|..
7ffd5e0b4fb0  30 95 a9 43 40 7c 00 00 de c4 aa 43 40 7c 00 00  0..C@|.....C@|..
7ffd5e0b4fc0  30 53 a4 43 40 7c 00 00 00 00 00 00 00 00 00 00  0S.C@|..........
7ffd5e0b4fd0  20 51 0b 5e fd 7f 00 00 02 00 00 00 00 00 00 00   Q.^............
7ffd5e0b4fe0  00 30 94 49 40 7c 00 00 14 00 00 00 00 00 00 00  .0.I@|..........
7ffd5e0b4ff0  01 00 00 00 05 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b5000  c0 51 0b 5e fd 7f 00 00 45 9b b2 43 40 7c 00 00  .Q.^....E..C@|..
7ffd5e0b5010  00 01 a6 43 40 7c 00 00 c0 f6 9f 42 40 7c 00 00  ...C@|.....B@|..
7ffd5e0b5020  70 51 0b 5e fd 7f 00 00 66 51 0b 5e fd 7f 00 00  pQ.^....fQ.^....
7ffd5e0b5030  00 00 00 00 00 00 00 00 67 51 0b 5e fd 7f 00 00  ........gQ.^....
7ffd5e0b5040  f0 50 0b 5e fd 7f 00 00 50 c5 a9 43 40 7c 00 00  .P.^....P..C@|..
7ffd5e0b5050  70 43 07 44 40 7c 00 00 98 43 07 44 40 7c 00 00  pC.D@|...C.D@|..
7ffd5e0b5060  00 0f 3d 00 00 00 00 00 90 f9 9f 42 40 7c 00 00  ..=........B@|..
7ffd5e0b5070  90 f9 9f 42 40 7c 00 00 90 f9 9f 42 40 7c 00 00  ...B@|.....B@|..
7ffd5e0b5080  00 00 00 00 00 00 00 00 00 f0 1f 42 40 7c 00 00  ...........B@|..
7ffd5e0b5090  c0 4a 7f 00 00 00 00 00 c0 f6 9f 42 40 7c 00 00  .J.........B@|..
7ffd5e0b50a0  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b50b0  00 00 00 00 00 00 00 00 00 a7 29 f8 bc be ec 94  ..........).....
7ffd5e0b50c0  f0 50 0b 5e fd 7f 00 00 c0 f6 9f 42 40 7c 00 00  .P.^.......B@|..
7ffd5e0b50d0  70 51 0b 5e fd 7f 00 00 68 51 0b 5e fd 7f 00 00  pQ.^....hQ.^....
7ffd5e0b50e0  c0 f6 9f 42 40 7c 00 00 00 f0 1f 42 40 7c 00 00  ...B@|.....B@|..
7ffd5e0b50f0  40 52 0b 5e fd 7f 00 00 1a cd a9 43 40 7c 00 00  @R.^.......C@|..
7ffd5e0b5100  80 f9 9f 42 40 7c 00 00 e0 c2 97 49 03 00 00 00  ...B@|.....I....
7ffd5e0b5110  00 10 80 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b5120  00 f0 1f 42 40 7c 00 00 00 10 80 00 00 00 00 00  ...B@|..........
7ffd5e0b5130  28 20 94 49 40 7c 00 00 c0 4a 7f 00 00 00 00 00  ( .I@|...J......
7ffd5e0b5140  00 20 94 49 40 7c 00 00 ad 11 94 49 40 7c 00 00  . .I@|.....I@|..
7ffd5e0b5150  38 36 2d 01 00 00 00 00 00 00 00 00 00 00 00 00  86-.............
7ffd5e0b5160  00 10 94 49 40 7c 00 01 00 00 00 00 00 00 00 00  ...I@|..........
7ffd5e0b5170  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b5180  00 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b5190  00 00 80 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
7ffd5e0b51a0  00 00 00 00 00 00 00 00 08 00 00 00 00 00 00 00  ................
7ffd5e0b51b0  c0 51 0b 5e fd 7f 00 00 20 fc ff ff ff ff ff ff  .Q.^.... .......
7ffd5e0b51c0  00 01 a6 43 40 7c 00 00 20 64 a6 43 40 7c 00 00  ...C@|.. d.C@|..
7ffd5e0b51d0  f0 52 b2 43 40 7c 00 00 40 5d b2 43 40 7c 00 00  .R.C@|..@].C@|..
7ffd5e0b51e0  e0 c2 b2 43 40 7c 00 00 10 c3 b2 43 40 7c 00 00  ...C@|.....C@|..
7ffd5e0b51f0  60 b9 b2 43 40 7c 00 00 04 00 00 18 40 7c 00 00  `..C@|......@|..
Process terminated
```


const newSql = "SELECT 1, TABLE_NAME, OWNER FROM all_tables";

