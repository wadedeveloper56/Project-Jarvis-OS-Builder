#include "pch.h"
#include "SpillFile.h"
#include "MemorySubsystem.h"
#include "debug.h"
#include "TempFileSubsystem.h"

SpillFile::SpillFile(MemorySubsystem *memorySubsystem)
{
	DEBUG((DBG_OLD, "SpillFile constructor\n"));
	this->memorySubsystem = memorySubsystem;
	this->TempFile = new TempFileSubsystem();
	TFileName = NULL;
	TmpFSize = 0;
}

SpillFile::~SpillFile()
{
	DEBUG((DBG_OLD, "SpillFile destructor\n"));
	_LnkFree(TFileName);
	TFileName = NULL;
	delete TempFile;
	TempFile = NULL;
}
