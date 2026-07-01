#include "pch.h"
#include "VirtualMemory.h"
#include "linkutil.h"
#include "MemorySubsystem.h"
#include "debug.h"

using namespace std;

VirtualMemory::VirtualMemory(MemorySubsystem *memorySubsystem)
{
	VMemBlocks = nullptr;
	this->memorySubsystem = memorySubsystem;
}

VirtualMemory::~VirtualMemory()
{
	DEBUG((DBG_OLD, "VirtualMemory destructor\n"));
	FreeList(memorySubsystem, VMemBlocks);
	VMemBlocks = NULL;
}

