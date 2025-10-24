#include "pch.h"
#include "errmsg.h"

int write_logo(void)
{
	return 0;
}

void Fatal(int msgnum, ...)
{
}

int EmitErr(int msgnum, ...)
{
	return 0;
}

void EmitWarn(int level, int msgnum, ...)
{
}

char* ErrnoStr(void)
{
	return NULL;
}

void DoDebugMsg(const char* format, ...)
{
}

void DoDebugMsg1(const char* format, ...)
{
}

int EmitError(int msgnum)
{
	return 0;
}

void PrintUsage(void)
{
}

int InternalError(const char* file, unsigned line)
{
	return 0;
}
