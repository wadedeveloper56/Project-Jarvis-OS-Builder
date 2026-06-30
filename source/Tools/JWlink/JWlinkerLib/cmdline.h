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

void FreeFormatStuff(MemorySubsystem *memorySubsystem);
void InitCmdFile(void);
char* GetNextLink(void);
void CleanSystemList(MemorySubsystem *memory, bool check);
void PruneSystemList(MemorySubsystem *memory);
void BurnSystemList(MemorySubsystem *memory);
void FreePaths(MemorySubsystem *memory);
