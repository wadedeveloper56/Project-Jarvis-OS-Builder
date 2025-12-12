#include "pch.h"
#include "globals.h"
#include "lsymtab.h"
#include "mem.h"
#include "symmem.h"
#include "carve.h"
#include "permdata.h"
#include "impexp.h"

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */
#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

int             (*CmpRtn)(const void*, const void*, size_t);
unsigned        NameLen;
symbol* LastSym;
static  symbol* SymList = NULL;
// not a static array to save space for watfor
static symbol** GlobalSymPtrs;
static symbol** StaticSymPtrs;

void ClearHashPointers(void)
{
    memset(GlobalSymPtrs, 0, GLOBAL_TABSIZE * sizeof(symbol*));
    memset(StaticSymPtrs, 0, STATIC_TABSIZE * sizeof(symbol*));
}

void ResetSym(void)
{
    NameLen = 0;
    SymList = NULL;
    HeadSym = NULL;
    LastSym = NULL;
    CmpRtn = _memicmp;
    GetSymBlock();
    ClearHashPointers();
}

void InitSym(void)
{
    _ChkAlloc(symbol * *,GlobalSymPtrs, GLOBAL_TABALLOC);
    _ChkAlloc(symbol * *,StaticSymPtrs, STATIC_TABALLOC);
}

void FiniSym(void)
{
    _LnkFree(GlobalSymPtrs);
    _LnkFree(StaticSymPtrs);
}

void SetSymCase(void)
{
    if (LinkFlags & CASE_FLAG) {
        CmpRtn = memcmp;
    }
    else {
        CmpRtn = _memicmp;
    }
}

static void WipeSym(symbol* sym)
{
    if (IS_SYM_IMPORTED(sym) && !(FmtData.type & MK_ELF)) {
        if (FmtData.type & MK_NOVELL) {
            if (sym->p.import != DUMMY_IMPORT_PTR) {
                _LnkFree(sym->p.import);
            }
        }
        else {
            FreeImport((dll_sym_info*)sym->p.import);
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

static void FreeSymbol(symbol* sym)
{
    WipeSym(sym);
    CarveFree(CarveSymbol, sym);
}

void CleanSym(void)
{
    symbol* sym;
    symbol* next;

    if (!(LinkFlags & INC_LINK_FLAG)) {
        for (sym = HeadSym; sym != NULL; sym = next) {
            next = sym->link;
            FreeSymbol(sym);
        }
    }
    RelSymBlock();
    ReleasePass1();
}
