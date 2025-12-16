#include "SymbolTable.h"

SymbolTable::SymbolTable(MemorySubsystem* memory)
{
	this->memory = memory;
	NameLen = 0;
	LastSym = nullptr;
	SymList = nullptr;
	GlobalSymPtrs = (symbol**)memory->AllocateMemory(GLOBAL_TABALLOC);
	StaticSymPtrs = (symbol**)memory->AllocateMemory(STATIC_TABALLOC);
}

SymbolTable::~SymbolTable()
{
	memory->FreeMemory(GlobalSymPtrs);
	memory->FreeMemory(StaticSymPtrs);
}
