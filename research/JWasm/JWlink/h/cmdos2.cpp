#include "pch.h"
#include "globals.h"
#include "cmdos2.h"
#include "msg.h"
#include "wlmsgs.h"
#include "cmdline.h"
#include "loados2.h"
#include "mem.h"
#include "impexp.h"
#include "objfree.h"

void ChkBase(offset align)
/*********************************/
// Note: align must be a power of 2
{
    if (FmtData.objalign != -1 && FmtData.objalign > align) {
        align = FmtData.objalign;
    }
    if (FmtData.base != -1 && (FmtData.base & (align - 1)) != 0) {
        LnkMsg(LOC + LINE + WRN + MSG_OFFSET_MUST_BE_ALIGNED, "l", align);
        FmtData.base = (FmtData.base + align - 1) & ~(align - 1);
    }
}

void SetOS2Fmt(void)
/*********************/
// set up the structures needed to be able to process something in OS/2 mode.
{
    if (LinkState & FMT_INITIALIZED) return;
    LinkState |= FMT_INITIALIZED;
    FmtData.u.os2.flags = MULTIPLE_AUTO_DATA;
    FmtData.u.os2.heapsize = 0;
    FmtData.u.os2.segment_shift = -1;
    FmtData.u.os2.res_module_name = nullptr;
    FmtData.u.os2.stub_file_name = nullptr;
    FmtData.u.os2.os2_seg_flags = nullptr;
    FmtData.u.os2.description = nullptr;
    FmtData.u.os2.exports = nullptr;
    FmtData.u.os2.old_lib_name = nullptr;
#if 0 /* jwlink. set PRELOAD for DATA segs only! */
    if (FmtData.type & MK_WIN_NE) {
        FmtData.def_seg_flags |= SEG_PRELOAD;
    }
#endif
    Extension = E_LOAD;
    ChkBase(64 * 1024);
}

void FreeOS2Fmt(void)
/**********************/
{
    _LnkFree(FmtData.u.os2.stub_file_name);
    _LnkFree(FmtData.u.os2.res_module_name);
    _LnkFree(FmtData.u.os2.old_lib_name);
    _LnkFree(FmtData.u.os2.description);
    FreeImpNameTab();
    FreeExportList();
    FreeSegFlags((seg_flags*)FmtData.u.os2.os2_seg_flags);
}
