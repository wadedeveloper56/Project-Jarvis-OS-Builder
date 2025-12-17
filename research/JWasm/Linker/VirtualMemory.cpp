#include "VirtualMemory.h"
#include "globals.h"

VirtualMemory::VirtualMemory(MemorySubsystem* memory)
{
	this->memory = memory;
	VMemBlocks = nullptr;
}

VirtualMemory::~VirtualMemory()
{
	FreeList(VMemBlocks);
	VMemBlocks = nullptr;
}

void VirtualMemory::FreeList(void* _curr)
{
    node* curr = (node *)_curr;
    node* next_node;

    while (curr) {
        next_node = (node*)curr->next;
        memory->FreeMemory(curr);
        curr = next_node;
    }
}