#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "TokenBuffer.h"

#define CACHE_PAGE_SIZE         (8*1024)
#define ROUND_UP( x, r )        (((x)+((r)-1))&~((r)-1))
#define SECTOR_SIZE     512

class MixCache
{
	bool Multipage;
	MemorySubsystem* memory;
	FileSubsystem* file;
	TokenBuffer* tokenBuffer;
public:
	MixCache(MemorySubsystem* memory, FileSubsystem* file, TokenBuffer* tokenBuffer);
	~MixCache();
	void* CachePermRead(file_list* list, unsigned long pos, size_t len);
	void* CacheRead(file_list* list, unsigned long pos, size_t len);
	bool DumpFileCache(infilelist* file, bool nuke);
	void FreeObjCache(file_list* list);
	unsigned NumCacheBlocks(unsigned long len);
	void CacheClose(file_list* list, unsigned pass);
	void CacheFree(file_list* list, void* mem);
};

