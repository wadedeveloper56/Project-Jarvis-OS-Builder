#include "pch.h"
#include "command.h"
#include "alloc.h"
#include "linkutil.h"
#include "formats.h"
#include "standard.h"
#include "cmdqnx.h"
#include "cmdelf.h"

struct select_format {
    int bits;
    const char* lib_var_name;
    void (*set_func)(void);
    void (*free_func)(void);
};

static struct select_format PossibleFmt[] = {
    MK_DOS,         "LIBDOS",       NULL,           NULL,
#ifdef _DOS16M
    MK_DOS16M,      "LIBDOS16M",    SetD16MFmt,     FreeD16MFmt,
#endif
#ifdef _QNXLOAD
    MK_QNX,         "LIBQNX",       SetQNXFmt,      FreeQNXFmt,
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
    MK_PHAR_LAP,    "LIBPHAR",      SetPharFmt,     FreePharFmt,
#endif
#ifdef _NOVELL
    MK_NOVELL,      "LIBNOV",       SetNovFmt,      FreeNovFmt,
#endif
};

#define NUMPOSSIBLEFMT ( sizeof( PossibleFmt ) / sizeof ( PossibleFmt[0] ) )

file_defext     Extension; 
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

void FreePaths(void)
{
    FreeList(Path);
    Path = NULL;
    if (Name != NULL) {
        _LnkFree(Name);
        Name = NULL;
    }
}

void FreeFormatStuff(void)
{
    int i;
    exe_format                  possible;

    if (!(LinkState & FMT_DECIDED)) return;
    for (i = 0; i < NUMPOSSIBLEFMT; i++) {
        possible = PossibleFmt[i].bits;
        if ((~possible & FmtData.type) == 0) {
            if (PossibleFmt[i].free_func != NULL)
                PossibleFmt[i].free_func();
            break;
        }
    }
}
