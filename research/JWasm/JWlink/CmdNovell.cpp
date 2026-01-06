#include "pch.h"
#include "globals.h"
#include "CmdNovell.h"
#include "CmdUtils.h"

CmdNovell::CmdNovell(MemorySubsystem* memory, MessagingSubsystem* msg) :CmdPlatform(memory, msg)
{
    Name = nullptr;
}

CmdNovell::~CmdNovell()
{
}

void CmdNovell::setFormat()
{
    Extension = E_NLM;
    if (!(LinkState & FMT_SPECIFIED) && Name != NULL) {
        FmtData.u.nov.description = FileName(memory, msg, Name, strlen(Name), E_NLM, CmdFlags & CF_UNNAMED);
    }
}

void CmdNovell::freeFormat()
{
    _LnkFree(FmtData.u.nov.screenname);
    _LnkFree(FmtData.u.nov.description);
    _LnkFree(FmtData.u.nov.checkfn);
    _LnkFree(FmtData.u.nov.exitfn);
    _LnkFree(FmtData.u.nov.customdata);
    _LnkFree(FmtData.u.nov.threadname);
    _LnkFree(FmtData.u.nov.copyright);
    _LnkFree(FmtData.u.nov.messages);
    _LnkFree(FmtData.u.nov.help);
    _LnkFree(FmtData.u.nov.rpcdata);
    _LnkFree(FmtData.u.nov.sharednlm);
}
