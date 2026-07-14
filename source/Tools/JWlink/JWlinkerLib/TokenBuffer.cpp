#include "pch.h"
#include "MemorySubsystem.h"
#include "TokenBuffer.h"
#include "debug.h"

using namespace std;

TokenBuffer::TokenBuffer(MemorySubsystem *memorySubsystem)
{
	DEBUG((DBG_OLD, "TokenBuffer constructor\n"));
	this->memorySubsystem = memorySubsystem;
	TokSize = MAX_HEADROOM;
	TokBuff = (char*)memorySubsystem->AllocateMemory(TokSize);
}

TokenBuffer::~TokenBuffer()
{
	DEBUG((DBG_OLD, "TokenBuffer destructor\n"));
	memorySubsystem->FreeMemory(TokBuff);
}
