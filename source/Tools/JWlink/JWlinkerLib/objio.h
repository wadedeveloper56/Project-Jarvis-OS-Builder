#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"
#include "Structs.h"

using namespace std;

extern infilelist* CachedLibFiles;
extern infilelist* CachedFiles;

void ResetObjIO(void);
infilelist* AllocEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path);
infilelist* AllocFileEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path);
infilelist* AllocUniqueFileEntry(MemorySubsystem *memorySubsystem, char* name, path_entry* path);
bool CleanCachedHandles(void);
#define LIB_SEARCH (INSTAT_USE_LIBPATH | INSTAT_LIBRARY)
f_handle PathObjOpen(char* path_ptr, char* name, char* new_name, infilelist* list);
f_handle TrySearchingLib(char* name, char* new_name, infilelist* list);
bool DoObjOpen(infilelist* list);
uint16_t CalcAlign(uint32_t pos, uint16_t align);
void InitTokBuff(MemorySubsystem *memorySubsystem);
void FreeTokBuffs(MemorySubsystem *memorySubsystem);
void BadObject(void);
void EarlyEOF(shared_ptr<MessagingSubsystem> messagingSubsystem);
