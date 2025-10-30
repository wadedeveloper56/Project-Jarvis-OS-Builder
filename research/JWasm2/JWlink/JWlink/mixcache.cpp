#include "pch.h"
#include "objnode.h"
#include "mem.h"
#include "ntio.h"

#define CACHE_PAGE_SIZE         (8*1024)

static bool     Multipage;
unsigned       TokSize;
char* TokBuff;

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
				QSeek(file->handle, newpos, file->name);
			}
			file->currpos = newpos + CACHE_PAGE_SIZE;
			QRead(file->handle, cache[bufnum], CACHE_PAGE_SIZE, file->name);
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
			_LnkReAlloc(char*, TokBuff, TokBuff, TokSize);
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
	char* buf;
	char* result;

	buf = (char*)CacheRead(list, pos, len);
	if (list->file->flags & INSTAT_FULL_CACHE) return buf;
	if (Multipage) {
		_LnkReAlloc(char*, result, buf, len);
		_ChkAlloc(char*, TokBuff, TokSize);
		Multipage = true;              // indicate that last read is permanent.
	}
	else {
		_ChkAlloc(char*, result, len);
		memcpy(result, buf, len);
	}
	return result;
}
