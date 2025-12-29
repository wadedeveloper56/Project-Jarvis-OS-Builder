#include "pch.h"
#include "CmdElf.h"

CmdElf::CmdElf(MemorySubsystem* memory, MessagingSubsystem* msg) :CmdPlatform(memory, msg)
{
}

CmdElf::~CmdElf()
{
}

void CmdElf::setFormat()
{
    Extension = E_ELF;
    FmtData.u.elf.exp.export1 = NULL;
    FmtData.u.elf.exp.module = NULL;
    FmtData.u.elf.extrasects = 0;
    FmtData.u.elf.segment_shift = 0;
    FmtData.u.elf.abitype = 0;
    FmtData.u.elf.abiversion = 0;
}

void CmdElf::freeFormat()
{
}