#pragma once

#include "globals.h"
#include "PermData.h"

extern char* SymFileName;
extern group_entry* DBIGroups;

void ResetDBI(void);
void DBICleanup(PermData* permData);
void DBISectCleanup(section* sect);
