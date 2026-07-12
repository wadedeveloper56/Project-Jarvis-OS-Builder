#include "pch.h"
#include "dbginfo.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

uint32_t  DBISize;
dbgheader    Master;                 
snamelist* DBISourceLang;         

#ifdef _INT_DEBUG
struct
{
    offset   sizeadded;
    offset   sizegenned;
} TraceInfo;
#endif

void ODBISectCleanup(MemorySubsystem *memorySubsystem,section* sect)
{
    memorySubsystem->FreeMemory(sect->dbg_info);
}

snamelist* LangAlloc(MemorySubsystem* memorySubsystem, ::byte len, char* buff)
{
    snamelist* node;

    _LnkAlloc(snamelist*, node, sizeof(snamelist) + len);
    node->len = (::byte)len;
    memcpy(node->name, buff, len);
    node->name[len] = '\0';
    return(node);
}

void ODBIInit(MemorySubsystem* memorySubsystem, section* sect)
{
    DBISize = sizeof(dbgheader);
    Master.signature = DBG_SIGNATURE;
    Master.exe_major_ver = EXE_MAJOR_VERSION;
    Master.exe_minor_ver = EXE_MINOR_VERSION;
    Master.obj_major_ver = 0;
    Master.obj_minor_ver = 0;
    DBISourceLang = LangAlloc(memorySubsystem, 1, "C");
    DBISourceLang->next = NULL;
    _LnkAlloc(void*, sect->dbg_info, sizeof(debug_info));
    memset(sect->dbg_info, 0, sizeof(debug_info));     
#ifdef _INT_DEBUG
    memset(&TraceInfo, 0, sizeof(TraceInfo));
#endif
}
