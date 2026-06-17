#pragma once

typedef struct vmemblock
{
    struct vmemblock* next;
    struct vmemblock* prev;
    char                mem[1];
} vmemblock; 

class VirtualMemory
{
    vmemblock* VMemBlocks;
public:

	VirtualMemory();
	~VirtualMemory();
};

