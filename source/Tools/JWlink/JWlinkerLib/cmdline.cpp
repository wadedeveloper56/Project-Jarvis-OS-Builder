#include "pch.h"
#include <memory>
#include "MemorySubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"

file_defext     Extension;
file_list** CurrFList;
tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands; 
sysblock* PrevCommand;

#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void InitCmdFile(void)
{
    PrevCommand = NULL;
}

char* GetNextLink(void)
{
	return(NULL);
}

void CleanSystemList(shared_ptr<MemorySubsystem> memory, bool check)
{
    sysblock** sys;
    sysblock* next;
    char* name;

    sys = &SysBlocks;
    while (*sys != NULL)
    {
        name = (*sys)->name;
        if (!check
            || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0))
        {
            next = (*sys)->next;
            memory->FreeMemory(name);
            memory->FreeMemory(*sys);
            *sys = next;
        }
        else
        {
            sys = &(*sys)->next;
        }
    }
}

void PruneSystemList(shared_ptr<MemorySubsystem> memory)
{
    CleanSystemList(memory, true);
}

void BurnSystemList(shared_ptr<MemorySubsystem> memory)
{
    CleanSystemList(memory, false);
}

void FreePaths(shared_ptr<MemorySubsystem> memory)
{
    FreeList(memory, Path);
    Path = NULL;
    if (Name != NULL)
    {
        memory->FreeMemory(Name);
        Name = NULL;
    }
}

