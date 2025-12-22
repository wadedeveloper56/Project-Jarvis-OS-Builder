#include "pch.h"
#include "CmdLine.h"
#include "LinkerUtils.h"
#include "CmdPlatform.h"
#include "CmdQnx.h"
#include "CmdElf.h"
#include "CmdWinOS2.h"
#include "CmdPharlap.h"
#include "CmdNovell.h"

CmdLine::CmdLine(MemorySubsystem* memory, MessagingSubsystem* msg)
{
	this->memory = memory;
    this->msg = msg;
	PrevCommand = nullptr;
	SysBlocks = nullptr;
	Name = nullptr;
    PossibleFmt[0] = { (exe_format)MK_DOS,         "LIBDOS",       nullptr };
    PossibleFmt[1] = { (exe_format)MK_QNX,         "LIBQNX",       new CmdQnx(memory, msg) };
    PossibleFmt[2] = { (exe_format)MK_ELF,         "LIBELF",       new CmdElf(memory, msg) };
    PossibleFmt[3] = { (exe_format)MK_WIN_NE,      "LIBWIN",       new CmdWinOS2(memory, msg) };
    PossibleFmt[4] = { (exe_format)MK_OS2_NE,      "LIBOS2",       new CmdWinOS2(memory, msg) };
    PossibleFmt[5] = { (exe_format)MK_OS2_LE,      "LIBOS2FLAT",   new CmdWinOS2(memory, msg) };
    PossibleFmt[6] = { (exe_format)MK_OS2_LX,      "LIBOS2FLAT",   new CmdWinOS2(memory, msg) };
    PossibleFmt[7] = { (exe_format)MK_PE,          "LIBPE",        new CmdWinOS2(memory, msg) };
    PossibleFmt[8] = { (exe_format)MK_WIN_VXD,     "LIBVXD",       new CmdWinOS2(memory, msg) };
    PossibleFmt[9] = { (exe_format)MK_PHAR_LAP,    "LIBPHAR",      new CmdPharlap(memory, msg) };
    PossibleFmt[10]= { (exe_format)MK_NOVELL,      "LIBNOV",       new CmdNovell(memory, msg) };
}

CmdLine::~CmdLine()
{
}

void CmdLine::CleanSystemList(bool check)
{
    sysblock** sys;
    sysblock* next;
    char* name;

    sys = &SysBlocks;
    while (*sys != NULL) {
        name = (*sys)->name;
        if (!check || (memcmp("286", name, 4) != 0 && memcmp("386", name, 4) != 0)) {
            next = (*sys)->next;
            memory->FreeMemory(name);
            memory->FreeMemory(*sys);
            *sys = next;
        }
        else {
            sys = &(*sys)->next;
        }
    }
}

void CmdLine::BurnSystemList(void)
{
	CleanSystemList(false);
}

void CmdLine::FreePaths(void)
{
    FreeList(memory, Path);
    Path = nullptr;
    if (Name != nullptr) {
        memory->FreeMemory(Name);
        Name = nullptr;
    }
}


void CmdLine::FreeFormatStuff(void)
{
    exe_format possible;

    if (!(LinkState & FMT_DECIDED)) return;
    for (int i = 0; i <= 10; i++) {
        possible = PossibleFmt[i].bits;
        if ((~possible & FmtData.type) == 0) {
            if (PossibleFmt[i].platform != NULL)
                PossibleFmt[i].platform->freeFormat();
            break;
        }
    }
}

