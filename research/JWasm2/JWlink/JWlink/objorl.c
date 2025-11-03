#include "pch.h"
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkstd.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "alloc.h"
#include "orl.h"
#include "specials.h"
#include "obj2supp.h"
#include "objnode.h"
#include "objcache.h"
#include "objio.h"
#include "cmdline.h"
#include "dbgall.h"
#include "objpass1.h"
#include "objpass2.h"
#include "objorl.h"
#include "strtab.h"
#include "carve.h"
#include "wcomdef.h"
#include "permdata.h"
#include "command.h"    // NYI: don't want to include this!
#include "impexp.h"
#include "virtmem.h"
#include "loadfile.h"
#include "objstrip.h"
#include "toc.h"
#include "walloca.h"

static long ORLSeek(void*, long, int);
static void* ORLRead(void*, size_t);
static void ClearCachedData(file_list* list);
static orl_funcs        ORLFuncs = { ORLRead, ORLSeek, ChkLAlloc, LFree };
static orl_handle       ORLHandle;
static long             ORLFilePos;

typedef struct readcache READCACHE;

typedef struct readcache {
    READCACHE* next;
    void* data;
} readcache;

static readcache* ReadCacheList;

static void* ORLRead(void* _list, size_t len)
{
    file_list* list = (file_list*)_list;
    void* result;
    readcache* cache;

    result = CachePermRead(list, ORLFilePos, (int)len);
    ORLFilePos += (int)len;
    _ChkAlloc(readcache * , cache, sizeof(readcache));
    cache->next = ReadCacheList;
    ReadCacheList = cache;
    cache->data = result;
    return(result);
}

static long ORLSeek(void* _list, long pos, int where)
{
    file_list* list = (file_list*)_list;

    if (where == SEEK_SET) {
        ORLFilePos = pos;
    }
    else if (where == SEEK_CUR) {
        ORLFilePos += pos;
    }
    else {
        ORLFilePos = list->file->len - pos;
    }
    return(ORLFilePos);
}

void ObjORLFini(void)
{
    ORLFini(ORLHandle);
}

void InitObjORL(void)
{
    ORLHandle = ORLInit(&ORLFuncs);
    ReadCacheList = NULL;
}