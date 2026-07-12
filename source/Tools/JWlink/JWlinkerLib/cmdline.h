#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"
#include "MessagingSubsystem.h"
#include "FileSubsystem.h"
#include "SpillFile.h"

using namespace std;

typedef struct parse_entry
{
    char* keyword;
    bool                (*rtn)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
    enum exe_format     format;
    commandflag         flags;
} parse_entry;

extern file_defext     Extension;
extern file_list** CurrFList;
extern tok             Token;
extern commandflag     CmdFlags;
extern char* Name;
extern sysblock* SysBlocks;
extern sysblock* LinkCommands;
extern sysblock* PrevCommand; 

void FreeFormatStuff(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
void InitCmdFile();
char* GetNextLink();
void CleanSystemList(MemorySubsystem* memory, bool check);
void PruneSystemList(MemorySubsystem* memory);
void BurnSystemList(MemorySubsystem* memory);
void FreePaths(MemorySubsystem* memory);
void SetSegMask();
void ResetCmdFile(void);
bool IsStdOutConsole();
void Burn(MemorySubsystem* memorySubsystem, FileSubsystem* fileSubsystem, MessagingSubsystem* messagingSubsystem);
void Ignite(MemorySubsystem* memorySubsystem, FileSubsystem* fileSubsystem, MessagingSubsystem* messagingSubsystem);
void WriteMsg(char msg_buffer[]);
void PressKey(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
void WriteHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, unsigned first_ln, unsigned last_ln, bool prompt);
void WriteGenHelp(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
void DisplayOptions(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
void Crash(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, bool check_file);
void Help(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem);
void InitFmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, void (*set)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem));
void AddLibPaths(MemorySubsystem* memorySubsystem, char* name, unsigned len, bool add_to_front);
void AddEnvPaths(MemorySubsystem* memorySubsystem, char* envname);
void AddFmtLibPaths(MemorySubsystem* memorySubsystem);
bool HintFormat(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, exe_format hint);
void DoCmdFile(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, FileSubsystem* fileSubsystem, SpillFile* spillFile, char*** _argv, char* fname);

