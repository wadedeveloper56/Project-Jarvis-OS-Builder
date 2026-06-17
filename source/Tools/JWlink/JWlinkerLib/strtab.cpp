#include "pch.h"
#include "Structs.h"
#include "MemorySubsystem.h"
#include "ring.h"

using namespace std;
#define STR_BLOCK_SIZE   (4*1024)

stringblock* AllocNewBlock(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab)
{
	stringblock* blk = (stringblock*)memorySubsystem->AllocateMemory(sizeof(stringblock));
    blk->next = NULL;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(shared_ptr<MemorySubsystem> memorySubsystem, stringtable* strtab, bool dontsplit)
{
    strtab->data = NULL;
    if (dontsplit)
    {
        strtab->currbase = 1;
    }
    else
    {
        strtab->currbase = 0;
    }
    AllocNewBlock(memorySubsystem, strtab);
}
