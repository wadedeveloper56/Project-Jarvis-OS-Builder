#pragma once

#include "MemorySubsystem.h"
#include "globals.h"
#include "SymbolTableMemory.h"
#include "PermData.h"

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

class SymbolTable
{
	int (*CmpRtn)(const void*, const void*, size_t);
	unsigned NameLen;
	symbol* LastSym;
	symbol* SymList;
	symbol** GlobalSymPtrs;
	symbol** StaticSymPtrs;
	MemorySubsystem* memory;
	PermData* permData;
public:
	SymbolTableMemory* symMem;
	SymbolTable(MemorySubsystem* memory, PermData* permData);
	~SymbolTable();
	void ResetSym(void);
	void ClearHashPointers(void);
	void SetSymCase(void);
	void CleanSym(void);
	void FreeSymbol(symbol* sym);
	void WipeSym(symbol* sym);
};

