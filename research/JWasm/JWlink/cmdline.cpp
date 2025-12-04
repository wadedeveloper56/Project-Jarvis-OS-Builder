#include "pch.h"
#include "command.h"

static sysblock* PrevCommand;

void InitCmdFile(void)
{
    PrevCommand = NULL;
}
