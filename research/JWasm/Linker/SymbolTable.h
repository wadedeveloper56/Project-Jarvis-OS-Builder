#pragma once

#include "MemorySubsystem.h"
#include "globals.h"

#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

class SymbolTable
{
	unsigned NameLen;
	symbol* LastSym;
	symbol* SymList;
	symbol** GlobalSymPtrs;
	symbol** StaticSymPtrs;
	MemorySubsystem* memory;
public:
	SymbolTable(MemorySubsystem* memory);
	~SymbolTable();
};

