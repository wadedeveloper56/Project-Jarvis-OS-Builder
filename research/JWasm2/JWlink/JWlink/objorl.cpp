#include "pch.h"
#include "objorl.h"
#include "mem.h"
#include "orl.h"
#include "mem.h"
#include "objnode.h"
#include "objcache.h"

orl_handle ORLHandle;
orl_funcs ORLFuncs = { ORLRead, ORLSeek, ChkLAlloc, LFree };
readcache* ReadCacheList;
long             ORLFilePos;

void InitObjORL(void)
{
    ORLHandle = ORLInit(&ORLFuncs);
    ReadCacheList = NULL;
}

void ObjORLFini(void)
{
    ORLFini(ORLHandle);
}

long ORLSeek(void* _list, long pos, int where)
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

void* ORLRead(void* _list, size_t len)
{
    file_list* list = (file_list*)_list;
    void* result;
    readcache* cache;

    result = CachePermRead(list, ORLFilePos, (unsigned int)len);
    ORLFilePos += (long)len;
    _ChkAlloc(readcache*, cache, sizeof(readcache));
    cache->next = ReadCacheList;
    ReadCacheList = cache;
    cache->data = result;
    return(result);
}

