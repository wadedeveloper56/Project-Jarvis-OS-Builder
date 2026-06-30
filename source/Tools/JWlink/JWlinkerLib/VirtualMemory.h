#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

typedef struct vmemblock
{
    struct vmemblock* next;
    struct vmemblock* prev;
    char                mem[1];
} vmemblock; 

class VirtualMemory
{
    MemorySubsystem *memorySubsystem;
    vmemblock* VMemBlocks;
public:
    VirtualMemory() { VMemBlocks = NULL; }
	VirtualMemory(MemorySubsystem *memorySubsystem);
	~VirtualMemory();
};

