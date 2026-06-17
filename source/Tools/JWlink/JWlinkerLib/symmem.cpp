#include "pch.h"
#include "symmem.h"
#include "globals.h"

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