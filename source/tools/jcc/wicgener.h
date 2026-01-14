#pragma once

#include <stddef.h>
#include <stdio.h>

#ifdef DEVBUILD
 #if !defined( _NO_EXT_KEYS ) /* extensions enabled */
  #define assert(expr)  ((expr)?(void)0:wicAssert(0,#expr,__FILE__,__LINE__))
 #else
  #define assert(expr)  wicAssert(expr,#expr,__FILE__,__LINE__)
 #endif
#else
 #define assert(__ignore) ((void)0)
#endif
