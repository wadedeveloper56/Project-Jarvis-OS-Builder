#include "pch.h"
#include <memory>
#include "MemorySubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdos2.h"
#include "cmdphar.h"
#include "cmdnov.h"
#include "MessagingSubsystem.h"

using namespace std;

file_defext     Extension;
file_list** CurrFList;
tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands;
sysblock* PrevCommand;

struct select_format
{
	exe_format bits;
	char* lib_var_name;
	void (*set_func)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
	void (*free_func)(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem);
};

struct select_format PossibleFmt[] =
{
	(exe_format)MK_DOS,         "LIBDOS",       NULL,           NULL,
#ifdef _DOS16M
				MK_DOS16M,      "LIBDOS16M",    SetD16MFmt,     FreeD16MFmt,
#endif
#ifdef _QNXLOAD
	(exe_format)MK_QNX,         "LIBQNX",       SetQNXFmt,      FreeQNXFmt,
#endif
#ifdef _ELF
				MK_ELF,         "LIBELF",       SetELFFmt,      FreeELFFmt,
#endif
#ifdef _OS2
				MK_WIN_NE,      "LIBWIN",       SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_NE,      "LIBOS2",       SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_LE,      "LIBOS2FLAT",   SetOS2Fmt,      FreeOS2Fmt,
				MK_OS2_LX,      "LIBOS2FLAT",   SetOS2Fmt,      FreeOS2Fmt,
				MK_PE,          "LIBPE",        SetOS2Fmt,      FreeOS2Fmt,
				MK_WIN_VXD,     "LIBVXD",       SetOS2Fmt,      FreeOS2Fmt,
#endif
#ifdef _PHARLAP
	(exe_format)MK_PHAR_LAP,    "LIBPHAR",      SetPharFmt,     FreePharFmt,
#endif
#ifdef _NOVELL
				MK_NOVELL,      "LIBNOV",       SetNovFmt,      FreeNovFmt,
#endif
};

#define NUMPOSSIBLEFMT ( sizeof( PossibleFmt ) / sizeof ( PossibleFmt[0] ) )

#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void FreeFormatStuff(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	int i;
	exe_format                  possible;

	if (!(LinkState & FMT_DECIDED)) return;
	for (i = 0; i < NUMPOSSIBLEFMT; i++)
	{
		possible = PossibleFmt[i].bits;
		if ((~possible & FmtData.type) == 0)
		{
			if (PossibleFmt[i].free_func != NULL)
				PossibleFmt[i].free_func(memorySubsystem, messagingSubsystem);
			break;
		}
	}
}

void InitCmdFile()
{
	PrevCommand = NULL;
}

char* GetNextLink()
{
	return(NULL);
}

void CleanSystemList(MemorySubsystem* memory, bool check)
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

void PruneSystemList(MemorySubsystem* memory)
{
	CleanSystemList(memory, true);
}

void BurnSystemList(MemorySubsystem* memory)
{
	CleanSystemList(memory, false);
}

void FreePaths(MemorySubsystem* memory)
{
	FreeList(memory, Path);
	Path = NULL;
	if (Name != NULL)
	{
		memory->FreeMemory(Name);
		Name = NULL;
	}
}

