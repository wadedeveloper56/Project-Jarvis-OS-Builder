#include "pch.h"
#include "CmdQnx.h"
#include "Initialize.h"

CmdQnx::CmdQnx() :CmdPlatform()
{
}

CmdQnx::~CmdQnx()
{
}

void CmdQnx::setFormat()
{
	Extension = E_QNX;
	FmtData.u.qnx.flags = 0;
	FmtData.u.qnx.priv_level = 0;
	FmtData.u.qnx.seg_flags = nullptr;
	FmtData.u.qnx.heapsize = 4096;
	FmtData.u.qnx.gen_seg_relocs = true;
	FmtData.u.qnx.gen_linear_relocs = false;
	ChkBase(4 * 1024);
}

void CmdQnx::freeFormat()
{
	FreeSegFlags((seg_flags*)FmtData.u.qnx.seg_flags);
}
