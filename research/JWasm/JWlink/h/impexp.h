#pragma once

#include "types.h"
#include "globals.h"

#define NOT_IMP_BY_ORDINAL 0xFFFFFFFF

typedef struct entry_export {
    struct entry_export* next;
    char* name;
    unsigned_32             ordinal;
    unsigned_16             iopl_words;
    unsigned_16             isresident : 1;
    unsigned_16             isexported : 1;
    unsigned_16             ismovable : 1;
    unsigned_16             isanonymous : 1;
    unsigned_16             isfree : 1;
    unsigned_16             isprivate : 1;
    symbol* sym;
    char* impname;
    targ_addr               addr;
} entry_export;

