#include "pch.h"
#include "MemorySubsystem.h"
#include "TokenBuffer.h"

using namespace std;

TokenBuffer::TokenBuffer(MemorySubsystem *memorySubsystem)
{
	this->memorySubsystem = memorySubsystem;
	TokSize = MAX_HEADROOM;
	TokBuff = (char*)memorySubsystem->AllocateMemory(TokSize);
}

TokenBuffer::~TokenBuffer()
{
	memorySubsystem->FreeMemory(TokBuff);
}
