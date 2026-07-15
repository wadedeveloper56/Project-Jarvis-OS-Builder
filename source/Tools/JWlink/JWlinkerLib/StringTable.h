#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"

#define STR_BLOCK_SIZE   (4*1024)

typedef struct stringblock STRINGBLOCK;

class StringTable
{
	MemorySubsystem* memorySubsystem;
	stringtable* strtab;
public:
	StringTable(MemorySubsystem* memorySubsystem);
	~StringTable();
	stringblock* AllocNewBlock();
	void InitStringTable(bool dontsplit);
};

