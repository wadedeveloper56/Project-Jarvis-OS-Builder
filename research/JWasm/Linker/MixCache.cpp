#include "pch.h"
#include "MixCache.h"
#include "FileSubsystem.h"
#include "TokenBuffer.h"

MixCache::MixCache(MemorySubsystem* memory, FileSubsystem* file, TokenBuffer* tokenBuffer)
{
    this->memory = memory;
	this->file = file;
	this->tokenBuffer = tokenBuffer;
	Multipage = false;
}

MixCache::~MixCache()
{
}

void* MixCache::CachePermRead(file_list* list, unsigned long pos, size_t len)
{
    char* result;

    char *buf = (char*)CacheRead(list, pos, len);
    if (list->file->flags & INSTAT_FULL_CACHE) return buf;
    if (Multipage) {
        result = (char*)memory->ReallocateMemory(buf, len);
        //_ChkAlloc(TokBuff, TokSize);
        Multipage = false;              // indicate that last read is permanent.
    }
    else {
        result = (char *)memory->AllocateMemory(len);
        memcpy(result, buf, len);
    }
    return result;
}

void* MixCache::CacheRead(file_list* list, unsigned long pos, size_t len)
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
            cache[bufnum] = (char*)memory->AllocateMemory(CACHE_PAGE_SIZE);
            newpos = (unsigned long)bufnum * CACHE_PAGE_SIZE;
            if (file->currpos != newpos) {
                this->file->Seek(file->handle,newpos,SEEK_SET);
            }
            file->currpos = newpos + CACHE_PAGE_SIZE;
            this->file->Read(file->handle, cache[bufnum], CACHE_PAGE_SIZE, 1);
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
        if (len > tokenBuffer->GetSize()) {
            tokenBuffer->Reallocate(ROUND_UP(len, SECTOR_SIZE));
        }
        amtread = CACHE_PAGE_SIZE - offset;
        memcpy(tokenBuffer->GetBuffer(), cache[startnum] + offset, amtread);
        len -= amtread;
        result = tokenBuffer->GetBuffer() + amtread;
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
        result = tokenBuffer->GetBuffer();
    }
    return result;
}

unsigned MixCache::NumCacheBlocks(unsigned long len)
{
    unsigned    numblocks;

    numblocks = len / CACHE_PAGE_SIZE;
    if (len % CACHE_PAGE_SIZE != 0) {
        numblocks++;
    }
    return numblocks;
}

bool MixCache::DumpFileCache(infilelist* file, bool nuke)
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

void MixCache::FreeObjCache(file_list* list)
{
    if (list == NULL) return;
    if (list->file->flags & INSTAT_FULL_CACHE) {
        _LnkFree(list->file->cache);
    }
    else {
        DumpFileCache(list->file, true);
    }
    list->file->cache = NULL;
}

void MixCache::CacheClose(file_list* list, unsigned pass)
{
    infilelist* file;
    bool        nukecache;

    if (list == NULL) return;
    file = list->file;
    //    if( file->handle == NIL_HANDLE ) return;
    file->flags =  (infile_flags)(file->flags & ~INSTAT_IN_USE);
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
                this->file->Close(file->handle);
                file->handle = NIL_HANDLE;
            }
            break;
    }
}

void MixCache::CacheFree(file_list* list, void* mem)
{
    if (list->file->flags & INSTAT_PAGE_CACHE) {
        _LnkFree(mem);
    }
}

