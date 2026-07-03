#include "pch.h"
#include <memory>
#include "MemorySubsystem.h"
#include "cmdos2.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdline.h"
#include "objfree.h"
#include "carve.h"
#include "permdata.h"

using namespace std;

void SetOS2Fmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
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
	if (FmtData.type & MK_WIN_NE)
	{
		FmtData.def_seg_flags |= SEG_PRELOAD;
	}
#endif
	Extension = E_LOAD;
	ChkBase(memorySubsystem, messagingSubsystem, 64 * 1024);
}

void FreeImpNameTab()
{
	FmtData.u.os2.mod_ref_list = NULL;
	FmtData.u.os2.imp_tab_list = NULL;
}

entry_export* FreeAnExport(MemorySubsystem* memorySubsystem, entry_export* exp)
{
	entry_export* next;

	memorySubsystem->FreeMemory(exp->impname);
	next = exp->next;
	CarveFree(CarveExportInfo, exp);
	return(next);
}

void FreeExportList(MemorySubsystem* memorySubsystem)
{
	entry_export* exp;

	if (LinkFlags & INC_LINK_FLAG) return;
	exp = FmtData.u.os2.exports;
	while (exp != NULL)
	{
		exp = FreeAnExport(memorySubsystem, exp);
	}
}

void FreeOS2Fmt(MemorySubsystem* memorySubsystem, MessagingSubsystem* messagingSubsystem)
{
	memorySubsystem->FreeMemory(FmtData.u.os2.stub_file_name);
	memorySubsystem->FreeMemory(FmtData.u.os2.res_module_name);
	memorySubsystem->FreeMemory(FmtData.u.os2.old_lib_name);
	memorySubsystem->FreeMemory(FmtData.u.os2.description);
	FreeImpNameTab();
	FreeExportList(memorySubsystem);
	FreeSegFlags(memorySubsystem, (seg_flags*)FmtData.u.os2.os2_seg_flags);
}
