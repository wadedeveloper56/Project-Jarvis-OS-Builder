#include "pch.h"
#include "cmdqnx.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "Structs.h"
#include "cmdline.h"
#include "objfree.h"

using namespace std;

void ChkBase(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem, offset align)
{
	if (FmtData.objalign != (offset)NO_BASE_SPEC && FmtData.objalign > align)
	{
		align = FmtData.objalign;
	}
	if (FmtData.base != (offset)NO_BASE_SPEC && (FmtData.base & (align - 1)) != 0)
	{
		messagingSubsystem->LnkMsg(LOC + LINE + WRN + MSG_OFFSET_MUST_BE_ALIGNED, "l", align);
		FmtData.base = (FmtData.base + align - 1) & ~(align - 1);
	}
}

void SetQNXFmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	Extension = E_QNX;
	FmtData.u.qnx.flags = 0;
	FmtData.u.qnx.priv_level = 0;
	FmtData.u.qnx.seg_flags = NULL;
	FmtData.u.qnx.heapsize = 4096;
	FmtData.u.qnx.gen_seg_relocs = TRUE;
	FmtData.u.qnx.gen_linear_relocs = FALSE;
	ChkBase(memorySubsystem, messagingSubsystem, 4 * 1024);
}

void FreeQNXFmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	FreeSegFlags(memorySubsystem, (seg_flags*)FmtData.u.qnx.seg_flags);
}