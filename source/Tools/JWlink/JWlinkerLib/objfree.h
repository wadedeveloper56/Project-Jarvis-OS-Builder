#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void FiniLinkStruct(shared_ptr<MemorySubsystem> memorySubsystem);
void FreeFiles(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list);
void CleanLinkStruct(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile);
void FreeAGroup(group_entry* group);
void FreeGroups(group_entry* head);
void FreeSections(shared_ptr<MemorySubsystem> memorySubsystem, section* sec);
void FreeClasses(class_entry* list);
void FreeAreas(shared_ptr<MemorySubsystem> memorySubsystem, OVL_AREA* area);
void FreeAMod(mod_entry* mod);
