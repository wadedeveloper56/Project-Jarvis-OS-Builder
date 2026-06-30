#pragma once

#include "MemorySubsystem.h"
#include "SymbolTable.h"
#include "Structs.h"

using namespace std;

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

class SymbolTable
{
    int (*CmpRtn)(const void*, const void*, size_t);
	MemorySubsystem *memorySubsystem;
	symbol* SymList;
	symbol** GlobalSymPtrs;
	symbol** StaticSymPtrs;
	/* this var holds the value of the NAMELEN option */
	unsigned        NameLen;
	symbol* LastSym;
public:
	SymbolTable(MemorySubsystem *memorySubsystem);
	~SymbolTable();
	void ResetSym();
	void ClearHashPointers();
	void SetSymCase();
};

