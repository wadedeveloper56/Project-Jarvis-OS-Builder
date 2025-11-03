#include "pch.h"
#ifdef TRMEM
#include "trmem.h"
#endif
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "library.h"
#include "virtmem.h"
#include "reloc.h"
#include "objcache.h"
#include "alloc.h"
#if defined( __QNX__ )
#include <sys/seginfo.h>

unsigned LastChanceSeg;
#endif

#ifdef _INT_DEBUG
static  int     Chunks;
#endif

#ifdef TRMEM
#include "fileio.h"

void* TrHdl;

static void         PrintAllMem(void);
#endif

static bool         CacheRelease(void);

#ifdef TRMEM

void PrintLine(int* bogus, const char* buff, unsigned len)
{
    bogus = bogus;           
    len = len;
    WriteStdOut((void*)buff);
}
#endif

void LnkMemInit(void)
{
#if defined( __QNX__ )
    LastChanceSeg = qnx_segment_alloc(65000);
#endif
#ifdef _INT_DEBUG
    Chunks = 0;
#endif
#ifdef TRMEM
    TrHdl = _trmem_open(malloc, free, realloc, _expand,
        NULL, PrintLine,
        _TRMEM_ALLOC_SIZE_0 | _TRMEM_REALLOC_SIZE_0 | _TRMEM_REALLOC_NULL |
        _TRMEM_FREE_NULL | _TRMEM_OUT_OF_MEMORY | _TRMEM_CLOSE_CHECK_FREE);
#endif
}


void LnkMemFini(void)
{
#ifdef _INT_DEBUG
    if (Chunks != 0) {
        DEBUG((DBG_ALWAYS, "%d Chunks unfreed", Chunks));
    }
#endif
#ifdef TRMEM
    PrintAllMem();
    _trmem_close(TrHdl);
#endif
}

#ifdef TRMEM
void* DoLAlloc(size_t size, void (*ra)(void))
#else
void* LAlloc(size_t size)
#endif
{
    void* p;

    for (;; ) {
#ifdef TRMEM
        p = _trmem_alloc(size, ra, TrHdl);
#else
        p = malloc(size);
#endif
        if (p != NULL) {
            memset(p, 0, size);
            break;
        }
        if (!FreeUpMemory()) break;
    }
#ifdef _INT_DEBUG
    if (p != NULL) ++Chunks;
#endif
    return(p);
}

#ifdef TRMEM
void* LAlloc(size_t size)
{
    void        (*ra)(void);

    ra = _trmem_guess_who();

    return(DoLAlloc(size, ra));
}
#endif

void* ChkLAlloc(size_t size)
{
    void* ptr;
#ifdef TRMEM
    void                (*ra)(void);

    ra = _trmem_guess_who();

    ptr = DoLAlloc(size, ra);
#else
    ptr = LAlloc(size);
#endif
    if (ptr == NULL) {
        LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
    }
    return(ptr);
}

void LFree(void* p)
{
    if (p == NULL) return;
#ifdef TRMEM
    _trmem_free(p, _trmem_guess_who(), TrHdl);
#else
    free(p);
#endif
#ifdef _INT_DEBUG
    --Chunks;
#endif
}

void* LnkExpand(void* src, size_t size)
{
#ifdef TRMEM
    return(_trmem_expand(src, size, _trmem_guess_who(), TrHdl));
#else
    return(_expand(src, size));
#endif
}

void* LnkReAlloc(void* src, size_t size)
{
    void* dest;
#ifdef TRMEM
    void        (*ra)(void);

    ra = _trmem_guess_who();      
#endif
    for (;; ) {
#ifdef TRMEM
        dest = _trmem_realloc(src, size, ra, TrHdl);
#else
        dest = realloc(src, size);
#endif
        if (dest != NULL) break;
        if (!CacheRelease() && !SwapOutVirt() && !SwapOutRelocs()) {
            LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);           
        }
    }
    return(dest);
}
#ifdef TRMEM
int ValidateMem(void)
{
    return(_trmem_validate_all(TrHdl));
}

void PrintAllMem(void)
{
    if (_trmem_prt_list(TrHdl) == 0) {
        _trmem_prt_usage(TrHdl);
    }
}
#endif

#ifndef NDEBUG
void DbgZapAlloc(void* tgt, size_t size)
{
    memset(tgt, 0xA5, size);
}

void DbgZapFreed(void* tgt, size_t size)
{
    memset(tgt, 0xBD, size);
}
#endif

static bool CacheRelease(void)
{
    bool   freed;

    freed = DumpObjCache();
    if (!freed) {
        freed = DiscardDicts();          
    }
    return(freed);
}

bool FreeUpMemory(void)
{
#if defined( __QNX__ )
    if (LastChanceSeg != (unsigned)-1) {
        qnx_segment_free(LastChanceSeg);
        LastChanceSeg = -1;
        _heapenable(0);
    }
#endif
    return(PermShrink() || CacheRelease() || SwapOutVirt() || SwapOutRelocs());
}

int __nmemneed(size_t amount)
{
    amount = amount;
    return(FreeUpMemory());
}

#ifdef _M_I86
int __fmemneed(size_t amount)
{
    amount = amount;
    return(FreeUpMemory());
}
#endif
