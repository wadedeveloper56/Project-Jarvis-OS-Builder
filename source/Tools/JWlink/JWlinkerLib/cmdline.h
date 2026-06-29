#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

extern file_defext     Extension;
extern file_list** CurrFList;
extern tok             Token;
extern commandflag     CmdFlags;
extern char* Name;
extern sysblock* SysBlocks;
extern sysblock* LinkCommands;
extern sysblock* PrevCommand; 

void FreeFormatStuff(shared_ptr<MemorySubsystem> memorySubsystem);
void InitCmdFile(void);
char* GetNextLink(void);
void CleanSystemList(shared_ptr<MemorySubsystem> memory, bool check);
void PruneSystemList(shared_ptr<MemorySubsystem> memory);
void BurnSystemList(shared_ptr<MemorySubsystem> memory);
void FreePaths(shared_ptr<MemorySubsystem> memory);
