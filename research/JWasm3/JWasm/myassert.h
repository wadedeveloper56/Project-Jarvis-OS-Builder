#pragma once

#ifdef NDEBUG
#define myassert(expr)   ((void)0)
#else
#if defined( __WATCOMC__ )
#pragma aux InternalError aborts;
#endif
extern int InternalError(const char* file, unsigned line);
#define myassert(expr)   ((void)((expr) ? 0 : InternalError(__FILE__,__LINE__)))
#endif