#include "pch.h"
#include "globals.h"
#include "permdata.h"
#include "debug.h"
#include "strtab.h"
#include "impexp.h"
#include "ntio.h"
#include "mem.h"
#include "ring.h"

stringtable             PermStrings;
stringtable             PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
carve_t                 CarveLeader;
carve_t                 CarveModEntry;
carve_t                 CarveSymbol;
carve_t                 CarveSegData;
carve_t                 CarveClass;
carve_t                 CarveGroup;
carve_t                 CarveDLLInfo;
carve_t                 CarveExportInfo;
char* IncFileName;
incgroupdef* IncGroupDefs;
group_entry** IncGroups;
libnamelist* SavedUserLibs;
libnamelist* SavedDefLibs;

static stringtable      StoredRelocs;
static char* ReadRelocs;
static unsigned         SizeRelocs;
static char* OldExe;
static char* OldSymFile;
static void* AltDefData;
static char* IncStrTab;

#define SEG_CARVE_SIZE          (2*1024)
#define MOD_CARVE_SIZE          (5*1024)
#define SDATA_CARVE_SIZE        (16*1024)
#define SYM_CARVE_SIZE          (32*1024)

void ResetPermData(void)
{
    DEBUG((DBG_OLD, "ResetPermData() enter"));
    IncFileName = nullptr;
    IncStrTab = nullptr;
    ReadRelocs = nullptr;
    OldExe = nullptr;
    AltDefData = nullptr;
    OldSymFile = nullptr;
    IncGroupDefs = nullptr;
    IncGroups = nullptr;
    SavedUserLibs = nullptr;
    SavedDefLibs = nullptr;
    CarveClass = CarveCreate(sizeof(class_entry), 20 * sizeof(class_entry));
    CarveGroup = CarveCreate(sizeof(group_entry), 20 * sizeof(group_entry));
    CarveDLLInfo = CarveCreate(sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
    CarveExportInfo = CarveCreate(sizeof(entry_export), 20 * sizeof(entry_export));
    CarveLeader = CarveCreate(sizeof(seg_leader), SEG_CARVE_SIZE);
    CarveModEntry = CarveCreate(sizeof(mod_entry), MOD_CARVE_SIZE);
    CarveSegData = CarveCreate(sizeof(segdata), SDATA_CARVE_SIZE);
    CarveSymbol = CarveCreate(sizeof(symbol), SYM_CARVE_SIZE);
    InitStringTable(&PermStrings, TRUE);
    InitStringTable(&PrefixStrings, TRUE);
    InitStringTable(&StoredRelocs, FALSE);
}

void FreeList(void* _curr)
{
    node* curr = (node*)_curr;
    node* next_node;

    while (curr) {
        next_node = (node*)curr->next;
        _LnkFree(curr);
        curr = next_node;
    }
}

void CleanPermData(void)
{
#ifndef NDEBUG
    if (!(LinkFlags & INC_LINK_FLAG)) {
        CarveVerifyAllGone(CarveLeader, "seg_leader");
        CarveVerifyAllGone(CarveModEntry, "mod_entry");
        CarveVerifyAllGone(CarveDLLInfo, "dll_sym_info");
        CarveVerifyAllGone(CarveExportInfo, "entry_export");
        CarveVerifyAllGone(CarveSymbol, "symbol");
        CarveVerifyAllGone(CarveSegData, "segdata");
        CarveVerifyAllGone(CarveClass, "class_entry");
        CarveVerifyAllGone(CarveGroup, "group_entry");
    }
#endif
    if (LinkState & LINK_ERROR) {
        QDelete(IncFileName);
    }
    CarveDestroy(CarveLeader);
    CarveDestroy(CarveModEntry);
    CarveDestroy(CarveDLLInfo);
    CarveDestroy(CarveExportInfo);
    CarveDestroy(CarveSymbol);
    CarveDestroy(CarveSegData);
    CarveDestroy(CarveClass);
    CarveDestroy(CarveGroup);
    FiniStringTable(&PrefixStrings);
    FiniStringTable(&PermStrings);
    FiniStringTable(&StoredRelocs);
    _LnkFree(IncFileName);
    _LnkFree(IncStrTab);
    _LnkFree(ReadRelocs);
    _LnkFree(OldExe);
    _LnkFree(OldSymFile);
    _LnkFree(AltDefData);
    RingFree(&IncGroupDefs);
    _LnkFree(IncGroups);
    FreeList(SavedUserLibs);
    FreeList(SavedDefLibs);
}
