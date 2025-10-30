#pragma once

#include "orlintnl.h"
#include "omftype.h"

#define _ClientRead( a, b )             ((a)->omf_hnd->funcs->read( a->file, b ))
#define _ClientSeek( a, b, c )          ((a)->omf_hnd->funcs->seek( a->file, b, c ))
#define _ClientAlloc( a, b )            ((a)->omf_hnd->funcs->alloc( b ))
#define _ClientFree( a, b )             ((a)->omf_hnd->funcs->free( b ))
#define _ClientReAlloc( a, b, c )       ((a)->omf_hnd->funcs->realloc( b, c ))

#define _ClientSecRead( a, b, c )       ((a)->omf_file_hnd->omf_hnd->funcs->read( a->omf_file_hnd->file, b, c ))
#define _ClientSecSeek( a, b, c )       ((a)->omf_file_hnd->omf_hnd->funcs->seek( a->omf_file_hnd->file, b, c ))
#define _ClientSecAlloc( a, b )         ((a)->omf_file_hnd->omf_hnd->funcs->alloc( b ))
#define _ClientSecFree( a, b )          ((a)->omf_file_hnd->omf_hnd->funcs->free( b ))

#define ORL_FILE_WORD_SIZE_MASK         ( ORL_FILE_FLAG_16BIT_MACHINE | \
                                          ORL_FILE_FLAG_32BIT_MACHINE | \
                                          ORL_FILE_FLAG_64BIT_MACHINE )
#define _SetWordSize( a, b )            (a=(a & ~ORL_FILE_WORD_SIZE_MASK) | b)

#define _Is32BitRec( a )                (a & 1)

#define _TurnBitOn( map, bit )          (map[bit >> 3] |= (1 << (bit & 0x1f)))
#define _TestBit( map, bit )            (map[bit >> 3] & (1 << (bit & 0x1f)))

