#include "pch.h"
#include "globals.h"
#include "cmdline.h"
#include "mem.h"
#include "permdata.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdos2.h"
#include "cmdphar.h"
#include "cmdnov.h"

struct select_format {
    int bits;
    char* lib_var_name;
    void (*set_func)(void);
    void (*free_func)(void);
};

static struct select_format PossibleFmt[] = {
    MK_DOS,         "LIBDOS",       nullptr,           nullptr,
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
file_list** CurrFList;
tok             Token;
commandflag     CmdFlags;
char* Name;
sysblock* SysBlocks;
sysblock* LinkCommands;

static sysblock* PrevCommand;

//#define INIT_FILE_NAME  "wlink.lnk"
//#define INIT_FILE_ENV   "WLINK_LNK"
#define INIT_FILE_NAME  "jwlink.lnk"
#define INIT_FILE_ENV   "JWLINK_LNK"

void InitCmdFile(void)
{
    PrevCommand = nullptr;
}

static void CleanSystemList(bool check)
{
    sysblock** sys;
    sysblock* next;
    char* name;

    sys = &SysBlocks;
    while (*sys != nullptr) {
        name = (*sys)->name;
        if (!check || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
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
    CleanSystemList(FALSE);
}

void FreePaths(void)
{
    FreeList(Path);
    Path = nullptr;
    if (Name != nullptr) {
        _LnkFree(Name);
        Name = nullptr;
    }
}

void FreeFormatStuff(void)
{
    int i;
    exe_format                  possible;

    if (!(LinkState & FMT_DECIDED)) return;
    for (i = 0; i < NUMPOSSIBLEFMT; i++) {
        possible = (exe_format)PossibleFmt[i].bits;
        if ((~possible & FmtData.type) == 0) {
            if (PossibleFmt[i].free_func != nullptr)
                PossibleFmt[i].free_func();
            break;
        }
    }
}

char* GetNextLink(void)
{
    char* cmd;

    cmd = nullptr;
    _LnkFree(PrevCommand);
    if (LinkCommands != nullptr) {
        PrevCommand = LinkCommands;
        LinkCommands = LinkCommands->next;
        cmd = PrevCommand->commands;
    }
    return(cmd);
}
