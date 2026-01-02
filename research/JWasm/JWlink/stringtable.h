#pragma once

#include "globals.h"
#include "MemorySubsystem.h"

void InitStringTable(MemorySubsystem* memory,stringtable* strtab, bool dontsplit);
void FiniStringTable(MemorySubsystem* memory, stringtable* strtab);
