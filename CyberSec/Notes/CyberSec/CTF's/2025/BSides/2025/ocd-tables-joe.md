```
Enter username: joe
Enter password: 
Connected to Oracle database successfully. Welcome back, joe
           /* TID 0x438f */
  7183 ms  OCIStmtPrepare()
  7183 ms  sql: SET ROLE waiter
  7183 ms  Storing handle for role statement
  7185 ms  OCIStmtExecute()
  7213 ms  OCIStmtPrepare()
  7213 ms  sql: SELECT * FROM SYS.MENU
  7213 ms  New sql: SELECT 1, TABLE_NAME, OWNER FROM all_tables
  7213 ms  sql arg after injection: SELECT 1, TABLE_NAME, OWNER FROM all_tables
  7213 ms  OCIStmtExecute()
ID: 1, Name: DUAL, Description: SYS
ID: 1, Name: SYSTEM_PRIVILEGE_MAP, Description: SYS
ID: 1, Name: TABLE_PRIVILEGE_MAP, Description: SYS
ID: 1, Name: USER_PRIVILEGE_MAP, Description: SYS
ID: 1, Name: STMT_AUDIT_OPTION_MAP, Description: SYS
ID: 1, Name: AV_DUAL, Description: SYS
ID: 1, Name: AUDIT_ACTIONS, Description: SYS
ID: 1, Name: ALL_UNIFIED_AUDIT_ACTIONS, Description: SYS
ID: 1, Name: SCHEDULER_FILEWATCHER_QT, Description: SYS
ID: 1, Name: AW$EXPRESS, Description: SYS
ID: 1, Name: AW$AWMD, Description: SYS
ID: 1, Name: AW$AWCREATE, Description: SYS
ID: 1, Name: AW$AWCREATE10G, Description: SYS
ID: 1, Name: AW$AWXML, Description: SYS
ID: 1, Name: AW$AWREPORT, Description: SYS
ID: 1, Name: MENU, Description: SYS
ID: 1, Name: WRR$_REPLAY_CALL_FILTER, Description: SYS
ID: 1, Name: FINALHIST$, Description: SYS
ID: 1, Name: MODELGTTRAW$, Description: SYS
ID: 1, Name: PMAPGTT$, Description: SYS
ID: 1, Name: MV_CAPABILITIES_TABLE$, Description: SYS
ID: 1, Name: REWRITE_TABLE$, Description: SYS
ID: 1, Name: WRI$_ADV_ASA_RECO_DATA, Description: SYS
ID: 1, Name: WRI$_HEATMAP_TOPN_DEP1, Description: SYS
ID: 1, Name: WRI$_HEATMAP_TOPN_DEP2, Description: SYS
ID: 1, Name: PLAN_TABLE$, Description: SYS
ID: 1, Name: KU$_LIST_FILTER_TEMP, Description: SYS
ID: 1, Name: KU$_LIST_FILTER_TEMP_2, Description: SYS
ID: 1, Name: DATA_PUMP_XPL_TABLE$, Description: SYS
  8335 ms  OCIDefineByPos()
  8335 ms  Stored:
buf: 0x7ffe0437fce4
size: 4
dt: 3
rlenp: 0x7ffe0437fcde

  8335 ms  OCIDefineByPos()
  8335 ms  Stored:
buf: 0x7ffe0437fde0
size: 50
dt: 1
rlenp: 0x7ffe0437fce0

  8335 ms  OCIDefineByPos()
  8335 ms  Stored:
buf: 0x7ffe0437fe20
size: 4000
dt: 1
rlenp: 0x7ffe0437fce2

  8335 ms  OCIStmtFetch()
  8335 ms  OCIStmtFetch return value: 0
  8335 ms  Buffer 0 DataType: 3
ID: 1, Name: KU$NOEXP_TAB, Description: SYS
  8335 ms  Actual length: 4
ID: 1, Name: KU$_SHARD_DOMIDX_NAMEMAP, Description: SYS
  8335 ms  Integer value: 1
  8335 ms  Buffer 1 DataType: 1
  8335 ms  Actual length: 4
  8335 ms  Value: DUAL
  8335 ms  Buffer 2 DataType: 1
  8335 ms  Actual length: 3
  8335 ms  Value: SYS
  8335 ms  OCIStmtFetch()
  8337 ms  OCIStmtFetch return value: 0
  8337 ms  Buffer 0 DataType: 3
  8337 ms  Actual length: 4
  8337 ms  Integer value: 1
  8337 ms  Buffer 1 DataType: 1
  8337 ms  Actual length: 20
  8337 ms  Value: SYSTEM_PRIVILEGE_MAP
  8337 ms  Buffer 2 DataType: 1
  8337 ms  Actual length: 3
  8337 ms  Value: SYS
  8337 ms  OCIStmtFetch()
  8337 ms  OCIStmtFetch return value: 0
  8337 ms  Buffer 0 DataType: 3
  8337 ms  Actual length: 4
  8337 ms  Integer value: 1
  8337 ms  Buffer 1 DataType: 1
  8337 ms  Actual length: 19
  8337 ms  Value: TABLE_PRIVILEGE_MAP
  8337 ms  Buffer 2 DataType: 1
  8337 ms  Actual length: 3
  8337 ms  Value: SYS
  8337 ms  OCIStmtFetch()
  8338 ms  OCIStmtFetch return value: 0
  8338 ms  Buffer 0 DataType: 3
  8338 ms  Actual length: 4
  8338 ms  Integer value: 1
  8338 ms  Buffer 1 DataType: 1
  8338 ms  Actual length: 18
  8338 ms  Value: USER_PRIVILEGE_MAP
  8338 ms  Buffer 2 DataType: 1
  8338 ms  Actual length: 3
  8338 ms  Value: SYS
  8338 ms  OCIStmtFetch()
  8338 ms  OCIStmtFetch return value: 0
  8338 ms  Buffer 0 DataType: 3
  8338 ms  Actual length: 4
  8338 ms  Integer value: 1
  8338 ms  Buffer 1 DataType: 1
  8338 ms  Actual length: 21
  8338 ms  Value: STMT_AUDIT_OPTION_MAP
  8338 ms  Buffer 2 DataType: 1
  8338 ms  Actual length: 3
  8338 ms  Value: SYS
  8338 ms  OCIStmtFetch()
  8341 ms  OCIStmtFetch return value: 0
  8341 ms  Buffer 0 DataType: 3
  8341 ms  Actual length: 4
  8341 ms  Integer value: 1
  8341 ms  Buffer 1 DataType: 1
  8341 ms  Actual length: 7
  8341 ms  Value: AV_DUAL
  8341 ms  Buffer 2 DataType: 1
  8341 ms  Actual length: 3
  8341 ms  Value: SYS
  8341 ms  OCIStmtFetch()
  8341 ms  OCIStmtFetch return value: 0
  8341 ms  Buffer 0 DataType: 3
  8341 ms  Actual length: 4
  8341 ms  Integer value: 1
  8341 ms  Buffer 1 DataType: 1
  8341 ms  Actual length: 13
  8341 ms  Value: AUDIT_ACTIONS
  8341 ms  Buffer 2 DataType: 1
  8341 ms  Actual length: 3
  8341 ms  Value: SYS
  8342 ms  OCIStmtFetch()
  8346 ms  OCIStmtFetch return value: 0
  8346 ms  Buffer 0 DataType: 3
  8346 ms  Actual length: 4
  8346 ms  Integer value: 1
  8346 ms  Buffer 1 DataType: 1
  8346 ms  Actual length: 25
  8346 ms  Value: ALL_UNIFIED_AUDIT_ACTIONS
  8346 ms  Buffer 2 DataType: 1
  8346 ms  Actual length: 3
  8346 ms  Value: SYS
  8346 ms  OCIStmtFetch()
  8346 ms  OCIStmtFetch return value: 0
  8346 ms  Buffer 0 DataType: 3
  8346 ms  Actual length: 4
ID: 1, Name: KU$XKTFBUE, Description: SYS
  8346 ms  Integer value: 1
ID: 1, Name: COMMIT_SCN_LOG$, Description: SYS
  8346 ms  Buffer 1 DataType: 1
  8346 ms  Actual length: 24
  8346 ms  Value: SCHEDULER_FILEWATCHER_QT
  8346 ms  Buffer 2 DataType: 1
  8346 ms  Actual length: 3
  8346 ms  Value: SYS
  8346 ms  OCIStmtFetch()
  8351 ms  OCIStmtFetch return value: 0
  8351 ms  Buffer 0 DataType: 3
  8351 ms  Actual length: 4
  8351 ms  Integer value: 1
  8351 ms  Buffer 1 DataType: 1
  8351 ms  Actual length: 10
  8351 ms  Value: AW$EXPRESS
  8351 ms  Buffer 2 DataType: 1
  8351 ms  Actual length: 3
  8351 ms  Value: SYS
  8351 ms  OCIStmtFetch()
  8351 ms  OCIStmtFetch return value: 0
  8351 ms  Buffer 0 DataType: 3
  8351 ms  Actual length: 4
  8351 ms  Integer value: 1
  8351 ms  Buffer 1 DataType: 1
  8351 ms  Actual length: 7
  8351 ms  Value: AW$AWMD
  8351 ms  Buffer 2 DataType: 1
  8351 ms  Actual length: 3
  8351 ms  Value: SYS
  8351 ms  OCIStmtFetch()
  8351 ms  OCIStmtFetch return value: 0
  8351 ms  Buffer 0 DataType: 3
  8351 ms  Actual length: 4
  8351 ms  Integer value: 1
  8351 ms  Buffer 1 DataType: 1
  8351 ms  Actual length: 11
  8351 ms  Value: AW$AWCREATE
  8351 ms  Buffer 2 DataType: 1
  8351 ms  Actual length: 3
  8351 ms  Value: SYS
  8351 ms  OCIStmtFetch()
  8351 ms  OCIStmtFetch return value: 0
  8351 ms  Buffer 0 DataType: 3
  8351 ms  Actual length: 4
  8351 ms  Integer value: 1
  8351 ms  Buffer 1 DataType: 1
  8351 ms  Actual length: 14
  8351 ms  Value: AW$AWCREATE10G
  8351 ms  Buffer 2 DataType: 1
  8351 ms  Actual length: 3
  8351 ms  Value: SYS
  8352 ms  OCIStmtFetch()
  8352 ms  OCIStmtFetch return value: 0
  8352 ms  Buffer 0 DataType: 3
  8352 ms  Actual length: 4
  8352 ms  Integer value: 1
  8352 ms  Buffer 1 DataType: 1
  8352 ms  Actual length: 8
  8352 ms  Value: AW$AWXML
  8352 ms  Buffer 2 DataType: 1
  8352 ms  Actual length: 3
  8352 ms  Value: SYS
  8352 ms  OCIStmtFetch()
  8352 ms  OCIStmtFetch return value: 0
  8352 ms  Buffer 0 DataType: 3
  8352 ms  Actual length: 4
  8352 ms  Integer value: 1
  8352 ms  Buffer 1 DataType: 1
  8352 ms  Actual length: 11
  8352 ms  Value: AW$AWREPORT
  8352 ms  Buffer 2 DataType: 1
  8352 ms  Actual length: 3
  8352 ms  Value: SYS
  8352 ms  OCIStmtFetch()
  8359 ms  OCIStmtFetch return value: 0
  8359 ms  Buffer 0 DataType: 3
  8359 ms  Actual length: 4
  8359 ms  Integer value: 1
  8359 ms  Buffer 1 DataType: 1
  8359 ms  Actual length: 4
  8359 ms  Value: MENU
  8359 ms  Buffer 2 DataType: 1
  8359 ms  Actual length: 3
  8359 ms  Value: SYS
  8360 ms  OCIStmtFetch()
  8360 ms  OCIStmtFetch return value: 0
  8360 ms  Buffer 0 DataType: 3
  8360 ms  Actual length: 4
  8360 ms  Integer value: 1
  8360 ms  Buffer 1 DataType: 1
  8360 ms  Actual length: 23
  8360 ms  Value: WRR$_REPLAY_CALL_FILTER
  8360 ms  Buffer 2 DataType: 1
  8360 ms  Actual length: 3
  8360 ms  Value: SYS
  8360 ms  OCIStmtFetch()
  8380 ms  OCIStmtFetch return value: 0
  8380 ms  Buffer 0 DataType: 3
  8380 ms  Actual length: 4
  8380 ms  Integer value: 1
  8380 ms  Buffer 1 DataType: 1
  8380 ms  Actual length: 10
  8380 ms  Value: FINALHIST$
  8380 ms  Buffer 2 DataType: 1
  8380 ms  Actual length: 3
  8380 ms  Value: SYS
  8380 ms  OCIStmtFetch()
  8380 ms  OCIStmtFetch return value: 0
  8380 ms  Buffer 0 DataType: 3
  8380 ms  Actual length: 4
  8380 ms  Integer value: 1
  8380 ms  Buffer 1 DataType: 1
  8380 ms  Actual length: 12
  8380 ms  Value: MODELGTTRAW$
  8380 ms  Buffer 2 DataType: 1
  8380 ms  Actual length: 3
  8380 ms  Value: SYS
  8381 ms  OCIStmtFetch()
  8384 ms  OCIStmtFetch return value: 0
  8384 ms  Buffer 0 DataType: 3
  8384 ms  Actual length: 4
  8384 ms  Integer value: 1
  8384 ms  Buffer 1 DataType: 1
  8384 ms  Actual length: 8
  8384 ms  Value: PMAPGTT$
  8384 ms  Buffer 2 DataType: 1
  8384 ms  Actual length: 3
  8384 ms  Value: SYS
  8385 ms  OCIStmtFetch()
  8385 ms  OCIStmtFetch return value: 0
  8385 ms  Buffer 0 DataType: 3
  8385 ms  Actual length: 4
  8385 ms  Integer value: 1
  8385 ms  Buffer 1 DataType: 1
  8385 ms  Actual length: 22
  8385 ms  Value: MV_CAPABILITIES_TABLE$
  8385 ms  Buffer 2 DataType: 1
  8385 ms  Actual length: 3
  8385 ms  Value: SYS
  8385 ms  OCIStmtFetch()
ID: 1, Name: SYS_DIRECTIVE_TRACKED_OBJS, Description: SYS
ID: 1, Name: ODCI_SECOBJ$, Description: SYS
ID: 1, Name: ODCI_WARNINGS$, Description: SYS
ID: 1, Name: ODCI_PMO_ROWIDS$, Description: SYS
ID: 1, Name: XS$VALIDATION_TABLE, Description: SYS
ID: 1, Name: IMPDP_STATS, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_12_2, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_12_0, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_11_2, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_11_1_0_7, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_11_1, Description: SYS
ID: 1, Name: KU$_DATAPUMP_MASTER_10_1, Description: SYS
ID: 1, Name: SPD_SCRATCH_TAB, Description: SYS
ID: 1, Name: SAM_SPARSITY_ADVICE, Description: SYS
ID: 1, Name: HELP, Description: SYSTEM
ID: 1, Name: OL$, Description: SYSTEM
ID: 1, Name: OL$HINTS, Description: SYSTEM
ID: 1, Name: OL$NODES, Description: SYSTEM
ID: 1, Name: XDB_INDEX_DDL_CACHE, Description: XDB
ID: 1, Name: XDB$IMPORT_TT_INFO, Description: XDB
ID: 1, Name: XDB$IMPORT_QN_INFO, Description: XDB
ID: 1, Name: XDB$IMPORT_NM_INFO, Description: XDB
ID: 1, Name: XDB$IMPORT_PT_INFO, Description: XDB
ID: 1, Name: XDB$XIDX_IMP_T, Description: XDB
ID: 1, Name: DR$NUMBER_SEQUENCE, Description: CTXSYS
ID: 1, Name: DR$OBJECT_ATTRIBUTE, Description: CTXSYS
ID: 1, Name: DR$POLICY_TAB, Description: CTXSYS
ID: 1, Name: DR$THS, Description: CTXSYS
ID: 1, Name: DR$THS_PHRASE, Description: CTXSYS
ID: 1, Name: SDO_ELLIPSOIDS, Description: MDSYS
ID: 1, Name: SDO_DATUMS, Description: MDSYS
ID: 1, Name: SDO_UNITS_OF_MEASURE, Description: MDSYS
ID: 1, Name: SDO_COORD_REF_SYS, Description: MDSYS
ID: 1, Name: SDO_COORD_SYS, Description: MDSYS
ID: 1, Name: SDO_COORD_AXES, Description: MDSYS
ID: 1, Name: SDO_COORD_AXIS_NAMES, Description: MDSYS
ID: 1, Name: SDO_COORD_OPS, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_PATHS, Description: MDSYS
ID: 1, Name: SDO_PREFERRED_OPS_SYSTEM, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_METHODS, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_PARAMS, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_PARAM_VALS, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_PARAM_USE, Description: MDSYS
ID: 1, Name: SDO_CS_SRS, Description: MDSYS
ID: 1, Name: SDO_PRIME_MERIDIANS, Description: MDSYS
ID: 1, Name: SDO_CRS_GEOGRAPHIC_PLUS_HEIGHT, Description: MDSYS
ID: 1, Name: SDO_ELLIPSOIDS_OLD_SNAPSHOT, Description: MDSYS
ID: 1, Name: SDO_PROJECTIONS_OLD_SNAPSHOT, Description: MDSYS
ID: 1, Name: SDO_DATUMS_OLD_SNAPSHOT, Description: MDSYS
ID: 1, Name: SDO_XML_SCHEMAS, Description: MDSYS
ID: 1, Name: SDO_FEATURE_USAGE, Description: MDSYS
ID: 1, Name: SDO_XSD_TABLE, Description: MDSYS
ID: 1, Name: SDO_GEOR_XMLSCHEMA_TABLE, Description: MDSYS
ID: 1, Name: SDO_TIN_PC_SEQ, Description: MDSYS
ID: 1, Name: SDO_TIN_PC_SYSDATA_TABLE, Description: MDSYS
ID: 1, Name: SRSNAMESPACE_TABLE, Description: MDSYS
  8387 ms  OCIStmtFetch return value: 0
  8387 ms  Buffer 0 DataType: 3
  8387 ms  Actual length: 4
  8387 ms  Integer value: 1
  8387 ms  Buffer 1 DataType: 1
ID: 1, Name: SDO_PREFERRED_OPS_USER, Description: MDSYS
ID: 1, Name: NTV2_XML_DATA, Description: MDSYS
  8387 ms  Actual length: 14
  8387 ms  Value: REWRITE_TABLE$
  8387 ms  Buffer 2 DataType: 1
  8387 ms  Actual length: 3
  8387 ms  Value: SYS
  8388 ms  OCIStmtFetch()
ID: 1, Name: SDO_SRIDS_BY_URN, Description: MDSYS
  8388 ms  OCIStmtFetch return value: 0
  8388 ms  Buffer 0 DataType: 3
  8388 ms  Actual length: 4
  8388 ms  Integer value: 1
ID: 1, Name: SDO_SRIDS_BY_URN_PATTERN, Description: MDSYS
  8388 ms  Buffer 1 DataType: 1
  8388 ms  Actual length: 22
  8388 ms  Value: WRI$_ADV_ASA_RECO_DATA
  8388 ms  Buffer 2 DataType: 1
ID: 1, Name: SDO_INDEX_HISTOGRAM_TABLE, Description: MDSYS
  8388 ms  Actual length: 3
  8388 ms  Value: SYS
  8388 ms  OCIStmtFetch()
  8388 ms  OCIStmtFetch return value: 0
  8388 ms  Buffer 0 DataType: 3
  8388 ms  Actual length: 4
  8388 ms  Integer value: 1
  8388 ms  Buffer 1 DataType: 1
  8388 ms  Actual length: 22
  8388 ms  Value: WRI$_HEATMAP_TOPN_DEP1
  8388 ms  Buffer 2 DataType: 1
ID: 1, Name: SDO_DIST_METADATA_TABLE, Description: MDSYS
  8388 ms  Actual length: 3
  8388 ms  Value: SYS
  8388 ms  OCIStmtFetch()
  8388 ms  OCIStmtFetch return value: 0
  8388 ms  Buffer 0 DataType: 3
  8388 ms  Actual length: 4
  8388 ms  Integer value: 1
  8388 ms  Buffer 1 DataType: 1
  8388 ms  Actual length: 22
  8388 ms  Value: WRI$_HEATMAP_TOPN_DEP2
  8388 ms  Buffer 2 DataType: 1
  8388 ms  Actual length: 3
  8388 ms  Value: SYS
  8389 ms  OCIStmtFetch()
  8392 ms  OCIStmtFetch return value: 0
  8392 ms  Buffer 0 DataType: 3
  8392 ms  Actual length: 4
  8392 ms  Integer value: 1
  8392 ms  Buffer 1 DataType: 1
  8392 ms  Actual length: 11
  8392 ms  Value: PLAN_TABLE$
  8392 ms  Buffer 2 DataType: 1
  8392 ms  Actual length: 3
  8392 ms  Value: SYS
  8392 ms  OCIStmtFetch()
  8392 ms  OCIStmtFetch return value: 0
  8392 ms  Buffer 0 DataType: 3
  8392 ms  Actual length: 4
  8392 ms  Integer value: 1
  8392 ms  Buffer 1 DataType: 1
  8392 ms  Actual length: 20
  8392 ms  Value: KU$_LIST_FILTER_TEMP
  8392 ms  Buffer 2 DataType: 1
  8392 ms  Actual length: 3
  8392 ms  Value: SYS
  8392 ms  OCIStmtFetch()
  8393 ms  OCIStmtFetch return value: 0
  8393 ms  Buffer 0 DataType: 3
  8393 ms  Actual length: 4
  8393 ms  Integer value: 1
  8393 ms  Buffer 1 DataType: 1
  8393 ms  Actual length: 22
  8393 ms  Value: KU$_LIST_FILTER_TEMP_2
  8393 ms  Buffer 2 DataType: 1
  8393 ms  Actual length: 3
  8393 ms  Value: SYS
  8393 ms  OCIStmtFetch()
  8393 ms  OCIStmtFetch return value: 0
  8393 ms  Buffer 0 DataType: 3
  8393 ms  Actual length: 4
  8393 ms  Integer value: 1
  8393 ms  Buffer 1 DataType: 1
  8393 ms  Actual length: 20
  8393 ms  Value: DATA_PUMP_XPL_TABLE$
  8393 ms  Buffer 2 DataType: 1
  8393 ms  Actual length: 3
  8393 ms  Value: SYS
  8393 ms  OCIStmtFetch()
  8395 ms  OCIStmtFetch return value: 0
  8395 ms  Buffer 0 DataType: 3
  8395 ms  Actual length: 4
  8395 ms  Integer value: 1
  8395 ms  Buffer 1 DataType: 1
  8395 ms  Actual length: 12
  8395 ms  Value: KU$NOEXP_TAB
  8395 ms  Buffer 2 DataType: 1
  8395 ms  Actual length: 3
  8395 ms  Value: SYS
  8395 ms  OCIStmtFetch()
  8395 ms  OCIStmtFetch return value: 0
  8395 ms  Buffer 0 DataType: 3
  8395 ms  Actual length: 4
  8395 ms  Integer value: 1
  8395 ms  Buffer 1 DataType: 1
  8395 ms  Actual length: 24
  8395 ms  Value: KU$_SHARD_DOMIDX_NAMEMAP
  8395 ms  Buffer 2 DataType: 1
  8395 ms  Actual length: 3
  8395 ms  Value: SYS
  8395 ms  OCIStmtFetch()
  8402 ms  OCIStmtFetch return value: 0
  8402 ms  Buffer 0 DataType: 3
  8402 ms  Actual length: 4
  8402 ms  Integer value: 1
  8402 ms  Buffer 1 DataType: 1
  8402 ms  Actual length: 10
  8402 ms  Value: KU$XKTFBUE
  8402 ms  Buffer 2 DataType: 1
  8402 ms  Actual length: 3
  8402 ms  Value: SYS
  8402 ms  OCIStmtFetch()
  8402 ms  OCIStmtFetch return value: 0
  8402 ms  Buffer 0 DataType: 3
  8402 ms  Actual length: 4
  8402 ms  Integer value: 1
  8402 ms  Buffer 1 DataType: 1
  8402 ms  Actual length: 15
  8402 ms  Value: COMMIT_SCN_LOG$
  8402 ms  Buffer 2 DataType: 1
  8402 ms  Actual length: 3
  8402 ms  Value: SYS
  8402 ms  OCIStmtFetch()
  8410 ms  OCIStmtFetch return value: 0
  8410 ms  Buffer 0 DataType: 3
  8410 ms  Actual length: 4
  8410 ms  Integer value: 1
  8410 ms  Buffer 1 DataType: 1
  8410 ms  Actual length: 26
  8410 ms  Value: SYS_DIRECTIVE_TRACKED_OBJS
  8410 ms  Buffer 2 DataType: 1
  8410 ms  Actual length: 3
  8410 ms  Value: SYS
  8410 ms  OCIStmtFetch()
  8410 ms  OCIStmtFetch return value: 0
  8410 ms  Buffer 0 DataType: 3
  8410 ms  Actual length: 4
  8410 ms  Integer value: 1
  8410 ms  Buffer 1 DataType: 1
  8410 ms  Actual length: 12
  8410 ms  Value: ODCI_SECOBJ$
  8410 ms  Buffer 2 DataType: 1
  8410 ms  Actual length: 3
  8410 ms  Value: SYS
  8411 ms  OCIStmtFetch()
  8411 ms  OCIStmtFetch return value: 0
  8411 ms  Buffer 0 DataType: 3
  8411 ms  Actual length: 4
  8411 ms  Integer value: 1
  8411 ms  Buffer 1 DataType: 1
  8411 ms  Actual length: 14
  8411 ms  Value: ODCI_WARNINGS$
  8411 ms  Buffer 2 DataType: 1
  8411 ms  Actual length: 3
  8411 ms  Value: SYS
  8411 ms  OCIStmtFetch()
  8411 ms  OCIStmtFetch return value: 0
  8411 ms  Buffer 0 DataType: 3
  8411 ms  Actual length: 4
  8411 ms  Integer value: 1
  8411 ms  Buffer 1 DataType: 1
  8411 ms  Actual length: 16
  8411 ms  Value: ODCI_PMO_ROWIDS$
  8411 ms  Buffer 2 DataType: 1
  8411 ms  Actual length: 3
  8411 ms  Value: SYS
  8411 ms  OCIStmtFetch()
  8414 ms  OCIStmtFetch return value: 0
  8414 ms  Buffer 0 DataType: 3
  8414 ms  Actual length: 4
  8414 ms  Integer value: 1
  8414 ms  Buffer 1 DataType: 1
  8414 ms  Actual length: 19
  8414 ms  Value: XS$VALIDATION_TABLE
  8414 ms  Buffer 2 DataType: 1
  8414 ms  Actual length: 3
  8414 ms  Value: SYS
  8415 ms  OCIStmtFetch()
  8415 ms  OCIStmtFetch return value: 0
  8415 ms  Buffer 0 DataType: 3
  8415 ms  Actual length: 4
  8415 ms  Integer value: 1
  8415 ms  Buffer 1 DataType: 1
  8415 ms  Actual length: 11
  8415 ms  Value: IMPDP_STATS
  8415 ms  Buffer 2 DataType: 1
  8415 ms  Actual length: 3
  8415 ms  Value: SYS
  8415 ms  OCIStmtFetch()
  8415 ms  OCIStmtFetch return value: 0
  8415 ms  Buffer 0 DataType: 3
  8415 ms  Actual length: 4
  8415 ms  Integer value: 1
  8415 ms  Buffer 1 DataType: 1
  8415 ms  Actual length: 24
  8415 ms  Value: KU$_DATAPUMP_MASTER_12_2
  8415 ms  Buffer 2 DataType: 1
  8415 ms  Actual length: 3
  8415 ms  Value: SYS
  8416 ms  OCIStmtFetch()
ID: 1, Name: OGIS_SPATIAL_REFERENCE_SYSTEMS, Description: MDSYS
ID: 1, Name: OGIS_GEOMETRY_COLUMNS, Description: MDSYS
  8416 ms  OCIStmtFetch return value: 0
  8416 ms  Buffer 0 DataType: 3
  8416 ms  Actual length: 4
  8416 ms  Integer value: 1
  8416 ms  Buffer 1 DataType: 1
  8416 ms  Actual length: 24
  8416 ms  Value: KU$_DATAPUMP_MASTER_12_0
  8416 ms  Buffer 2 DataType: 1
  8416 ms  Actual length: 3
  8416 ms  Value: SYS
  8416 ms  OCIStmtFetch()
  8416 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_WS_CONFERENCE, Description: MDSYS
  8416 ms  Buffer 0 DataType: 3
  8416 ms  Actual length: 4
  8416 ms  Integer value: 1
  8416 ms  Buffer 1 DataType: 1
  8416 ms  Actual length: 24
  8416 ms  Value: KU$_DATAPUMP_MASTER_11_2
ID: 1, Name: SDO_WS_CONFERENCE_RESULTS, Description: MDSYS
  8416 ms  Buffer 2 DataType: 1
  8416 ms  Actual length: 3
  8416 ms  Value: SYS
  8416 ms  OCIStmtFetch()
  8416 ms  OCIStmtFetch return value: 0
  8416 ms  Buffer 0 DataType: 3
  8416 ms  Actual length: 4
  8416 ms  Integer value: 1
  8416 ms  Buffer 1 DataType: 1
ID: 1, Name: SDO_WS_CONFERENCE_PARTICIPANTS, Description: MDSYS
ID: 1, Name: SDO_GEOR_PLUGIN_REGISTRY, Description: MDSYS
  8416 ms  Actual length: 28
  8416 ms  Value: KU$_DATAPUMP_MASTER_11_1_0_7
  8416 ms  Buffer 2 DataType: 1
  8416 ms  Actual length: 3
  8416 ms  Value: SYS
  8416 ms  OCIStmtFetch()
  8417 ms  OCIStmtFetch return value: 0
  8417 ms  Buffer 0 DataType: 3
  8417 ms  Actual length: 4
  8417 ms  Integer value: 1
  8417 ms  Buffer 1 DataType: 1
  8417 ms  Actual length: 24
  8417 ms  Value: KU$_DATAPUMP_MASTER_11_1
  8417 ms  Buffer 2 DataType: 1
  8417 ms  Actual length: 3
ID: 1, Name: RDF_PARAM$_TBL, Description: MDSYS
  8417 ms  Value: SYS
  8417 ms  OCIStmtFetch()
  8417 ms  OCIStmtFetch return value: 0
  8417 ms  Buffer 0 DataType: 3
  8417 ms  Actual length: 4
ID: 1, Name: SDO_CS_CONTEXT_INFORMATION, Description: MDSYS
  8417 ms  Integer value: 1
  8417 ms  Buffer 1 DataType: 1
  8417 ms  Actual length: 24
ID: 1, Name: SDO_ST_TOLERANCE, Description: MDSYS
  8417 ms  Value: KU$_DATAPUMP_MASTER_10_1
  8417 ms  Buffer 2 DataType: 1
  8417 ms  Actual length: 3
  8417 ms  Value: SYS
  8417 ms  OCIStmtFetch()
  8419 ms  OCIStmtFetch return value: 0
  8419 ms  Buffer 0 DataType: 3
  8419 ms  Actual length: 4
  8419 ms  Integer value: 1
  8419 ms  Buffer 1 DataType: 1
  8419 ms  Actual length: 15
  8419 ms  Value: SPD_SCRATCH_TAB
ID: 1, Name: SDO_TTS_METADATA_TABLE, Description: MDSYS
  8419 ms  Buffer 2 DataType: 1
  8419 ms  Actual length: 3
  8419 ms  Value: SYS
  8419 ms  OCIStmtFetch()
  8419 ms  OCIStmtFetch return value: 0
  8419 ms  Buffer 0 DataType: 3
  8419 ms  Actual length: 4
  8419 ms  Integer value: 1
  8419 ms  Buffer 1 DataType: 1
  8419 ms  Actual length: 19
ID: 1, Name: SDO_TXN_JOURNAL_GTT, Description: MDSYS
ID: 1, Name: SDO_TXN_JOURNAL_REG, Description: MDSYS
  8419 ms  Value: SAM_SPARSITY_ADVICE
  8419 ms  Buffer 2 DataType: 1
  8419 ms  Actual length: 3
  8419 ms  Value: SYS
  8419 ms  OCIStmtFetch()
  8421 ms  OCIStmtFetch return value: 0
  8421 ms  Buffer 0 DataType: 3
  8421 ms  Actual length: 4
  8421 ms  Integer value: 1
  8421 ms  Buffer 1 DataType: 1
  8421 ms  Actual length: 4
ID: 1, Name: SDO_TXN_IDX_EXP_UPD_RGN, Description: MDSYS
ID: 1, Name: SDO_TOPO_TRANSACT_DATA, Description: MDSYS
  8421 ms  Value: HELP
  8421 ms  Buffer 2 DataType: 1
  8421 ms  Actual length: 6
  8421 ms  Value: SYSTEM
  8421 ms  OCIStmtFetch()
  8421 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_TOPO_RELATION_DATA, Description: MDSYS
  8421 ms  Buffer 0 DataType: 3
  8421 ms  Actual length: 4
  8421 ms  Integer value: 1
  8421 ms  Buffer 1 DataType: 1
ID: 1, Name: SDO_WFS_LOCAL_TXNS, Description: MDSYS
  8421 ms  Actual length: 3
  8421 ms  Value: OL$
  8421 ms  Buffer 2 DataType: 1
  8421 ms  Actual length: 6
  8421 ms  Value: SYSTEM
  8421 ms  OCIStmtFetch()
  8421 ms  OCIStmtFetch return value: 0
  8421 ms  Buffer 0 DataType: 3
  8421 ms  Actual length: 4
  8421 ms  Integer value: 1
  8421 ms  Buffer 1 DataType: 1
  8421 ms  Actual length: 8
ID: 1, Name: SDO_GEOR_DDL__TABLE$$, Description: MDSYS
  8421 ms  Value: OL$HINTS
  8421 ms  Buffer 2 DataType: 1
  8421 ms  Actual length: 6
  8421 ms  Value: SYSTEM
  8422 ms  OCIStmtFetch()
ID: 1, Name: SDO_GR_MOSAIC_0, Description: MDSYS
  8422 ms  OCIStmtFetch return value: 0
  8422 ms  Buffer 0 DataType: 3
  8422 ms  Actual length: 4
  8422 ms  Integer value: 1
  8422 ms  Buffer 1 DataType: 1
  8422 ms  Actual length: 8
  8422 ms  Value: OL$NODES
ID: 1, Name: SDO_GR_MOSAIC_1, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_2, Description: MDSYS
  8422 ms  Buffer 2 DataType: 1
  8422 ms  Actual length: 6
  8422 ms  Value: SYSTEM
  8422 ms  OCIStmtFetch()
  8426 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_GR_MOSAIC_3, Description: MDSYS
  8426 ms  Buffer 0 DataType: 3
  8426 ms  Actual length: 4
  8426 ms  Integer value: 1
  8426 ms  Buffer 1 DataType: 1
  8426 ms  Actual length: 19
  8426 ms  Value: XDB_INDEX_DDL_CACHE
  8426 ms  Buffer 2 DataType: 1
  8426 ms  Actual length: 3
  8426 ms  Value: XDB
  8426 ms  OCIStmtFetch()
  8426 ms  OCIStmtFetch return value: 0
  8426 ms  Buffer 0 DataType: 3
  8426 ms  Actual length: 4
  8426 ms  Integer value: 1
  8426 ms  Buffer 1 DataType: 1
  8426 ms  Actual length: 18
  8426 ms  Value: XDB$IMPORT_TT_INFO
  8426 ms  Buffer 2 DataType: 1
  8426 ms  Actual length: 3
  8426 ms  Value: XDB
  8426 ms  OCIStmtFetch()
  8427 ms  OCIStmtFetch return value: 0
  8427 ms  Buffer 0 DataType: 3
  8427 ms  Actual length: 4
  8427 ms  Integer value: 1
  8427 ms  Buffer 1 DataType: 1
  8427 ms  Actual length: 18
  8427 ms  Value: XDB$IMPORT_QN_INFO
  8427 ms  Buffer 2 DataType: 1
  8427 ms  Actual length: 3
  8427 ms  Value: XDB
  8427 ms  OCIStmtFetch()
  8427 ms  OCIStmtFetch return value: 0
  8427 ms  Buffer 0 DataType: 3
  8427 ms  Actual length: 4
  8427 ms  Integer value: 1
  8427 ms  Buffer 1 DataType: 1
  8427 ms  Actual length: 18
  8427 ms  Value: XDB$IMPORT_NM_INFO
  8427 ms  Buffer 2 DataType: 1
  8427 ms  Actual length: 3
  8427 ms  Value: XDB
  8427 ms  OCIStmtFetch()
  8428 ms  OCIStmtFetch return value: 0
  8428 ms  Buffer 0 DataType: 3
  8428 ms  Actual length: 4
  8428 ms  Integer value: 1
  8428 ms  Buffer 1 DataType: 1
  8428 ms  Actual length: 18
  8428 ms  Value: XDB$IMPORT_PT_INFO
  8428 ms  Buffer 2 DataType: 1
  8428 ms  Actual length: 3
  8428 ms  Value: XDB
  8428 ms  OCIStmtFetch()
  8428 ms  OCIStmtFetch return value: 0
  8428 ms  Buffer 0 DataType: 3
  8428 ms  Actual length: 4
  8428 ms  Integer value: 1
  8428 ms  Buffer 1 DataType: 1
  8428 ms  Actual length: 14
  8428 ms  Value: XDB$XIDX_IMP_T
  8428 ms  Buffer 2 DataType: 1
  8428 ms  Actual length: 3
  8428 ms  Value: XDB
  8428 ms  OCIStmtFetch()
  8430 ms  OCIStmtFetch return value: 0
  8430 ms  Buffer 0 DataType: 3
  8430 ms  Actual length: 4
  8430 ms  Integer value: 1
  8430 ms  Buffer 1 DataType: 1
  8430 ms  Actual length: 18
  8430 ms  Value: DR$NUMBER_SEQUENCE
  8430 ms  Buffer 2 DataType: 1
  8430 ms  Actual length: 6
  8430 ms  Value: CTXSYS
  8430 ms  OCIStmtFetch()
  8430 ms  OCIStmtFetch return value: 0
  8430 ms  Buffer 0 DataType: 3
  8430 ms  Actual length: 4
  8430 ms  Integer value: 1
  8430 ms  Buffer 1 DataType: 1
  8430 ms  Actual length: 19
  8430 ms  Value: DR$OBJECT_ATTRIBUTE
  8430 ms  Buffer 2 DataType: 1
  8430 ms  Actual length: 6
  8430 ms  Value: CTXSYS
  8431 ms  OCIStmtFetch()
  8431 ms  OCIStmtFetch return value: 0
  8431 ms  Buffer 0 DataType: 3
  8431 ms  Actual length: 4
  8431 ms  Integer value: 1
  8431 ms  Buffer 1 DataType: 1
  8431 ms  Actual length: 13
  8431 ms  Value: DR$POLICY_TAB
  8431 ms  Buffer 2 DataType: 1
  8431 ms  Actual length: 6
  8431 ms  Value: CTXSYS
  8432 ms  OCIStmtFetch()
  8432 ms  OCIStmtFetch return value: 0
  8432 ms  Buffer 0 DataType: 3
  8432 ms  Actual length: 4
  8432 ms  Integer value: 1
  8432 ms  Buffer 1 DataType: 1
  8432 ms  Actual length: 6
  8432 ms  Value: DR$THS
  8432 ms  Buffer 2 DataType: 1
  8432 ms  Actual length: 6
  8432 ms  Value: CTXSYS
  8432 ms  OCIStmtFetch()
  8433 ms  OCIStmtFetch return value: 0
  8433 ms  Buffer 0 DataType: 3
  8433 ms  Actual length: 4
  8433 ms  Integer value: 1
  8433 ms  Buffer 1 DataType: 1
  8433 ms  Actual length: 13
  8433 ms  Value: DR$THS_PHRASE
  8433 ms  Buffer 2 DataType: 1
  8433 ms  Actual length: 6
  8433 ms  Value: CTXSYS
  8434 ms  OCIStmtFetch()
  8434 ms  OCIStmtFetch return value: 0
  8434 ms  Buffer 0 DataType: 3
  8434 ms  Actual length: 4
ID: 1, Name: SDO_GR_MOSAIC_CB, Description: MDSYS
ID: 1, Name: SDO_GR_PARALLEL, Description: MDSYS
ID: 1, Name: SDO_GR_RDT_1, Description: MDSYS
  8434 ms  Integer value: 1
  8434 ms  Buffer 1 DataType: 1
  8434 ms  Actual length: 14
  8434 ms  Value: SDO_ELLIPSOIDS
  8434 ms  Buffer 2 DataType: 1
  8434 ms  Actual length: 5
  8434 ms  Value: MDSYS
  8434 ms  OCIStmtFetch()
  8434 ms  OCIStmtFetch return value: 0
  8434 ms  Buffer 0 DataType: 3
  8434 ms  Actual length: 4
  8434 ms  Integer value: 1
  8434 ms  Buffer 1 DataType: 1
  8434 ms  Actual length: 10
  8434 ms  Value: SDO_DATUMS
  8434 ms  Buffer 2 DataType: 1
  8434 ms  Actual length: 5
  8434 ms  Value: MDSYS
  8434 ms  OCIStmtFetch()
  8434 ms  OCIStmtFetch return value: 0
  8434 ms  Buffer 0 DataType: 3
  8434 ms  Actual length: 4
  8434 ms  Integer value: 1
  8434 ms  Buffer 1 DataType: 1
  8434 ms  Actual length: 20
  8434 ms  Value: SDO_UNITS_OF_MEASURE
  8434 ms  Buffer 2 DataType: 1
  8434 ms  Actual length: 5
  8434 ms  Value: MDSYS
  8434 ms  OCIStmtFetch()
  8435 ms  OCIStmtFetch return value: 0
  8435 ms  Buffer 0 DataType: 3
  8435 ms  Actual length: 4
  8435 ms  Integer value: 1
  8435 ms  Buffer 1 DataType: 1
  8435 ms  Actual length: 17
  8435 ms  Value: SDO_COORD_REF_SYS
  8435 ms  Buffer 2 DataType: 1
  8435 ms  Actual length: 5
  8435 ms  Value: MDSYS
  8435 ms  OCIStmtFetch()
  8435 ms  OCIStmtFetch return value: 0
  8435 ms  Buffer 0 DataType: 3
  8435 ms  Actual length: 4
  8435 ms  Integer value: 1
  8435 ms  Buffer 1 DataType: 1
  8435 ms  Actual length: 13
  8435 ms  Value: SDO_COORD_SYS
  8435 ms  Buffer 2 DataType: 1
  8435 ms  Actual length: 5
  8435 ms  Value: MDSYS
  8435 ms  OCIStmtFetch()
  8435 ms  OCIStmtFetch return value: 0
  8435 ms  Buffer 0 DataType: 3
  8435 ms  Actual length: 4
  8435 ms  Integer value: 1
  8435 ms  Buffer 1 DataType: 1
  8435 ms  Actual length: 14
  8435 ms  Value: SDO_COORD_AXES
  8435 ms  Buffer 2 DataType: 1
  8435 ms  Actual length: 5
  8435 ms  Value: MDSYS
  8436 ms  OCIStmtFetch()
  8436 ms  OCIStmtFetch return value: 0
  8436 ms  Buffer 0 DataType: 3
  8436 ms  Actual length: 4
  8436 ms  Integer value: 1
  8436 ms  Buffer 1 DataType: 1
  8436 ms  Actual length: 20
  8436 ms  Value: SDO_COORD_AXIS_NAMES
  8436 ms  Buffer 2 DataType: 1
  8436 ms  Actual length: 5
  8436 ms  Value: MDSYS
  8436 ms  OCIStmtFetch()
  8436 ms  OCIStmtFetch return value: 0
  8436 ms  Buffer 0 DataType: 3
  8436 ms  Actual length: 4
  8436 ms  Integer value: 1
  8436 ms  Buffer 1 DataType: 1
  8436 ms  Actual length: 13
  8436 ms  Value: SDO_COORD_OPS
  8436 ms  Buffer 2 DataType: 1
  8436 ms  Actual length: 5
  8436 ms  Value: MDSYS
  8436 ms  OCIStmtFetch()
  8436 ms  OCIStmtFetch return value: 0
  8436 ms  Buffer 0 DataType: 3
  8436 ms  Actual length: 4
  8436 ms  Integer value: 1
  8436 ms  Buffer 1 DataType: 1
  8436 ms  Actual length: 18
  8436 ms  Value: SDO_COORD_OP_PATHS
  8436 ms  Buffer 2 DataType: 1
  8436 ms  Actual length: 5
  8436 ms  Value: MDSYS
  8437 ms  OCIStmtFetch()
  8437 ms  OCIStmtFetch return value: 0
  8437 ms  Buffer 0 DataType: 3
  8437 ms  Actual length: 4
  8437 ms  Integer value: 1
  8437 ms  Buffer 1 DataType: 1
  8437 ms  Actual length: 24
  8437 ms  Value: SDO_PREFERRED_OPS_SYSTEM
  8437 ms  Buffer 2 DataType: 1
  8437 ms  Actual length: 5
  8437 ms  Value: MDSYS
  8437 ms  OCIStmtFetch()
  8437 ms  OCIStmtFetch return value: 0
  8437 ms  Buffer 0 DataType: 3
  8437 ms  Actual length: 4
  8437 ms  Integer value: 1
  8437 ms  Buffer 1 DataType: 1
  8437 ms  Actual length: 20
  8437 ms  Value: SDO_COORD_OP_METHODS
  8437 ms  Buffer 2 DataType: 1
  8437 ms  Actual length: 5
  8437 ms  Value: MDSYS
  8437 ms  OCIStmtFetch()
ID: 1, Name: RDF_PARAMETER, Description: MDSYS
  8441 ms  OCIStmtFetch return value: 0
  8441 ms  Buffer 0 DataType: 3
  8441 ms  Actual length: 4
  8441 ms  Integer value: 1
  8441 ms  Buffer 1 DataType: 1
  8441 ms  Actual length: 19
  8441 ms  Value: SDO_COORD_OP_PARAMS
  8441 ms  Buffer 2 DataType: 1
  8441 ms  Actual length: 5
  8441 ms  Value: MDSYS
  8441 ms  OCIStmtFetch()
  8442 ms  OCIStmtFetch return value: 0
  8442 ms  Buffer 0 DataType: 3
  8442 ms  Actual length: 4
  8442 ms  Integer value: 1
  8442 ms  Buffer 1 DataType: 1
  8442 ms  Actual length: 23
  8442 ms  Value: SDO_COORD_OP_PARAM_VALS
  8442 ms  Buffer 2 DataType: 1
  8442 ms  Actual length: 5
  8442 ms  Value: MDSYS
  8442 ms  OCIStmtFetch()
  8442 ms  OCIStmtFetch return value: 0
  8442 ms  Buffer 0 DataType: 3
  8442 ms  Actual length: 4
  8442 ms  Integer value: 1
  8442 ms  Buffer 1 DataType: 1
  8442 ms  Actual length: 22
  8442 ms  Value: SDO_COORD_OP_PARAM_USE
  8442 ms  Buffer 2 DataType: 1
  8442 ms  Actual length: 5
  8442 ms  Value: MDSYS
  8442 ms  OCIStmtFetch()
  8442 ms  OCIStmtFetch return value: 0
  8442 ms  Buffer 0 DataType: 3
  8442 ms  Actual length: 4
  8442 ms  Integer value: 1
  8442 ms  Buffer 1 DataType: 1
  8442 ms  Actual length: 10
  8442 ms  Value: SDO_CS_SRS
  8442 ms  Buffer 2 DataType: 1
  8442 ms  Actual length: 5
  8442 ms  Value: MDSYS
  8442 ms  OCIStmtFetch()
  8443 ms  OCIStmtFetch return value: 0
  8443 ms  Buffer 0 DataType: 3
  8443 ms  Actual length: 4
  8443 ms  Integer value: 1
  8443 ms  Buffer 1 DataType: 1
  8443 ms  Actual length: 19
  8443 ms  Value: SDO_PRIME_MERIDIANS
  8443 ms  Buffer 2 DataType: 1
  8443 ms  Actual length: 5
  8443 ms  Value: MDSYS
  8443 ms  OCIStmtFetch()
  8443 ms  OCIStmtFetch return value: 0
  8443 ms  Buffer 0 DataType: 3
  8443 ms  Actual length: 4
  8443 ms  Integer value: 1
  8443 ms  Buffer 1 DataType: 1
  8443 ms  Actual length: 30
  8443 ms  Value: SDO_CRS_GEOGRAPHIC_PLUS_HEIGHT
  8443 ms  Buffer 2 DataType: 1
  8443 ms  Actual length: 5
  8443 ms  Value: MDSYS
  8443 ms  OCIStmtFetch()
  8443 ms  OCIStmtFetch return value: 0
  8443 ms  Buffer 0 DataType: 3
  8443 ms  Actual length: 4
  8443 ms  Integer value: 1
  8443 ms  Buffer 1 DataType: 1
  8443 ms  Actual length: 27
  8443 ms  Value: SDO_ELLIPSOIDS_OLD_SNAPSHOT
  8443 ms  Buffer 2 DataType: 1
  8443 ms  Actual length: 5
  8443 ms  Value: MDSYS
  8443 ms  OCIStmtFetch()
  8443 ms  OCIStmtFetch return value: 0
  8443 ms  Buffer 0 DataType: 3
  8443 ms  Actual length: 4
  8443 ms  Integer value: 1
  8443 ms  Buffer 1 DataType: 1
  8443 ms  Actual length: 28
  8443 ms  Value: SDO_PROJECTIONS_OLD_SNAPSHOT
  8443 ms  Buffer 2 DataType: 1
  8443 ms  Actual length: 5
  8443 ms  Value: MDSYS
  8444 ms  OCIStmtFetch()
  8444 ms  OCIStmtFetch return value: 0
  8444 ms  Buffer 0 DataType: 3
  8444 ms  Actual length: 4
  8444 ms  Integer value: 1
  8444 ms  Buffer 1 DataType: 1
  8444 ms  Actual length: 23
  8444 ms  Value: SDO_DATUMS_OLD_SNAPSHOT
  8444 ms  Buffer 2 DataType: 1
  8444 ms  Actual length: 5
  8444 ms  Value: MDSYS
  8444 ms  OCIStmtFetch()
  8444 ms  OCIStmtFetch return value: 0
  8444 ms  Buffer 0 DataType: 3
  8444 ms  Actual length: 4
  8444 ms  Integer value: 1
  8444 ms  Buffer 1 DataType: 1
  8444 ms  Actual length: 15
  8444 ms  Value: SDO_XML_SCHEMAS
  8444 ms  Buffer 2 DataType: 1
  8444 ms  Actual length: 5
  8444 ms  Value: MDSYS
  8445 ms  OCIStmtFetch()
  8445 ms  OCIStmtFetch return value: 0
  8445 ms  Buffer 0 DataType: 3
  8445 ms  Actual length: 4
  8445 ms  Integer value: 1
  8445 ms  Buffer 1 DataType: 1
  8445 ms  Actual length: 17
  8445 ms  Value: SDO_FEATURE_USAGE
  8445 ms  Buffer 2 DataType: 1
  8445 ms  Actual length: 5
  8445 ms  Value: MDSYS
  8445 ms  OCIStmtFetch()
  8445 ms  OCIStmtFetch return value: 0
  8445 ms  Buffer 0 DataType: 3
  8445 ms  Actual length: 4
  8445 ms  Integer value: 1
  8445 ms  Buffer 1 DataType: 1
  8445 ms  Actual length: 13
  8445 ms  Value: SDO_XSD_TABLE
  8445 ms  Buffer 2 DataType: 1
  8445 ms  Actual length: 5
  8445 ms  Value: MDSYS
  8445 ms  OCIStmtFetch()
  8446 ms  OCIStmtFetch return value: 0
  8446 ms  Buffer 0 DataType: 3
  8446 ms  Actual length: 4
  8446 ms  Integer value: 1
  8446 ms  Buffer 1 DataType: 1
  8446 ms  Actual length: 24
  8446 ms  Value: SDO_GEOR_XMLSCHEMA_TABLE
  8446 ms  Buffer 2 DataType: 1
  8446 ms  Actual length: 5
  8446 ms  Value: MDSYS
  8446 ms  OCIStmtFetch()
  8446 ms  OCIStmtFetch return value: 0
  8446 ms  Buffer 0 DataType: 3
  8446 ms  Actual length: 4
  8446 ms  Integer value: 1
  8446 ms  Buffer 1 DataType: 1
  8446 ms  Actual length: 14
  8446 ms  Value: SDO_TIN_PC_SEQ
  8446 ms  Buffer 2 DataType: 1
  8446 ms  Actual length: 5
  8446 ms  Value: MDSYS
  8446 ms  OCIStmtFetch()
  8446 ms  OCIStmtFetch return value: 0
  8446 ms  Buffer 0 DataType: 3
  8446 ms  Actual length: 4
  8446 ms  Integer value: 1
  8446 ms  Buffer 1 DataType: 1
  8446 ms  Actual length: 24
  8446 ms  Value: SDO_TIN_PC_SYSDATA_TABLE
  8446 ms  Buffer 2 DataType: 1
  8446 ms  Actual length: 5
  8446 ms  Value: MDSYS
  8447 ms  OCIStmtFetch()
  8447 ms  OCIStmtFetch return value: 0
  8447 ms  Buffer 0 DataType: 3
  8447 ms  Actual length: 4
  8447 ms  Integer value: 1
  8447 ms  Buffer 1 DataType: 1
  8447 ms  Actual length: 18
  8447 ms  Value: SRSNAMESPACE_TABLE
  8447 ms  Buffer 2 DataType: 1
  8447 ms  Actual length: 5
  8447 ms  Value: MDSYS
  8447 ms  OCIStmtFetch()
  8448 ms  OCIStmtFetch return value: 0
  8448 ms  Buffer 0 DataType: 3
  8448 ms  Actual length: 4
  8448 ms  Integer value: 1
  8448 ms  Buffer 1 DataType: 1
  8448 ms  Actual length: 22
  8448 ms  Value: SDO_PREFERRED_OPS_USER
  8448 ms  Buffer 2 DataType: 1
  8448 ms  Actual length: 5
  8448 ms  Value: MDSYS
  8449 ms  OCIStmtFetch()
  8449 ms  OCIStmtFetch return value: 0
  8449 ms  Buffer 0 DataType: 3
  8449 ms  Actual length: 4
  8449 ms  Integer value: 1
  8449 ms  Buffer 1 DataType: 1
  8449 ms  Actual length: 13
  8449 ms  Value: NTV2_XML_DATA
  8449 ms  Buffer 2 DataType: 1
  8449 ms  Actual length: 5
  8449 ms  Value: MDSYS
  8449 ms  OCIStmtFetch()
  8450 ms  OCIStmtFetch return value: 0
  8450 ms  Buffer 0 DataType: 3
  8450 ms  Actual length: 4
  8450 ms  Integer value: 1
  8450 ms  Buffer 1 DataType: 1
  8450 ms  Actual length: 16
  8450 ms  Value: SDO_SRIDS_BY_URN
  8450 ms  Buffer 2 DataType: 1
  8450 ms  Actual length: 5
  8450 ms  Value: MDSYS
  8450 ms  OCIStmtFetch()
  8450 ms  OCIStmtFetch return value: 0
  8450 ms  Buffer 0 DataType: 3
  8450 ms  Actual length: 4
  8450 ms  Integer value: 1
  8450 ms  Buffer 1 DataType: 1
  8450 ms  Actual length: 24
  8450 ms  Value: SDO_SRIDS_BY_URN_PATTERN
  8450 ms  Buffer 2 DataType: 1
  8450 ms  Actual length: 5
  8450 ms  Value: MDSYS
  8451 ms  OCIStmtFetch()
  8452 ms  OCIStmtFetch return value: 0
  8452 ms  Buffer 0 DataType: 3
  8452 ms  Actual length: 4
  8452 ms  Integer value: 1
  8452 ms  Buffer 1 DataType: 1
  8452 ms  Actual length: 25
  8452 ms  Value: SDO_INDEX_HISTOGRAM_TABLE
  8452 ms  Buffer 2 DataType: 1
  8452 ms  Actual length: 5
  8452 ms  Value: MDSYS
  8453 ms  OCIStmtFetch()
  8453 ms  OCIStmtFetch return value: 0
  8453 ms  Buffer 0 DataType: 3
  8453 ms  Actual length: 4
  8453 ms  Integer value: 1
  8453 ms  Buffer 1 DataType: 1
  8453 ms  Actual length: 23
  8453 ms  Value: SDO_DIST_METADATA_TABLE
  8453 ms  Buffer 2 DataType: 1
  8453 ms  Actual length: 5
  8453 ms  Value: MDSYS
  8453 ms  OCIStmtFetch()
  8456 ms  OCIStmtFetch return value: 0
  8456 ms  Buffer 0 DataType: 3
  8456 ms  Actual length: 4
  8456 ms  Integer value: 1
  8456 ms  Buffer 1 DataType: 1
  8456 ms  Actual length: 30
  8456 ms  Value: OGIS_SPATIAL_REFERENCE_SYSTEMS
  8456 ms  Buffer 2 DataType: 1
  8456 ms  Actual length: 5
  8456 ms  Value: MDSYS
  8456 ms  OCIStmtFetch()
  8456 ms  OCIStmtFetch return value: 0
  8456 ms  Buffer 0 DataType: 3
  8456 ms  Actual length: 4
  8456 ms  Integer value: 1
  8456 ms  Buffer 1 DataType: 1
  8456 ms  Actual length: 21
  8456 ms  Value: OGIS_GEOMETRY_COLUMNS
  8456 ms  Buffer 2 DataType: 1
  8456 ms  Actual length: 5
  8456 ms  Value: MDSYS
  8457 ms  OCIStmtFetch()
  8458 ms  OCIStmtFetch return value: 0
  8458 ms  Buffer 0 DataType: 3
  8458 ms  Actual length: 4
  8458 ms  Integer value: 1
  8458 ms  Buffer 1 DataType: 1
  8458 ms  Actual length: 17
  8458 ms  Value: SDO_WS_CONFERENCE
  8458 ms  Buffer 2 DataType: 1
  8458 ms  Actual length: 5
  8458 ms  Value: MDSYS
  8459 ms  OCIStmtFetch()
  8459 ms  OCIStmtFetch return value: 0
  8459 ms  Buffer 0 DataType: 3
  8459 ms  Actual length: 4
  8459 ms  Integer value: 1
  8459 ms  Buffer 1 DataType: 1
  8459 ms  Actual length: 25
  8459 ms  Value: SDO_WS_CONFERENCE_RESULTS
  8459 ms  Buffer 2 DataType: 1
  8459 ms  Actual length: 5
  8459 ms  Value: MDSYS
  8459 ms  OCIStmtFetch()
  8460 ms  OCIStmtFetch return value: 0
  8460 ms  Buffer 0 DataType: 3
  8460 ms  Actual length: 4
  8460 ms  Integer value: 1
  8460 ms  Buffer 1 DataType: 1
  8460 ms  Actual length: 30
  8460 ms  Value: SDO_WS_CONFERENCE_PARTICIPANTS
  8460 ms  Buffer 2 DataType: 1
  8460 ms  Actual length: 5
  8460 ms  Value: MDSYS
  8460 ms  OCIStmtFetch()
  8460 ms  OCIStmtFetch return value: 0
  8460 ms  Buffer 0 DataType: 3
  8460 ms  Actual length: 4
  8460 ms  Integer value: 1
  8460 ms  Buffer 1 DataType: 1
  8460 ms  Actual length: 24
  8460 ms  Value: SDO_GEOR_PLUGIN_REGISTRY
  8460 ms  Buffer 2 DataType: 1
  8460 ms  Actual length: 5
  8460 ms  Value: MDSYS
  8461 ms  OCIStmtFetch()
  8462 ms  OCIStmtFetch return value: 0
  8462 ms  Buffer 0 DataType: 3
  8462 ms  Actual length: 4
  8462 ms  Integer value: 1
  8462 ms  Buffer 1 DataType: 1
  8462 ms  Actual length: 14
  8462 ms  Value: RDF_PARAM$_TBL
  8462 ms  Buffer 2 DataType: 1
  8462 ms  Actual length: 5
  8462 ms  Value: MDSYS
  8462 ms  OCIStmtFetch()
  8462 ms  OCIStmtFetch return value: 0
  8462 ms  Buffer 0 DataType: 3
  8462 ms  Actual length: 4
  8462 ms  Integer value: 1
  8462 ms  Buffer 1 DataType: 1
  8462 ms  Actual length: 26
  8462 ms  Value: SDO_CS_CONTEXT_INFORMATION
  8462 ms  Buffer 2 DataType: 1
  8462 ms  Actual length: 5
  8462 ms  Value: MDSYS
  8463 ms  OCIStmtFetch()
  8464 ms  OCIStmtFetch return value: 0
  8464 ms  Buffer 0 DataType: 3
  8464 ms  Actual length: 4
  8464 ms  Integer value: 1
  8464 ms  Buffer 1 DataType: 1
  8464 ms  Actual length: 16
  8464 ms  Value: SDO_ST_TOLERANCE
  8464 ms  Buffer 2 DataType: 1
  8464 ms  Actual length: 5
  8464 ms  Value: MDSYS
  8464 ms  OCIStmtFetch()
  8464 ms  OCIStmtFetch return value: 0
  8464 ms  Buffer 0 DataType: 3
  8464 ms  Actual length: 4
  8464 ms  Integer value: 1
  8464 ms  Buffer 1 DataType: 1
  8464 ms  Actual length: 22
  8464 ms  Value: SDO_TTS_METADATA_TABLE
  8464 ms  Buffer 2 DataType: 1
  8464 ms  Actual length: 5
  8464 ms  Value: MDSYS
  8464 ms  OCIStmtFetch()
  8465 ms  OCIStmtFetch return value: 0
  8465 ms  Buffer 0 DataType: 3
  8465 ms  Actual length: 4
  8465 ms  Integer value: 1
  8465 ms  Buffer 1 DataType: 1
  8465 ms  Actual length: 19
  8465 ms  Value: SDO_TXN_JOURNAL_GTT
  8465 ms  Buffer 2 DataType: 1
  8465 ms  Actual length: 5
  8465 ms  Value: MDSYS
  8465 ms  OCIStmtFetch()
  8465 ms  OCIStmtFetch return value: 0
  8465 ms  Buffer 0 DataType: 3
  8465 ms  Actual length: 4
  8465 ms  Integer value: 1
  8465 ms  Buffer 1 DataType: 1
  8465 ms  Actual length: 19
  8465 ms  Value: SDO_TXN_JOURNAL_REG
  8465 ms  Buffer 2 DataType: 1
  8465 ms  Actual length: 5
  8465 ms  Value: MDSYS
  8466 ms  OCIStmtFetch()
  8466 ms  OCIStmtFetch return value: 0
  8466 ms  Buffer 0 DataType: 3
  8466 ms  Actual length: 4
  8466 ms  Integer value: 1
  8466 ms  Buffer 1 DataType: 1
  8466 ms  Actual length: 23
  8466 ms  Value: SDO_TXN_IDX_EXP_UPD_RGN
  8466 ms  Buffer 2 DataType: 1
  8466 ms  Actual length: 5
  8466 ms  Value: MDSYS
  8467 ms  OCIStmtFetch()
  8467 ms  OCIStmtFetch return value: 0
  8467 ms  Buffer 0 DataType: 3
  8467 ms  Actual length: 4
  8467 ms  Integer value: 1
  8467 ms  Buffer 1 DataType: 1
  8467 ms  Actual length: 22
  8467 ms  Value: SDO_TOPO_TRANSACT_DATA
  8467 ms  Buffer 2 DataType: 1
  8467 ms  Actual length: 5
  8467 ms  Value: MDSYS
  8467 ms  OCIStmtFetch()
  8468 ms  OCIStmtFetch return value: 0
  8468 ms  Buffer 0 DataType: 3
  8468 ms  Actual length: 4
  8468 ms  Integer value: 1
  8468 ms  Buffer 1 DataType: 1
  8468 ms  Actual length: 22
  8468 ms  Value: SDO_TOPO_RELATION_DATA
  8468 ms  Buffer 2 DataType: 1
  8468 ms  Actual length: 5
  8468 ms  Value: MDSYS
  8468 ms  OCIStmtFetch()
  8468 ms  OCIStmtFetch return value: 0
  8468 ms  Buffer 0 DataType: 3
  8468 ms  Actual length: 4
  8468 ms  Integer value: 1
  8468 ms  Buffer 1 DataType: 1
  8468 ms  Actual length: 18
  8468 ms  Value: SDO_WFS_LOCAL_TXNS
  8468 ms  Buffer 2 DataType: 1
  8468 ms  Actual length: 5
  8468 ms  Value: MDSYS
  8468 ms  OCIStmtFetch()
  8469 ms  OCIStmtFetch return value: 0
  8469 ms  Buffer 0 DataType: 3
  8469 ms  Actual length: 4
  8469 ms  Integer value: 1
  8469 ms  Buffer 1 DataType: 1
  8469 ms  Actual length: 21
  8469 ms  Value: SDO_GEOR_DDL__TABLE$$
  8469 ms  Buffer 2 DataType: 1
  8469 ms  Actual length: 5
  8469 ms  Value: MDSYS
  8469 ms  OCIStmtFetch()
  8469 ms  OCIStmtFetch return value: 0
  8469 ms  Buffer 0 DataType: 3
  8469 ms  Actual length: 4
  8469 ms  Integer value: 1
  8469 ms  Buffer 1 DataType: 1
  8469 ms  Actual length: 15
  8469 ms  Value: SDO_GR_MOSAIC_0
  8469 ms  Buffer 2 DataType: 1
  8469 ms  Actual length: 5
  8469 ms  Value: MDSYS
  8470 ms  OCIStmtFetch()
  8470 ms  OCIStmtFetch return value: 0
  8470 ms  Buffer 0 DataType: 3
  8470 ms  Actual length: 4
  8470 ms  Integer value: 1
  8470 ms  Buffer 1 DataType: 1
  8470 ms  Actual length: 15
  8470 ms  Value: SDO_GR_MOSAIC_1
  8470 ms  Buffer 2 DataType: 1
  8470 ms  Actual length: 5
  8470 ms  Value: MDSYS
  8470 ms  OCIStmtFetch()
  8470 ms  OCIStmtFetch return value: 0
  8470 ms  Buffer 0 DataType: 3
  8470 ms  Actual length: 4
  8470 ms  Integer value: 1
  8470 ms  Buffer 1 DataType: 1
  8470 ms  Actual length: 15
  8470 ms  Value: SDO_GR_MOSAIC_2
  8470 ms  Buffer 2 DataType: 1
  8470 ms  Actual length: 5
  8470 ms  Value: MDSYS
  8471 ms  OCIStmtFetch()
  8471 ms  OCIStmtFetch return value: 0
  8471 ms  Buffer 0 DataType: 3
  8471 ms  Actual length: 4
  8471 ms  Integer value: 1
  8471 ms  Buffer 1 DataType: 1
  8471 ms  Actual length: 15
  8471 ms  Value: SDO_GR_MOSAIC_3
  8471 ms  Buffer 2 DataType: 1
  8471 ms  Actual length: 5
  8471 ms  Value: MDSYS
  8472 ms  OCIStmtFetch()
  8472 ms  OCIStmtFetch return value: 0
  8472 ms  Buffer 0 DataType: 3
  8472 ms  Actual length: 4
  8472 ms  Integer value: 1
  8472 ms  Buffer 1 DataType: 1
  8472 ms  Actual length: 16
  8472 ms  Value: SDO_GR_MOSAIC_CB
  8472 ms  Buffer 2 DataType: 1
  8472 ms  Actual length: 5
  8472 ms  Value: MDSYS
  8473 ms  OCIStmtFetch()
  8474 ms  OCIStmtFetch return value: 0
  8474 ms  Buffer 0 DataType: 3
  8474 ms  Actual length: 4
  8474 ms  Integer value: 1
  8474 ms  Buffer 1 DataType: 1
  8474 ms  Actual length: 15
  8474 ms  Value: SDO_GR_PARALLEL
  8474 ms  Buffer 2 DataType: 1
  8474 ms  Actual length: 5
  8474 ms  Value: MDSYS
  8474 ms  OCIStmtFetch()
  8474 ms  OCIStmtFetch return value: 0
  8474 ms  Buffer 0 DataType: 3
  8474 ms  Actual length: 4
  8474 ms  Integer value: 1
  8474 ms  Buffer 1 DataType: 1
  8474 ms  Actual length: 12
  8474 ms  Value: SDO_GR_RDT_1
  8474 ms  Buffer 2 DataType: 1
  8474 ms  Actual length: 5
  8474 ms  Value: MDSYS
  8474 ms  OCIStmtFetch()
  8479 ms  OCIStmtFetch return value: 0
  8479 ms  Buffer 0 DataType: 3
  8479 ms  Actual length: 4
  8479 ms  Integer value: 1
  8479 ms  Buffer 1 DataType: 1
  8479 ms  Actual length: 13
  8479 ms  Value: RDF_PARAMETER
  8479 ms  Buffer 2 DataType: 1
  8479 ms  Actual length: 5
  8479 ms  Value: MDSYS
  8479 ms  OCIStmtFetch()
  8479 ms  OCIStmtFetch return value: 100
  8479 ms  Fetch failed or no data (retval: 100)
Process terminated
```