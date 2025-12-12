#include "pch.h"
#include "globals.h"
#include "symmem.h"
#include "permdata.h"

#define SYM_BLOCK_SIZE      (16*1024)
#define SYM_BLOCK_MIN       32

typedef struct sym_block {
    struct sym_block* next;       /* NOTE: this *must* be the first field */
    unsigned            size;
    char                block[1];
} sym_block;

#define ALLOC_SIZE  (sizeof( sym_block )-1)

typedef struct block_data {
    sym_block* list;
    unsigned        currbrk;
} block_data;

static block_data Pass1Blocks;
static block_data PermBlocks;

void GetSymBlock(void)
{
    PermBlocks.list = nullptr;
}

void ReleasePass1(void)
{
    FreeList(Pass1Blocks.list);
    Pass1Blocks.list = nullptr;
}

void RelSymBlock(void)
{
    FreeList(PermBlocks.list);
    PermBlocks.list = nullptr;
}
