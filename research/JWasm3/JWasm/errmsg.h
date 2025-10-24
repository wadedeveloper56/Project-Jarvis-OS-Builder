#pragma once

#define pick( code, text )  code,
enum msgno {
    #include "msgdef.h"
    MSG_LAST
};

#ifdef DEBUG_OUT
extern void DoDebugMsg(const char* format, ...);
extern void DoDebugMsg1(const char* format, ...);
#define DebugMsg( x ) DoDebugMsg x
#define DebugMsg1( x ) DoDebugMsg1 x
#define DebugCmd( x ) x
#else
#define DebugMsg( x )
#define DebugMsg1( x )
#define DebugCmd( x )
#endif

int EmitError(int msgnum);
int write_logo(void);
char* ErrnoStr(void);
int EmitErr(int msgnum, ...);
