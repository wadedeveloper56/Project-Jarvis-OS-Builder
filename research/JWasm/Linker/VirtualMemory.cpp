#include "pch.h"
#include "VirtualMemory.h"
#include "globals.h"
#include "LinkerUtils.h"

VirtualMemory::VirtualMemory(MemorySubsystem* memory)
{
	this->memory = memory;
	VMemBlocks = nullptr;
}

VirtualMemory::~VirtualMemory()
{
	FreeList(memory, VMemBlocks);
	VMemBlocks = nullptr;
}
