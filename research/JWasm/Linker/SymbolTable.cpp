#include "pch.h"
#include "SymbolTable.h"

SymbolTable::SymbolTable(MemorySubsystem* memory)
{
	this->memory = memory;
	this->symMem = new SymbolTableMemory();
	NameLen = 0;
	LastSym = nullptr;
	SymList = nullptr;
	CmpRtn = nullptr;
	_ChkAlloc(symbol**, GlobalSymPtrs, GLOBAL_TABALLOC);
	_ChkAlloc(symbol**, StaticSymPtrs, STATIC_TABALLOC);
}

SymbolTable::~SymbolTable()
{
	delete symMem;
	_LnkFree(GlobalSymPtrs);
	_LnkFree(StaticSymPtrs);
}

void SymbolTable::ClearHashPointers(void)
{
	memset(GlobalSymPtrs, 0, GLOBAL_TABSIZE * sizeof(symbol*));
	memset(StaticSymPtrs, 0, STATIC_TABSIZE * sizeof(symbol*));
}

void SymbolTable::SetSymCase(void)
{
	if (LinkFlags & CASE_FLAG) {
		CmpRtn = memcmp;
	}
	else {
		CmpRtn = _memicmp;
	}
}

void SymbolTable::ResetSym(void)
{
	NameLen = 0;
	SymList = nullptr;
	HeadSym = nullptr;
	LastSym = nullptr;
	CmpRtn = _memicmp;
	ClearHashPointers();
}