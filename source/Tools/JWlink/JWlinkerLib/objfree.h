#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "SpillFile.h"

using namespace std;

void FiniLinkStruct(MemorySubsystem *memorySubsystem);
void FreeFiles(MemorySubsystem *memorySubsystem, file_list* list);
void CleanLinkStruct(MemorySubsystem *memorySubsystem, SpillFile * spillFile);
void FreeAGroup(group_entry* group);
void FreeGroups(group_entry* head);
void FreeSections(MemorySubsystem *memorySubsystem, section* sec);
void FreeClasses(class_entry* list);
void FreeAreas(MemorySubsystem *memorySubsystem, OVL_AREA* area);
void FreeAMod(mod_entry* mod);
#if defined(_OS2) || defined( _QNXLOAD )
void FreeSegFlags(MemorySubsystem *memorySubsystem, seg_flags* curr);
#endif
void FreeObjInfo();
