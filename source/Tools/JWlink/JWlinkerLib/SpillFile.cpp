#include "pch.h"
#include "SpillFile.h"
#include "MemorySubsystem.h"
#include "debug.h"
#include "FileSubsystem.h"

SpillFile::SpillFile(MemorySubsystem *memorySubsystem, FileSubsystem *fileSubsystem)
{
	this->memorySubsystem = memorySubsystem;
	this->fileSubsystem = fileSubsystem;
	DEBUG((DBG_OLD, "SpillFile constructor\n"));
}

SpillFile::~SpillFile()
{
	DEBUG((DBG_OLD, "SpillFile destructor\n"));
}
