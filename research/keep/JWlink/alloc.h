#pragma once

#include "Memory.h"

extern void* ChkLAlloc(size_t);
extern void* LAlloc(size_t);
extern void* TryAlloc(size_t);
extern void* LnkReAlloc(void*, size_t);
extern void     LFree(void*);
extern void* PermAlloc(size_t);
extern void* Pass1Alloc(size_t);
extern void* LnkExpand(void*, size_t); 

#define _ChkAlloc( cast, dest, size ) dest = (cast)ChkLAlloc( size )
#define _LnkAlloc( cast, dest, size ) dest = (cast)LAlloc( size )
#define _TryAlloc( cast, dest, size ) dest = (cast)TryAlloc( size )
#define _PermAlloc( cast, dest, size ) dest = (cast)PermAlloc( size );
#define _LnkReAlloc( cast, dest, src, size ) dest = (cast)LnkReAlloc( src, size );
#define _LnkFree( ptr )         LFree( ptr )
#define _PermFree( ptr )        /* nothing to do */
#define _Pass1Alloc( cast, dest, size ) dest = (cast)Pass1Alloc( size );
#define _LnkExpand( cast, dest, src, size ) dest = (cast)LnkExpand( src, size );
