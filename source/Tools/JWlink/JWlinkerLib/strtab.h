#pragma once

#include <memory>
#include "Structs.h"
#include "MemorySubsystem.h"

using namespace std;

void InitStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, bool dontsplit);
char* AddToStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, void* data, unsigned len, bool addnullchar);
void AddCharStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, char data);
char* AddStringStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, char* data);
char* AddBufferStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, void* data, unsigned len);
char* AddSymbolStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab, char* data, unsigned len);
void FiniStringTable(MemorySubsystem *memorySubsystem, stringtable* strtab);
