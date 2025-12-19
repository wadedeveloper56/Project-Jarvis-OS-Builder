#include "pch.h"
#include "globals.h"
#include "reloc.h"
#include "MemorySubsystem.h"

unsigned FmtRelocSize;
reloc_info* FloatFixups;

void ResetReloc(void)
{
    FloatFixups = nullptr;
}

static bool TraverseRelocBlock(MemorySubsystem* memory, reloc_info** reloclist, unsigned num, bool (*fn)(MemorySubsystem*,reloc_info*))
{
    while (num > 0) {
        if (fn(memory,*reloclist++))
            return(true);
        if (FmtData.type & MK_OS2_FLAT) {
            if (fn(memory,*reloclist++)) {
                return(true);
            }
        }
        num--;
    }
    return(false);
}

bool TraverseOS2RelocList(MemorySubsystem* memory,group_entry* group, bool (*fn)(MemorySubsystem*,reloc_info*))
{
    unsigned_32         index;
    unsigned_32         highidx;
    unsigned            lowidx;
    reloc_info*** reloclist;

    reloclist = (reloc_info***)group->g.grp_relocs;
    if (reloclist != NULL) {
        index = OSF_PAGE_COUNT(group->totalsize);
        highidx = OSF_RLIDX_HIGH(index);
        while (highidx > 0) {
            if (TraverseRelocBlock(memory, *reloclist, OSF_RLIDX_MAX, fn))
                return(true);
            reloclist++;
            highidx--;
        }
        lowidx = OSF_RLIDX_LOW(index);
        if (lowidx > 0) {
            return(TraverseRelocBlock(memory, *reloclist, OSF_RLIDX_LOW(index), fn));
        }
    }
    return(false);
}

static bool FreeRelocList(MemorySubsystem* memory, reloc_info* list)
{
    while (list != NULL) {
        if (!(list->sizeleft & RELOC_SPILLED)) {
            _LnkFree(list->loc.addr);
        }
        list = list->next;
    }
    return(false);  /* needed for OS2 generic traversal routines */
}

static void FreeGroupRelocs(MemorySubsystem *memory, group_entry* group)
{
    unsigned_32         highidx;
    unsigned_32         index;
    reloc_info*** reloclist;

    if (!(LinkState & MAKE_RELOCS))
        return;
    if (FmtData.type & (MK_OS2_FLAT | MK_PE)) {
        TraverseOS2RelocList(memory, group, FreeRelocList);
        reloclist = (reloc_info***)group->g.grp_relocs;
        if (reloclist != NULL) {
            index = OSF_PAGE_COUNT(group->totalsize);
            highidx = OSF_RLIDX_HIGH(index);
            if (OSF_RLIDX_LOW(index) != 0) {
                highidx++;
            }
            while (highidx > 0) {
                _LnkFree(*reloclist);
                reloclist++;
                highidx--;
            }
        }
    }
    else if (FmtData.type & (MK_ELF | MK_OS2_16BIT | MK_QNX)) {
        FreeRelocList(memory, (reloc_info*)group->g.grp_relocs);
    }
}

static void FreeRelocSect(MemorySubsystem*memory,section* sect)
{
    FreeRelocList(memory, (reloc_info *)sect->reloclist);
}

void FreeRelocInfo(MemorySubsystem* memory)
{
    group_entry* group;

    if (!(LinkState & MAKE_RELOCS))
        return;
    if (FmtData.type & (MK_ELF | MK_OS2_FLAT | MK_PE | MK_OS2_16BIT | MK_QNX)) {
        for (group = Groups; group != NULL; group = group->next_group) {
            FreeGroupRelocs(memory, group);
        }
    }
    else if (Root != NULL) {
        //FIX ME WalkAllSects(FreeRelocSect);
    }
    if (FmtData.type & MK_QNX) {
        FreeRelocList(memory, FloatFixups);
        FreeRelocSect(memory, Root);
    }
}
