#include "pch.h"
#include "dbgall.h"

char* SymFileName;
group_entry* DBIGroups;

void ResetDBI(void)
{
    SymFileName = NULL;
    DBIGroups = NULL;
}