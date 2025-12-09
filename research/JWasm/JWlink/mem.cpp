#include "pch.h"
#include "globals.h"
#include "mem.h"
#include "Memory.h"

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
    void* ptr;
    ptr = LAlloc(size);
    if (ptr == NULL) {
        //LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
    }
    return(ptr);
}

void LFree(void* p)
{
    if (p == NULL) return;
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
        if (dest != NULL) break;
    }
    return(dest);
}