#pragma once

#include "MemorySubsystem.h"
#define MAX_HEADROOM    (4*1024)

class TokenBuffer
{
	char* TokBuff;        // Multi-purpose large buffer
	unsigned TokSize;        // size of above buffer
	MemorySubsystem* memory;
public:
	TokenBuffer(MemorySubsystem *memory);
	~TokenBuffer();
};

