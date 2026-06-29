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

void LinkList(void* in_head, void* newnode)
{
    node** owner;

    owner = (node**)&in_head;
    ((node*)newnode)->next = NULL;
    while (*owner != NULL)
    {
        owner = (node**)&(*owner)->next;
    }
    *owner = (node*)newnode;
}

