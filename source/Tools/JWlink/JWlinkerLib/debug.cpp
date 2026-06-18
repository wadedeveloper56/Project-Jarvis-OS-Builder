#include "pch.h"
#include <stdarg.h>
#include "debug.h"

void _Debug(unsigned int mask, char* str, ...)
{
    va_list arglist;
	va_start(arglist, str);
	vprintf(str, arglist);
}
