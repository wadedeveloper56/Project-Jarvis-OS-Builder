#include "pch.h"
#include "CmdWinOS2.h"
#include "Initialize.h"

CmdWinOS2::CmdWinOS2(MemorySubsystem* memory, MessagingSubsystem* msg) :CmdPlatform(memory, msg)
{
}

CmdWinOS2::~CmdWinOS2()
{
}

void CmdWinOS2::setFormat()
{
    if (LinkState & FMT_INITIALIZED) return;
    LinkState |= FMT_INITIALIZED;
    FmtData.u.os2.flags = MULTIPLE_AUTO_DATA;
    FmtData.u.os2.heapsize = 0;
    FmtData.u.os2.segment_shift = -1;
    FmtData.u.os2.res_module_name = NULL;
    FmtData.u.os2.stub_file_name = NULL;
    FmtData.u.os2.os2_seg_flags = NULL;
    FmtData.u.os2.description = NULL;
    FmtData.u.os2.exports = NULL;
    FmtData.u.os2.old_lib_name = NULL;
#if 0 /* jwlink. set PRELOAD for DATA segs only! */
    if (FmtData.type & MK_WIN_NE) {
        FmtData.def_seg_flags |= SEG_PRELOAD;
    }
#endif
    Extension = E_LOAD;
    ChkBase(msg, 64 * 1024);
}

void CmdWinOS2::FreeImpNameTab(void)
{
    FmtData.u.os2.mod_ref_list = NULL;  /* these are permalloc'd */
    FmtData.u.os2.imp_tab_list = NULL;
}

void CmdWinOS2::FreeExportList(void)
{
    entry_export* exp;

    if (LinkFlags & INC_LINK_FLAG) return;
    exp = FmtData.u.os2.exports;
    while (exp != NULL) {
        //FIX ME exp = permData->FreeAnExport(exp);
    }
}

void CmdWinOS2::freeFormat()
{
    _LnkFree(FmtData.u.os2.stub_file_name);
    _LnkFree(FmtData.u.os2.res_module_name);
    _LnkFree(FmtData.u.os2.old_lib_name);
    _LnkFree(FmtData.u.os2.description);
    FreeImpNameTab();
    FreeExportList();
    FreeSegFlags(memory, (seg_flags*)FmtData.u.os2.os2_seg_flags);
}
