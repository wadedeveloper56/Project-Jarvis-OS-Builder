#pragma once

#include "types.h"

typedef enum {
    NONBUFFERED,
    COMMANDLINE,
    INTERACTIVE,
    BUFFERED,
    ENVIRONMENT,
    SYSTEM
} method;

typedef struct Token {
    char* buff;
    unsigned    len;
    char* next;
    char* this1;
    unsigned_16 line;
    char        quoted;     /* if token parsed as a quoted string*/
    unsigned_8  where : 2;
    unsigned_8  how : 3;
    unsigned_8  thumb : 1;
    unsigned_8  locked : 1;
    unsigned_8  skipToNext : 1;   /* set true if we need to skip to next token without a separator */
} Token, *TokenPtr, **TokenPtrPtr;
