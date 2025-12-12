#pragma once

#include <cstdarg>
#include <ctype.h>
#include "structures.h"

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

class MessagingSubsystem
{
public:
	MessagingSubsystem();
	~MessagingSubsystem();
    void ResetMsg(void);
    int Msg_Get(int resourceid, char buffer[]);
    void Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, ...);
    void Msg_Put_Args(char rc_buff[], MSG_ARG_LIST*, char*, va_list*);
};

