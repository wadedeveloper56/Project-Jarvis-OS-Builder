#include "pch.h"
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "library.h"
#include "virtmem.h"
#include "reloc.h"
#include "objcache.h"
#include "alloc.h"

void LnkMemInit(void)
{
}

void LnkMemFini(void)
{
}

bool CacheRelease(void)
{
    return false;
}

bool FreeUpMemory(void)
{
    return(PermShrink() || CacheRelease() || SwapOutVirt() || SwapOutRelocs());
}

void* LAlloc(size_t size)
{
    void* p;

    for (;; ) {
        p = malloc(size);
        if (p != NULL) {
            memset(p, 0, size);
            break;
        }
        if (!FreeUpMemory()) break;
    }
    return(p);
}

void* ChkLAlloc(size_t size)
{
    void* ptr;
    ptr = LAlloc(size);
    if (ptr == NULL) {
        //FIX ME LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
    }
    return(ptr);
}


void LFree(void* p)
{
    if (p == NULL) return;
    free(p);
}
