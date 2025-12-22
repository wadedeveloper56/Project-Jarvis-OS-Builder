#pragma once

#include "MemorySubsystem.h"
#include "PermData.h"

void CleanLinkStruct(MemorySubsystem* memory, PermData* permData);
void FreeSegFlags(MemorySubsystem* memory, seg_flags* curr);
void FreeGroups(PermData* permData, group_entry* head);
