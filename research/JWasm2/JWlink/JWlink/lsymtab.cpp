#include "pch.h"
#include "lsymbtab.h"
#include "ntio.h"
#include "objnode.h"
#include "mem.h"

symbol* SymList = NULL;
symbol** GlobalSymPtrs = NULL;
symbol** StaticSymPtrs = NULL;

void InitSym(void)
{
    _ChkAlloc(symbol * *,GlobalSymPtrs, GLOBAL_TABALLOC);
    _ChkAlloc(symbol * *,StaticSymPtrs, STATIC_TABALLOC);
}