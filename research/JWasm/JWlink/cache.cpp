#include "pch.h"
#include "cache.h"
#include "Initialize.h"
#include "symmem.h"

#define CACHE_PAGE_SIZE         (8*1024)

bool Multipage;

unsigned NumCacheBlocks(unsigned long len)
{
    unsigned    numblocks;

    numblocks = len / CACHE_PAGE_SIZE;
    if (len % CACHE_PAGE_SIZE != 0) {
        numblocks++;
    }
    return numblocks;
}

bool CacheOpen(FileSubsystem* files, MemorySubsystem* memory, MessagingSubsystem* msg, file_list* list)
{
    infilelist* file;
    unsigned    numblocks;
    char** cache;

    if (list == NULL) return true;
    file = list->file;
    if (file->flags & INSTAT_IOERR) return(false);
    if (DoObjOpen(files, msg, file)) {
        file->flags |= INSTAT_IN_USE;
    }
    else {
        file->flags |= INSTAT_IOERR;
        return(false);
    }
    if (file->len == 0) {
        file->len = files->FileLength(file->handle);
        if (file->len == 0) {
            msg->LnkMsg(ERR + MSG_BAD_OBJECT, "s", file->name);
            file->flags |= INSTAT_IOERR;
            return(false);
        }
    }
    if (!(file->flags & INSTAT_SET_CACHE)) {
        if (LinkFlags & CACHE_FLAG) {
            file->flags |= INSTAT_FULL_CACHE;
        }
        else if (LinkFlags & NOCACHE_FLAG) {
            file->flags |= INSTAT_PAGE_CACHE;
        }
        else {
            if (file->flags & INSTAT_LIBRARY) {
                file->flags |= INSTAT_PAGE_CACHE;
            }
            else {
                file->flags |= INSTAT_FULL_CACHE;
            }
        }
    }
    if (file->cache == NULL) {
        if (file->flags & INSTAT_FULL_CACHE) {
            _ChkAlloc(void *, file->cache, file->len);
            if (file->currpos != 0) {
                files->Seek(file->handle, 0, SEEK_SET);
            }
            files->Read(file->handle, file->cache, file->len);
            file->currpos = file->len;
        }
        else {
            numblocks = NumCacheBlocks(file->len);
            _Pass1Alloc(memory, msg, file->cache, numblocks * sizeof(char*));
            cache = (char**)file->cache;
            while (numblocks > 0) {
                *cache = NULL;
                cache++;
                numblocks--;
            }
        }
    }
    return true;
}

void CacheClose(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned pass)
{
    infilelist* file;
    bool        nukecache;

    if (list == NULL) return;
    file = list->file;
    //    if( file->handle == NIL_HANDLE ) return;
    file->flags &= ~INSTAT_IN_USE;
    switch (pass) {
        case 1: /* first pass */
            nukecache = !(file->flags & INSTAT_LIBRARY);
            if (file->flags & INSTAT_FULL_CACHE) {
                if (nukecache) {
                    FreeObjCache(memory, list);
                }
            }
            else {
                DumpFileCache(memory, file, nukecache);   // don't cache .obj's
            }
            break;
        case 3: /* freeing structure */
            FreeObjCache(memory, list);
            if (file->handle != NIL_HANDLE) {
                files->Close(file->handle);
                file->handle = NIL_HANDLE;
            }
            break;
    }
}

void* CachePermRead(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned long pos, unsigned len)
{
    char* buf;
    char* result;

    buf = (char *)CacheRead(memory, files, list, pos, len);
    if (list->file->flags & INSTAT_FULL_CACHE) return buf;
    if (Multipage) {
        _LnkReAlloc(char*, result, buf, len);
        _ChkAlloc(char *,TokBuff, TokSize);
        Multipage = false;              // indicate that last read is permanent.
    }
    else {
        _ChkAlloc(char*, result, len);
        memcpy(result, buf, len);
    }
    return result;
}

void* CacheRead(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned long pos, unsigned len)
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
        if (pos + len > list->file->len) return NULL;
        return (char*)list->file->cache + pos;
    }
    Multipage = false;
    file = list->file;
    offset = pos % CACHE_PAGE_SIZE;
    amtread = CACHE_PAGE_SIZE - offset;
    startnum = pos / CACHE_PAGE_SIZE;
    bufnum = startnum;
    cache = (char**)file->cache;
    for (;;) {
        if (cache[bufnum] == NULL) {   // make sure page is in.
            _ChkAlloc(char*, cache[bufnum], CACHE_PAGE_SIZE);
            newpos = (unsigned long)bufnum * CACHE_PAGE_SIZE;
            if (file->currpos != newpos) {
                files->Seek(file->handle, newpos, SEEK_SET);
            }
            file->currpos = newpos + CACHE_PAGE_SIZE;
            files->Read(file->handle, cache[bufnum], CACHE_PAGE_SIZE);
        }
        if (amtread >= len) break;
        amtread += CACHE_PAGE_SIZE;     // it spans pages.
        bufnum++;
        Multipage = true;
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

bool CacheIsPerm(void)
/*****************************/
{
    return !Multipage;
}

bool CacheEnd(file_list* list, unsigned long pos)
/*********************************************************/
{
    return pos >= list->file->len;
}

void CacheFini(void)
{
}

void CacheFree(MemorySubsystem* memory, file_list* list, void* mem)
{
    if (list->file->flags & INSTAT_PAGE_CACHE) {
        _LnkFree(mem);
    }
}
bool DumpFileCache(MemorySubsystem* memory, infilelist* file, bool nuke)
{
    unsigned    num;
    unsigned    savenum;
    unsigned    index;
    char** blocklist;
    bool        blockfreed;

    blockfreed = false;
    if (nuke) {
        savenum = UINT_MAX;
    }
    else {
        savenum = file->currpos / CACHE_PAGE_SIZE;
    }
    if (file->cache != NULL) {
        num = NumCacheBlocks(file->len);
        blocklist = (char**)file->cache;
        for (index = 0; index < num; index++) {
            if (index != savenum && *blocklist != NULL) {
                _LnkFree(*blocklist);
                *blocklist = NULL;
                blockfreed = true;
            }
            blocklist++;
        }
    }
    return blockfreed;
}

void FreeObjCache(MemorySubsystem* memory,file_list* list)
{
    if (list == NULL) return;
    if (list->file->flags & INSTAT_FULL_CACHE) {
        _LnkFree(list->file->cache);
    }
    else {
        DumpFileCache(memory, list->file, true);
    }
    list->file->cache = NULL;
}

bool DumpObjCache(MemorySubsystem* memory)
{
    infilelist* file;

    file = CachedFiles;
    while (file != NULL) {
        if (file->flags & INSTAT_PAGE_CACHE) {
            if (CurrMod == NULL || CurrMod->f.source == NULL
                || CurrMod->f.source->file != file) {
                if (DumpFileCache(memory, file, true)) return true;
            }
        }
        file = file->next;
    }
    return false;
}
