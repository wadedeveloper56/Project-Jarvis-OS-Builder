#include "pch.h"
#include "CmdLine.h"
#include "CmdPlatform.h"
#include "CmdQnx.h"
#include "CmdElf.h"
#include "CmdWinOS2.h"
#include "CmdPharlap.h"
#include "CmdNovell.h"
#include "MemorySubsystem.h"

CmdLine::CmdLine()
{
    PossibleFmt[0] = { (exe_format)MK_DOS,         "LIBDOS",       nullptr };
	PossibleFmt[1] = { (exe_format)MK_QNX,         "LIBQNX",       new CmdQnx() };
	PossibleFmt[2] = { (exe_format)MK_ELF,         "LIBELF",       new CmdElf() };
	PossibleFmt[3] = { (exe_format)MK_WIN_NE,      "LIBWIN",       new CmdWinOS2() };
	PossibleFmt[4] = { (exe_format)MK_OS2_NE,      "LIBOS2",       new CmdWinOS2() };
	PossibleFmt[5] = { (exe_format)MK_OS2_LE,      "LIBOS2FLAT",   new CmdWinOS2() };
	PossibleFmt[6] = { (exe_format)MK_OS2_LX,      "LIBOS2FLAT",   new CmdWinOS2() };
	PossibleFmt[7] = { (exe_format)MK_PE,          "LIBPE",        new CmdWinOS2() };
	PossibleFmt[8] = { (exe_format)MK_WIN_VXD,     "LIBVXD",       new CmdWinOS2() };
	PossibleFmt[9] = { (exe_format)MK_PHAR_LAP,    "LIBPHAR",      new CmdPharlap() };
	PossibleFmt[10] = { (exe_format)MK_NOVELL,      "LIBNOV",       new CmdNovell() };
}

CmdLine::~CmdLine()
{
	for (int i = 0; i < 11; i++)
	{
		delete PossibleFmt[i].platform;
	}
}
