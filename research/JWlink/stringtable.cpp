#include "pch.h"
#include "globals.h"
#include "stringtable.h"
#include "ring.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"

void FiniStringTable(stringtable* strtab)
{
    RingFree(&strtab->data);
}

stringblock* AllocNewBlock(stringtable* strtab)
{
    _ChkAlloc2(stringblock *, blk, sizeof(stringblock));
    blk->next = NULL;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(stringtable* strtab, bool dontsplit)
{
    strtab->data = NULL;
    if (dontsplit) {
        strtab->currbase = 1;
    }
    else {
        strtab->currbase = 0;
    }
    AllocNewBlock(strtab);
}
