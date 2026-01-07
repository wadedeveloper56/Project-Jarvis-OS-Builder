#include "pch.h"
#include "symmem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "MemorySubsystem.h"

#define SYM_BLOCK_SIZE      (16*1024)
#define SYM_BLOCK_MIN       32
#define ALLOC_SIZE  (sizeof( sym_block )-1)

extern block_data Pass1Blocks;
extern block_data PermBlocks;

bool ShrinkBlock(block_data* block)
{
    /* There is no guarantee realloc() won't move memory - just don't do it */
    return(false);
}

void GetNewBlock(block_data* block, unsigned size)
{
    unsigned   try1;
    sym_block* new1;

    ShrinkBlock(block);
    try1 = SYM_BLOCK_SIZE;
    if (try1 < size) try1 = size;
    for (;; ) {
        _LnkAlloc(sym_block*, new1, try1 + ALLOC_SIZE);
        if (new1 != NULL) break;
        try1 /= 2;
        if (try1 < size || try1 < SYM_BLOCK_MIN) {
            msg->LnkMsg(FTL + MSG_NO_DYN_MEM, NULL);
        }
    }
    new1->next = block->list;
    block->list = new1;
    new1->size = try1;
    block->currbrk = 0;
}

void* AllocBlock(unsigned size, block_data* block)
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

void* Pass1Alloc(size_t size)
{
    return(AllocBlock(size, &Pass1Blocks));
}

void* PermAlloc(size_t size)
{
    return(AllocBlock(size, &PermBlocks));
}

