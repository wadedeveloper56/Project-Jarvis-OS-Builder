#include "pch.h"
#include "cmdos2.h"
#include "globals.h"
#include "msg.h"
#include "wlmsgs.h"
#include "globals.h"
#include "link.h"
#include "command.h"
#include "objfree.h"
#include "alloc.h"
#include "loados2.h"
#include "impexp.h"

void ChkBase(offset align)
{
    if (FmtData.objalign != (signed_32)-1 && FmtData.objalign > align) {
        align = FmtData.objalign;
    }
    if (FmtData.base != -1 && (FmtData.base & (align - 1)) != 0) {
        LnkMsg(LOC + LINE + WRN + MSG_OFFSET_MUST_BE_ALIGNED, (char *)"l", align);
        FmtData.base = (FmtData.base + align - 1) & ~(align - 1);
    }
}

void SetOS2Fmt(void)
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
    ChkBase(64 * 1024);
}

void FreeOS2Fmt(void)
{
    _LnkFree(FmtData.u.os2.stub_file_name);
    _LnkFree(FmtData.u.os2.res_module_name);
    _LnkFree(FmtData.u.os2.old_lib_name);
    _LnkFree(FmtData.u.os2.description);
    FreeImpNameTab();
    FreeExportList();
    FreeSegFlags((seg_flags*)FmtData.u.os2.os2_seg_flags);
}

