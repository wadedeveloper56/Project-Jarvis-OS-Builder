#pragma once

extern char* SymFileName;
extern group_entry* DBIGroups;

void ResetDBI(void);
void ODBISectCleanup(section* sect);
void DBISectCleanup(section* sect);
void DBICleanup(void);
