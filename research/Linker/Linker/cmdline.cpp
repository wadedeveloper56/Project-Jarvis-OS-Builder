#include "pch.h"
#include "linkstd.h"
#include "exeos2.h"
#include "msg.h"
#include "alloc.h"
#include "command.h"
#include "wlnkmsg.h"
#include "cmdall.h"
#include "cmdos2.h"
#include "cmdqnx.h"
#include "cmd16m.h"
#include "cmdnov.h"
#include "cmdelf.h"
#include "cmdphar.h"
#include "cmddos.h"
#include "cmdline.h"
#include "overlays.h"
#include "fileio.h"
#include "symtrace.h"
#include "reloc.h"
#include "dbgall.h"
#include "loadfile.h"

char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands;
static sysblock* PrevCommand;
tok             Token;

void InitCmdFile(void)
{
    PrevCommand = NULL;
}

char* GetNextLink(void)
{
    char* cmd;

    cmd = NULL;
    _LnkFree(PrevCommand);
    if (LinkCommands != NULL) {
        PrevCommand = LinkCommands;
        LinkCommands = LinkCommands->next;
        cmd = PrevCommand->commands;
    }
    return(cmd);
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

void PruneSystemList(void)
{
    CleanSystemList(TRUE);
}

void BurnSystemList(void)
{
    CleanSystemList(FALSE);
}

