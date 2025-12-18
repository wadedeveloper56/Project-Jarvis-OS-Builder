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
