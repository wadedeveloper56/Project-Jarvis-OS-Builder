#include "pch.h"
#include "lsymtab.h"
#include "Structs.h"
#include "carve.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "objfree.h"
#include "impexp.h"
#include "symmem.h"

using namespace std;

void WipeSym(MemorySubsystem* memorySubsystem, symbol* sym)
{
    if (IS_SYM_IMPORTED(sym) && !(FmtData.type & MK_ELF))
    {
        if (FmtData.type & MK_NOVELL)
        {
            if (sym->p.import != DUMMY_IMPORT_PTR)
            {
                _LnkFree(sym->p.import);
            }
        }
        else
        {
            FreeImport((dll_sym_info*)sym->p.import);
        }
        sym->p.import = NULL;
    }
    else if (IS_SYM_ALIAS(sym))
    {
        if (sym->info & SYM_FREE_ALIAS)
        {
            _LnkFree(sym->p.alias);
        }
        sym->u.aliaslen = 0;          
    }
}

void FreeSymbol(MemorySubsystem* memorySubsystem, symbol* sym)
{
    WipeSym(memorySubsystem, sym);
    CarveFree(CarveSymbol, sym);
}

void CleanSym(MemorySubsystem* memorySubsystem)
{
    symbol* sym;
    symbol* next;

#ifdef _INT_DEBUG
    DumpHashTable();
#endif
    if (!(LinkFlags & INC_LINK_FLAG))
    {
        for (sym = HeadSym; sym != NULL; sym = next)
        {
            next = sym->link;
            FreeSymbol(memorySubsystem, sym);
        }
    }
    RelSymBlock(memorySubsystem);
    ReleasePass1(memorySubsystem);
}


