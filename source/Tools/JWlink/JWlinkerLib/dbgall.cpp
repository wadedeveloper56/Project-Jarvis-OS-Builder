#include "pch.h"
#include "dbgall.h"
#include "globals.h"
#include "Structs.h"

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI()
{
    SymFileName = NULL;
    DBIGroups = NULL;
}
