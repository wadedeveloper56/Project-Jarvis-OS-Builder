#pragma once

#include "cmdutil.h"

extern tok             Token;
extern file_defext     Extension;
extern file_list** CurrFList;
extern tok             Token;
extern commandflag     CmdFlags;
extern char* Name;
extern sysblock* SysBlocks;
extern sysblock* LinkCommands;

void InitCmdFile(void);
void BurnSystemList(void);
void FreePaths(void);
void FreeFormatStuff(void);
