#pragma once

void LnkMemInit(void);
void LnkMemFini(void);
void* LAlloc(size_t size);
void* ChkLAlloc(size_t size);
void LFree(void* p);
void* LnkExpand(void* src, size_t size);
void* LnkReAlloc(void* src, size_t size);

#define _ChkAlloc( cast, dest, size ) dest = (cast)ChkLAlloc( size )
#define _LnkAlloc( cast, dest, size ) dest = (cast)LAlloc( size )
#define _TryAlloc( cast, dest, size ) dest = (cast)TryAlloc( size )
#define _PermAlloc( cast, dest, size ) dest = (cast)PermAlloc( size );
#define _LnkReAlloc( cast, dest, src, size ) dest = (cast)LnkReAlloc( src, size );
#define _LnkFree( ptr )         LFree( ptr )
#define _PermFree( ptr )        /* nothing to do */
#define _Pass1Alloc( cast, dest, size ) dest = (cast)Pass1Alloc( size );
#define _LnkExpand( cast, dest, src, size ) dest = (cast)LnkExpand( src, size );

