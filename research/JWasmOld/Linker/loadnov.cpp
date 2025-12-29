#include "pch.h"
#include "loadnov.h"
#include "globals.h"

static unsigned_32  DbgInfoCount;
static unsigned_32  DbgInfoLen;
static virt_mem     NovDbgInfo;
static virt_mem     CurrDbgLoc;

void ResetLoadNov(void)
{
    DbgInfoCount = 0;
    DbgInfoLen = 0;
}