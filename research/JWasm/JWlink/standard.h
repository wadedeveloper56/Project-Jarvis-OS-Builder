#pragma once

#define NLCHAR         '\n'
#define CTRLZ          '\32'

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

/* round up by a power of 2 */
#define ROUND_UP( x, r )        (((x)+((r)-1))&~((r)-1))
#define ROUND_SHIFT( x, r )     ROUND_UP( x, 1 << (r) )

#define MAKE_EVEN( x ) ROUND_UP( x, 2 )
#define MAKE_PARA( x ) ROUND_UP( x, 16 )

// useful for stringizing tokens
#define __str( m )      #m
#define __xstr( l )     __str( l )

#ifndef NDEBUG
#define __location " (" __FILE__ "," __xstr(__LINE__) ")"
#define DbgVerify( cond, msg ) if( ! ( cond ) ) LnkFatal( msg __location );
#define DbgDefault( msg ) default: LnkFatal( msg __location )
#define DbgAssert( cond )   if( !(cond) ) LnkFatal( #cond __location );
#else
#define DbgVerify( cond, msg )
#define DbgDefault( msg )
#define DbgAssert( cond )
#endif

#if defined( __UNIX__ )
#define PATH_SEP '/'
#define IS_PATH_SEP( a ) ((a)=='/')
#define CASE_PATH_SEP case'/'
#define PATH_LIST_SEP ':'

#define CASE_SENSITIVE

#else
#define PATH_SEP '\\'
#define IS_PATH_SEP( a ) ((a)=='\\' || (a)=='/' || (a)==':')
#define CASE_PATH_SEP   case '\\': case '/': case ':'
#define PATH_LIST_SEP ';'

//    #define CASE_SENSITIVE

#endif

#ifdef CASE_SENSITIVE
#define FNAMECMPSTR      strcmp      /* for case  sensitive file systems */
#else
#define FNAMECMPSTR      stricmp     /* for case insensitive file systems */
#endif

#ifndef BOOL_DEFINED
#define BOOL_DEFINED
//typedef int bool;
#endif
typedef unsigned char   byte;
typedef unsigned long   virt_mem;
//typedef unsigned        f_handle;

#ifndef __386__
#define UNALIGN
//_WCUNALIGNED
#else
#define UNALIGN
#endif

#if defined( __QNX__ )
#define _EXE       0
#define _QNXLOAD   1
#define _OS2       2
#define _PHARLAP   3
#define _NOVELL    4
#define _DOS16M    5
//    #define _ELF       6
#else
#define _EXE       0
#define _QNXLOAD   1
#define _OS2       2
#define _PHARLAP   3
#define _NOVELL    4
//    #define _DOS16M    5
#define _ELF       6
//    #define _ZDOS      7
#define _RAW       8
#endif
