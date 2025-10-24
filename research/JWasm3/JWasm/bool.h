#pragma once

#if !defined( BOOL_DEFINED )  &&  !defined( bool ) && !(__WATCOMC__ >= 1070 && defined(__cplusplus))
#define BOOL_DEFINED
//typedef unsigned char bool;
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif