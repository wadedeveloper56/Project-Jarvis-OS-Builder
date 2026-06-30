#pragma once

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

#define MAX_HEADROOM    (4*1024)

class TokenBuffer
{
	MemorySubsystem *memorySubsystem;
	char* TokBuff;
	int TokSize;
public:
	TokenBuffer(MemorySubsystem *memorySubsystem);
	~TokenBuffer();
};

