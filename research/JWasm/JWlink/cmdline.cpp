#include "pch.h"
#include "command.h"
#include "alloc.h"

tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands; 

static sysblock* PrevCommand;

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
        if (!check
            || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
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
    CleanSystemList(false);
}
