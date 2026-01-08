#pragma once

#include "globals.h"
#include "obj.h"

extern infilelist* CachedFiles;
unsigned NumCacheBlocks(unsigned long len);
bool CacheOpen(file_list* list);
void CacheClose(file_list* list, unsigned pass);
void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void* CacheRead(file_list* list, unsigned long pos, unsigned len);
bool CacheIsPerm(void);
bool CacheEnd(file_list* list, unsigned long pos);
void CacheFini(void);
void CacheFree(file_list* list, void* mem);
bool DumpFileCache(infilelist* file, bool nuke);
void FreeObjCache(file_list* list);
bool DumpObjCache();


