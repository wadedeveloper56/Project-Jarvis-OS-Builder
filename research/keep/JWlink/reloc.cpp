#include "pch.h"
#include "globals.h"
#include "alloc.h"
#include "reloc.h"
#include "spillio.h"
#include "debug.h"
#include "overlays.h"
#include "loadfile.h"

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
    FloatFixups = NULL;
}

static reloc_info* AllocRelocInfo(void)
{
    reloc_info* info;

    _PermAlloc(reloc_info * ,info, sizeof(reloc_info));       /* allocate more */
    info->sizeleft = RELOC_PAGE_SIZE;
    _LnkAlloc(void *, info->loc.addr, RELOC_PAGE_SIZE);
    if (info->loc.addr == NULL) {
        info->loc.spill = SpillAlloc(RELOC_PAGE_SIZE);
        info->sizeleft |= RELOC_SPILLED;
    }
    return(info);
}

static void* OS2PagedRelocInit(offset size, int unitsize)
{
    void** mem;
    void** start;
    offset      pageidx;
    offset      idxhigh;
    unsigned    idxlow;
    unsigned    allocsize;

    pageidx = OSF_PAGE_COUNT(size);
    idxhigh = OSF_RLIDX_HIGH(pageidx);
    _PermAlloc(void**, mem, (idxhigh + 1) * sizeof(void*));
    start = mem;
    allocsize = OSF_RLIDX_MAX * unitsize;
    while (idxhigh > 0) {
        _ChkAlloc(void*, *mem, allocsize);
        memset(*mem, 0, allocsize);
        mem++;
        idxhigh--;
    }
    idxlow = OSF_RLIDX_LOW(pageidx);
    if (idxlow != 0) {
        allocsize = idxlow * unitsize;
        _ChkAlloc(void*, *mem, allocsize);
        memset(*mem, 0, allocsize);
    }
    return(start);
}

static void* OS2FlatRelocInit(offset size)
{
    return(OS2PagedRelocInit(size, sizeof(os2_reloc_header)));
}

static void* PERelocInit(offset size)
{
    return(OS2PagedRelocInit(size, sizeof(reloc_info*)));
}

static void DoWriteReloc(void* lst, void* reloc, unsigned size)
{
    reloc_info** list = (reloc_info**)lst;
    reloc_info* info;
    unsigned        offset;

    info = *(reloc_info**)list;
    if (info == NULL) {
        info = AllocRelocInfo();
        info->next = NULL;
        *list = info;
    }
    if ((info->sizeleft & SIZELEFT_MASK) < size) {     /* if no space */
        info = AllocRelocInfo();
        info->next = *list;
        *list = info;
    }
    offset = RELOC_PAGE_SIZE - (info->sizeleft & SIZELEFT_MASK);
    if (info->sizeleft & RELOC_SPILLED) {
        SpillWrite(info->loc.spill, offset, reloc, size);
    }
    else {
        memcpy((char*)(info->loc.addr) + offset, reloc, size);
    }
    info->sizeleft -= size;
}

void WriteReloc(group_entry* group, offset off, void* reloc, unsigned size)
{
    os2_reloc_header** pagelist;
    reloc_info*** reloclist;
    reloc_info** header;
    unsigned_32         idx;

    if (FmtData.type & MK_PE) {
        reloclist = (reloc_info***)group->g.grp_relocs;
        if (reloclist == NULL) {
            reloclist = (reloc_info***)PERelocInit(group->totalsize);
            group->g.grp_relocs = reloclist;
        }
        idx = (off - group->grp_addr.off) >> OSF_PAGE_SHIFT;
        header = &reloclist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)];
        DoWriteReloc(header, reloc, size);
    }
    else if (FmtData.type & MK_OS2_FLAT) {
        pagelist = (os2_reloc_header**)group->g.grp_relocs;
        if (pagelist == NULL) {
            pagelist = (os2_reloc_header**)OS2FlatRelocInit(group->totalsize);
            group->g.grp_relocs = pagelist;
        }
        idx = (off - group->grp_addr.off) >> OSF_PAGE_SHIFT;
        header = &pagelist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)].externals;
        switch (((os2_flat_reloc_item*)reloc)->fmt.nr_flags & OSF_TARGET_MASK) {
            case INTERNAL_REFERENCE:
                switch (((os2_flat_reloc_item*)reloc)->fmt.nr_stype) {
                    case OFFSET_ONLY:
                    case OFFSET48_ONLY:
                    case OFFSET48_RELATIVE:
                        //NYI: don't have to write this out if we can figure out
                        // how to tell the loader that we're doing it.
                        header =
                            &pagelist[OSF_RLIDX_HIGH(idx)][OSF_RLIDX_LOW(idx)].internals;
                        break;
                }
                break;
        }
        DoWriteReloc(header, reloc, size);
    }
    else if (FmtData.type & (MK_OS2_16BIT | MK_ELF)) {
        DoWriteReloc(&group->g.grp_relocs, reloc, size);
    }
    else {
        DoWriteReloc(&group->section->reloclist, reloc, size);
    }
    group->section->relocs++;
}

#ifdef _QNXLOAD
void FloatReloc(reloc_item* item)
{
    DoWriteReloc(&FloatFixups, item, sizeof(qnx_reloc_item));
}

void QNXLinearReloc(group_entry* group, reloc_item* item)
{
    DoWriteReloc(&group->g.grp_relocs, item, sizeof(qnx_linear_item));
}
#endif

static bool FreeRelocList(reloc_info* list)
{
    while (list != NULL) {
        if (!(list->sizeleft & RELOC_SPILLED)) {
            _LnkFree(list->loc.addr);
        }
        list = list->next;
    }
    return(false);  /* needed for OS2 generic traversal routines */
}

static void FreeRelocSect(section* sect)
{
    FreeRelocList((reloc_info*)sect->reloclist);
}

static bool TraverseRelocBlock(reloc_info** reloclist, unsigned num, bool (*fn)(reloc_info*))
{
    while (num > 0) {
        if (fn(*reloclist++))
            return(true);
        if (FmtData.type & MK_OS2_FLAT) {
            if (fn(*reloclist++)) {
                return(true);
            }
        }
        num--;
    }
    return(false);
}

bool TraverseOS2RelocList(group_entry* group, bool (*fn)(reloc_info*))
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
            if (TraverseRelocBlock(*reloclist, OSF_RLIDX_MAX, fn))
                return(true);
            reloclist++;
            highidx--;
        }
        lowidx = OSF_RLIDX_LOW(index);
        if (lowidx > 0) {
            return(TraverseRelocBlock(*reloclist, OSF_RLIDX_LOW(index), fn));
        }
    }
    return(false);
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
        FreeRelocList((reloc_info*)group->g.grp_relocs);
    }
}

void FreeRelocInfo(void)
{
    group_entry* group;

    if (!(LinkState & MAKE_RELOCS))
        return;
    if (FmtData.type & (MK_ELF | MK_OS2_FLAT | MK_PE | MK_OS2_16BIT | MK_QNX)) {
        for (group = Groups; group != NULL; group = group->next_group) {
            FreeGroupRelocs(group);
        }
    }
    else if (Root != NULL) {
        WalkAllSects(FreeRelocSect);
    }
    if (FmtData.type & MK_QNX) {
        FreeRelocList(FloatFixups);
        FreeRelocSect(Root);
    }
}

unsigned_32 RelocSize(reloc_info* list)
/***********************************************/
/* find the size of all the relocations stored here */
{
    unsigned_32 size;

    size = 0;
    while (list != NULL) {
        size += RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
        list = list->next;
    }
    return(size);
}

unsigned_32 DumpMaxRelocList(reloc_info** head, unsigned_32 max)
{
    unsigned_32         size;
    unsigned_32         total;
    reloc_info* list;

    total = 0;
    list = *head;
    DEBUG((DBG_OLD, (char*)"DumpMaxRelocList() enter"));
    for (;; ) {
        if (list == NULL)
            break;
        size = RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
        if ((max != 0) && (total != 0) && ((total + size) >= max))
            break;
        if (size != 0) {
            if (list->sizeleft & RELOC_SPILLED) {
                SpillRead(list->loc.spill, 0, TokBuff, size);
                WriteLoad(TokBuff, size);
            }
            else {
                WriteLoad(list->loc.addr, size);
            }
        }
        DEBUG((DBG_OLD, (char*)"DumpMaxRelocList(): addr=%h size=%h", list->loc.addr, size));
        list = list->next;
        total += size;
    }
    *head = list;
    return(total);
}

bool DumpRelocList(reloc_info* list)
/********************************************/
{
    DumpMaxRelocList(&list, 0);
    return(false);            /* so traverse works */
}

unsigned_32 WalkRelocList(reloc_info** head, bool (*fn)(void* data, unsigned_32 size, void* ctx), void* ctx)
/**************************************************************************************************************/
/* walk the given reloc information list and call user fn for each reloc */
{
    unsigned_32         size;
    unsigned_32         total;
    reloc_info* list;
    bool                quit = false;

    total = 0;
    list = *head;
    for (;; ) {
        if ((list == NULL) || quit)
            break;
        size = RELOC_PAGE_SIZE - (list->sizeleft & SIZELEFT_MASK);
        if (size != 0) {
            if (list->sizeleft & RELOC_SPILLED) {
                SpillRead(list->loc.spill, 0, TokBuff, size);
                quit = fn(TokBuff, size, ctx);
            }
            else {
                quit = fn(list->loc.addr, size, ctx);
            }
        }
        list = list->next;
        total += size;
    }
    *head = list;
    return(total);
}

void SetRelocSize(void)
/******************************/
{
    if (FmtData.type & (MK_OS2 | MK_WIN_VXD)) {
        FmtRelocSize = sizeof(os2_reloc_item);
    }
    else if (FmtData.type & MK_PE) {
        FmtRelocSize = sizeof(pe_reloc_item);
    }
    else if (FmtData.type & MK_NOVELL) {
        FmtRelocSize = sizeof(nov_reloc_item);
    }
    else if (FmtData.type & MK_PHAR_REX) {
        FmtRelocSize = sizeof(rex_reloc_item);
    }
    else if (FmtData.type & MK_QNX) {
        FmtRelocSize = sizeof(qnx_reloc_item);
    }
    else if (FmtData.type & MK_ELF) {
        // elf_reloc_item contains pointer to symbol which gets
        // converted later on into index into symbol table
        if (FmtData.u.elf.elf64)
            FmtRelocSize = sizeof(elf64_reloc_item);
        else
            FmtRelocSize = sizeof(elf32_reloc_item);
    }
    else if (FmtData.type & MK_PHAR_MULTISEG) {
        FmtRelocSize = sizeof(pms_reloc_item);
    }
    else {
        FmtRelocSize = sizeof(dos_addr);
    }
}


static bool SpillRelocList(reloc_info* list)
/*********************************************/
/* spill any reloc blocks pointed to by list */
{
    virt_mem    spill;

    while (list != NULL) {
        if (!(list->sizeleft & RELOC_SPILLED)) {
            spill = SpillAlloc(RELOC_PAGE_SIZE);
            SpillWrite(spill, 0, list->loc.addr,
                RELOC_PAGE_SIZE - list->sizeleft);
            _LnkFree(list->loc.addr);
            list->loc.spill = spill;
            list->sizeleft |= RELOC_SPILLED;
            return(true);
        }
        list = list->next;
    }
    return(false);
}

static bool SpillAreas(OVL_AREA* ovl);

static bool SpillSections(section* sect)
/****************************************/
{
    for (; sect != NULL; sect = sect->next_sect) {
        if (SpillRelocList((reloc_info*)sect->reloclist))
            return(true);
        if (SpillAreas(sect->areas)) {
            return(true);
        }
    }
    return(false);
}

static bool SpillAreas(OVL_AREA* ovl)
/************************************/
{
    for (; ovl != NULL; ovl = ovl->next_area) {
        if (SpillSections(ovl->sections)) {
            return(true);
        }
    }
    return(false);
}

bool SwapOutRelocs(void)
/*******************************/
{
    group_entry* group;

    if (!(LinkState & FMT_DECIDED))
        return(false);
    if (FmtData.type & (MK_OS2_FLAT | MK_PE)) {
        for (group = Groups; group != NULL; group = group->next_group) {
            if (TraverseOS2RelocList(group, SpillRelocList)) {
                return(true);
            }
        }
    }
    else if (FmtData.type & (MK_OS2_16BIT | MK_QNX)) {
        for (group = Groups; group != NULL; group = group->next_group) {
            if (SpillRelocList((reloc_info*)group->g.grp_relocs)) {
                return(true);
            }
        }
    }
    else {
        if (SpillRelocList((reloc_info*)Root->reloclist))
            return(true);
        if (SpillAreas(Root->areas)) {
            return(true);
        }
    }
    if (FmtData.type & MK_QNX) {
        if (SpillRelocList(FloatFixups))
            return(true);
        return(SpillRelocList((reloc_info*)Root->reloclist));
    }
    return(false);
}
