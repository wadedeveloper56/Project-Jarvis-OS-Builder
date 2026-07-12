#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"

extern char* SymFileName;
extern group_entry* DBIGroups;

void ResetDBI();
void DBISectCleanup(MemorySubsystem *memorySubsystem,section* sect);
void DBIInit(MemorySubsystem* memorySubsystem);
