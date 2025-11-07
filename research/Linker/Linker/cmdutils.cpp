#include "pch.h"
#include "walloca.h"
#include "linkstd.h"
#include "loadfile.h"
#include "command.h"
#include "alloc.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "cmdline.h"

int stricmp_wrapper(const void* s1, const void* s2)
{
    return(_stricmp((char*)s1, (char*)s2));
}

section* NewSection(void)
{
    section* sect;

    OvlNum++;
    _ChkAlloc(section*,sect, sizeof(section));
    sect->next_sect = NULL;
    sect->classlist = NULL;
    sect->orderlist = NULL;
    sect->areas = NULL;
    sect->files = NULL;
    sect->modFilesHashed = CreateHTable(256, StringiHashFunc, stricmp_wrapper, ChkLAlloc, LFree);
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
