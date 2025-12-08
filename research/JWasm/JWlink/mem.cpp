#include "pch.h"
#include "mem.h"
#include "Memory.h"
#include "msg.h"
#include "wlmsgs.h"

void LnkMemInit(void)
{
}

void LnkMemFini(void)
{
}

void* LAlloc(size_t size)
{
    void* p;

    for (;; ) {
        p = AllocateMemory(size);
        if (p != NULL) {
            memset(p, 0, size);
            break;
        }
    }
    return(p);
}

void* ChkLAlloc(size_t size)
{
    void* ptr = LAlloc(size);
    if (ptr == NULL) {
        LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
    }
    return(ptr);
}

void  LFree(void* ptr) 
{
    FreeMemory(ptr);
}

void* LnkReAlloc(void* src, size_t size) 
{
    void* dest;
    for (;; ) {
        dest = ReallocateMemory(src, size);
        if (dest != NULL) break;
    }
    return(dest);
}

void* LnkExpand(void* src, size_t size)
{
    return(ExpandMemory(src, size));
}

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
