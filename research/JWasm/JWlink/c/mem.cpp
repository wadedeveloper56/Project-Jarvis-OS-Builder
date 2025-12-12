#include "pch.h"
#include "globals.h"
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
        if (p != nullptr) {
            memset(p, 0, size);
            break;
        }
    }
    return(p);
}

void* ChkLAlloc(size_t size)
{
    void* ptr;
    ptr = LAlloc(size);
    if (ptr == nullptr) {
        LnkMsg(FTL + MSG_NO_DYN_MEM, nullptr);
    }
    return(ptr);
}

void LFree(void* p)
{
    if (p == nullptr) return;
    FreeMemory(p);
}

void* LnkExpand(void* src, size_t size)
{
    return(ExpandMemory(src, size));
}

void* LnkReAlloc(void* src, size_t size)
{
    void* dest;
    for (;; ) {
        dest = ReallocateMemory(src, size);
        if (dest != nullptr) break;
    }
    return(dest);
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
#else
void DbgZapAlloc(void* tgt, size_t size)
{
}

void DbgZapFreed(void* tgt, size_t size)
{
}
#endif