#include "pch.h"
#include "CmdUtils.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "HashTable.h"

static int stricmp_wrapper(const void* s1, const void* s2)
{
    return(_stricmp((const char*)s1, (const char*)s2));
}

section* NewSection(MemorySubsystem* memory, HashTable* hashTable)
{
    section* sect;

    OvlNum++;
    sect = (section*)memory->AllocateMemory(sizeof(section));
    sect->next_sect = nullptr;
    sect->classlist = nullptr;
    sect->orderlist = nullptr;
    sect->areas = nullptr;
    sect->files = nullptr;
    sect->modFilesHashed = hashTable->CreateHTable(256, StringiHashFunc, stricmp_wrapper);
    sect->mods = nullptr;
    sect->reloclist = nullptr;
    sect->sect_addr.off = 0;
    sect->sect_addr.seg = UNDEFINED;
    sect->ovl_num = 0;
    sect->parent = nullptr;
    sect->relocs = 0;
    sect->size = 0;
    sect->outfile = nullptr;
    sect->u.dist_mods = nullptr;
    sect->dbg_info = nullptr;
    return(sect);
}
