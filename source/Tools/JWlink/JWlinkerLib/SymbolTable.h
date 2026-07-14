#pragma once

#include "MemorySubsystem.h"
#include "SymbolTable.h"
#include "Structs.h"

using namespace std;

#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

class SymbolTable
{
	MemorySubsystem *memorySubsystem;
	symbol** GlobalSymPtrs;
	symbol** StaticSymPtrs;
public:
	SymbolTable(MemorySubsystem *memorySubsystem);
	~SymbolTable();
};

