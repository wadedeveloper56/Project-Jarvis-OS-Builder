#include "TokenBuffer.h"
#include "MemorySubsystem.h"

TokenBuffer::TokenBuffer(MemorySubsystem* memory)
{
	this->memory = memory;
	TokSize = MAX_HEADROOM;
	TokBuff = (char*)memory->AllocateMemory(TokSize);
}

TokenBuffer::~TokenBuffer()
{
	memory->FreeMemory(TokBuff);
}