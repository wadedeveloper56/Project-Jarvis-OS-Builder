#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <fcntl.h>

#define UNALIGN

typedef unsigned        uint;
typedef unsigned char   uint_8;
typedef unsigned short  uint_16;
typedef unsigned int    uint_32;
typedef unsigned long   uint_64;
typedef unsigned char   unsigned_8;
typedef unsigned short  unsigned_16;
typedef unsigned int    unsigned_32;
typedef unsigned long   unsigned_64;

typedef signed char     int_8;
typedef signed short    int_16;
typedef signed int      int_32;
typedef signed long     int_64;
typedef signed char     signed_8;
typedef signed short    signed_16;
typedef signed int      signed_32;
typedef signed long     signed_64;

typedef unsigned char   byte;
typedef unsigned long   virt_mem;
typedef unsigned        f_handle;
