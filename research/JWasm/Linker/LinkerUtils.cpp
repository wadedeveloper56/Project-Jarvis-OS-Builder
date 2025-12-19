#include "pch.h"
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

