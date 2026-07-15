#include "pch.h"
#include "StringTable.h"

StringTable::StringTable(MemorySubsystem* memorySubsystem) : memorySubsystem(memorySubsystem), strtab(nullptr)
{
}

StringTable::~StringTable()
{
}

stringblock* StringTable::AllocNewBlock()
{
    stringblock* blk;

    _ChkAlloc(stringblock*, blk, sizeof(stringblock));
    blk->next = NULL;
    //RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void StringTable::InitStringTable(bool dontsplit)
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
    AllocNewBlock();
}

