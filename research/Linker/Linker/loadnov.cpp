#include "pch.h"
#include "linkstd.h"
#include "alloc.h"
#include "msg.h"
#include "exenov.h"
#include "dbginfo.h"
#include "reloc.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "fileio.h"
#include "dbgall.h"
#include "impexp.h"
#include "loadfile.h"
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
