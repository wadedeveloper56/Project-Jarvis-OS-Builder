#include "pch.h"
#include "SymbolTable.h"

SymbolTable::SymbolTable(MemorySubsystem* memory, PermData* permData)
{
	this->memory = memory;
	this->permData = permData;
	this->symMem = new SymbolTableMemory(memory);
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

void SymbolTable::WipeSym(symbol* sym)
{
	if (IS_SYM_IMPORTED(sym) && !(FmtData.type & MK_ELF)) {
		if (FmtData.type & MK_NOVELL) {
			if (sym->p.import != DUMMY_IMPORT_PTR) {
				_LnkFree(sym->p.import);
			}
		}
		else {
			permData->FreeImport((dll_sym_info*)sym->p.import);
		}
		sym->p.import = NULL;
	}
	else if (IS_SYM_ALIAS(sym)) {
		if (sym->info & SYM_FREE_ALIAS) {
			_LnkFree(sym->p.alias);
		}
		sym->u.aliaslen = 0;    // make sure this is nulled again
	}
}

void SymbolTable::FreeSymbol(symbol* sym)
{
	WipeSym(sym);
	permData->FreeSymbol(sym);
}

void SymbolTable::CleanSym(void)
{
	symbol* sym;
	symbol* next;

	if (!(LinkFlags & INC_LINK_FLAG)) {
		for (sym = HeadSym; sym != NULL; sym = next) {
			next = sym->link;
			FreeSymbol(sym);
		}
	}
	symMem->RelSymBlock();
	symMem->ReleasePass1();
}

