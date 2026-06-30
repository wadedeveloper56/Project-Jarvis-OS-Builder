#pragma once

#include <memory>
#include "permdata.h"
#include "MemorySubsystem.h"
#include "Structs.h"
#include "carve.h"
#include "strtab.h"

using namespace std;

extern stringtable             PermStrings;
extern stringtable             PrefixStrings;  /* these are NetWare prefix strings of which there could possibly be several */
extern carve_t                 CarveLeader;
extern carve_t                 CarveModEntry;
extern carve_t                 CarveSymbol;
extern carve_t                 CarveSegData;
extern carve_t                 CarveClass;
extern carve_t                 CarveGroup;
extern carve_t                 CarveDLLInfo;
extern carve_t                 CarveExportInfo;
extern char* IncFileName;
extern incgroupdef* IncGroupDefs;
extern group_entry** IncGroups;
extern libnamelist* SavedUserLibs;
extern libnamelist* SavedDefLibs;

void ResetPermData(MemorySubsystem *memorySubsystem);
