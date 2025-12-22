#include "pch.h"
#include "SymbolTableMemory.h"
#include "LinkerUtils.h"

SymbolTableMemory::SymbolTableMemory(MemorySubsystem* memory)
{
	this->memory = memory;
	Pass1Blocks.list = nullptr;
	PermBlocks.list = nullptr;
}

SymbolTableMemory::~SymbolTableMemory()
{
}

void SymbolTableMemory::RelSymBlock(void)
{
	FreeList(memory, PermBlocks.list);
	PermBlocks.list = NULL;
}

void SymbolTableMemory::ReleasePass1(void)
{
	FreeList(memory, Pass1Blocks.list);
	Pass1Blocks.list = NULL;
}
