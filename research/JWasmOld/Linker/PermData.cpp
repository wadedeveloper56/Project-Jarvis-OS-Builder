#include "pch.h"
#include "PermData.h"
#include "globals.h"
#include "LinkerUtils.h"

PermData::PermData(MemorySubsystem* memory, Ring* ring, Carve* carve, StringTable* strtab)
{
	this->memory = memory;
	this->ring = ring;
	this->carve = carve;
    this->strtab = strtab;
}

PermData::~PermData()
{
}

entry_export* PermData::FreeAnExport(entry_export* exp)
{
    entry_export* next;

    _LnkFree(exp->impname);
    next = exp->next;
    carve->CarveFree(CarveExportInfo, exp);
    return(next);
}

void PermData::FreeSymbol(symbol* sym)
{
    carve->CarveFree(CarveSymbol, sym);
}

void PermData::Reset(void)
{
    IncFileName = NULL;
    IncStrTab = NULL;
    ReadRelocs = NULL;
    OldExe = NULL;
    AltDefData = NULL;
    OldSymFile = NULL;
    IncGroupDefs = NULL;
    IncGroups = NULL;
    SavedUserLibs = NULL;
    SavedDefLibs = NULL;
    CarveClass = carve->CarveCreate(sizeof(class_entry), 20 * sizeof(class_entry));
    CarveGroup = carve->CarveCreate(sizeof(group_entry), 20 * sizeof(group_entry));
    CarveDLLInfo = carve->CarveCreate(sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
    CarveExportInfo = carve->CarveCreate(sizeof(entry_export), 20 * sizeof(entry_export));
    CarveLeader = carve->CarveCreate(sizeof(seg_leader), SEG_CARVE_SIZE);
    CarveModEntry = carve->CarveCreate(sizeof(mod_entry), MOD_CARVE_SIZE);
    CarveSegData = carve->CarveCreate(sizeof(segdata), SDATA_CARVE_SIZE);
    CarveSymbol = carve->CarveCreate(sizeof(symbol), SYM_CARVE_SIZE);
    strtab->InitStringTable(&PermStrings, true);
    strtab->InitStringTable(&PrefixStrings, true);
    strtab->InitStringTable(&StoredRelocs, false);
}

void PermData::CleanPermData(void)
{
#ifndef NDEBUG
    if (!(LinkFlags & INC_LINK_FLAG)) {
        carve->CarveVerifyAllGone(CarveLeader, "seg_leader");
        carve->CarveVerifyAllGone(CarveModEntry, "mod_entry");
        carve->CarveVerifyAllGone(CarveDLLInfo, "dll_sym_info");
        carve->CarveVerifyAllGone(CarveExportInfo, "entry_export");
        carve->CarveVerifyAllGone(CarveSymbol, "symbol");
        carve->CarveVerifyAllGone(CarveSegData, "segdata");
        carve->CarveVerifyAllGone(CarveClass, "class_entry");
        carve->CarveVerifyAllGone(CarveGroup, "group_entry");
    }
#endif
    if (LinkState & LINK_ERROR) {
        //FOX ME QDelete(IncFileName);
    }
    carve->CarveDestroy(CarveLeader);
    carve->CarveDestroy(CarveModEntry);
    carve->CarveDestroy(CarveDLLInfo);
    carve->CarveDestroy(CarveExportInfo);
    carve->CarveDestroy(CarveSymbol);
    carve->CarveDestroy(CarveSegData);
    carve->CarveDestroy(CarveClass);
    carve->CarveDestroy(CarveGroup);
    strtab->FiniStringTable(&PrefixStrings);
    strtab->FiniStringTable(&PermStrings);
    strtab->FiniStringTable(&StoredRelocs);
    _LnkFree(IncFileName);
    _LnkFree(IncStrTab);
    _LnkFree(ReadRelocs);
    _LnkFree(OldExe);
    _LnkFree(OldSymFile);
    _LnkFree(AltDefData);
    ring->RingFree(&IncGroupDefs);
    _LnkFree(IncGroups);
    FreeList(memory, SavedUserLibs);
    FreeList(memory, SavedDefLibs);
}

void PermData::FreeAGroup(group_entry* group)
{
    carve->CarveFree(CarveGroup, group);
}

void PermData::FreeImport(dll_sym_info* dll)
{
    carve->CarveFree(CarveDLLInfo, dll);
}

static PermData* permDataLocal;

static void FreeLeaderLocal(void* curr)
{
    permDataLocal->FreeLeader(curr);
}

void PermData::FreeClasses(class_entry* list)
{
    class_entry* next;

    while (list != NULL) {
        next = list->next_class;
        permDataLocal = this;
        ring->RingWalk(list->segs, FreeLeaderLocal);
        carve->CarveFree(CarveClass, list);
        list = next;
    }
}

void PermData::FreeModEntry(mod_entry* mod)
{
    carve->CarveFree(CarveModEntry, mod);
}

static void FreeSegDataLocal(void* curr)
{
    permDataLocal->FreeSegData(curr);
}

void PermData::FreeLeader(void* seg)
{
    permDataLocal = this;
    ring->RingWalk(((seg_leader*)seg)->pieces, FreeSegDataLocal);
    carve->CarveFree(CarveLeader, seg);
}

void PermData::FreeSegData(void* sdata)
{
    carve->CarveFree(CarveSegData, sdata);
}