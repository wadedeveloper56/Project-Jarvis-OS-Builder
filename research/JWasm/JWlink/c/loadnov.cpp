#include "pch.h"
#include "globals.h"
#include "loadnov.h"

#define DUMMY_THREAD_NAME " LONG"

static unsigned_32  DbgInfoCount;
static unsigned_32  DbgInfoLen;
static virt_mem     NovDbgInfo;
static virt_mem     CurrDbgLoc;

void ResetLoadNov(void)
{
    DbgInfoCount = 0;
    DbgInfoLen = 0;
}
