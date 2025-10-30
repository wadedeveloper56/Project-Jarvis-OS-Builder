#pragma once

#include "orlintnl.h"
#include "cofftype.h"
#include "coffimpl.h"

#define _ClientRead( a, b )             (((a)->implib_data != NULL) ? ImportLibData.read( a, b ) : (a)->coff_hnd->funcs->read( a->file, b ))
#define _ClientSeek( a, b, c )          (((a)->implib_data != NULL) ? ImportLibData.seek( a, b, c ) : (a)->coff_hnd->funcs->seek( a->file, b, c ))
#define _ClientAlloc( a, b )            ((a)->coff_hnd->funcs->alloc( b ))
#define _ClientFree( a, b )             ((a)->coff_hnd->funcs->free( b ))
#define _ClientReAlloc( a, b, c )       ((a)->coff_hnd->funcs->realloc( b, c ))

#define _ClientSecRead( a, b )          ((a)->coff_file_hnd->coff_hnd->funcs->read( a->coff_file_hnd->file, b ))
#define _ClientSecSeek( a, b, c )       ((a)->coff_file_hnd->coff_hnd->funcs->seek( a->coff_file_hnd->file, b, c ))
#define _ClientSecAlloc( a, b )         ((a)->coff_file_hnd->coff_hnd->funcs->alloc( b ))
#define _ClientSecFree( a, b )          ((a)->coff_file_hnd->coff_hnd->funcs->free( b ))




