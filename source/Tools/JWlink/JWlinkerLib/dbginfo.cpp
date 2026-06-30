#include "pch.h"
#include "dbginfo.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

void ODBISectCleanup(MemorySubsystem *memorySubsystem,section* sect)
{
    memorySubsystem->FreeMemory(sect->dbg_info);
}
