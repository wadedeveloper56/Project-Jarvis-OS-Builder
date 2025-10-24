#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <ctype.h>
#include <setjmp.h>

#pragma warning(disable:4267)  /* conversion from 'size_t' to 'type', possible loss of data */
#pragma warning(disable:4018)  /* signed/unsigned mismatch */
#pragma warning(disable:4244)  /* conversion from 'type1' to 'type2', possible loss of data */
#pragma warning(disable:4311)  /* 'type cast': pointer truncation from 'type' to 'type' */
#pragma warning(disable:4113)  /* incompatible parameter lists */
#pragma warning(disable:4477)  /* 'format string' : too many arguments for format specifier */
#pragma warning(disable:5287)  /* 'function' : function has no prototype */

#define WILDCARDS 1
#define CATCHBREAK 1
#define TRMEM 1
#ifdef _DEBUG
#define DEBUG_OUT 1
#endif
