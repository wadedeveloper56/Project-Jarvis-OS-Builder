#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <malloc.h>
#include <signal.h>
#include <string.h>
#include <process.h>
#include <conio.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include <setjmp.h>
#include <direct.h>
#include <time.h>
#include <basetsd.h>
typedef SSIZE_T ssize_t;

#pragma warning(disable:6031)
#pragma warning(disable:4018)
#pragma warning(disable:4267)
#pragma warning(disable:4244)

#define setmode _setmode
