#include "StringTable.h"

StringTable::StringTable(MemorySubsystem* memory, Ring* ring)
{
	this->memory = memory;
	this->ring = ring;
}

StringTable::~StringTable()
{
}

stringblock* StringTable::AllocNewBlock(stringtable* strtab)
{
    stringblock* blk = (stringblock*)memory->AllocateMemory(sizeof(stringblock));
    blk->next = nullptr;
    ring->RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void StringTable::InitStringTable(stringtable* strtab, bool dontsplit)
{
    strtab->data = nullptr;
    if (dontsplit) {
        strtab->currbase = 1;
    }
    else {
        strtab->currbase = 0;
    }
    AllocNewBlock(strtab);
}

void StringTable::FiniStringTable(stringtable* table)
{
    ring->RingFree(&table->data);
}
