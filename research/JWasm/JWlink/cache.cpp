#include "pch.h"
#include "cache.h"
#include "Initialize.h"

unsigned NumCacheBlocks(unsigned long len)
{
	unsigned    numblocks;

	numblocks = len / CACHE_PAGE_SIZE;
	if (len % CACHE_PAGE_SIZE != 0) {
		numblocks++;
	}
	return numblocks;
}

void* CachePermRead(file_list* list, unsigned long pos, unsigned len)
{
	return CacheRead(list, pos, len);
}

void* CacheRead(file_list* list, unsigned long pos, unsigned len)
{
	if (pos + len > list->file->len) return NULL;
	return (char*)list->file->cache + pos;
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

void CacheClose(FileSubsystem* files, MemorySubsystem* memory, file_list* list, unsigned pass)
{
	infilelist* file;
	bool        nukecache;

	if (list == NULL) return;
	file = list->file;
	//    if( file->handle == NIL_HANDLE ) return;
	file->flags = (infile_flags)(file->flags & ~INSTAT_IN_USE);
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

