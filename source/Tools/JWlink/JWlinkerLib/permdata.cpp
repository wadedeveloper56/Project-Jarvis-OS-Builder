#include "pch.h"
#include "permdata.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "carve.h"
#include "strtab.h"
#include "ring.h"
#include "globals.h"
#include "ntio.h"
#include "linkutil.h"
#include "permdata.h"
#include "strtab.h"

using namespace std;

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

void ResetPermData(MemorySubsystem* memorySubsystem)
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
	CarveClass = CarveCreate(memorySubsystem, sizeof(class_entry), 20 * sizeof(class_entry));
	CarveGroup = CarveCreate(memorySubsystem, sizeof(group_entry), 20 * sizeof(group_entry));
	CarveDLLInfo = CarveCreate(memorySubsystem, sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
	CarveExportInfo = CarveCreate(memorySubsystem, sizeof(entry_export), 20 * sizeof(entry_export));
	CarveLeader = CarveCreate(memorySubsystem, sizeof(seg_leader), SEG_CARVE_SIZE);
	CarveModEntry = CarveCreate(memorySubsystem, sizeof(mod_entry), MOD_CARVE_SIZE);
	CarveSegData = CarveCreate(memorySubsystem, sizeof(segdata), SDATA_CARVE_SIZE);
	CarveSymbol = CarveCreate(memorySubsystem, sizeof(symbol), SYM_CARVE_SIZE);
	InitStringTable(memorySubsystem, &PermStrings, true);
	InitStringTable(memorySubsystem, &PrefixStrings, true);
	InitStringTable(memorySubsystem, &StoredRelocs, false);
}

void CleanPermData(MemorySubsystem* memorySubsystem)
{
#ifndef NDEBUG
	if (!(LinkFlags & INC_LINK_FLAG))
	{
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
	if (LinkState & LINK_ERROR)
	{
		QDelete(IncFileName);
	}
	CarveDestroy(memorySubsystem, CarveLeader);
	CarveDestroy(memorySubsystem, CarveModEntry);
	CarveDestroy(memorySubsystem, CarveDLLInfo);
	CarveDestroy(memorySubsystem, CarveExportInfo);
	CarveDestroy(memorySubsystem, CarveSymbol);
	CarveDestroy(memorySubsystem, CarveSegData);
	CarveDestroy(memorySubsystem, CarveClass);
	CarveDestroy(memorySubsystem, CarveGroup);
	FiniStringTable(memorySubsystem, &PrefixStrings);
	FiniStringTable(memorySubsystem, &PermStrings);
	FiniStringTable(memorySubsystem, &StoredRelocs);
	_LnkFree(IncFileName);
	_LnkFree(IncStrTab);
	_LnkFree(ReadRelocs);
	_LnkFree(OldExe);
	_LnkFree(OldSymFile);
	_LnkFree(AltDefData);
	RingFree(memorySubsystem, &IncGroupDefs);
	_LnkFree(IncGroups);
	FreeList(memorySubsystem, SavedUserLibs);
	FreeList(memorySubsystem, SavedDefLibs);
}
