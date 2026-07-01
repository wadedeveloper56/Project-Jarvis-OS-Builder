#include "pch.h"
#include "reloc.h"
#include "Structs.h"
#include "globals.h"
#include "carve.h"
#include "debug.h"
#include "orl.h"
#include "Memory.h"
#include "Orl2.h"
#include "cmdline.h"
#include "objfree.h"
#include "ObjectNode.h"
#include "permdata.h"
#include "libr.h"
#include "cmdutils.h"
#include "dbgall.h"
#include "mapio.h"
#include "cmdall.h"
#include "ovlsupp.h"
#include "wcomdef.h"
#include "distrib.h"
#include "loadnov.h"
#include "loadpe.h"
#include "obj2supp.h"
#include "objio.h"
#include "objomf.h"
#include "objpass1.h"
#include "objstrip.h"
#include "omfreloc.h"
#include "symtrace.h"
#include "loadfile.h"
#include "salloc.h"
#include "toc.h"
#include "ntio.h"
#include "linkutil.h"
#include "procfile.h"
#include "MemorySubsystem.h"
#include "ovlsupp.h"
#include "SpillFile.h"

using namespace std;

unsigned        FmtRelocSize;
reloc_info* FloatFixups;

void ResetReloc()
{
	FloatFixups = NULL;
}

reloc_info* AllocRelocInfo(MemorySubsystem *memorySubsystem, SpillFile * spillFile)
{
	reloc_info* info = (reloc_info*)memorySubsystem->AllocateMemory(sizeof(reloc_info));
	info->sizeleft = RELOC_PAGE_SIZE;
	info->loc.addr = memorySubsystem->AllocateMemory(RELOC_PAGE_SIZE);
	if (info->loc.addr == NULL)
	{
		info->loc.spill = spillFile->SpillAlloc(RELOC_PAGE_SIZE);
		info->sizeleft |= RELOC_SPILLED;
	}
	return(info);
}

void* OS2PagedRelocInit(MemorySubsystem *memorySubsystem, offset size, int unitsize)
{
	void** mem;
	void** start;
	offset      pageidx;
	offset      idxhigh;
	unsigned    idxlow;
	unsigned    allocsize;

	pageidx = OSF_PAGE_COUNT(size);
	idxhigh = OSF_RLIDX_HIGH(pageidx);
	mem = (void**)memorySubsystem->AllocateMemory((idxhigh + 1) * sizeof(void*));
	start = mem;
	allocsize = OSF_RLIDX_MAX * unitsize;
	while (idxhigh > 0)
	{
		mem = (void**)memorySubsystem->AllocateMemory(allocsize);
		memset(*mem, 0, allocsize);
		mem++;
		idxhigh--;
	}
	idxlow = OSF_RLIDX_LOW(pageidx);
	if (idxlow != 0)
	{
		allocsize = idxlow * unitsize;
		*mem = (void*)memorySubsystem->AllocateMemory(allocsize);
		memset(*mem, 0, allocsize);
	}
	return(start);
}

void* OS2FlatRelocInit(MemorySubsystem *memorySubsystem, offset size)
{
	return(OS2PagedRelocInit(memorySubsystem, size, sizeof(os2_reloc_header)));
}

void* PERelocInit(MemorySubsystem *memorySubsystem, offset size)
{
	return(OS2PagedRelocInit(memorySubsystem, size, sizeof(reloc_info*)));
}

void DoWriteReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, void* lst, void* reloc, unsigned size)
{
	reloc_info** list = (reloc_info**)lst;
	reloc_info* info;
	unsigned        offset;

	info = *(reloc_info**)list;
	if (info == NULL)
	{
		info = AllocRelocInfo(memorySubsystem, spillFile);
		info->next = NULL;
		*list = info;
	}
	if ((info->sizeleft & SIZELEFT_MASK) < size)
	{
		info = AllocRelocInfo(memorySubsystem, spillFile);
		info->next = *list;
		*list = info;
	}
	offset = RELOC_PAGE_SIZE - (info->sizeleft & SIZELEFT_MASK);
	if (info->sizeleft & RELOC_SPILLED)
	{
		spillFile->SpillWrite(info->loc.spill, offset, reloc, size);
	}
	else
	{
		memcpy((char*)(info->loc.addr) + offset, reloc, size);
	}
	info->sizeleft -= size;
}

void WriteReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, offset off, void* reloc, unsigned size)
{
	os2_reloc_header** pagelist;
	reloc_info*** reloclist;
	reloc_info** header;
	uint32_t         idx;

	if (FmtData.type & MK_PE)
	{
		reloclist = (reloc_info***)group->g.grp_relocs;
		if (reloclist == NULL)
		{
			reloclist = (reloc_info***)PERelocInit(memorySubsystem, group->totalsize);
			group->g.grp_relocs = reloclist;
		}
		idx = (off - group->grp_addr.off) >> OSF_PAGE_SHIFT;
		header = &reloclist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)];
		DoWriteReloc(memorySubsystem, spillFile, header, reloc, size);
	}
	else if (FmtData.type & MK_OS2_FLAT)
	{
		pagelist = (os2_reloc_header**)group->g.grp_relocs;
		if (pagelist == NULL)
		{
			pagelist = (os2_reloc_header**)OS2FlatRelocInit(memorySubsystem, group->totalsize);
			group->g.grp_relocs = pagelist;
		}
		idx = (off - group->grp_addr.off) >> OSF_PAGE_SHIFT;
		header = &pagelist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)].externals;
		switch (((os2_flat_reloc_item*)reloc)->fmt.nr_flags & OSF_TARGET_MASK)
		{
			case INTERNAL_REFERENCE:
				switch (((os2_flat_reloc_item*)reloc)->fmt.nr_stype)
				{
					case OFFSET_ONLY:
					case OFFSET48_ONLY:
					case OFFSET48_RELATIVE:
						header =
							&pagelist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)].internals;
						break;
				}
				break;
		}
		DoWriteReloc(memorySubsystem, spillFile, header, reloc, size);
	}
	else if (FmtData.type & (MK_OS2_16BIT | MK_ELF))
	{
		DoWriteReloc(memorySubsystem, spillFile, &group->g.grp_relocs, reloc, size);
	}
	else
	{
		DoWriteReloc(memorySubsystem, spillFile, &group->section->reloclist, reloc, size);
	}
	group->section->relocs++;
}

#ifdef _QNXLOAD
void FloatReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_item* item)
{
	DoWriteReloc(memorySubsystem,spillFile,&FloatFixups, item, sizeof(qnx_reloc_item));
}

void QNXLinearReloc(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, reloc_item* item)
{
	DoWriteReloc(memorySubsystem,spillFile,&group->g.grp_relocs, item, sizeof(qnx_linear_item));
}
#endif

bool FreeRelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info* list)
{
	while (list != NULL)
	{
		if (!(list->sizeleft & RELOC_SPILLED))
		{
			memorySubsystem->FreeMemory(list->loc.addr);
		}
		list = list->next;
	}
	return(FALSE);
}

void FreeRelocSect(MemorySubsystem *memorySubsystem, SpillFile * spillFile, section* sect)
{
	FreeRelocList(memorySubsystem, spillFile, (reloc_info*)sect->reloclist);
}

bool TraverseRelocBlock(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info** reloclist, unsigned num, bool (*fn)(MemorySubsystem *, SpillFile *, reloc_info*))
{
	while (num > 0)
	{
		if (fn(memorySubsystem, spillFile, *reloclist++))
			return(TRUE);
		if (FmtData.type & MK_OS2_FLAT)
		{
			if (fn(memorySubsystem, spillFile, *reloclist++))
			{
				return(TRUE);
			}
		}
		num--;
	}
	return(FALSE);
}

bool TraverseOS2RelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group, bool (*fn)(MemorySubsystem *, SpillFile *, reloc_info*))
{
	uint32_t         index;
	uint32_t         highidx;
	unsigned            lowidx;
	reloc_info*** reloclist;

	reloclist = (reloc_info***)group->g.grp_relocs;
	if (reloclist != NULL)
	{
		index = OSF_PAGE_COUNT(group->totalsize);
		highidx = OSF_RLIDX_HIGH(index);
		while (highidx > 0)
		{
			if (TraverseRelocBlock(memorySubsystem,	spillFile, *reloclist, OSF_RLIDX_MAX, fn))
				return(TRUE);
			reloclist++;
			highidx--;
		}
		lowidx = OSF_RLIDX_LOW(index);
		if (lowidx > 0)
		{
			return(TraverseRelocBlock(memorySubsystem, spillFile, *reloclist, OSF_RLIDX_LOW(index), fn));
		}
	}
	return(FALSE);
}

void FreeGroupRelocs(MemorySubsystem *memorySubsystem, SpillFile * spillFile, group_entry* group)
{
	uint32_t         highidx;
	uint32_t         index;
	reloc_info*** reloclist;

	if (!(LinkState & MAKE_RELOCS))
		return;
	if (FmtData.type & (MK_OS2_FLAT | MK_PE))
	{
		TraverseOS2RelocList(memorySubsystem, spillFile, group, FreeRelocList);
		reloclist = (reloc_info***)group->g.grp_relocs;
		if (reloclist != NULL)
		{
			index = OSF_PAGE_COUNT(group->totalsize);
			highidx = OSF_RLIDX_HIGH(index);
			if (OSF_RLIDX_LOW(index) != 0)
			{
				highidx++;
			}
			while (highidx > 0)
			{
				memorySubsystem->FreeMemory(*reloclist);
				reloclist++;
				highidx--;
			}
		}
	}
	else if (FmtData.type & (MK_ELF | MK_OS2_16BIT | MK_QNX))
	{
		FreeRelocList(memorySubsystem, spillFile, (reloc_info*)group->g.grp_relocs);
	}
}

void WalkAllSects(MemorySubsystem *memorySubsystem, SpillFile * spillFile,void (*rtn)(MemorySubsystem *, SpillFile *, section*))
{
	rtn(memorySubsystem, spillFile, Root);
	if (FmtData.type & MK_OVERLAYS)
	{
		WalkAreas(memorySubsystem, spillFile, Root->areas, rtn);
	}
}

void FreeRelocInfo(MemorySubsystem *memorySubsystem, SpillFile * spillFile)
{
	group_entry* group;

	if (!(LinkState & MAKE_RELOCS))
		return;
	if (FmtData.type & (MK_ELF | MK_OS2_FLAT | MK_PE | MK_OS2_16BIT | MK_QNX))
	{
		for (group = Groups; group != NULL; group = group->next_group)
		{
			FreeGroupRelocs(memorySubsystem, spillFile, group);
		}
	}
	else if (Root != NULL)
	{
		WalkAllSects(memorySubsystem, spillFile, FreeRelocSect);
	}
	if (FmtData.type & MK_QNX)
	{
		FreeRelocList(memorySubsystem, spillFile, FloatFixups);
		FreeRelocSect(memorySubsystem, spillFile, Root);
	}
}

uint32_t RelocSize(reloc_info* list)
{
	uint32_t size;

	size = 0;
	while (list != NULL)
	{
		size += RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
		list = list->next;
	}
	return(size);
}

uint32_t DumpMaxRelocList(SpillFile * spillFile, reloc_info** head, uint32_t max)
{
	uint32_t         size;
	uint32_t         total;
	reloc_info* list;

	total = 0;
	list = *head;
	DEBUG((DBG_OLD, "DumpMaxRelocList() enter\n"));
	for (;; )
	{
		if (list == NULL)
			break;
		size = RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
		if ((max != 0) && (total != 0) && ((total + size) >= max))
			break;
		if (size != 0)
		{
			if (list->sizeleft & RELOC_SPILLED)
			{
				spillFile->SpillRead(list->loc.spill, 0, TokBuff, size);
				WriteLoad(TokBuff, size);
			}
			else
			{
				WriteLoad(list->loc.addr, size);
			}
		}
		DEBUG((DBG_OLD, "DumpMaxRelocList(): addr=%h size=%h\n", list->loc.addr, size));
		list = list->next;
		total += size;
	}
	*head = list;
	return(total);
}

bool DumpRelocList(SpillFile * spillFile, reloc_info* list)
{
	DumpMaxRelocList(spillFile, &list, 0);
	return(FALSE);
}

uint32_t WalkRelocList(SpillFile * spillFile, reloc_info** head, bool (*fn)(void* data, uint32_t size, void* ctx), void* ctx)
{
	uint32_t         size;
	uint32_t         total;
	reloc_info* list;
	bool                quit = FALSE;

	total = 0;
	list = *head;
	for (;; )
	{
		if ((list == NULL) || quit)
			break;
		size = RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
		if (size != 0)
		{
			if (list->sizeleft & RELOC_SPILLED)
			{
				spillFile->SpillRead(list->loc.spill, 0, TokBuff, size);
				quit = fn(TokBuff, size, ctx);
			}
			else
			{
				quit = fn(list->loc.addr, size, ctx);
			}
		}
		list = list->next;
		total += size;
	}
	*head = list;
	return(total);
}

void SetRelocSize()
{
	if (FmtData.type & (MK_OS2 | MK_WIN_VXD))
	{
		FmtRelocSize = sizeof(os2_reloc_item);
	}
	else if (FmtData.type & MK_PE)
	{
		FmtRelocSize = sizeof(pe_reloc_item);
	}
	else if (FmtData.type & MK_NOVELL)
	{
		FmtRelocSize = sizeof(nov_reloc_item);
	}
	else if (FmtData.type & MK_PHAR_REX)
	{
		FmtRelocSize = sizeof(rex_reloc_item);
	}
	else if (FmtData.type & MK_QNX)
	{
		FmtRelocSize = sizeof(qnx_reloc_item);
	}
	else if (FmtData.type & MK_ELF)
	{
		if (FmtData.u.elf.elf64)
			FmtRelocSize = sizeof(elf64_reloc_item);
		else
			FmtRelocSize = sizeof(elf32_reloc_item);
	}
	else if (FmtData.type & MK_PHAR_MULTISEG)
	{
		FmtRelocSize = sizeof(pms_reloc_item);
	}
	else
	{
		FmtRelocSize = sizeof(dos_addr);
	}
}

bool SpillRelocList(MemorySubsystem *memorySubsystem, SpillFile * spillFile, reloc_info* list)
{
	virt_mem    spill;

	while (list != NULL)
	{
		if (!(list->sizeleft & RELOC_SPILLED))
		{
			spill = spillFile->SpillAlloc(RELOC_PAGE_SIZE);
			spillFile->SpillWrite(spill, 0, list->loc.addr, RELOC_PAGE_SIZE - list->sizeleft);
			memorySubsystem->FreeMemory(list->loc.addr);
			list->loc.spill = spill;
			list->sizeleft |= RELOC_SPILLED;
			return(TRUE);
		}
		list = list->next;
	}
	return(FALSE);
}

bool SpillSections(MemorySubsystem *memorySubsystem, SpillFile * spillFile, section* sect)
{
	for (; sect != NULL; sect = sect->next_sect)
	{
		if (SpillRelocList(memorySubsystem, spillFile, (reloc_info*)sect->reloclist))
			return(TRUE);
		if (SpillAreas(memorySubsystem, spillFile, sect->areas))
		{
			return(TRUE);
		}
	}
	return(FALSE);
}

bool SpillAreas(MemorySubsystem *memorySubsystem, SpillFile * spillFile, OVL_AREA* ovl)
{
	for (; ovl != NULL; ovl = ovl->next_area)
	{
		if (SpillSections(memorySubsystem, spillFile, ovl->sections))
		{
			return(TRUE);
		}
	}
	return(FALSE);
}

bool SwapOutRelocs(MemorySubsystem *memorySubsystem, SpillFile * spillFile)
{
	group_entry* group;

	if (!(LinkState & FMT_DECIDED))
		return(FALSE);
	if (FmtData.type & (MK_OS2_FLAT | MK_PE))
	{
		for (group = Groups; group != NULL; group = group->next_group)
		{
			if (TraverseOS2RelocList(memorySubsystem, spillFile, group, SpillRelocList))
			{
				return(TRUE);
			}
		}
	}
	else if (FmtData.type & (MK_OS2_16BIT | MK_QNX))
	{
		for (group = Groups; group != NULL; group = group->next_group)
		{
			if (SpillRelocList(memorySubsystem, spillFile, (reloc_info*)group->g.grp_relocs))
			{
				return(TRUE);
			}
		}
	}
	else
	{
		if (SpillRelocList(memorySubsystem, spillFile, (reloc_info*)Root->reloclist))
			return(TRUE);
		if (SpillAreas(memorySubsystem, spillFile, Root->areas))
		{
			return(TRUE);
		}
	}
	if (FmtData.type & MK_QNX)
	{
		if (SpillRelocList(memorySubsystem, spillFile, (reloc_info*)FloatFixups))
			return(TRUE);
		return(SpillRelocList(memorySubsystem, spillFile, (reloc_info*)Root->reloclist));
	}
	return(FALSE);
}
