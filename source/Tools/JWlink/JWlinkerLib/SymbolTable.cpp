#include "pch.h"
#include "SymbolTable.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "globals.h"
#include "symmem.h"
#include "debug.h"

SymbolTable::SymbolTable(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem)
{
	this->memorySubsystem = memorySubsystem;
	GlobalSymPtrs = (symbol**)memorySubsystem->AllocateMemory(GLOBAL_TABALLOC);
	StaticSymPtrs = (symbol**)memorySubsystem->AllocateMemory(STATIC_TABALLOC);
}

SymbolTable::~SymbolTable()
{
	DEBUG((DBG_OLD, "SymbolTable destructor\n"));
	memorySubsystem->FreeMemory(GlobalSymPtrs);
	memorySubsystem->FreeMemory(StaticSymPtrs);
}

void SymbolTable::ResetSym()
{
	NameLen = 0;
	SymList = NULL;
	HeadSym = NULL;
	LastSym = NULL;
	CmpRtn = _memicmp;
	GetSymBlock();
	ClearHashPointers();
}

void SymbolTable::ClearHashPointers()
{
	memset(GlobalSymPtrs, 0, GLOBAL_TABSIZE * sizeof(symbol*));
	memset(StaticSymPtrs, 0, STATIC_TABSIZE * sizeof(symbol*));
}

void SymbolTable::SetSymCase()
{
	CmpRtn = _memicmp;
}
