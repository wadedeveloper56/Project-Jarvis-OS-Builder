#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "obj.h"

extern infilelist* CachedFiles;
unsigned NumCacheBlocks(unsigned long len);
bool CacheOpen(FileSubsystem* files, MemorySubsystem* memory, MessagingSubsystem* msg, file_list* list);
void CacheClose(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned pass);
void* CachePermRead(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned long pos, unsigned len);
void* CacheRead(MemorySubsystem* memory, FileSubsystem* files, file_list* list, unsigned long pos, unsigned len);
bool CacheIsPerm(void);
bool CacheEnd(file_list* list, unsigned long pos);
void CacheFini(void);
void CacheFree(MemorySubsystem* memory, file_list* list, void* mem);
bool DumpFileCache(MemorySubsystem* memory, infilelist* file, bool nuke);
void FreeObjCache(MemorySubsystem* memory, file_list* list);
bool DumpObjCache(MemorySubsystem* memory);


