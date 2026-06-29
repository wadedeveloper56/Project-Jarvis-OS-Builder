#include "pch.h"
#include "dbgall.h"
#include "globals.h"
#include "Structs.h"
#include "dbginfo.h"
#include "MemorySubsystem.h"

using namespace std;

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI()
{
    SymFileName = NULL;
    DBIGroups = NULL;
}

void DBISectCleanup(shared_ptr<MemorySubsystem> memorySubsystem,section* sect)
{
    if (LinkFlags & OLD_DBI_FLAG)
    {
        ODBISectCleanup(memorySubsystem,sect);
    }
}
