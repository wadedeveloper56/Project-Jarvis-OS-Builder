#pragma once

#include "MemorySubsystem.h"
#include "PermData.h"
#include "MixCache.h"

void BurnLibs(MemorySubsystem* memory, MixCache* cache);
void FreeSections(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache, section* sec);
void FreeAreas(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache, OVL_AREA* area);
void FreeAMod(PermData* permData, MixCache* cache, mod_entry* mod);
void FreeMods(PermData* permData, MixCache* cache, mod_entry* head);
void FreeFiles(MemorySubsystem* memory, MixCache* cache, file_list* list);
void CleanLinkStruct(MemorySubsystem* memory, PermData* permData, HashTable* hashTable, MixCache* cache);
void FreeSegFlags(MemorySubsystem* memory, seg_flags* curr);
void FreeGroups(PermData* permData, group_entry* head);
