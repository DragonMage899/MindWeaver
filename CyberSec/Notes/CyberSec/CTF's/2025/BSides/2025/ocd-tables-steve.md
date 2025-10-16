```c
           /* TID 0x5493 */
  6890 ms  OCIStmtPrepare()
  6890 ms  sql: SET ROLE waiter
  6890 ms  Changing role
  6890 ms  New sql: SET ROLE chef
  6890 ms  sql arg after injection: SET ROLE chef
  6891 ms  OCIStmtExecute()
  6891 ms  errhp: 0x62f43f88cda0
  6897 ms  OCIStmtPrepare()
  6897 ms  sql: SELECT * FROM SYS.MENU
  6897 ms  New sql: SELECT 1, TABLE_NAME, OWNER FROM all_tables
  6897 ms  sql arg after injection: SELECT 1, TABLE_NAME, OWNER FROM all_tables
  6897 ms  OCIStmtExecute()
  6897 ms  errhp: 0x62f43f88cda0
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
ID: 1, Name: RECIPE, Description: SYS
ID: 1, Name: WRR$_REPLAY_CALL_FILTER, Description: SYS
ID: 1, Name: FINALHIST$, Description: SYS
ID: 1, Name: MODELGTTRAW$, Description: SYS
ID: 1, Name: PMAPGTT$, Description: SYS
ID: 1, Name: MV_CAPABILITIES_TABLE$, Description: SYS
ID: 1, Name: REWRITE_TABLE$, Description: SYS
ID: 1, Name: WRI$_ADV_ASA_RECO_DATA, Description: SYS
ID: 1, Name: WRI$_HEATMAP_TOPN_DEP1, Description: SYS
  7997 ms  OCIDefineByPos()
ID: 1, Name: WRI$_HEATMAP_TOPN_DEP2, Description: SYS
ID: 1, Name: PLAN_TABLE$, Description: SYS
  7997 ms  Stored:
buf: 0x7ffe678b3164
size: 4
dt: 3
rlenp: 0x7ffe678b315e

  7998 ms  OCIDefineByPos()
  7998 ms  Stored:
buf: 0x7ffe678b3260
size: 50
dt: 1
rlenp: 0x7ffe678b3160

  7998 ms  OCIDefineByPos()
  7998 ms  Stored:
buf: 0x7ffe678b32a0
size: 4000
dt: 1
rlenp: 0x7ffe678b3162

  7998 ms  OCIStmtFetch()
  7998 ms  fetch_errhp: 0x62f43f88cda0
  7998 ms  OCIStmtFetch return value: 0
  7998 ms  
[Buffer: 0]  DataType: 3
  7998 ms  Value: 1
  7998 ms  
[Buffer: 1]  DataType: 1
  7998 ms  Value: DUAL
  7998 ms  
[Buffer: 2]  DataType: 1
  7998 ms  Value: SYS
  7998 ms  OCIStmtFetch()
  7998 ms  fetch_errhp: 0x62f43f88cda0
  7999 ms  OCIStmtFetch return value: 0
  7999 ms  
[Buffer: 0]  DataType: 3
  7999 ms  Value: 1
  7999 ms  
[Buffer: 1]  DataType: 1
  7999 ms  Value: SYSTEM_PRIVILEGE_MAP
  7999 ms  
[Buffer: 2]  DataType: 1
  7999 ms  Value: SYS
  7999 ms  OCIStmtFetch()
  7999 ms  fetch_errhp: 0x62f43f88cda0
  7999 ms  OCIStmtFetch return value: 0
  7999 ms  
[Buffer: 0]  DataType: 3
  7999 ms  Value: 1
  7999 ms  
[Buffer: 1]  DataType: 1
  7999 ms  Value: TABLE_PRIVILEGE_MAP
  7999 ms  
[Buffer: 2]  DataType: 1
  7999 ms  Value: SYS
  7999 ms  OCIStmtFetch()
  7999 ms  fetch_errhp: 0x62f43f88cda0
  8000 ms  OCIStmtFetch return value: 0
  8000 ms  
[Buffer: 0]  DataType: 3
  8000 ms  Value: 1
  8000 ms  
[Buffer: 1]  DataType: 1
  8000 ms  Value: USER_PRIVILEGE_MAP
  8000 ms  
[Buffer: 2]  DataType: 1
  8000 ms  Value: SYS
  8000 ms  OCIStmtFetch()
  8000 ms  fetch_errhp: 0x62f43f88cda0
  8000 ms  OCIStmtFetch return value: 0
  8000 ms  
[Buffer: 0]  DataType: 3
  8000 ms  Value: 1
  8000 ms  
[Buffer: 1]  DataType: 1
  8000 ms  Value: STMT_AUDIT_OPTION_MAP
  8000 ms  
[Buffer: 2]  DataType: 1
  8000 ms  Value: SYS
  8000 ms  OCIStmtFetch()
  8000 ms  fetch_errhp: 0x62f43f88cda0
  8003 ms  OCIStmtFetch return value: 0
  8003 ms  
[Buffer: 0]  DataType: 3
  8003 ms  Value: 1
  8003 ms  
[Buffer: 1]  DataType: 1
  8003 ms  Value: AV_DUAL
  8003 ms  
[Buffer: 2]  DataType: 1
  8003 ms  Value: SYS
  8003 ms  OCIStmtFetch()
  8003 ms  fetch_errhp: 0x62f43f88cda0
  8003 ms  OCIStmtFetch return value: 0
  8003 ms  
[Buffer: 0]  DataType: 3
  8003 ms  Value: 1
  8003 ms  
[Buffer: 1]  DataType: 1
  8003 ms  Value: AUDIT_ACTIONS
  8003 ms  
[Buffer: 2]  DataType: 1
  8003 ms  Value: SYS
  8003 ms  OCIStmtFetch()
  8003 ms  fetch_errhp: 0x62f43f88cda0
  8007 ms  OCIStmtFetch return value: 0
  8007 ms  
[Buffer: 0]  DataType: 3
  8007 ms  Value: 1
  8007 ms  
[Buffer: 1]  DataType: 1
  8007 ms  Value: ALL_UNIFIED_AUDIT_ACTIONS
  8007 ms  
[Buffer: 2]  DataType: 1
  8007 ms  Value: SYS
  8007 ms  OCIStmtFetch()
  8007 ms  fetch_errhp: 0x62f43f88cda0
  8007 ms  OCIStmtFetch return value: 0
  8007 ms  
[Buffer: 0]  DataType: 3
  8007 ms  Value: 1
  8007 ms  
[Buffer: 1]  DataType: 1
  8007 ms  Value: SCHEDULER_FILEWATCHER_QT
  8007 ms  
[Buffer: 2]  DataType: 1
  8007 ms  Value: SYS
  8007 ms  OCIStmtFetch()
  8007 ms  fetch_errhp: 0x62f43f88cda0
  8012 ms  OCIStmtFetch return value: 0
  8012 ms  
[Buffer: 0]  DataType: 3
  8012 ms  Value: 1
  8012 ms  
[Buffer: 1]  DataType: 1
  8012 ms  Value: AW$EXPRESS
  8012 ms  
[Buffer: 2]  DataType: 1
  8012 ms  Value: SYS
  8012 ms  OCIStmtFetch()
  8012 ms  fetch_errhp: 0x62f43f88cda0
  8012 ms  OCIStmtFetch return value: 0
  8012 ms  
[Buffer: 0]  DataType: 3
  8012 ms  Value: 1
  8012 ms  
[Buffer: 1]  DataType: 1
  8012 ms  Value: AW$AWMD
  8012 ms  
[Buffer: 2]  DataType: 1
  8012 ms  Value: SYS
  8012 ms  OCIStmtFetch()
  8012 ms  fetch_errhp: 0x62f43f88cda0
  8013 ms  OCIStmtFetch return value: 0
  8013 ms  
[Buffer: 0]  DataType: 3
  8013 ms  Value: 1
ID: 1, Name: KU$_LIST_FILTER_TEMP, Description: SYS
ID: 1, Name: KU$_LIST_FILTER_TEMP_2, Description: SYS
ID: 1, Name: DATA_PUMP_XPL_TABLE$, Description: SYS
ID: 1, Name: KU$NOEXP_TAB, Description: SYS
ID: 1, Name: KU$_SHARD_DOMIDX_NAMEMAP, Description: SYS
ID: 1, Name: KU$XKTFBUE, Description: SYS
  8013 ms  
[Buffer: 1]  DataType: 1
  8013 ms  Value: AW$AWCREATE
  8013 ms  
[Buffer: 2]  DataType: 1
  8013 ms  Value: SYS
  8013 ms  OCIStmtFetch()
  8013 ms  fetch_errhp: 0x62f43f88cda0
  8013 ms  OCIStmtFetch return value: 0
  8013 ms  
[Buffer: 0]  DataType: 3
  8013 ms  Value: 1
  8013 ms  
[Buffer: 1]  DataType: 1
  8013 ms  Value: AW$AWCREATE10G
  8013 ms  
[Buffer: 2]  DataType: 1
  8013 ms  Value: SYS
  8013 ms  OCIStmtFetch()
  8013 ms  fetch_errhp: 0x62f43f88cda0
  8013 ms  OCIStmtFetch return value: 0
  8013 ms  
[Buffer: 0]  DataType: 3
  8013 ms  Value: 1
  8013 ms  
[Buffer: 1]  DataType: 1
  8013 ms  Value: AW$AWXML
  8013 ms  
[Buffer: 2]  DataType: 1
  8013 ms  Value: SYS
  8014 ms  OCIStmtFetch()
  8014 ms  fetch_errhp: 0x62f43f88cda0
  8014 ms  OCIStmtFetch return value: 0
  8014 ms  
[Buffer: 0]  DataType: 3
  8014 ms  Value: 1
  8014 ms  
[Buffer: 1]  DataType: 1
  8014 ms  Value: AW$AWREPORT
  8014 ms  
[Buffer: 2]  DataType: 1
  8014 ms  Value: SYS
  8014 ms  OCIStmtFetch()
  8014 ms  fetch_errhp: 0x62f43f88cda0
  8015 ms  OCIStmtFetch return value: 0
  8015 ms  
[Buffer: 0]  DataType: 3
  8015 ms  Value: 1
  8015 ms  
[Buffer: 1]  DataType: 1
  8015 ms  Value: MENU
  8015 ms  
[Buffer: 2]  DataType: 1
  8015 ms  Value: SYS
  8015 ms  OCIStmtFetch()
  8015 ms  fetch_errhp: 0x62f43f88cda0
  8015 ms  OCIStmtFetch return value: 0
  8015 ms  
[Buffer: 0]  DataType: 3
  8015 ms  Value: 1
  8015 ms  
[Buffer: 1]  DataType: 1
  8015 ms  Value: RECIPE
  8015 ms  
[Buffer: 2]  DataType: 1
  8015 ms  Value: SYS
  8015 ms  OCIStmtFetch()
  8015 ms  fetch_errhp: 0x62f43f88cda0
  8038 ms  OCIStmtFetch return value: 0
  8038 ms  
[Buffer: 0]  DataType: 3
  8038 ms  Value: 1
  8038 ms  
[Buffer: 1]  DataType: 1
  8038 ms  Value: WRR$_REPLAY_CALL_FILTER
  8038 ms  
[Buffer: 2]  DataType: 1
  8038 ms  Value: SYS
  8039 ms  OCIStmtFetch()
  8039 ms  fetch_errhp: 0x62f43f88cda0
  8039 ms  OCIStmtFetch return value: 0
  8039 ms  
[Buffer: 0]  DataType: 3
  8039 ms  Value: 1
  8039 ms  
[Buffer: 1]  DataType: 1
  8039 ms  Value: FINALHIST$
  8039 ms  
[Buffer: 2]  DataType: 1
  8039 ms  Value: SYS
  8039 ms  OCIStmtFetch()
  8039 ms  fetch_errhp: 0x62f43f88cda0
  8044 ms  OCIStmtFetch return value: 0
  8044 ms  
[Buffer: 0]  DataType: 3
  8044 ms  Value: 1
  8044 ms  
[Buffer: 1]  DataType: 1
  8044 ms  Value: MODELGTTRAW$
  8044 ms  
[Buffer: 2]  DataType: 1
  8044 ms  Value: SYS
  8045 ms  OCIStmtFetch()
  8045 ms  fetch_errhp: 0x62f43f88cda0
  8045 ms  OCIStmtFetch return value: 0
  8045 ms  
[Buffer: 0]  DataType: 3
  8045 ms  Value: 1
  8045 ms  
[Buffer: 1]  DataType: 1
  8045 ms  Value: PMAPGTT$
  8045 ms  
[Buffer: 2]  DataType: 1
  8045 ms  Value: SYS
  8045 ms  OCIStmtFetch()
  8045 ms  fetch_errhp: 0x62f43f88cda0
ID: 1, Name: COMMIT_SCN_LOG$, Description: SYS
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
  8050 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_UNITS_OF_MEASURE, Description: MDSYS
ID: 1, Name: SDO_COORD_REF_SYS, Description: MDSYS
  8050 ms  
[Buffer: 0]  DataType: 3
  8050 ms  Value: 1
  8050 ms  
[Buffer: 1]  DataType: 1ID: 1, Name: SDO_COORD_SYS, Description: MDSYS

  8050 ms  Value: MV_CAPABILITIES_TABLE$
  8050 ms  
[Buffer: 2]  DataType: 1
  8050 ms  Value: SYS
  8051 ms  OCIStmtFetch()
  8051 ms  fetch_errhp: 0x62f43f88cda0
  8051 ms  OCIStmtFetch return value: 0
  8051 ms  
[Buffer: 0]  DataType: 3
  8051 ms  Value: 1
ID: 1, Name: SDO_COORD_AXES, Description: MDSYS
  8051 ms  
[Buffer: 1]  DataType: 1
  8051 ms  Value: REWRITE_TABLE$
  8051 ms  
[Buffer: 2]  DataType: 1
  8051 ms  Value: SYS
  8051 ms  OCIStmtFetch()
  8051 ms  fetch_errhp: 0x62f43f88cda0
  8053 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_COORD_AXIS_NAMES, Description: MDSYS
  8053 ms  
[Buffer: 0]  DataType: 3
  8053 ms  Value: 1
  8053 ms  
[Buffer: 1]  DataType: 1
ID: 1, Name: SDO_COORD_OPS, Description: MDSYS
  8053 ms  Value: WRI$_ADV_ASA_RECO_DATA
  8053 ms  
[Buffer: 2]  DataType: 1
  8053 ms  Value: SYS
  8053 ms  OCIStmtFetch()
  8053 ms  fetch_errhp: 0x62f43f88cda0
  8053 ms  OCIStmtFetch return value: 0
ID: 1, Name: SDO_COORD_OP_PATHS, Description: MDSYS
ID: 1, Name: SDO_PREFERRED_OPS_SYSTEM, Description: MDSYS
  8053 ms  
[Buffer: 0]  DataType: 3
  8053 ms  Value: 1
  8053 ms  
[Buffer: 1]  DataType: 1
  8053 ms  Value: WRI$_HEATMAP_TOPN_DEP1
  8053 ms  
[Buffer: 2]  DataType: 1
ID: 1, Name: SDO_COORD_OP_METHODS, Description: MDSYS
  8053 ms  Value: SYS
  8053 ms  OCIStmtFetch()
  8053 ms  fetch_errhp: 0x62f43f88cda0
  8054 ms  OCIStmtFetch return value: 0
  8054 ms  
[Buffer: 0]  DataType: 3
ID: 1, Name: SDO_COORD_OP_PARAMS, Description: MDSYS
  8054 ms  Value: 1
  8054 ms  
[Buffer: 1]  DataType: 1
  8054 ms  Value: WRI$_HEATMAP_TOPN_DEP2
  8054 ms  
[Buffer: 2]  DataType: 1
  8054 ms  Value: SYS
ID: 1, Name: SDO_COORD_OP_PARAM_VALS, Description: MDSYS
ID: 1, Name: SDO_COORD_OP_PARAM_USE, Description: MDSYS
  8054 ms  OCIStmtFetch()
  8054 ms  fetch_errhp: 0x62f43f88cda0
  8054 ms  OCIStmtFetch return value: 0
  8054 ms  
[Buffer: 0]  DataType: 3
  8054 ms  Value: 1
  8054 ms  
[Buffer: 1]  DataType: 1
  8054 ms  Value: PLAN_TABLE$
  8054 ms  
[Buffer: 2]  DataType: 1
  8054 ms  Value: SYS
  8055 ms  OCIStmtFetch()
  8055 ms  fetch_errhp: 0x62f43f88cda0
  8059 ms  OCIStmtFetch return value: 0
  8059 ms  
[Buffer: 0]  DataType: 3ID: 1, Name: SDO_CS_SRS, Description: MDSYS
ID: 1, Name: SDO_PRIME_MERIDIANS, Description: MDSYS

  8059 ms  Value: 1
  8059 ms  
[Buffer: 1]  DataType: 1
  8059 ms  Value: KU$_LIST_FILTER_TEMP
  8059 ms  
[Buffer: 2]  DataType: 1
  8059 ms  Value: SYS
  8060 ms  OCIStmtFetch()
  8060 ms  fetch_errhp: 0x62f43f88cda0
  8060 ms  OCIStmtFetch return value: 0
  8060 ms  
[Buffer: 0]  DataType: 3
  8060 ms  Value: 1
ID: 1, Name: SDO_CRS_GEOGRAPHIC_PLUS_HEIGHT, Description: MDSYS
ID: 1, Name: SDO_ELLIPSOIDS_OLD_SNAPSHOT, Description: MDSYS
  8060 ms  
[Buffer: 1]  DataType: 1
  8060 ms  Value: KU$_LIST_FILTER_TEMP_2
  8060 ms  
[Buffer: 2]  DataType: 1
  8060 ms  Value: SYS
  8060 ms  OCIStmtFetch()
  8060 ms  fetch_errhp: 0x62f43f88cda0
  8060 ms  OCIStmtFetch return value: 0
  8060 ms  
[Buffer: 0]  DataType: 3
  8060 ms  Value: 1
  8060 ms  
[Buffer: 1]  DataType: 1
  8060 ms  Value: DATA_PUMP_XPL_TABLE$
ID: 1, Name: SDO_PROJECTIONS_OLD_SNAPSHOT, Description: MDSYS
ID: 1, Name: SDO_DATUMS_OLD_SNAPSHOT, Description: MDSYS
  8060 ms  
[Buffer: 2]  DataType: 1
  8060 ms  Value: SYS
  8060 ms  OCIStmtFetch()
  8060 ms  fetch_errhp: 0x62f43f88cda0
  8060 ms  OCIStmtFetch return value: 0
  8060 ms  
[Buffer: 0]  DataType: 3
  8060 ms  Value: 1
  8060 ms  
[Buffer: 1]  DataType: 1
  8060 ms  Value: KU$NOEXP_TAB
  8060 ms  
[Buffer: 2]  DataType: 1
  8060 ms  Value: SYS
  8060 ms  OCIStmtFetch()
  8060 ms  fetch_errhp: 0x62f43f88cda0
  8061 ms  OCIStmtFetch return value: 0
  8061 ms  
[Buffer: 0]  DataType: 3
  8061 ms  Value: 1
  8061 ms  
[Buffer: 1]  DataType: 1
  8061 ms  Value: KU$_SHARD_DOMIDX_NAMEMAP
  8061 ms  
[Buffer: 2]  DataType: 1
  8061 ms  Value: SYS
  8061 ms  OCIStmtFetch()
  8061 ms  fetch_errhp: 0x62f43f88cda0
  8061 ms  OCIStmtFetch return value: 0
  8061 ms  
[Buffer: 0]  DataType: 3
  8061 ms  Value: 1
  8061 ms  
[Buffer: 1]  DataType: 1
  8061 ms  Value: KU$XKTFBUE
  8061 ms  
[Buffer: 2]  DataType: 1
  8061 ms  Value: SYS
  8061 ms  OCIStmtFetch()
  8061 ms  fetch_errhp: 0x62f43f88cda0
  8072 ms  OCIStmtFetch return value: 0
  8072 ms  
[Buffer: 0]  DataType: 3
  8072 ms  Value: 1
  8072 ms  
[Buffer: 1]  DataType: 1
  8072 ms  Value: COMMIT_SCN_LOG$
  8072 ms  
[Buffer: 2]  DataType: 1
  8072 ms  Value: SYS
  8072 ms  OCIStmtFetch()
  8072 ms  fetch_errhp: 0x62f43f88cda0
  8072 ms  OCIStmtFetch return value: 0
  8072 ms  
[Buffer: 0]  DataType: 3
  8072 ms  Value: 1
  8072 ms  
[Buffer: 1]  DataType: 1
  8072 ms  Value: SYS_DIRECTIVE_TRACKED_OBJS
  8072 ms  
[Buffer: 2]  DataType: 1
  8072 ms  Value: SYS
  8073 ms  OCIStmtFetch()
  8073 ms  fetch_errhp: 0x62f43f88cda0
  8077 ms  OCIStmtFetch return value: 0
  8077 ms  
[Buffer: 0]  DataType: 3
  8077 ms  Value: 1
  8077 ms  
[Buffer: 1]  DataType: 1
  8077 ms  Value: ODCI_SECOBJ$
  8077 ms  
[Buffer: 2]  DataType: 1
  8077 ms  Value: SYS
  8078 ms  OCIStmtFetch()
  8078 ms  fetch_errhp: 0x62f43f88cda0
  8078 ms  OCIStmtFetch return value: 0
  8078 ms  
[Buffer: 0]  DataType: 3
  8078 ms  Value: 1
  8078 ms  
[Buffer: 1]  DataType: 1
  8078 ms  Value: ODCI_WARNINGS$
  8078 ms  
[Buffer: 2]  DataType: 1
  8078 ms  Value: SYS
  8078 ms  OCIStmtFetch()
  8078 ms  fetch_errhp: 0x62f43f88cda0
  8078 ms  OCIStmtFetch return value: 0
  8078 ms  
[Buffer: 0]  DataType: 3
  8078 ms  Value: 1
  8078 ms  
[Buffer: 1]  DataType: 1
  8078 ms  Value: ODCI_PMO_ROWIDS$
  8078 ms  
[Buffer: 2]  DataType: 1
  8078 ms  Value: SYS
  8078 ms  OCIStmtFetch()
  8078 ms  fetch_errhp: 0x62f43f88cda0
  8078 ms  OCIStmtFetch return value: 0
  8078 ms  
[Buffer: 0]  DataType: 3
  8078 ms  Value: 1
  8078 ms  
[Buffer: 1]  DataType: 1
  8078 ms  Value: XS$VALIDATION_TABLE
  8078 ms  
[Buffer: 2]  DataType: 1
  8078 ms  Value: SYS
  8078 ms  OCIStmtFetch()
  8078 ms  fetch_errhp: 0x62f43f88cda0
  8081 ms  OCIStmtFetch return value: 0
  8081 ms  
[Buffer: 0]  DataType: 3
  8081 ms  Value: 1
  8081 ms  
[Buffer: 1]  DataType: 1
  8081 ms  Value: IMPDP_STATS
  8081 ms  
[Buffer: 2]  DataType: 1
  8081 ms  Value: SYS
  8081 ms  OCIStmtFetch()
  8081 ms  fetch_errhp: 0x62f43f88cda0
  8081 ms  OCIStmtFetch return value: 0
  8081 ms  
[Buffer: 0]  DataType: 3
  8081 ms  Value: 1
  8081 ms  
[Buffer: 1]  DataType: 1
  8081 ms  Value: KU$_DATAPUMP_MASTER_12_2
  8081 ms  
[Buffer: 2]  DataType: 1
  8081 ms  Value: SYS
  8082 ms  OCIStmtFetch()
  8082 ms  fetch_errhp: 0x62f43f88cda0
  8082 ms  OCIStmtFetch return value: 0
  8082 ms  
[Buffer: 0]  DataType: 3
  8082 ms  Value: 1
  8082 ms  
[Buffer: 1]  DataType: 1
  8082 ms  Value: KU$_DATAPUMP_MASTER_12_0
  8082 ms  
[Buffer: 2]  DataType: 1
  8082 ms  Value: SYS
  8082 ms  OCIStmtFetch()
  8082 ms  fetch_errhp: 0x62f43f88cda0
  8082 ms  OCIStmtFetch return value: 0
  8082 ms  
[Buffer: 0]  DataType: 3
  8082 ms  Value: 1
  8082 ms  
[Buffer: 1]  DataType: 1
  8082 ms  Value: KU$_DATAPUMP_MASTER_11_2
  8082 ms  
[Buffer: 2]  DataType: 1
  8082 ms  Value: SYS
  8082 ms  OCIStmtFetch()
ID: 1, Name: SDO_XML_SCHEMAS, Description: MDSYS
ID: 1, Name: SDO_FEATURE_USAGE, Description: MDSYS
ID: 1, Name: SDO_XSD_TABLE, Description: MDSYS
ID: 1, Name: SDO_GEOR_XMLSCHEMA_TABLE, Description: MDSYS
ID: 1, Name: SDO_TIN_PC_SEQ, Description: MDSYS
ID: 1, Name: SDO_TIN_PC_SYSDATA_TABLE, Description: MDSYS
ID: 1, Name: SRSNAMESPACE_TABLE, Description: MDSYS
ID: 1, Name: SDO_PREFERRED_OPS_USER, Description: MDSYS
ID: 1, Name: NTV2_XML_DATA, Description: MDSYS
  8082 ms  fetch_errhp: 0x62f43f88cda0
  8082 ms  OCIStmtFetch return value: 0
  8082 ms  
[Buffer: 0]  DataType: 3
  8082 ms  Value: 1
ID: 1, Name: SDO_SRIDS_BY_URN, Description: MDSYS
  8082 ms  
[Buffer: 1]  DataType: 1
  8082 ms  Value: KU$_DATAPUMP_MASTER_11_1_0_7
  8082 ms  
[Buffer: 2]  DataType: 1ID: 1, Name: SDO_SRIDS_BY_URN_PATTERN, Description: MDSYS
ID: 1, Name: SDO_INDEX_HISTOGRAM_TABLE, Description: MDSYS

  8082 ms  Value: SYS
  8083 ms  OCIStmtFetch()
  8083 ms  fetch_errhp: 0x62f43f88cda0
  8083 ms  OCIStmtFetch return value: 0
  8083 ms  
[Buffer: 0]  DataType: 3
  8083 ms  Value: 1
  8083 ms  
[Buffer: 1]  DataType: 1
  8083 ms  Value: KU$_DATAPUMP_MASTER_11_1
ID: 1, Name: SDO_DIST_METADATA_TABLE, Description: MDSYS
ID: 1, Name: OGIS_SPATIAL_REFERENCE_SYSTEMS, Description: MDSYS
  8083 ms  
[Buffer: 2]  DataType: 1
  8083 ms  Value: SYS
  8083 ms  OCIStmtFetch()
  8083 ms  fetch_errhp: 0x62f43f88cda0
  8084 ms  OCIStmtFetch return value: 0
  8084 ms  
[Buffer: 0]  DataType: 3
  8084 ms  Value: 1
  8084 ms  
[Buffer: 1]  DataType: 1
  8084 ms  Value: KU$_DATAPUMP_MASTER_10_1
  8084 ms  
[Buffer: 2]  DataType: 1
  8084 ms  Value: SYS
  8084 ms  OCIStmtFetch()
  8084 ms  fetch_errhp: 0x62f43f88cda0
  8084 ms  OCIStmtFetch return value: 0
  8084 ms  
[Buffer: 0]  DataType: 3
  8084 ms  Value: 1
  8084 ms  
[Buffer: 1]  DataType: 1
  8084 ms  Value: SPD_SCRATCH_TAB
  8084 ms  
[Buffer: 2]  DataType: 1
  8084 ms  Value: SYS
  8084 ms  OCIStmtFetch()
  8084 ms  fetch_errhp: 0x62f43f88cda0
  8085 ms  OCIStmtFetch return value: 0
  8085 ms  
[Buffer: 0]  DataType: 3
  8085 ms  Value: 1
  8085 ms  
[Buffer: 1]  DataType: 1
  8085 ms  Value: SAM_SPARSITY_ADVICE
  8085 ms  
[Buffer: 2]  DataType: 1
  8085 ms  Value: SYS
  8085 ms  OCIStmtFetch()
  8085 ms  fetch_errhp: 0x62f43f88cda0
  8085 ms  OCIStmtFetch return value: 0
  8085 ms  
[Buffer: 0]  DataType: 3
  8085 ms  Value: 1
  8085 ms  
[Buffer: 1]  DataType: 1
  8085 ms  Value: HELP
  8085 ms  
[Buffer: 2]  DataType: 1
  8085 ms  Value: SYSTEM
  8086 ms  OCIStmtFetch()
  8086 ms  fetch_errhp: 0x62f43f88cda0
  8087 ms  OCIStmtFetch return value: 0
  8087 ms  
[Buffer: 0]  DataType: 3
  8087 ms  Value: 1
  8087 ms  
[Buffer: 1]  DataType: 1
  8087 ms  Value: OL$
  8087 ms  
[Buffer: 2]  DataType: 1
  8087 ms  Value: SYSTEM
  8087 ms  OCIStmtFetch()
  8087 ms  fetch_errhp: 0x62f43f88cda0
  8087 ms  OCIStmtFetch return value: 0
  8087 ms  
[Buffer: 0]  DataType: 3
  8087 ms  Value: 1
  8087 ms  
[Buffer: 1]  DataType: 1
  8087 ms  Value: OL$HINTS
  8087 ms  
[Buffer: 2]  DataType: 1
  8087 ms  Value: SYSTEM
  8087 ms  OCIStmtFetch()
  8087 ms  fetch_errhp: 0x62f43f88cda0
  8093 ms  OCIStmtFetch return value: 0
  8093 ms  
[Buffer: 0]  DataType: 3
  8093 ms  Value: 1
  8093 ms  
[Buffer: 1]  DataType: 1
  8093 ms  Value: OL$NODES
  8093 ms  
[Buffer: 2]  DataType: 1
  8093 ms  Value: SYSTEM
  8093 ms  OCIStmtFetch()
  8093 ms  fetch_errhp: 0x62f43f88cda0
  8093 ms  OCIStmtFetch return value: 0
  8093 ms  
[Buffer: 0]  DataType: 3
  8093 ms  Value: 1
  8093 ms  
[Buffer: 1]  DataType: 1
  8093 ms  Value: XDB_INDEX_DDL_CACHE
  8093 ms  
[Buffer: 2]  DataType: 1
  8093 ms  Value: XDB
  8093 ms  OCIStmtFetch()
  8093 ms  fetch_errhp: 0x62f43f88cda0
  8094 ms  OCIStmtFetch return value: 0
  8094 ms  
[Buffer: 0]  DataType: 3
  8094 ms  Value: 1
  8094 ms  
[Buffer: 1]  DataType: 1
  8094 ms  Value: XDB$IMPORT_TT_INFO
  8094 ms  
[Buffer: 2]  DataType: 1
  8094 ms  Value: XDB
  8094 ms  OCIStmtFetch()
  8094 ms  fetch_errhp: 0x62f43f88cda0
  8094 ms  OCIStmtFetch return value: 0
  8094 ms  
[Buffer: 0]  DataType: 3
  8094 ms  Value: 1
  8094 ms  
[Buffer: 1]  DataType: 1
  8094 ms  Value: XDB$IMPORT_QN_INFO
  8094 ms  
[Buffer: 2]  DataType: 1
  8094 ms  Value: XDB
  8094 ms  OCIStmtFetch()
  8094 ms  fetch_errhp: 0x62f43f88cda0
  8094 ms  OCIStmtFetch return value: 0
  8094 ms  
[Buffer: 0]  DataType: 3
  8094 ms  Value: 1
  8094 ms  
[Buffer: 1]  DataType: 1
  8094 ms  Value: XDB$IMPORT_NM_INFO
  8094 ms  
[Buffer: 2]  DataType: 1
  8094 ms  Value: XDB
  8094 ms  OCIStmtFetch()
  8094 ms  fetch_errhp: 0x62f43f88cda0
  8094 ms  OCIStmtFetch return value: 0
  8094 ms  
[Buffer: 0]  DataType: 3
  8094 ms  Value: 1
ID: 1, Name: OGIS_GEOMETRY_COLUMNS, Description: MDSYS
ID: 1, Name: SDO_WS_CONFERENCE, Description: MDSYS
ID: 1, Name: SDO_WS_CONFERENCE_RESULTS, Description: MDSYS
ID: 1, Name: SDO_WS_CONFERENCE_PARTICIPANTS, Description: MDSYS
ID: 1, Name: SDO_GEOR_PLUGIN_REGISTRY, Description: MDSYS
ID: 1, Name: RDF_PARAM$_TBL, Description: MDSYS
ID: 1, Name: SDO_CS_CONTEXT_INFORMATION, Description: MDSYS
ID: 1, Name: SDO_ST_TOLERANCE, Description: MDSYS
  8094 ms  
[Buffer: 1]  DataType: 1
  8094 ms  Value: XDB$IMPORT_PT_INFO
  8094 ms  
[Buffer: 2]  DataType: 1
  8094 ms  Value: XDB
ID: 1, Name: SDO_TTS_METADATA_TABLE, Description: MDSYS
ID: 1, Name: SDO_TXN_JOURNAL_GTT, Description: MDSYS
  8095 ms  OCIStmtFetch()
  8095 ms  fetch_errhp: 0x62f43f88cda0
  8099 ms  OCIStmtFetch return value: 0
  8099 ms  
[Buffer: 0]  DataType: 3
  8099 ms  Value: 1
  8099 ms  
[Buffer: 1]  DataType: 1
  8099 ms  Value: XDB$XIDX_IMP_T
  8099 ms  
[Buffer: 2]  DataType: 1ID: 1, Name: SDO_TXN_JOURNAL_REG, Description: MDSYS
ID: 1, Name: SDO_TXN_IDX_EXP_UPD_RGN, Description: MDSYS

  8099 ms  Value: XDB
  8099 ms  OCIStmtFetch()
  8099 ms  fetch_errhp: 0x62f43f88cda0
  8099 ms  OCIStmtFetch return value: 0
  8099 ms  
[Buffer: 0]  DataType: 3
ID: 1, Name: SDO_TOPO_TRANSACT_DATA, Description: MDSYS
  8099 ms  Value: 1
ID: 1, Name: SDO_TOPO_RELATION_DATA, Description: MDSYS
  8099 ms  
[Buffer: 1]  DataType: 1
  8099 ms  Value: DR$NUMBER_SEQUENCE
  8099 ms  
[Buffer: 2]  DataType: 1
  8099 ms  Value: CTXSYS
  8100 ms  OCIStmtFetch()
  8100 ms  fetch_errhp: 0x62f43f88cda0
  8100 ms  OCIStmtFetch return value: 0
  8100 ms  
[Buffer: 0]  DataType: 3
  8100 ms  Value: 1
  8100 ms  
[Buffer: 1]  DataType: 1
  8100 ms  Value: DR$OBJECT_ATTRIBUTE
  8100 ms  
[Buffer: 2]  DataType: 1
  8100 ms  Value: CTXSYS
  8100 ms  OCIStmtFetch()
  8100 ms  fetch_errhp: 0x62f43f88cda0
  8101 ms  OCIStmtFetch return value: 0
  8101 ms  
[Buffer: 0]  DataType: 3
  8101 ms  Value: 1
  8101 ms  
[Buffer: 1]  DataType: 1
  8101 ms  Value: DR$POLICY_TAB
  8101 ms  
[Buffer: 2]  DataType: 1
  8101 ms  Value: CTXSYS
  8101 ms  OCIStmtFetch()
  8101 ms  fetch_errhp: 0x62f43f88cda0
ID: 1, Name: SDO_WFS_LOCAL_TXNS, Description: MDSYS
ID: 1, Name: SDO_GEOR_DDL__TABLE$$, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_0, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_1, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_2, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_3, Description: MDSYS
ID: 1, Name: SDO_GR_MOSAIC_CB, Description: MDSYS
ID: 1, Name: SDO_GR_PARALLEL, Description: MDSYS
ID: 1, Name: SDO_GR_RDT_1, Description: MDSYS
ID: 1, Name: RDF_PARAMETER, Description: MDSYS
  8103 ms  OCIStmtFetch return value: 0
  8103 ms  
[Buffer: 0]  DataType: 3
  8103 ms  Value: 1
  8103 ms  
[Buffer: 1]  DataType: 1
  8103 ms  Value: DR$THS
  8103 ms  
[Buffer: 2]  DataType: 1
  8103 ms  Value: CTXSYS
  8104 ms  OCIStmtFetch()
  8104 ms  fetch_errhp: 0x62f43f88cda0
  8104 ms  OCIStmtFetch return value: 0
  8104 ms  
[Buffer: 0]  DataType: 3
  8104 ms  Value: 1
  8104 ms  
[Buffer: 1]  DataType: 1
  8104 ms  Value: DR$THS_PHRASE
  8104 ms  
[Buffer: 2]  DataType: 1
  8104 ms  Value: CTXSYS
  8104 ms  OCIStmtFetch()
  8104 ms  fetch_errhp: 0x62f43f88cda0
  8108 ms  OCIStmtFetch return value: 0
  8108 ms  
[Buffer: 0]  DataType: 3
  8108 ms  Value: 1
  8108 ms  
[Buffer: 1]  DataType: 1
  8108 ms  Value: SDO_ELLIPSOIDS
  8108 ms  
[Buffer: 2]  DataType: 1
  8108 ms  Value: MDSYS
  8108 ms  OCIStmtFetch()
  8108 ms  fetch_errhp: 0x62f43f88cda0
  8108 ms  OCIStmtFetch return value: 0
  8108 ms  
[Buffer: 0]  DataType: 3
  8108 ms  Value: 1
  8108 ms  
[Buffer: 1]  DataType: 1
  8108 ms  Value: SDO_DATUMS
  8108 ms  
[Buffer: 2]  DataType: 1
  8108 ms  Value: MDSYS
  8108 ms  OCIStmtFetch()
  8108 ms  fetch_errhp: 0x62f43f88cda0
  8109 ms  OCIStmtFetch return value: 0
  8109 ms  
[Buffer: 0]  DataType: 3
  8109 ms  Value: 1
  8109 ms  
[Buffer: 1]  DataType: 1
  8109 ms  Value: SDO_UNITS_OF_MEASURE
  8109 ms  
[Buffer: 2]  DataType: 1
  8109 ms  Value: MDSYS
  8110 ms  OCIStmtFetch()
  8110 ms  fetch_errhp: 0x62f43f88cda0
  8110 ms  OCIStmtFetch return value: 0
  8110 ms  
[Buffer: 0]  DataType: 3
  8110 ms  Value: 1
  8110 ms  
[Buffer: 1]  DataType: 1
  8110 ms  Value: SDO_COORD_REF_SYS
  8110 ms  
[Buffer: 2]  DataType: 1
  8110 ms  Value: MDSYS
  8110 ms  OCIStmtFetch()
  8110 ms  fetch_errhp: 0x62f43f88cda0
  8111 ms  OCIStmtFetch return value: 0
  8111 ms  
[Buffer: 0]  DataType: 3
  8111 ms  Value: 1
  8111 ms  
[Buffer: 1]  DataType: 1
  8111 ms  Value: SDO_COORD_SYS
  8111 ms  
[Buffer: 2]  DataType: 1
  8111 ms  Value: MDSYS
  8111 ms  OCIStmtFetch()
  8111 ms  fetch_errhp: 0x62f43f88cda0
  8111 ms  OCIStmtFetch return value: 0
  8111 ms  
[Buffer: 0]  DataType: 3
  8111 ms  Value: 1
  8111 ms  
[Buffer: 1]  DataType: 1
  8111 ms  Value: SDO_COORD_AXES
  8111 ms  
[Buffer: 2]  DataType: 1
  8111 ms  Value: MDSYS
  8112 ms  OCIStmtFetch()
  8112 ms  fetch_errhp: 0x62f43f88cda0
  8112 ms  OCIStmtFetch return value: 0
  8112 ms  
[Buffer: 0]  DataType: 3
  8112 ms  Value: 1
  8112 ms  
[Buffer: 1]  DataType: 1
  8112 ms  Value: SDO_COORD_AXIS_NAMES
  8112 ms  
[Buffer: 2]  DataType: 1
  8112 ms  Value: MDSYS
  8113 ms  OCIStmtFetch()
  8113 ms  fetch_errhp: 0x62f43f88cda0
  8113 ms  OCIStmtFetch return value: 0
  8113 ms  
[Buffer: 0]  DataType: 3
  8113 ms  Value: 1
  8113 ms  
[Buffer: 1]  DataType: 1
  8113 ms  Value: SDO_COORD_OPS
  8113 ms  
[Buffer: 2]  DataType: 1
  8113 ms  Value: MDSYS
  8113 ms  OCIStmtFetch()
  8113 ms  fetch_errhp: 0x62f43f88cda0
  8114 ms  OCIStmtFetch return value: 0
  8114 ms  
[Buffer: 0]  DataType: 3
  8114 ms  Value: 1
  8114 ms  
[Buffer: 1]  DataType: 1
  8114 ms  Value: SDO_COORD_OP_PATHS
  8114 ms  
[Buffer: 2]  DataType: 1
  8114 ms  Value: MDSYS
  8114 ms  OCIStmtFetch()
  8114 ms  fetch_errhp: 0x62f43f88cda0
  8114 ms  OCIStmtFetch return value: 0
  8114 ms  
[Buffer: 0]  DataType: 3
  8114 ms  Value: 1
  8114 ms  
[Buffer: 1]  DataType: 1
  8114 ms  Value: SDO_PREFERRED_OPS_SYSTEM
  8114 ms  
[Buffer: 2]  DataType: 1
  8114 ms  Value: MDSYS
  8115 ms  OCIStmtFetch()
  8115 ms  fetch_errhp: 0x62f43f88cda0
  8115 ms  OCIStmtFetch return value: 0
  8115 ms  
[Buffer: 0]  DataType: 3
  8115 ms  Value: 1
  8115 ms  
[Buffer: 1]  DataType: 1
  8115 ms  Value: SDO_COORD_OP_METHODS
  8115 ms  
[Buffer: 2]  DataType: 1
  8115 ms  Value: MDSYS
  8116 ms  OCIStmtFetch()
  8116 ms  fetch_errhp: 0x62f43f88cda0
  8116 ms  OCIStmtFetch return value: 0
  8116 ms  
[Buffer: 0]  DataType: 3
  8116 ms  Value: 1
  8116 ms  
[Buffer: 1]  DataType: 1
  8116 ms  Value: SDO_COORD_OP_PARAMS
  8116 ms  
[Buffer: 2]  DataType: 1
  8116 ms  Value: MDSYS
  8116 ms  OCIStmtFetch()
  8116 ms  fetch_errhp: 0x62f43f88cda0
  8117 ms  OCIStmtFetch return value: 0
  8117 ms  
[Buffer: 0]  DataType: 3
  8117 ms  Value: 1
  8117 ms  
[Buffer: 1]  DataType: 1
  8117 ms  Value: SDO_COORD_OP_PARAM_VALS
  8117 ms  
[Buffer: 2]  DataType: 1
  8117 ms  Value: MDSYS
  8117 ms  OCIStmtFetch()
  8117 ms  fetch_errhp: 0x62f43f88cda0
  8117 ms  OCIStmtFetch return value: 0
  8117 ms  
[Buffer: 0]  DataType: 3
  8117 ms  Value: 1
  8117 ms  
[Buffer: 1]  DataType: 1
  8117 ms  Value: SDO_COORD_OP_PARAM_USE
  8117 ms  
[Buffer: 2]  DataType: 1
  8117 ms  Value: MDSYS
  8117 ms  OCIStmtFetch()
  8117 ms  fetch_errhp: 0x62f43f88cda0
  8118 ms  OCIStmtFetch return value: 0
  8118 ms  
[Buffer: 0]  DataType: 3
  8118 ms  Value: 1
  8118 ms  
[Buffer: 1]  DataType: 1
  8118 ms  Value: SDO_CS_SRS
  8118 ms  
[Buffer: 2]  DataType: 1
  8118 ms  Value: MDSYS
  8119 ms  OCIStmtFetch()
  8119 ms  fetch_errhp: 0x62f43f88cda0
  8119 ms  OCIStmtFetch return value: 0
  8119 ms  
[Buffer: 0]  DataType: 3
  8119 ms  Value: 1
  8119 ms  
[Buffer: 1]  DataType: 1
  8119 ms  Value: SDO_PRIME_MERIDIANS
  8119 ms  
[Buffer: 2]  DataType: 1
  8119 ms  Value: MDSYS
  8119 ms  OCIStmtFetch()
  8119 ms  fetch_errhp: 0x62f43f88cda0
  8120 ms  OCIStmtFetch return value: 0
  8120 ms  
[Buffer: 0]  DataType: 3
  8120 ms  Value: 1
  8120 ms  
[Buffer: 1]  DataType: 1
  8120 ms  Value: SDO_CRS_GEOGRAPHIC_PLUS_HEIGHT
  8120 ms  
[Buffer: 2]  DataType: 1
  8120 ms  Value: MDSYS
  8121 ms  OCIStmtFetch()
  8121 ms  fetch_errhp: 0x62f43f88cda0
  8121 ms  OCIStmtFetch return value: 0
  8121 ms  
[Buffer: 0]  DataType: 3
  8121 ms  Value: 1
  8121 ms  
[Buffer: 1]  DataType: 1
  8121 ms  Value: SDO_ELLIPSOIDS_OLD_SNAPSHOT
  8121 ms  
[Buffer: 2]  DataType: 1
  8121 ms  Value: MDSYS
  8121 ms  OCIStmtFetch()
  8121 ms  fetch_errhp: 0x62f43f88cda0
  8122 ms  OCIStmtFetch return value: 0
  8122 ms  
[Buffer: 0]  DataType: 3
  8122 ms  Value: 1
  8122 ms  
[Buffer: 1]  DataType: 1
  8122 ms  Value: SDO_PROJECTIONS_OLD_SNAPSHOT
  8122 ms  
[Buffer: 2]  DataType: 1
  8122 ms  Value: MDSYS
  8122 ms  OCIStmtFetch()
  8122 ms  fetch_errhp: 0x62f43f88cda0
  8122 ms  OCIStmtFetch return value: 0
  8122 ms  
[Buffer: 0]  DataType: 3
  8122 ms  Value: 1
  8122 ms  
[Buffer: 1]  DataType: 1
  8122 ms  Value: SDO_DATUMS_OLD_SNAPSHOT
  8122 ms  
[Buffer: 2]  DataType: 1
  8122 ms  Value: MDSYS
  8123 ms  OCIStmtFetch()
  8123 ms  fetch_errhp: 0x62f43f88cda0
  8125 ms  OCIStmtFetch return value: 0
  8125 ms  
[Buffer: 0]  DataType: 3
  8125 ms  Value: 1
  8125 ms  
[Buffer: 1]  DataType: 1
  8125 ms  Value: SDO_XML_SCHEMAS
  8125 ms  
[Buffer: 2]  DataType: 1
  8125 ms  Value: MDSYS
  8125 ms  OCIStmtFetch()
  8125 ms  fetch_errhp: 0x62f43f88cda0
  8125 ms  OCIStmtFetch return value: 0
  8125 ms  
[Buffer: 0]  DataType: 3
  8125 ms  Value: 1
  8125 ms  
[Buffer: 1]  DataType: 1
  8125 ms  Value: SDO_FEATURE_USAGE
  8125 ms  
[Buffer: 2]  DataType: 1
  8125 ms  Value: MDSYS
  8126 ms  OCIStmtFetch()
  8126 ms  fetch_errhp: 0x62f43f88cda0
  8126 ms  OCIStmtFetch return value: 0
  8126 ms  
[Buffer: 0]  DataType: 3
  8126 ms  Value: 1
  8126 ms  
[Buffer: 1]  DataType: 1
  8126 ms  Value: SDO_XSD_TABLE
  8126 ms  
[Buffer: 2]  DataType: 1
  8126 ms  Value: MDSYS
  8126 ms  OCIStmtFetch()
  8126 ms  fetch_errhp: 0x62f43f88cda0
  8126 ms  OCIStmtFetch return value: 0
  8126 ms  
[Buffer: 0]  DataType: 3
  8126 ms  Value: 1
  8126 ms  
[Buffer: 1]  DataType: 1
  8126 ms  Value: SDO_GEOR_XMLSCHEMA_TABLE
  8126 ms  
[Buffer: 2]  DataType: 1
  8126 ms  Value: MDSYS
  8126 ms  OCIStmtFetch()
  8126 ms  fetch_errhp: 0x62f43f88cda0
  8127 ms  OCIStmtFetch return value: 0
  8127 ms  
[Buffer: 0]  DataType: 3
  8127 ms  Value: 1
  8127 ms  
[Buffer: 1]  DataType: 1
  8127 ms  Value: SDO_TIN_PC_SEQ
  8127 ms  
[Buffer: 2]  DataType: 1
  8127 ms  Value: MDSYS
  8127 ms  OCIStmtFetch()
  8127 ms  fetch_errhp: 0x62f43f88cda0
  8127 ms  OCIStmtFetch return value: 0
  8127 ms  
[Buffer: 0]  DataType: 3
  8127 ms  Value: 1
  8127 ms  
[Buffer: 1]  DataType: 1
  8127 ms  Value: SDO_TIN_PC_SYSDATA_TABLE
  8127 ms  
[Buffer: 2]  DataType: 1
  8127 ms  Value: MDSYS
  8127 ms  OCIStmtFetch()
  8127 ms  fetch_errhp: 0x62f43f88cda0
  8128 ms  OCIStmtFetch return value: 0
  8128 ms  
[Buffer: 0]  DataType: 3
  8128 ms  Value: 1
  8128 ms  
[Buffer: 1]  DataType: 1
  8128 ms  Value: SRSNAMESPACE_TABLE
  8128 ms  
[Buffer: 2]  DataType: 1
  8128 ms  Value: MDSYS
  8128 ms  OCIStmtFetch()
  8128 ms  fetch_errhp: 0x62f43f88cda0
  8128 ms  OCIStmtFetch return value: 0
  8128 ms  
[Buffer: 0]  DataType: 3
  8128 ms  Value: 1
  8128 ms  
[Buffer: 1]  DataType: 1
  8128 ms  Value: SDO_PREFERRED_OPS_USER
  8128 ms  
[Buffer: 2]  DataType: 1
  8128 ms  Value: MDSYS
  8128 ms  OCIStmtFetch()
  8128 ms  fetch_errhp: 0x62f43f88cda0
  8128 ms  OCIStmtFetch return value: 0
  8128 ms  
[Buffer: 0]  DataType: 3
  8128 ms  Value: 1
  8128 ms  
[Buffer: 1]  DataType: 1
  8128 ms  Value: NTV2_XML_DATA
  8128 ms  
[Buffer: 2]  DataType: 1
  8128 ms  Value: MDSYS
  8129 ms  OCIStmtFetch()
  8129 ms  fetch_errhp: 0x62f43f88cda0
  8129 ms  OCIStmtFetch return value: 0
  8129 ms  
[Buffer: 0]  DataType: 3
  8129 ms  Value: 1
  8129 ms  
[Buffer: 1]  DataType: 1
  8129 ms  Value: SDO_SRIDS_BY_URN
  8129 ms  
[Buffer: 2]  DataType: 1
  8129 ms  Value: MDSYS
  8129 ms  OCIStmtFetch()
  8129 ms  fetch_errhp: 0x62f43f88cda0
  8131 ms  OCIStmtFetch return value: 0
  8131 ms  
[Buffer: 0]  DataType: 3
  8131 ms  Value: 1
  8131 ms  
[Buffer: 1]  DataType: 1
  8131 ms  Value: SDO_SRIDS_BY_URN_PATTERN
  8131 ms  
[Buffer: 2]  DataType: 1
  8131 ms  Value: MDSYS
  8131 ms  OCIStmtFetch()
  8131 ms  fetch_errhp: 0x62f43f88cda0
  8131 ms  OCIStmtFetch return value: 0
  8131 ms  
[Buffer: 0]  DataType: 3
  8131 ms  Value: 1
  8131 ms  
[Buffer: 1]  DataType: 1
  8131 ms  Value: SDO_INDEX_HISTOGRAM_TABLE
  8131 ms  
[Buffer: 2]  DataType: 1
  8131 ms  Value: MDSYS
  8132 ms  OCIStmtFetch()
  8132 ms  fetch_errhp: 0x62f43f88cda0
  8132 ms  OCIStmtFetch return value: 0
  8132 ms  
[Buffer: 0]  DataType: 3
  8132 ms  Value: 1
  8132 ms  
[Buffer: 1]  DataType: 1
  8132 ms  Value: SDO_DIST_METADATA_TABLE
  8132 ms  
[Buffer: 2]  DataType: 1
  8132 ms  Value: MDSYS
  8133 ms  OCIStmtFetch()
  8133 ms  fetch_errhp: 0x62f43f88cda0
  8133 ms  OCIStmtFetch return value: 0
  8133 ms  
[Buffer: 0]  DataType: 3
  8133 ms  Value: 1
  8133 ms  
[Buffer: 1]  DataType: 1
  8133 ms  Value: OGIS_SPATIAL_REFERENCE_SYSTEMS
  8133 ms  
[Buffer: 2]  DataType: 1
  8133 ms  Value: MDSYS
  8133 ms  OCIStmtFetch()
  8133 ms  fetch_errhp: 0x62f43f88cda0
  8136 ms  OCIStmtFetch return value: 0
  8136 ms  
[Buffer: 0]  DataType: 3
  8136 ms  Value: 1
  8136 ms  
[Buffer: 1]  DataType: 1
  8136 ms  Value: OGIS_GEOMETRY_COLUMNS
  8136 ms  
[Buffer: 2]  DataType: 1
  8136 ms  Value: MDSYS
  8136 ms  OCIStmtFetch()
  8136 ms  fetch_errhp: 0x62f43f88cda0
  8137 ms  OCIStmtFetch return value: 0
  8137 ms  
[Buffer: 0]  DataType: 3
  8137 ms  Value: 1
  8137 ms  
[Buffer: 1]  DataType: 1
  8137 ms  Value: SDO_WS_CONFERENCE
  8137 ms  
[Buffer: 2]  DataType: 1
  8137 ms  Value: MDSYS
  8137 ms  OCIStmtFetch()
  8137 ms  fetch_errhp: 0x62f43f88cda0
  8137 ms  OCIStmtFetch return value: 0
  8137 ms  
[Buffer: 0]  DataType: 3
  8137 ms  Value: 1
  8137 ms  
[Buffer: 1]  DataType: 1
  8137 ms  Value: SDO_WS_CONFERENCE_RESULTS
  8137 ms  
[Buffer: 2]  DataType: 1
  8137 ms  Value: MDSYS
  8137 ms  OCIStmtFetch()
  8137 ms  fetch_errhp: 0x62f43f88cda0
  8137 ms  OCIStmtFetch return value: 0
  8137 ms  
[Buffer: 0]  DataType: 3
  8137 ms  Value: 1
  8137 ms  
[Buffer: 1]  DataType: 1
  8137 ms  Value: SDO_WS_CONFERENCE_PARTICIPANTS
  8137 ms  
[Buffer: 2]  DataType: 1
  8137 ms  Value: MDSYS
  8137 ms  OCIStmtFetch()
  8137 ms  fetch_errhp: 0x62f43f88cda0
  8138 ms  OCIStmtFetch return value: 0
  8138 ms  
[Buffer: 0]  DataType: 3
  8138 ms  Value: 1
  8138 ms  
[Buffer: 1]  DataType: 1
  8138 ms  Value: SDO_GEOR_PLUGIN_REGISTRY
  8138 ms  
[Buffer: 2]  DataType: 1
  8138 ms  Value: MDSYS
  8138 ms  OCIStmtFetch()
  8138 ms  fetch_errhp: 0x62f43f88cda0
  8138 ms  OCIStmtFetch return value: 0
  8138 ms  
[Buffer: 0]  DataType: 3
  8138 ms  Value: 1
  8138 ms  
[Buffer: 1]  DataType: 1
  8138 ms  Value: RDF_PARAM$_TBL
  8138 ms  
[Buffer: 2]  DataType: 1
  8138 ms  Value: MDSYS
  8138 ms  OCIStmtFetch()
  8138 ms  fetch_errhp: 0x62f43f88cda0
  8139 ms  OCIStmtFetch return value: 0
  8139 ms  
[Buffer: 0]  DataType: 3
  8139 ms  Value: 1
  8139 ms  
[Buffer: 1]  DataType: 1
  8139 ms  Value: SDO_CS_CONTEXT_INFORMATION
  8139 ms  
[Buffer: 2]  DataType: 1
  8139 ms  Value: MDSYS
  8139 ms  OCIStmtFetch()
  8139 ms  fetch_errhp: 0x62f43f88cda0
  8139 ms  OCIStmtFetch return value: 0
  8139 ms  
[Buffer: 0]  DataType: 3
  8139 ms  Value: 1
  8139 ms  
[Buffer: 1]  DataType: 1
  8139 ms  Value: SDO_ST_TOLERANCE
  8139 ms  
[Buffer: 2]  DataType: 1
  8139 ms  Value: MDSYS
  8139 ms  OCIStmtFetch()
  8139 ms  fetch_errhp: 0x62f43f88cda0
  8140 ms  OCIStmtFetch return value: 0
  8140 ms  
[Buffer: 0]  DataType: 3
  8140 ms  Value: 1
  8140 ms  
[Buffer: 1]  DataType: 1
  8140 ms  Value: SDO_TTS_METADATA_TABLE
  8140 ms  
[Buffer: 2]  DataType: 1
  8140 ms  Value: MDSYS
  8141 ms  OCIStmtFetch()
  8141 ms  fetch_errhp: 0x62f43f88cda0
  8141 ms  OCIStmtFetch return value: 0
  8141 ms  
[Buffer: 0]  DataType: 3
  8141 ms  Value: 1
  8141 ms  
[Buffer: 1]  DataType: 1
  8141 ms  Value: SDO_TXN_JOURNAL_GTT
  8141 ms  
[Buffer: 2]  DataType: 1
  8141 ms  Value: MDSYS
  8141 ms  OCIStmtFetch()
  8141 ms  fetch_errhp: 0x62f43f88cda0
  8142 ms  OCIStmtFetch return value: 0
  8142 ms  
[Buffer: 0]  DataType: 3
  8142 ms  Value: 1
  8142 ms  
[Buffer: 1]  DataType: 1
  8142 ms  Value: SDO_TXN_JOURNAL_REG
  8142 ms  
[Buffer: 2]  DataType: 1
  8142 ms  Value: MDSYS
  8142 ms  OCIStmtFetch()
  8142 ms  fetch_errhp: 0x62f43f88cda0
  8142 ms  OCIStmtFetch return value: 0
  8142 ms  
[Buffer: 0]  DataType: 3
  8142 ms  Value: 1
  8142 ms  
[Buffer: 1]  DataType: 1
  8142 ms  Value: SDO_TXN_IDX_EXP_UPD_RGN
  8142 ms  
[Buffer: 2]  DataType: 1
  8142 ms  Value: MDSYS
  8143 ms  OCIStmtFetch()
  8143 ms  fetch_errhp: 0x62f43f88cda0
  8143 ms  OCIStmtFetch return value: 0
  8143 ms  
[Buffer: 0]  DataType: 3
  8143 ms  Value: 1
  8143 ms  
[Buffer: 1]  DataType: 1
  8143 ms  Value: SDO_TOPO_TRANSACT_DATA
  8143 ms  
[Buffer: 2]  DataType: 1
  8143 ms  Value: MDSYS
  8143 ms  OCIStmtFetch()
  8143 ms  fetch_errhp: 0x62f43f88cda0
  8143 ms  OCIStmtFetch return value: 0
  8143 ms  
[Buffer: 0]  DataType: 3
  8143 ms  Value: 1
  8143 ms  
[Buffer: 1]  DataType: 1
  8143 ms  Value: SDO_TOPO_RELATION_DATA
  8143 ms  
[Buffer: 2]  DataType: 1
  8143 ms  Value: MDSYS
  8144 ms  OCIStmtFetch()
  8144 ms  fetch_errhp: 0x62f43f88cda0
  8145 ms  OCIStmtFetch return value: 0
  8145 ms  
[Buffer: 0]  DataType: 3
  8145 ms  Value: 1
  8145 ms  
[Buffer: 1]  DataType: 1
  8145 ms  Value: SDO_WFS_LOCAL_TXNS
  8145 ms  
[Buffer: 2]  DataType: 1
  8145 ms  Value: MDSYS
  8145 ms  OCIStmtFetch()
  8145 ms  fetch_errhp: 0x62f43f88cda0
  8145 ms  OCIStmtFetch return value: 0
  8145 ms  
[Buffer: 0]  DataType: 3
  8145 ms  Value: 1
  8145 ms  
[Buffer: 1]  DataType: 1
  8145 ms  Value: SDO_GEOR_DDL__TABLE$$
  8145 ms  
[Buffer: 2]  DataType: 1
  8145 ms  Value: MDSYS
  8145 ms  OCIStmtFetch()
  8145 ms  fetch_errhp: 0x62f43f88cda0
  8145 ms  OCIStmtFetch return value: 0
  8145 ms  
[Buffer: 0]  DataType: 3
  8145 ms  Value: 1
  8145 ms  
[Buffer: 1]  DataType: 1
  8145 ms  Value: SDO_GR_MOSAIC_0
  8145 ms  
[Buffer: 2]  DataType: 1
  8145 ms  Value: MDSYS
  8146 ms  OCIStmtFetch()
  8146 ms  fetch_errhp: 0x62f43f88cda0
  8146 ms  OCIStmtFetch return value: 0
  8146 ms  
[Buffer: 0]  DataType: 3
  8146 ms  Value: 1
  8146 ms  
[Buffer: 1]  DataType: 1
  8146 ms  Value: SDO_GR_MOSAIC_1
  8146 ms  
[Buffer: 2]  DataType: 1
  8146 ms  Value: MDSYS
  8146 ms  OCIStmtFetch()
  8146 ms  fetch_errhp: 0x62f43f88cda0
  8146 ms  OCIStmtFetch return value: 0
  8146 ms  
[Buffer: 0]  DataType: 3
  8146 ms  Value: 1
  8146 ms  
[Buffer: 1]  DataType: 1
  8146 ms  Value: SDO_GR_MOSAIC_2
  8146 ms  
[Buffer: 2]  DataType: 1
  8146 ms  Value: MDSYS
  8146 ms  OCIStmtFetch()
  8146 ms  fetch_errhp: 0x62f43f88cda0
  8146 ms  OCIStmtFetch return value: 0
  8146 ms  
[Buffer: 0]  DataType: 3
  8146 ms  Value: 1
  8146 ms  
[Buffer: 1]  DataType: 1
  8146 ms  Value: SDO_GR_MOSAIC_3
  8146 ms  
[Buffer: 2]  DataType: 1
  8146 ms  Value: MDSYS
  8146 ms  OCIStmtFetch()
  8146 ms  fetch_errhp: 0x62f43f88cda0
  8147 ms  OCIStmtFetch return value: 0
  8147 ms  
[Buffer: 0]  DataType: 3
  8147 ms  Value: 1
  8147 ms  
[Buffer: 1]  DataType: 1
  8147 ms  Value: SDO_GR_MOSAIC_CB
  8147 ms  
[Buffer: 2]  DataType: 1
  8147 ms  Value: MDSYS
  8147 ms  OCIStmtFetch()
  8147 ms  fetch_errhp: 0x62f43f88cda0
  8147 ms  OCIStmtFetch return value: 0
  8147 ms  
[Buffer: 0]  DataType: 3
  8147 ms  Value: 1
  8147 ms  
[Buffer: 1]  DataType: 1
  8147 ms  Value: SDO_GR_PARALLEL
  8147 ms  
[Buffer: 2]  DataType: 1
  8147 ms  Value: MDSYS
  8147 ms  OCIStmtFetch()
  8147 ms  fetch_errhp: 0x62f43f88cda0
  8147 ms  OCIStmtFetch return value: 0
  8147 ms  
[Buffer: 0]  DataType: 3
  8147 ms  Value: 1
  8147 ms  
[Buffer: 1]  DataType: 1
  8147 ms  Value: SDO_GR_RDT_1
  8147 ms  
[Buffer: 2]  DataType: 1
  8147 ms  Value: MDSYS
  8147 ms  OCIStmtFetch()
  8147 ms  fetch_errhp: 0x62f43f88cda0
  8147 ms  OCIStmtFetch return value: 0
  8147 ms  
[Buffer: 0]  DataType: 3
  8147 ms  Value: 1
  8147 ms  
[Buffer: 1]  DataType: 1
  8147 ms  Value: RDF_PARAMETER
  8147 ms  
[Buffer: 2]  DataType: 1
  8147 ms  Value: MDSYS
  8148 ms  OCIStmtFetch()
  8148 ms  fetch_errhp: 0x62f43f88cda0
  8150 ms  OCIStmtFetch return value: 100
  8150 ms  Fetch failed or no data (retval: 100)
Process terminated
```