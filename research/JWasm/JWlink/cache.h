#pragma once

#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"

void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void* CacheRead(file_list* list, unsigned long pos, unsigned len);
void CacheFini(void);
void CacheFree(MemorySubsystem* memory, file_list* list, void* mem);
void CacheClose(FileSubsystem* files, MemorySubsystem* memory, file_list* list, unsigned pass);
unsigned NumCacheBlocks(unsigned long len);
