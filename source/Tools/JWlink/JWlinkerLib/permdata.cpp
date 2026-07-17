#include "pch.h"
#include "permdata.h"
#include "Carve.h"
#include "debug.h"
#include "StringTable.h"

StringTable*             PermStrings;
StringTable*             PrefixStrings;               
Carve* CarveLeader;
Carve* CarveModEntry;
Carve* CarveSymbol;
Carve* CarveSegData;
Carve* CarveClass;
Carve* CarveGroup;
Carve* CarveDLLInfo;
Carve* CarveExportInfo;
char* IncFileName;
incgroupdef* IncGroupDefs;
group_entry** IncGroups;
libnamelist* SavedUserLibs;
libnamelist* SavedDefLibs;

static StringTable*      StoredRelocs;
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
	DEBUG((DBG_OLD, "ResetPermData() enter\n"));
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
	CarveClass = new Carve(memorySubsystem); CarveClass->CarveCreate(sizeof(class_entry), 20 * sizeof(class_entry));
	CarveGroup = new Carve(memorySubsystem); CarveGroup->CarveCreate(sizeof(group_entry), 20 * sizeof(group_entry));
	CarveDLLInfo = new Carve(memorySubsystem); CarveDLLInfo->CarveCreate(sizeof(dll_sym_info), 100 * sizeof(dll_sym_info));
	CarveExportInfo = new Carve(memorySubsystem); CarveExportInfo->CarveCreate(sizeof(entry_export), 20 * sizeof(entry_export));
	CarveLeader = new Carve(memorySubsystem); CarveLeader->CarveCreate(sizeof(seg_leader), SEG_CARVE_SIZE);
	CarveModEntry = new Carve(memorySubsystem); CarveModEntry->CarveCreate(sizeof(mod_entry), MOD_CARVE_SIZE);
	CarveSegData = new Carve(memorySubsystem); CarveSegData->CarveCreate(sizeof(segdata), SDATA_CARVE_SIZE);
	CarveSymbol = new Carve(memorySubsystem); CarveSymbol->CarveCreate(sizeof(symbol), SYM_CARVE_SIZE);
	PermStrings = new StringTable(memorySubsystem); PermStrings->InitStringTable(TRUE);
	PrefixStrings = new StringTable(memorySubsystem); PrefixStrings->InitStringTable( TRUE );
	StoredRelocs = new StringTable(memorySubsystem); StoredRelocs->InitStringTable( FALSE );
	DEBUG((DBG_OLD, "ResetPermData() exit\n"));
}
