#pragma once

#include "types.h"
#include "taddr.h"
#include "syms.h"
#include "wlmsgs.h"

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

extern int      InitMsg(void);
extern void     ResetMsg(void);
extern int      Msg_Get(int resourceid, char buffer[]);
extern void     Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, ...);
extern void     Msg_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, va_list*);
extern void     Msg_Write_Map(int resourceid, ...);
extern int      FiniMsg(void);