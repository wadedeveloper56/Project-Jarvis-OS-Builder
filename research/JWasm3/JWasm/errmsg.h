#pragma once

#define errout stdout
extern char banner_printed;
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

static void PrtMsg(int severity, int msgnum, va_list args1, va_list args2);
void Fatal(int msgnum, ...);
int EmitError(int msgnum);
int write_logo(void);
char* ErrnoStr(void);
int EmitErr(int msgnum, ...);
void EmitWarn(int level, int msgnum, ...);
void PrintUsage(void);
