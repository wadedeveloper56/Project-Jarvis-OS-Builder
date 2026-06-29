#pragma once

#include <memory>
#include "Structs.h"
#include "MemorySubsystem.h"

using namespace std;

void InitStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, bool dontsplit);
char* AddToStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, void* data, unsigned len, bool addnullchar);
void AddCharStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char data);
char* AddStringStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char* data);
char* AddBufferStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, void* data, unsigned len);
char* AddSymbolStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, char* data, unsigned len);
