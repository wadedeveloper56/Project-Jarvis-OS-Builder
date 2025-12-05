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