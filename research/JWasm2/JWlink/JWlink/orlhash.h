#pragma once

#include "orlhshdf.h"

extern void                     ORLHashTableFree(orl_hash_table);
extern orl_hash_data_struct* ORLHashTableQuery(orl_hash_table,
    orl_hash_value);
extern orl_return               ORLHashTableInsert(orl_hash_table,
    orl_hash_value,
    orl_hash_data);
extern orl_hash_table           ORLHashTableCreate(orl_funcs*,
    orl_hash_table_size,
    orl_hash_table_type,
    orl_hash_comparison_func);
extern int                      ORLNumberCmp(orl_hash_value n1,
    orl_hash_value n2);


