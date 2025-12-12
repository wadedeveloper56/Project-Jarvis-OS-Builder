#include "pch.h"
#include "globals.h"
#include "mixcache.h"
#include "mem.h"
#include "ntio.h"
#include "objio.h"

static bool     Multipage;

#define CACHE_PAGE_SIZE         (8*1024)

void CacheFini(void)
{
}

void* CacheRead(file_list* list, unsigned long pos, unsigned len)
{
    unsigned    bufnum;
    unsigned    startnum;
    unsigned    offset;
    unsigned    amtread;
    char* result;
    char** cache;
    unsigned long newpos;
    infilelist* file;

    if (list->file->flags & INSTAT_FULL_CACHE) {
        if (pos + len > list->file->len) return nullptr;
        return (char*)list->file->cache + pos;
    }
    Multipage = FALSE;
    file = list->file;
    offset = pos % CACHE_PAGE_SIZE;
    amtread = CACHE_PAGE_SIZE - offset;
    startnum = pos / CACHE_PAGE_SIZE;
    bufnum = startnum;
    cache = (char**)file->cache;
    for (;;) {
        if (cache[bufnum] == nullptr) {   // make sure page is in.
            _ChkAlloc(char*, cache[bufnum], CACHE_PAGE_SIZE);
            newpos = (unsigned long)bufnum * CACHE_PAGE_SIZE;
            if (file->currpos != newpos) {
                QSeek(file->handle, newpos, file->name);
            }
            file->currpos = newpos + CACHE_PAGE_SIZE;
            QRead(file->handle, cache[bufnum], CACHE_PAGE_SIZE, file->name);
        }
        if (amtread >= len) break;
        amtread += CACHE_PAGE_SIZE;     // it spans pages.
        bufnum++;
        Multipage = TRUE;
    }
    if (!Multipage) {
        result = cache[startnum] + offset;
    }
    else {
        if (len > TokSize) {
            TokSize = ROUND_UP(len, SECTOR_SIZE);
            _LnkReAlloc(char *, TokBuff, TokBuff, TokSize);
        }
        amtread = CACHE_PAGE_SIZE - offset;
        memcpy(TokBuff, cache[startnum] + offset, amtread);
        len -= amtread;
        result = TokBuff + amtread;
        for (;;) {
            startnum++;
            if (len <= CACHE_PAGE_SIZE) {
                memcpy(result, cache[startnum], len);
                break;
            }
            else {
                memcpy(result, cache[startnum], CACHE_PAGE_SIZE);
                len -= CACHE_PAGE_SIZE;
                result += CACHE_PAGE_SIZE;
            }
        }
        result = TokBuff;
    }
    return result;
}

void* CachePermRead(file_list* list, unsigned long pos, unsigned len)
{
    char* result;

    char *buf = (char *)CacheRead(list, pos, len);
    if (list->file->flags & INSTAT_FULL_CACHE) return buf;
    if (Multipage) {
        _LnkReAlloc(char*, result, buf, len);
        _ChkAlloc(char *, TokBuff, TokSize);
        Multipage = FALSE;              // indicate that last read is permanent.
    }
    else {
        _ChkAlloc(char *, result, len);
        memcpy(result, buf, len);
    }
    return result;
}

void CacheFree(file_list* list, void* mem)
{
    if (list->file->flags & INSTAT_PAGE_CACHE) {
        _LnkFree(mem);
    }
}

#define CACHE_PAGE_SIZE         (8*1024)

static unsigned NumCacheBlocks(unsigned long len)
{
    unsigned    numblocks;

    numblocks = len / CACHE_PAGE_SIZE;
    if (len % CACHE_PAGE_SIZE != 0) {
        numblocks++;
    }
    return numblocks;
}

static bool DumpFileCache(infilelist* file, bool nuke)
{
    unsigned    num;
    unsigned    savenum;
    unsigned    index;
    char** blocklist;
    bool        blockfreed;

    blockfreed = FALSE;
    if (nuke) {
        savenum = UINT_MAX;
    }
    else {
        savenum = file->currpos / CACHE_PAGE_SIZE;
    }
    if (file->cache != nullptr) {
        num = NumCacheBlocks(file->len);
        blocklist = (char**)file->cache;
        for (index = 0; index < num; index++) {
            if (index != savenum && *blocklist != nullptr) {
                _LnkFree(*blocklist);
                *blocklist = nullptr;
                blockfreed = TRUE;
            }
            blocklist++;
        }
    }
    return blockfreed;
}

void FreeObjCache(file_list* list)
{
    if (list == nullptr) return;
    if (list->file->flags & INSTAT_FULL_CACHE) {
        _LnkFree(list->file->cache);
    }
    else {
        DumpFileCache(list->file, TRUE);
    }
    list->file->cache = nullptr;
}

bool DumpObjCache(void)
{
    infilelist* file;

    file = CachedFiles;
    while (file != nullptr) {
        if (file->flags & INSTAT_PAGE_CACHE) {
            if (CurrMod == nullptr || CurrMod->f.source == nullptr
                || CurrMod->f.source->file != file) {
                if (DumpFileCache(file, TRUE)) return TRUE;
            }
        }
        file = file->next;
    }
    return FALSE;
}

void CacheClose(file_list* list, unsigned pass)
{
    infilelist* file;
    bool        nukecache;

    if (list == nullptr) return;
    file = list->file;
    //    if( file->handle == NIL_HANDLE ) return;
    file->flags = (infile_flags)(file->flags & ~INSTAT_IN_USE);
    switch (pass) {
        case 1: /* first pass */
            nukecache = !(file->flags & INSTAT_LIBRARY);
            if (file->flags & INSTAT_FULL_CACHE) {
                if (nukecache) {
                    FreeObjCache(list);
                }
            }
            else {
                DumpFileCache(file, nukecache);   // don't cache .obj's
            }
            break;
        case 3: /* freeing structure */
            FreeObjCache(list);
            if (file->handle != NIL_HANDLE) {
                QClose(file->handle, file->name);
                file->handle = NIL_HANDLE;
            }
            break;
    }
}
