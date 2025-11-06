#include "pch.h"
#include "linkstd.h"
#include "command.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "mapio.h"
#include "loadfile.h"
#include "demangle.h"
#include "msg.h"
#include "virtmem.h"
#include "reloc.h"

#undef pick
#define pick( num, string ) string

static char* MsgStrings[] = {
#include "msg.h"

#include "alloc.h"

static  char* LocFile;
static  char* LocMem;
static  int             LocRec;
static  MSG_ARG_LIST    MsgArgInfo;
static  char* CurrSymName;
#define MSG_ARRAY_SIZE ((MSG_MAX_ERR_MSG_NUM / 8) + 1)
unsigned long   MaxErrors;
bool            BannerPrinted;
byte MsgFlags[MSG_ARRAY_SIZE];

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

void ResetMsg(void)
{
    LocFile = NULL;
    LocMem = NULL;
    LocRec = 0;
    MsgArgInfo.index = -1;
    memset(MsgFlags, 0xFF, MSG_ARRAY_SIZE);
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

void* LnkExpand(void* src, size_t size)
{
    return(_expand(src, size));
}
