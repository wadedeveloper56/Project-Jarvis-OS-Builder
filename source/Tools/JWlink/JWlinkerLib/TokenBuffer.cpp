#include "pch.h"
#include "MemorySubsystem.h"
#include "TokenBuffer.h"
#include "debug.h"

using namespace std;

TokenBuffer::TokenBuffer(MemorySubsystem *memorySubsystem)
{
	this->memorySubsystem = memorySubsystem;
	TokSize = MAX_HEADROOM;
	TokBuff = (char*)memorySubsystem->AllocateMemory(TokSize);
}

TokenBuffer::~TokenBuffer()
{
	DEBUG((DBG_OLD, "TokenBuffer destructor\n"));
	memorySubsystem->FreeMemory(TokBuff);
}
