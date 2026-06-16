#include "pch.h"
#include "SymbolTable.h"
#include "MemorySubsystem.h"
#include "Structs.h"

SymbolTable::SymbolTable(shared_ptr<MemorySubsystem> memorySubsystem): memorySubsystem(memorySubsystem)
{
	this->memorySubsystem = memorySubsystem;
	GlobalSymPtrs = (symbol**)memorySubsystem->AllocateMemory(GLOBAL_TABALLOC);
	StaticSymPtrs = (symbol**)memorySubsystem->AllocateMemory(STATIC_TABALLOC);
}

SymbolTable::~SymbolTable()
{
	memorySubsystem->FreeMemory(GlobalSymPtrs);
	memorySubsystem->FreeMemory(StaticSymPtrs);
}
