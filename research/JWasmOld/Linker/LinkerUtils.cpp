#include "pch.h"
#include "globals.h"
#include "LinkerUtils.h"
#include "structures.h"

bool TestBit(int_8* array, unsigned num)
{
    int_8 mask = 1 << (num % 8);
    num /= 8;
    return(*(array + num) & mask);
}

void FreeList(MemorySubsystem* memory, void* _curr)
{
    node* curr = (node*)_curr;
    node* next_node;

    while (curr) {
        next_node = (node*)curr->next;
        memory->FreeMemory(curr);
        curr = next_node;
    }
}

void WalkSections(MemorySubsystem* memory,section* sect, void (*rtn)(MemorySubsystem*,section*))
{
    for (; sect != NULL; sect = sect->next_sect) {
        rtn(memory,sect);
        WalkAreas(memory,sect->areas, rtn);
    }
}

void WalkAreas(MemorySubsystem* memory,OVL_AREA* ovl, void (*rtn)(MemorySubsystem*,section*))
{
    for (; ovl != NULL; ovl = ovl->next_area) {
        WalkSections(memory,ovl->sections, rtn);
    }
}

void WalkAllSects(MemorySubsystem* memory,void (*rtn)(MemorySubsystem*,section*))
{
    rtn(memory,Root);
    if (FmtData.type & MK_OVERLAYS) {
        WalkAreas(memory, Root->areas, rtn);
    }
}
