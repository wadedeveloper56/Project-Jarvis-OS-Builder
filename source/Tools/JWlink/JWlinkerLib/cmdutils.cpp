#include "pch.h"
#include "cmdutils.h"
#include "MemorySubsystem.h"
#include "hash.h"
#include "Structs.h"
#include "globals.h"

using namespace std;

int stricmp_wrapper(const void* s1, const void* s2)
{
    return(_stricmp((const char*)s1, (const char*)s2));
}

section* NewSection(shared_ptr<MemorySubsystem> memorySubsystem)
{
    section* sect = nullptr;

    OvlNum++;
	sect = (section*)memorySubsystem->AllocateMemory(sizeof(section));
    sect->next_sect = NULL;
    sect->classlist = NULL;
    sect->orderlist = NULL;
    sect->areas = NULL;
    sect->files = NULL;
    sect->modFilesHashed = CreateHTable(256, StringiHashFunc, stricmp_wrapper, memorySubsystem);
    sect->mods = NULL;
    sect->reloclist = NULL;
    sect->sect_addr.off = 0;
    sect->sect_addr.seg = UNDEFINED;
    sect->ovl_num = 0;
    sect->parent = NULL;
    sect->relocs = 0;
    sect->size = 0;
    sect->outfile = NULL;
    sect->u.dist_mods = NULL;
    sect->dbg_info = NULL;
    return(sect);
}
