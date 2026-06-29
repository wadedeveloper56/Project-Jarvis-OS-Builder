// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

// add headers that you want to pre-compile here
#include "framework.h"
#include <windows.h>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <cstdlib>
#include <optional>
#include <cctype>
#include <cstring>
#include <iosfwd>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <stack>
#include <sstream>.

#ifndef PATH_MAX
#define PATH_MAX MAX_PATH
#endif

#define DO_OR_EQUAL(t,a,b,c) a = (t)((a)|(c));
#define DO_AND_EQUAL(t,a,b,c) a = (t)((a)&(c));

#if defined( __UNIX__ )
#define PATH_SEP '/'
#define IS_PATH_SEP( a ) ((a)=='/')
#define CASE_PATH_SEP case'/'
#define PATH_LIST_SEP ':'
#define CASE_SENSITIVE
# ifndef __WATCOMC__
#define memicmp strncasecmp
# endif
#else
#define PATH_SEP '\\'
#define IS_PATH_SEP( a ) ((a)=='\\' || (a)=='/' || (a)==':')
#define CASE_PATH_SEP   case '\\': case '/': case ':'
#define PATH_LIST_SEP ';'
//    #define CASE_SENSITIVE
#endif

#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:4018)
#pragma warning(disable:4311)
#pragma warning(disable:4146)
#pragma warning(disable:4113)
#pragma warning(disable:5286)
#pragma warning(disable:4312)
#pragma warning(disable:4477)
#pragma warning(disable:5287)
#pragma warning(disable:4047)
#pragma warning(disable:4065)
#pragma warning(disable:4005)
#pragma warning(disable:6011)
#pragma warning(disable:26495)


#endif //PCH_H
