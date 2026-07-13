#pragma once

#include "MemorySubsystem.h"
#include "SymbolTable.h"
#include "Structs.h"

using namespace std;

class SymbolTable
{
	MemorySubsystem *memorySubsystem;
public:
	SymbolTable(MemorySubsystem *memorySubsystem);
	~SymbolTable();
};

