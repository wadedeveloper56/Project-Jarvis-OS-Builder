#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "trmem.h"

static uint_32 memcalls = 0;
static uint_32 memstart;

extern _trmem_hdl   hTrmem;
#define malloc( x ) _trmem_alloc( x, _trmem_guess_who( &x ), hTrmem )
#define free( x )   _trmem_free( x, _trmem_guess_who( &x ), hTrmem )

void* MemAlloc(size_t size)
{
    void* ptr;
    ptr = malloc(size);
    DebugMsg1(("MemAlloc(0x%X)=%p cnt=%" I32_SPEC "u\n", size, ptr, ++memcalls));
    if (ptr == NULL) {
        Fatal(OUT_OF_MEMORY);
    }
    return(ptr);
}

void MemFree(void* ptr)
{
    DebugMsg1(("MemFree(0x%p) cnt=%" I32_SPEC "u\n", ptr, --memcalls));
    free(ptr);
    return;
}

