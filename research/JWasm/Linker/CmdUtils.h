#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "HashTable.h"

section* NewSection(MemorySubsystem* memory, HashTable* hashTable);
