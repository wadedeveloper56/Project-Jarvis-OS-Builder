#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <cstdint>

#define UNALIGN
#define ROUND_UP( x, r )        (((x)+((r)-1))&~((r)-1))
#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

typedef unsigned char   byte;
typedef unsigned long   virt_mem;
typedef unsigned        f_handle;
