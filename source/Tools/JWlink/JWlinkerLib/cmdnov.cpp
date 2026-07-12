#include "pch.h"
#include "cmdnov.h"
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
#include "cmdutils.h"
#include "objfree.h"

using namespace std;

void SetNovFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem)
{
    Extension = E_NLM;
    if (!(LinkState & FMT_SPECIFIED) && Name != NULL)
    {
        FmtData.u.nov.description = FileName(memorySubsystem, messagingSubsystem, Name, strlen(Name), E_NLM, CmdFlags & CF_UNNAMED);
    }
}

void FreeNovFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem)
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

void CmdNovFini(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem)
{
    if (FmtData.u.nov.description == NULL && Name != NULL)
    {
        FmtData.u.nov.description = FileName(memorySubsystem, messagingSubsystem, Name, strlen(Name), Extension, CmdFlags & CF_UNNAMED);
    }
}
