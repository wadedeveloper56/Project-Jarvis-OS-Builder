#include "pch.h"
#include "cmddos.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "Structs.h"
#include "globals.h"
#include "cmdline.h"
#include "cmdutils.h"

::byte            OvlLevel;

void SetOvlClasses(MemorySubsystem* memorySubsystem)
{
    list_of_names* ovlmgr;

    if (OvlClasses != NULL)
    {
        _LnkAlloc(list_of_names*, ovlmgr, sizeof(list_of_names) + OVL_MGR_CL_LEN);
        memcpy(ovlmgr->name, OvlMgrClass, OVL_MGR_CL_LEN + 1);
        ovlmgr->next_name = OvlClasses;
        OvlClasses = ovlmgr;
    }
}

void NewArea(MemorySubsystem* memorySubsystem, section* sect)
{
    ovl_area* ovl;
    ovl_area** owner;

    _LnkAlloc(ovl_area*, ovl, sizeof(ovl_area));
    ovl->next_area = NULL;
    ovl->sections = sect;
    sect->parent = CurrSect;
    owner = &CurrSect->areas;
    while (*owner != NULL)
    {
        owner = &(*owner)->next_area;
    }
    *owner = ovl;
}

void MakeNonArea(MemorySubsystem* memorySubsystem)
{
    NonSect = NewSection(memorySubsystem);
    NewArea(memorySubsystem, NonSect);
}

void CmdOvlFini(MemorySubsystem* memorySubsystem, FileSubsystem* fileSubsystem, MessagingSubsystem* messagingSubsystem)
{
    if (OvlLevel != 0)
    {
        Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
        messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_EXPECTING_END, NULL);
    }
    if (FmtData.u.dos.dynamic &&
        ((Root->areas == NULL) || (Root->areas->next_area != NULL)))
    {
        Ignite(memorySubsystem, fileSubsystem, messagingSubsystem);
        messagingSubsystem->LnkMsg(LOC + LINE + FTL + MSG_INCORRECT_NUM_AREAS, NULL);
    }
    SetOvlClasses(memorySubsystem);
    MakeNonArea(memorySubsystem);
#ifdef _INT_DEBUG
    PrintOvl();
#endif
}
