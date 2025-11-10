#include "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "strtab.h"
#include "carve.h"
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

static bool ShrinkBlock(block_data* block)
{
#ifdef __WATCOMC__
    sym_block* new;

    if (block->list == NULL) return(FALSE);
    if (block->currbrk >= block->list->size) return(FALSE);
    _LnkReAlloc(new, block->list, block->currbrk + ALLOC_SIZE);
    new->size = block->currbrk;
    /* assuming that a shrinkage will not move the block */
#if _DEVELOPMENT == _ON
    if (new != block->list) {
        LnkMsg(FTL + MSG_INTERNAL, "s", "realloc moved shrinked block!");
    }
#endif
    return(TRUE);
#else
    /* There is no guarantee realloc() won't move memory - just don't do it */
    return(FALSE);
#endif
}

static void GetNewBlock(block_data* block, unsigned size)
{
    unsigned            try1;
    sym_block* new1;

    ShrinkBlock(block);
    try1 = SYM_BLOCK_SIZE;
    if (try1 < size) try1 = size;
    for (;; ) {
        _LnkAlloc(sym_block * ,new1, try1 + ALLOC_SIZE);
        if (new1 != NULL) break;
        try1 /= 2;
        if (try1 < size || try1 < SYM_BLOCK_MIN) {
            LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
        }
    }
    new1->next = block->list;
    block->list = new1;
    new1->size = try1;
    block->currbrk = 0;
}

static void* AllocBlock(unsigned size, block_data* block)
{
    void* ptr;
    unsigned long       newbrk;

#define ROUND (sizeof(int)-1)

    size = (size + ROUND) & ~ROUND;
    newbrk = (unsigned long)block->currbrk + size;
    if (block->list == NULL) {
        GetNewBlock(block, size);
    }
    else if (newbrk > block->list->size) {
#ifndef __V80_LIB__
        ptr = NULL;
        if (newbrk < UINT_MAX - ALLOC_SIZE) {
            /* try to expand block without moving it */
            _LnkExpand(void *, ptr, block->list, ALLOC_SIZE + newbrk);
        }
        if (ptr != NULL) {
            block->list->size = newbrk;
        }
        else {
#else
            {
#endif
                GetNewBlock(block, size);
            }
        }
    ptr = block->list->block + block->currbrk;
    block->currbrk += size;
    return(ptr);
    }

bool PermShrink(void)
{
	return false;
}

void* PermAlloc(size_t size)
{
	return(AllocBlock(size, &PermBlocks));
}

void GetSymBlock(void)
{
    PermBlocks.list = NULL;
}
