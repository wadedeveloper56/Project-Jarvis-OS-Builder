#pragma once

#include "Structs.h"
#include "MemorySubsystem.h"

void ResetCmdAll();
file_list* AllocNewFile(MemorySubsystem* memorySubsystem, member_list* member);
file_list* AddObjLib(MemorySubsystem* memorySubsystem, char* name, lib_priority priority);
