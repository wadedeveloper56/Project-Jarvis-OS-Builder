#include "pch.h"
#include "globals.h"
#include "reloc.h"
#include "mem.h"
#include "overlays.h"

typedef union {
    unsigned long   spill;
    void* addr;
} spilladdr;

/* note: if either of these two structures get any bigger, the magic constants
 * in the RLIDX_* macros will have to change to ensure that no allocation > 64k
 * occurs. */

typedef struct reloc_info {
    struct reloc_info* next;
    unsigned            sizeleft;
    spilladdr           loc;
} reloc_info;

typedef struct os2_reloc_header {
    reloc_info* externals; /* external and segment style fixups */
    reloc_info* internals; /* internal, non-segment fixups */
} os2_reloc_header;

#define RELOC_PAGE_SIZE 512
#define RELOC_SPILLED   0x8000
#define SIZELEFT_MASK   0x7FFF

unsigned        FmtRelocSize;
reloc_info* FloatFixups;

void ResetReloc(void)
{
    FloatFixups = nullptr;
}

static bool FreeRelocList(reloc_info* list)
{
    while (list != nullptr) {
        if (!(list->sizeleft & RELOC_SPILLED)) {
            _LnkFree(list->loc.addr);
        }
        list = list->next;
    }
    return(FALSE);  /* needed for OS2 generic traversal routines */
}

static void FreeRelocSect(section* sect)
{
    FreeRelocList((reloc_info*)sect->reloclist);
}

static bool TraverseRelocBlock(reloc_info** reloclist, unsigned num,  bool (*fn)(reloc_info*))
{
    while (num > 0) {
        if (fn(*reloclist++))
            return(TRUE);
        if (FmtData.type & MK_OS2_FLAT) {
            if (fn(*reloclist++)) {
                return(TRUE);
            }
        }
        num--;
    }
    return(FALSE);
}

bool TraverseOS2RelocList(group_entry* group, bool (*fn)(reloc_info*))
{
    unsigned_32         index;
    unsigned_32         highidx;
    unsigned            lowidx;
    reloc_info*** reloclist;

    reloclist = (reloc_info***)group->g.grp_relocs;
    if (reloclist != nullptr) {
        index = OSF_PAGE_COUNT(group->totalsize);
        highidx = OSF_RLIDX_HIGH(index);
        while (highidx > 0) {
            if (TraverseRelocBlock(*reloclist, OSF_RLIDX_MAX, fn))
                return(TRUE);
            reloclist++;
            highidx--;
        }
        lowidx = OSF_RLIDX_LOW(index);
        if (lowidx > 0) {
            return(TraverseRelocBlock(*reloclist, OSF_RLIDX_LOW(index), fn));
        }
    }
    return(FALSE);
}

static void FreeGroupRelocs(group_entry* group)
{
    unsigned_32         highidx;
    unsigned_32         index;
    reloc_info*** reloclist;

    if (!(LinkState & MAKE_RELOCS))
        return;
    if (FmtData.type & (MK_OS2_FLAT | MK_PE)) {
        TraverseOS2RelocList(group, FreeRelocList);
        reloclist = (reloc_info***)group->g.grp_relocs;
        if (reloclist != nullptr) {
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
        FreeRelocList((reloc_info*)group->g.grp_relocs);
    }
}

void FreeRelocInfo(void)
{
    group_entry* group;

    if (!(LinkState & MAKE_RELOCS))
        return;
    if (FmtData.type & (MK_ELF | MK_OS2_FLAT | MK_PE | MK_OS2_16BIT | MK_QNX)) {
        for (group = Groups; group != nullptr; group = group->next_group) {
            FreeGroupRelocs(group);
        }
    }
    else if (Root != nullptr) {
        WalkAllSects(FreeRelocSect);
    }
    if (FmtData.type & MK_QNX) {
        FreeRelocList(FloatFixups);
        FreeRelocSect(Root);
    }
}
