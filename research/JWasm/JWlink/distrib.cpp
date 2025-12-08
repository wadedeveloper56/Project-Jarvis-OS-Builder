#include "pch.h"
#include "globals.h"
#include "alloc.h"
#include "objfree.h"
#include "symmem.h"

static unsigned_16  CurrModThere;
static arcdata* ArcBuffer;
static unsigned_32  ArcBufLen;
static mod_entry** ModTable;
static unsigned_16  CurrModHandle;
section** SectOvlTab;

void FreeDistStuff(void)
{
    unsigned    index;

    for (index = 1; index <= CurrModHandle; index++) {
        FreeAMod(ModTable[index]);
    }
    _LnkFree(ModTable);
    _LnkFree(ArcBuffer);
    _LnkFree(SectOvlTab);
    ReleasePass1();
}
