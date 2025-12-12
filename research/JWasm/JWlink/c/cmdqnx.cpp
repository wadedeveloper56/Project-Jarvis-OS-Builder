#include "pch.h"
#include "globals.h"
#include "cmdqnx.h"
#include "cmdline.h"
#include "cmdos2.h"
#include "objfree.h"

void SetQNXFmt(void)
{
    Extension = E_QNX;
    FmtData.u.qnx.flags = 0;
    FmtData.u.qnx.priv_level = 0;
    FmtData.u.qnx.seg_flags = nullptr;
    FmtData.u.qnx.heapsize = 4096;
    FmtData.u.qnx.gen_seg_relocs = TRUE;
    FmtData.u.qnx.gen_linear_relocs = FALSE;
    ChkBase(4 * 1024);
}

void FreeQNXFmt(void)
{
    FreeSegFlags((seg_flags*)FmtData.u.qnx.seg_flags);
}