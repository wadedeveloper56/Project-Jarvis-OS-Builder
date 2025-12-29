#include "pch.h"
#include "CmdUtils.h"
#include "globals.h"
#include "MemorySubsystem.h"
#include "HashTable.h"
#include "MessagingSubsystem.h"

static  char* DefExt[] = {
#undef pick1
#define pick1(enum,text) text,
#include "ldefext.h"
};

static int stricmp_wrapper(const void* s1, const void* s2)
{
    return(_stricmp((const char*)s1, (const char*)s2));
}

char* ChkToString(MemorySubsystem* memory, void* mem, unsigned len)
{
    char* str;

    _ChkAlloc(char *, str, len + 1);
    memcpy(str, mem, len);
    str[len] = '\0';
    return(str);
}

char* FileName(MemorySubsystem* memory, MessagingSubsystem* msg, char* buff, unsigned len, file_defext etype, bool force)
{
    char* namptr;
    char* namstart;
    char* ptr;
    unsigned    cnt;
    unsigned    namelen;

    namptr = buff + len;
    cnt = 0;
    while (cnt != len) {
        cnt++;
        --namptr;
        if (IS_PATH_SEP(*namptr)) {
            break;
        }
    }
    if (IS_PATH_SEP(*namptr)) {
        namptr++;
    }
    namstart = namptr;
    cnt = len - (namptr - buff);
    if (cnt == 0) {
        _ChkAlloc(char *, ptr,len + 1);
        memcpy(ptr, buff, len);
        ptr[len] = '\0';
        msg->LnkMsg(LOC + LINE + FTL + MSG_INV_FILENAME, "s", ptr);
    }
    namelen = cnt;
    namptr = buff + len - 1;
    while (--cnt != 0 && *namptr != '.') {
        namptr--;
    }
    if (force || *namptr != '.') {
        if (force && etype == E_MAP) {         // op map goes in current dir.
            buff = namstart;
            len = namelen;
        }
        if (cnt != 0) {
            len = namptr - buff;
        }
        _ChkAlloc(char *, ptr, len + strlen(DefExt[etype]) + 1);
        memcpy(ptr, buff, len);
        strcpy(ptr + len, DefExt[etype]);
    }
    else {
        ptr = ChkToString(memory, buff, len);
    }
    return(ptr);
}

section* NewSection(MemorySubsystem* memory, HashTable* hashTable)
{
    OvlNum++;
    section* sect;
    _ChkAlloc(section*, sect, sizeof(section));
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
