#include "pch.h"
#include "MemorySubsystem.h"
#include "objfree.h"
#include "ObjectNode.h"
#include "ObjORL.h"
#include "globals.h"
#include "debug.h"
#include "objio.h"
#include "Structs.h"
#include "linkutil.h"
#include "objcache.h"
#include "objnode.h"
#include "dbgall.h"
#include "libr.h"
#include "reloc.h"
#include "hash.h"
#include "ring.h"
#include "objpass1.h"
#include "ovlsupp.h"

using namespace std;

void FreeAGroup(group_entry* group)
{
    CarveFree(CarveGroup, group);
}

void FreeGroups(group_entry* head)
{
    group_entry* next;

    while (head != NULL)
    {
        next = head->next_group;
        FreeAGroup(head);
        head = next;
    }
}

void FreeAMod(mod_entry* mod)
{
    FreeObjCache(mod->f.source);
    FreeModEntry(mod);
}

void FreeMods(mod_entry* head)
{
    void* temp;

    while (head != NULL)
    {
        temp = head->n.next_mod;
        FreeAMod(head);
        head = (mod_entry*)temp;
    }
}

void FiniLinkStruct(shared_ptr<MemorySubsystem> memorySubsystem)
{
    BurnNodes(memorySubsystem);
    FreeTokBuffs(memorySubsystem);
    CacheFini();
    //ObjORLFini();
}

void FreeClasses(class_entry* list)
{
    class_entry* next;

    while (list != NULL)
    {
        next = list->next_class;
        RingWalk(list->segs, FreeLeader);
        CarveFree(CarveClass, list);
        list = next;
    }
}

void FreeAreas(shared_ptr<MemorySubsystem> memorySubsystem, OVL_AREA* area)
{
    OVL_AREA* next;

    while (area != NULL)
    {
        next = area->next_area;
        FreeSections(memorySubsystem, area->sections);
        area = next;
    }
}

void FreeSections(shared_ptr<MemorySubsystem> memorySubsystem, section* sec)
{
    section* next;
    ORDER_CLASS* Class1, * NextClass;
    ORDER_SEGMENT* Seg, * NextSeg;

    while (sec != NULL)
    {
        FreeFiles(memorySubsystem, sec->files);
        if (!(LinkFlags & INC_LINK_FLAG))
        {
            FreeMods(sec->mods);
            FreeClasses(sec->classlist);
        }
        DBISectCleanup(memorySubsystem, sec);
        FreeAreas(memorySubsystem, sec->areas);
        ZapHTable(sec->modFilesHashed);
        Class1 = sec->orderlist;
        while (Class1 != NULL)
        {         
            if (Class1->Name != NULL)
            {       
                memorySubsystem->FreeMemory(Class1->Name);
            }
            if (Class1->Copy)
            {
                memorySubsystem->FreeMemory(Class1->SrcName);
            }
            Seg = Class1->SegList;
            while (Seg != NULL)
            {           
                if (Seg->Name != NULL)
                {
                    memorySubsystem->FreeMemory(Seg->Name);
                }
                NextSeg = Seg->NextSeg;
                memorySubsystem->FreeMemory(Seg);
                Seg = NextSeg;
            }
            NextClass = Class1->NextClass;
            memorySubsystem->FreeMemory(Class1);
            Class1 = NextClass;
        }
        next = sec->next_sect;
        memorySubsystem->FreeMemory(sec);
        sec = next;
    }
}


void CleanLinkStruct(shared_ptr<MemorySubsystem> memorySubsystem, shared_ptr<SpillFile> spillFile)
{
    if (Root == NULL) return;      
    DEBUG((DBG_OLD, "CleanLinkStruct() enter\n"));
    BurnLibs(memorySubsystem);
    DEBUG((DBG_OLD, "CleanLinkStruct(): calling 1. FreeFiles()\n"));
    FreeFiles(memorySubsystem, ObjLibFiles);
    DEBUG((DBG_OLD, "CleanLinkStruct(): calling 2. FreeFiles()\n"));
    FreeFiles(memorySubsystem, Root->files);
    ObjLibFiles = NULL;
    Root->files = NULL;
    if (!(LinkFlags & INC_LINK_FLAG))
    {
        DEBUG((DBG_OLD, "CleanLinkStruct(): calling FreeMods()\n"));
        FreeMods(LibModules);
    }
    if (SymFileName != NULL)
    {
        memorySubsystem->FreeMemory(SymFileName);
    }
#if 0           
    if (FmtData.osname != NULL)
    {
        memorySubsystem->FreeMemory(FmtData.osname);
    }
#endif
    if (FmtData.resource != NULL)
    {
        memorySubsystem->FreeMemory(FmtData.resource);
    }
    DEBUG((DBG_OLD, "CleanLinkStruct(): calling FreeRelocInfo()\n"));
    FreeRelocInfo(memorySubsystem, spillFile);
    DEBUG((DBG_OLD, "CleanLinkStruct(): calling FreeGroups()\n"));
    FreeGroups(Groups);
    FreeGroups(AbsGroups);
    DEBUG((DBG_OLD, "CleanLinkStruct(): calling FreeSections()\n"));
    Groups = NULL;
    AbsGroups = NULL;
    FreeSections(memorySubsystem, Root);
    FreeGroups(DBIGroups);
    Root = NULL;
    if (FmtData.type & MK_REAL_MODE)
    {
        FreeOvlStruct(memorySubsystem);
    }
}

void FreeFiles(shared_ptr<MemorySubsystem> memorySubsystem, file_list* list)
{
    void* temp;

    while (list != NULL)
    {
        temp = list->next_file;
        CacheClose(memorySubsystem, list, 3);
        if (list->status & STAT_HAS_MEMBER && list->u.member != NULL)
        {
            FreeList(memorySubsystem, list->u.member);
        }
        memorySubsystem->FreeMemory(list);
        list = (file_list*)temp;
    }
}
