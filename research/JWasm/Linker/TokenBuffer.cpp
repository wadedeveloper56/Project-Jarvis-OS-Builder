#include "pch.h"
#include "TokenBuffer.h"
#include "MemorySubsystem.h"

TokenBuffer::TokenBuffer(MemorySubsystem* memory)
{
	this->memory = memory;
	TokSize = MAX_HEADROOM;
	_ChkAlloc(char *, TokBuff, TokSize);
	memset(TokBuff, 0, TokSize);
}

TokenBuffer::~TokenBuffer()
{
	memory->FreeMemory(TokBuff);
}

void TokenBuffer::Reallocate(unsigned newSize)
{
	if (newSize <= TokSize) return;
	_LnkReAlloc(char*, TokBuff, TokBuff, newSize);
	memset(TokBuff + TokSize, 0, newSize - TokSize);
	TokSize = newSize;
}