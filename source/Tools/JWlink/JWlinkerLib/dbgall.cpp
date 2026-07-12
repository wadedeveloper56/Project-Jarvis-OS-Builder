#include "pch.h"
#include "dbgall.h"
#include "globals.h"
#include "Structs.h"
#include "dbginfo.h"
#include "MemorySubsystem.h"
#include "dbgcv.h"
#include "dbgdwarf.h"

using namespace std;

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI()
{
	SymFileName = NULL;
	DBIGroups = NULL;
}

void DBISectCleanup(MemorySubsystem* memorySubsystem, section* sect)
{
	if (LinkFlags & OLD_DBI_FLAG)
	{
		ODBISectCleanup(memorySubsystem, sect);
	}
}

void DBIInit(MemorySubsystem* memorySubsystem)
{
	if (LinkFlags & OLD_DBI_FLAG)
	{
		ODBIInit(memorySubsystem, Root);
	}
	else if (LinkFlags & CV_DBI_FLAG)
	{
		CVInit();
	}
	else if (LinkFlags & DWARF_DBI_FLAG)
	{
		DwarfInit();
	}
}
