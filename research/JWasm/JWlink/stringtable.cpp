#include "pch.h"
#include "globals.h"
#include "stringtable.h"
#include "ring.h"

stringblock* AllocNewBlock(MemorySubsystem* memory, stringtable* strtab)
{
    _ChkAlloc2(stringblock *, blk, sizeof(stringblock));
    blk->next = NULL;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(MemorySubsystem* memory, stringtable* strtab, bool dontsplit)
{
    strtab->data = NULL;
    if (dontsplit) {
        strtab->currbase = 1;
    }
    else {
        strtab->currbase = 0;
    }
    AllocNewBlock(memory, strtab);
}
