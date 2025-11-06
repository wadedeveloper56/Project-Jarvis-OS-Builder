#include "pch.h"
#include "linkstd.h"
#include "strtab.h"
#include "dbgcomm.h"
#include "dbgall.h"
#include "carve.h"
#include "alloc.h"
#include "command.h"
#include "reloc.h"
#include "fileio.h"
#include "virtmem.h"
#include "impexp.h"
#include "loadfile.h"
#include "msg.h"
#include "objio.h"
#include "ring.h"
#include "wlnkmsg.h"
#include "objcalc.h"
#include "permdata.h"

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
