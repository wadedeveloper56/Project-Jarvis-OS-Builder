#include "pch.h"
#include "globals.h"
#include "lsymtab.h"
#include "mem.h"
#include "symmem.h"

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
