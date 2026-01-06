#include "pch.h"
#include "CmdPlatform.h"

CmdPlatform::CmdPlatform(MemorySubsystem* memory, MessagingSubsystem* msg)
{
	this->msg = msg;
	this->memory = memory;
	this->Extension = (file_defext)0;
}

CmdPlatform::~CmdPlatform()
{
}

void CmdPlatform::ChkBase(MessagingSubsystem* msg, offset align)
{
	if (FmtData.objalign != (offset)-1 && FmtData.objalign > align) {
		align = FmtData.objalign;
	}
	if (FmtData.base != (offset)-1 &&	(FmtData.base & (align - 1)) != 0) {
		msg->LnkMsg(LOC + LINE + WRN + MSG_OFFSET_MUST_BE_ALIGNED, "l", align);
		FmtData.base = (FmtData.base + align - 1) & ~(align - 1);
	}
}
