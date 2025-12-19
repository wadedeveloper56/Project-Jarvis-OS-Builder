#pragma once

#include "MemorySubsystem.h"

typedef struct vmemblock {
	struct vmemblock* next;
	struct vmemblock* prev;
	char                mem[1];
} vmemblock;

class VirtualMemory
{
	vmemblock* VMemBlocks;
	MemorySubsystem* memory;
public:
	VirtualMemory(MemorySubsystem* memory);
	~VirtualMemory();
};

