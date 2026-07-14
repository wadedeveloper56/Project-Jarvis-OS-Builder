#include "pch.h"
#include "SymbolTable.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "debug.h"

SymbolTable::SymbolTable(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem)
{
	DEBUG((DBG_OLD, "SymbolTable constructor\n"));
	_ChkAlloc(symbol**, GlobalSymPtrs, GLOBAL_TABALLOC);
	_ChkAlloc(symbol**, StaticSymPtrs, STATIC_TABALLOC);
}

SymbolTable::~SymbolTable()
{
	DEBUG((DBG_OLD, "SymbolTable destructor\n"));
	_LnkFree(GlobalSymPtrs);
	_LnkFree(StaticSymPtrs);
}
