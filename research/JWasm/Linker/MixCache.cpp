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
                this->file->Seek(newpos,SEEK_SET);
            }
            file->currpos = newpos + CACHE_PAGE_SIZE;
            this->file->Read(cache[bufnum], CACHE_PAGE_SIZE, 1);
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

