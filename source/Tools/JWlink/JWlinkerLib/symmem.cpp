#include "pch.h"
#include "symmem.h"
#include "globals.h"
#include "linkutil.h"
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

block_data Pass1Blocks;
block_data PermBlocks;

void GetSymBlock()
{
    PermBlocks.list = NULL;
}

void MakePass1Blocks()
{
    Pass1Blocks.list = NULL;
}

void ReleasePass1(MemorySubsystem *memorySubsystem)
{
    FreeList(memorySubsystem, Pass1Blocks.list);
    Pass1Blocks.list = NULL;
}

void RelSymBlock(MemorySubsystem* memorySubsystem)
{
    FreeList(memorySubsystem, Pass1Blocks.list);
    Pass1Blocks.list = NULL;
}