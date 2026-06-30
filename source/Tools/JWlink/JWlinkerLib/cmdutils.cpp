#include "pch.h"
#include "cmdutils.h"
#include "MemorySubsystem.h"
#include "hash.h"
#include "Structs.h"
#include "globals.h"
#include "linkutil.h"

using namespace std;

char* DefExt[] = {
#undef pick1
#define pick1(enum1,text) text,
#include "ldefext.h"
};

int stricmp_wrapper(const void* s1, const void* s2)
{
    return(_stricmp((const char*)s1, (const char*)s2));
}

section* NewSection(MemorySubsystem *memorySubsystem)
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

char* FileName(MemorySubsystem *memorySubsystem,char* buff, unsigned len, file_defext etype, bool force)
{
    char* namptr;
    char* namstart;
    char* ptr;
    unsigned    cnt;
    unsigned    namelen;

    namptr = buff + len;
    cnt = 0;
    while (cnt != len)
    {
        cnt++;
        --namptr;
        if (IS_PATH_SEP(*namptr))
        {
            break;
        }
    }
    if (IS_PATH_SEP(*namptr))
    {
        namptr++;
    }
    namstart = namptr;
    cnt = len - (namptr - buff);
    if (cnt == 0)
    {
        _LnkAlloc(char *,ptr,len + 1);
        memcpy(ptr, buff, len);
        ptr[len] = '\0';
        //LnkMsg(LOC + LINE + FTL + MSG_INV_FILENAME, "s", ptr);
    }
    namelen = cnt;
    namptr = buff + len - 1;
    while (--cnt != 0 && *namptr != '.')
    {
        namptr--;
    }
    if (force || *namptr != '.')
    {
        if (force && etype == E_MAP)
        {         // op map goes in current dir.
            buff = namstart;
            len = namelen;
        }
        if (cnt != 0)
        {
            len = namptr - buff;
        }
        _LnkAlloc(char *, ptr, len + strlen(DefExt[etype]) + 1);
        memcpy(ptr, buff, len);
        strcpy(ptr + len, DefExt[etype]);
    }
    else
    {
        ptr = ChkToString(memorySubsystem, buff, len);
    }
    return(ptr);
}