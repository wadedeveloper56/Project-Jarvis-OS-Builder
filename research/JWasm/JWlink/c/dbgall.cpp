#include "pch.h"
#include "globals.h"
#include "dbgall.h"
#include "mem.h"
#include "objfree.h"

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI(void)
{
    SymFileName = NULL;
    DBIGroups = NULL;
}

void ODBISectCleanup(section* sect)
{
    sect = sect;
    _PermFree(sect->dbg_info);
}

void DBISectCleanup(section* sect)
{
    if (LinkFlags & OLD_DBI_FLAG) {
        ODBISectCleanup(sect);
    }
}

void DBICleanup(void)
{
    FreeGroups(DBIGroups);
}
