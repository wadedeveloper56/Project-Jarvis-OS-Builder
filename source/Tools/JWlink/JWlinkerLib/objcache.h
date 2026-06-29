#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

bool CacheOpen(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list);
void CacheClose(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list, unsigned pass);
void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void* CacheRead(file_list* list, unsigned long pos, unsigned len);
bool CacheEnd(file_list* list, unsigned long pos);
void CacheFini(void);
void CacheFree(file_list* list, void* blk);
void FreeObjCache(file_list* list);
bool DumpObjCache(void);
