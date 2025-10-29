// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

#pragma warning(disable:4267)  /* conversion from 'size_t' to 'type', possible loss of data */
#pragma warning(disable:4018)  /* signed/unsigned mismatch */
#pragma warning(disable:4244)  /* conversion from 'type1' to 'type2', possible loss of data */
#pragma warning(disable:4311)  /* 'type cast': pointer truncation from 'type' to 'type' */
#pragma warning(disable:4113)  /* incompatible parameter lists */
#pragma warning(disable:4477)  /* 'format string' : too many arguments for format specifier */
#pragma warning(disable:5287)  /* 'function' : function has no prototype */

#define _WCUNALIGNED

#endif //PCH_H
