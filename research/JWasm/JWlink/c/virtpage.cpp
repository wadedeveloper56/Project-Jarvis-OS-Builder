#include "pch.h"
#include "globals.h"
#include "virtpage.h"
#include "permdata.h"

typedef struct vmemblock {
    struct vmemblock* next;
    struct vmemblock* prev;
    char                mem[1];
} vmemblock;

static vmemblock* VMemBlocks;

#define TINY_ALLOC_CUTOFF (2*1024)

void VirtMemInit(void)
{
    VMemBlocks = nullptr;
}

void FreeVirtMem(void)
{
    FreeList(VMemBlocks);
    VMemBlocks = nullptr;
}