#include "pch.h"
#include "globals.h"
#include "cmdline.h"
#include "mem.h"
#include "cmdnov.h"

void SetNovFmt(void)
{
    Extension = E_NLM;
    if (!(LinkState & FMT_SPECIFIED) && Name != nullptr) {
        FmtData.u.nov.description = FileName(Name, strlen(Name), E_NLM, CmdFlags & CF_UNNAMED);
    }
}

void FreeNovFmt(void)
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
    /*  FreeList( FmtData.u.nov.exp.export );
        FreeList( FmtData.u.nov.exp.module );  Permalloc'd now */
}
