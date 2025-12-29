#pragma once

#include "MemorySubsystem.h"
#include "Ring.h"

#define STR_BLOCK_SIZE   (4*1024)

typedef struct stringblock STRINGBLOCK;
typedef struct stringblock {
	STRINGBLOCK* next;
	unsigned    size;
	char        data[STR_BLOCK_SIZE];
} stringblock;

typedef struct {
	STRINGBLOCK* data;
	unsigned    currbase;
} stringtable;

class StringTable
{
	MemorySubsystem* memory;
	Ring* ring;
public:
	StringTable(MemorySubsystem* memory, Ring* ring);
	~StringTable();
	stringblock* AllocNewBlock(stringtable* strtab);
	void InitStringTable(stringtable*, bool);
	void FiniStringTable(stringtable*);
};

