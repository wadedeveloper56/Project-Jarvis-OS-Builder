#include "pch.h"
#include "globals.h"
#include "dbgall.h"

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI(void)
{
    SymFileName = NULL;
    DBIGroups = NULL;
}

