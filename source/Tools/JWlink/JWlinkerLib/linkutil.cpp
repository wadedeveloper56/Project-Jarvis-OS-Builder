#include "pch.h"
#include "linkutil.h"
#include "Structs.h"
#include "MemorySubsystem.h"

void FreeList(shared_ptr<MemorySubsystem> memorySubsystem, void* _curr)
{
    node* curr = (node*)_curr;
    node* next_node;

    while (curr)
    {
        next_node = (node*)curr->next;
        memorySubsystem->FreeMemory(curr);
        curr = next_node;
    }
}