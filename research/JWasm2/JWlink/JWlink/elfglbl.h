#pragma once

#include "orlintnl.h"
#include "elftype.h"

#define _ClientRead( a, b )             ((a)->elf_hnd->funcs->read( a->file, b ))
#define _ClientSeek( a, b, c )          ((a)->elf_hnd->funcs->seek( a->file, b, c ))
#define _ClientAlloc( a, b )            ((a)->elf_hnd->funcs->alloc( b ))
#define _ClientFree( a, b )             ((a)->elf_hnd->funcs->free( b ))
#define _ClientReAlloc( a, b, c )       ((a)->elf_hnd->funcs->realloc( b, c ))

#define _ClientSecRead( a, b, c )       ((a)->elf_file_hnd->elf_hnd->funcs->read( a->elf_file_hnd->file, b, c ))
#define _ClientSecSeek( a, b, c )       ((a)->elf_file_hnd->elf_hnd->funcs->seek( a->elf_file_hnd->file, b, c ))
#define _ClientSecAlloc( a, b )         ((a)->elf_file_hnd->elf_hnd->funcs->alloc( b ))
#define _ClientSecFree( a, b )          ((a)->elf_file_hnd->elf_hnd->funcs->free( b ))

