#include "pch.h"
#include "SymbolTable.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "debug.h"

SymbolTable::SymbolTable(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem)
{
	DEBUG((DBG_OLD, "SymbolTable constructor\n"));
}

SymbolTable::~SymbolTable()
{
	DEBUG((DBG_OLD, "SymbolTable destructor\n"));
}
