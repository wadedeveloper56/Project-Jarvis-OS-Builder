#pragma once

/* v2.12: 'uint' removed ( replaced by 'unsigned') */
//typedef unsigned        uint;

/* assumptions:
 * - [unsigned] char  is 8-bit
 * - [unsigned] short is 16-bit
 * - [unsigned] int   is either 16- or 32-bit
 * - [unsigned] long  is either 32- or 64-bit
 */

typedef unsigned char   uint_8;
typedef signed char     int_8;
typedef unsigned short  uint_16;
typedef signed short    int_16;
#if defined(LONG_IS_64BITS) || defined(__LP64__)
typedef unsigned int    uint_32;
typedef   signed int    int_32;
typedef unsigned long   uint_64;
typedef   signed long   int_64;
#else
typedef unsigned long      uint_32;
typedef   signed long      int_32;
#if defined(LLONG_MAX) || defined(__GNUC__) || defined(__TINYC__)
typedef unsigned long long uint_64;
typedef   signed long long int_64;
#else
typedef unsigned __int64  uint_64;
#ifdef __OCC__
typedef          __int64  int_64;
#else
typedef   signed __int64  int_64;
#endif
#endif
#endif

/* 32-bit integer format specifier */
#ifdef __I86__
#define I32_SPEC "l"
#else
#define I32_SPEC ""
#endif

/* 64-bit integer format specifier */
#if defined(LONG_IS_64BITS) || defined(__LP64__)
#define I64_SPEC "l"
#elif defined(__UNIX__) || defined(__CYGWIN__) || defined(__DJGPP__)
#define I64_SPEC "ll"
#else
#define I64_SPEC "I64"
#endif

