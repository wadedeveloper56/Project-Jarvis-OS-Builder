#include "pch.h"
#include "globals.h"
#include "strtab.h"
#include "mem.h"
#include "ring.h"

static stringblock* AllocNewBlock(stringtable* strtab)
{
    stringblock* blk;

    _ChkAlloc(stringblock * , blk, sizeof(stringblock));
    blk->next = nullptr;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(stringtable* strtab, bool dontsplit)
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

void FiniStringTable(stringtable* strtab)
{
    RingFree(&strtab->data);
}
