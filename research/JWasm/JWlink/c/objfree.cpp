#include "pch.h"
#include "globals.h"
#include "objfree.h"
#include "objnode.h"
#include "objio.h"
#include "mixcache.h"
#include "objorl.h"
#include "debug.h"
#include "permdata.h"
#include "mem.h"
#include "dbgall.h"
#include "mixcache.h"
#include "libr.h"
#include "reloc.h"
#include "ring.h"
#include "objpass1.h"
#include "hash.h"
#include "ovlsupp.h"

void FiniLinkStruct(void)
{
    DEBUG((DBG_OLD, "FiniLinkStruct()"));
    BurnNodes();
    FreeTokBuffs();
    CacheFini();
    ObjORLFini();
}

static void FreeFiles(file_list* list)
{
    void* temp;

    while (list != NULL) {
        temp = list->next_file;
        CacheClose(list, 3);
        if (list->status & STAT_HAS_MEMBER && list->u.member != NULL) {
            FreeList(list->u.member);
        }
        _PermFree(list);
        list = (file_list*)temp;
    }
}

void FreeAMod(mod_entry* mod)
{
    FreeObjCache(mod->f.source);
    FreeModEntry(mod);
}

static void FreeMods(mod_entry* head)
{
    void* temp;

    while (head != NULL) {
        temp = head->n.next_mod;
        FreeAMod(head);
        head = (mod_entry*)temp;
    }
}

static void FreeAGroup(group_entry* group)
{
    CarveFree(CarveGroup, group);
}

void FreeGroups(group_entry* head)
{
    group_entry* next;

    while (head != NULL) {
        next = head->next_group;
        FreeAGroup(head);
        head = next;
    }
}

static void FreeClasses(class_entry* list)
{
    class_entry* next;

    while (list != NULL) {
        next = list->next_class;
        RingWalk(list->segs, FreeLeader);
        CarveFree(CarveClass, list);
        list = next;
    }
}

static void FreeSections(section* sec);

static void FreeAreas(OVL_AREA* area)
{
    OVL_AREA* next;

    while (area != NULL) {
        next = area->next_area;
        FreeSections(area->sections);
        area = next;
    }
}

static void FreeSections(section* sec)
{
    section* next;
    ORDER_CLASS* Class, * NextClass;
    ORDER_SEGMENT* Seg, * NextSeg;

    while (sec != NULL) {
        FreeFiles(sec->files);
        if (!(LinkFlags & INC_LINK_FLAG)) {
            FreeMods(sec->mods);
            FreeClasses(sec->classlist);
        }
        DBISectCleanup(sec);
        FreeAreas(sec->areas);
        ZapHTable(sec->modFilesHashed, LFree);
        Class = sec->orderlist;
        while (Class != NULL) {   // Free up any Order Class entries
            if (Class->Name != NULL) {   // Including members and sucessors
                _LnkFree(Class->Name);
            }
            if (Class->Copy) {
                _LnkFree(Class->SrcName);
            }
            Seg = Class->SegList;
            while (Seg != NULL) {  // Order Seg emtries can also have members and sucessors
                if (Seg->Name != NULL) {
                    _LnkFree(Seg->Name);
                }
                NextSeg = Seg->NextSeg;
                _LnkFree(Seg);
                Seg = NextSeg;
            }
            NextClass = Class->NextClass;
            _LnkFree(Class);
            Class = NextClass;
        }
        next = sec->next_sect;
        _LnkFree(sec);
        sec = next;
    }
}

void CleanLinkStruct(void)
{
    if (Root == NULL) return;  /* haven't finished initializing */
    BurnLibs();
    FreeFiles(ObjLibFiles);
    FreeFiles(Root->files);
    ObjLibFiles = NULL;
    Root->files = NULL;
    if (!(LinkFlags & INC_LINK_FLAG)) {
        FreeMods(LibModules);
    }
    if (SymFileName != NULL) {
        _LnkFree(SymFileName);
    }
    if (FmtData.osname != NULL) {
        _LnkFree(FmtData.osname);
    }
    if (FmtData.resource != NULL) {
        _LnkFree(FmtData.resource);
    }
    FreeRelocInfo();
    FreeGroups(Groups);
    FreeGroups(AbsGroups);
    Groups = NULL;
    AbsGroups = NULL;
    FreeSections(Root);
    DBICleanup();
    Root = NULL;
    if (FmtData.type & MK_REAL_MODE) {
        FreeOvlStruct();
    }
}

