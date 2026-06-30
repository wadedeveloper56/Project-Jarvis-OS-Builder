#include "pch.h"
#include "VirtualMemory.h"
#include "linkutil.h"
#include "MemorySubsystem.h"

using namespace std;

VirtualMemory::VirtualMemory(MemorySubsystem *memorySubsystem)
{
	VMemBlocks = nullptr;
	this->memorySubsystem = memorySubsystem;
}

VirtualMemory::~VirtualMemory()
{
	FreeList(memorySubsystem, VMemBlocks);
	VMemBlocks = NULL;
}

