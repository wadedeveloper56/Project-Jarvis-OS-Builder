#include "pch.h"
#include "distrib.h"
#include "structs.h"

uint16_t  CurrModThere;
arcdata* ArcBuffer;
uint32_t  ArcBufLen;
mod_entry** ModTable;
uint16_t  CurrModHandle;
section** SectOvlTab;

#define MOD_DEREF( x )  (ModTable[(x)])
#define INITIAL_MOD_ALLOC 32
#define INITIAL_ARC_ALLOC 32
#define MAX_NUM_MODULES   (8 * 1024)

void ResetDistrib()
{
    ArcBuffer = NULL;
    ModTable = NULL;
    SectOvlTab = NULL;
}