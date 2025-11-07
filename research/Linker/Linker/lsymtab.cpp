#include "pch.h"
#include "walloca.h"
#include "linkstd.h"
#include "pcobj.h"
#include "objio.h"
#include "alloc.h"
#include "newmem.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "wcomdef.h"
#include "mapio.h"
#include "impexp.h"
#include "objstrip.h"
#include "objpass1.h"
#include "ring.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "nwpfx.h"
#include "command.h"
#include "symtab.h"

#define STATIC_TABSIZE  241  /* should be prime */
#define GLOBAL_TABSIZE  1789  /* should be prime */

#define STATIC_TABALLOC (256 * sizeof(symbol *))  // 1st power of 128 > TABSIZE
#define GLOBAL_TABALLOC (1792 * sizeof(symbol *)) // 1st power of 128 > TABSIZE

static symbol** GlobalSymPtrs;
static symbol** StaticSymPtrs;
static  symbol* SymList = NULL;
unsigned        NameLen;
symbol* LastSym;
int             (*CmpRtn)(const void*, const void*, size_t);

void InitSym(void)
{
	_ChkAlloc(symbol**, GlobalSymPtrs, GLOBAL_TABALLOC);
	_ChkAlloc(symbol**, StaticSymPtrs, STATIC_TABALLOC);
}

void FiniSym(void)
{
	_LnkFree(GlobalSymPtrs);
	_LnkFree(StaticSymPtrs);
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

void SetSymCase(void)
{
    if (LinkFlags & CASE_FLAG) {
        CmpRtn = memcmp;
    }
    else {
        CmpRtn = _memicmp;
    }
}

void ClearHashPointers(void)
{
    memset(GlobalSymPtrs, 0, GLOBAL_TABSIZE * sizeof(symbol*));
    memset(StaticSymPtrs, 0, STATIC_TABSIZE * sizeof(symbol*));
}
