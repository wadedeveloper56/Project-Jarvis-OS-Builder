#pragma once

#include "types.h"
#include "structures.h"
#include "lmsgs.h"

#define RESOURCE_MAX_SIZE       128

typedef union msg_arg {
    symbol* symb;
    char* string;
    char            c;
    unsigned_16     int_16;
    unsigned_32     int_32;
    targ_addr* address;
} MSG_ARG;

typedef struct msg_arg_list {
    int             index;
    MSG_ARG         arg[5];
} MSG_ARG_LIST;

