#pragma once

#include "MemorySubsystem.h"

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

class SymbolTableMemory
{
	MemorySubsystem* memory;
	block_data Pass1Blocks;
	block_data PermBlocks;
public:
	SymbolTableMemory(MemorySubsystem* memory);
	~SymbolTableMemory();
	void RelSymBlock(void);
	void ReleasePass1(void);
};

