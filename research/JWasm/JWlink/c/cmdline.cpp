#include "pch.h"
#include "globals.h"
#include "cmdline.h"
#include "mem.h"
#include "permdata.h"

file_defext     Extension;
file_list** CurrFList;
tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands;

static sysblock* PrevCommand;

//#define INIT_FILE_NAME  "wlink.lnk"
//#define INIT_FILE_ENV   "WLINK_LNK"
#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void InitCmdFile(void)
{
    PrevCommand = NULL;
}

static void CleanSystemList(bool check)
{
    sysblock** sys;
    sysblock* next;
    char* name;

    sys = &SysBlocks;
    while (*sys != NULL) {
        name = (*sys)->name;
        if (!check || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
            next = (*sys)->next;
            _LnkFree(name);
            _LnkFree(*sys);
            *sys = next;
        }
        else {
            sys = &(*sys)->next;
        }
    }
}

void BurnSystemList(void)
{
    CleanSystemList(FALSE);
}

void FreePaths(void)
{
    FreeList(Path);
    Path = NULL;
    if (Name != NULL) {
        _LnkFree(Name);
        Name = NULL;
    }
}
