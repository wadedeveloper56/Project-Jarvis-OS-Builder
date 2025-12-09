#include "pch.h"
#include "debug.h"
#include "msg.h"
#include "linkutil.h"

int Debug;

void _Debug(unsigned int mask, char* str, ...)
{
    va_list     arglist;
    char        buff[256];
    unsigned    len;

    if (Debug & mask || (mask & DBG_INFO_MASK) == DBG_ALWAYS) {
        va_start(arglist, str);
        len = DoFmtStr(buff, sizeof(buff), str, &arglist);
        WriteStdOut(buff);
        if (!(mask & DBG_NOCRLF)) {
            WriteNLStdOut();
        }
    }
}