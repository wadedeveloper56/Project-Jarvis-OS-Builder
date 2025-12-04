#include "pch.h"
#include "lsymtab.h"
#include "alloc.h"
#include "syms.h"

static symbol** GlobalSymPtrs;
static symbol** StaticSymPtrs;

void InitSym(void)
{
    _ChkAlloc(symbol * *, GlobalSymPtrs, GLOBAL_TABALLOC);
    _ChkAlloc(symbol * *, StaticSymPtrs, STATIC_TABALLOC);
}

void FiniSym(void)
{
    _LnkFree(GlobalSymPtrs);
    _LnkFree(StaticSymPtrs);
}