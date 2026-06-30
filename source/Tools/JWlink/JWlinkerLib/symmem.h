#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

extern block_data Pass1Blocks;
extern block_data PermBlocks;

void GetSymBlock();
void MakePass1Blocks();
void ReleasePass1(MemorySubsystem *memorySubsystem);
