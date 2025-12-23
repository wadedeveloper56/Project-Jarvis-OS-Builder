#include "pch.h"
#include "globals.h"
#include "distrib.h"

static unsigned_16  CurrModThere;
static arcdata* ArcBuffer;
static unsigned_32  ArcBufLen;
static mod_entry** ModTable;
static unsigned_16  CurrModHandle;
section** SectOvlTab;

void ResetDistrib(void)
{
    ArcBuffer = nullptr;
    ModTable = nullptr;
    SectOvlTab = nullptr;
}

void FreeDistStuff(MemorySubsystem* memory,PermData* permData, MixCache* cache, SymbolTableMemory *symMem)
{
    unsigned    index;

    for (index = 1; index <= CurrModHandle; index++) {
        FreeAMod(permData, cache, ModTable[index]);
    }
    _LnkFree(ModTable);
    _LnkFree(ArcBuffer);
    _LnkFree(SectOvlTab);
    symMem->ReleasePass1();
}
