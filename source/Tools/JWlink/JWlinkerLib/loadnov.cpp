#include "pch.h"
#include "loadnov.h"
#include "globals.h"

#define DUMMY_THREAD_NAME " LONG"

uint32_t  DbgInfoCount;
uint32_t  DbgInfoLen;
virt_mem  NovDbgInfo;
virt_mem  CurrDbgLoc;

void ResetLoadNov()
{
    DbgInfoCount = 0;
    DbgInfoLen = 0;
}