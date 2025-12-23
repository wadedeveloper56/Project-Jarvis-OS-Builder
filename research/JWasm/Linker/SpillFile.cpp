#include "pch.h"
#include "globals.h"
#include "SpillFile.h"
#include "FileSubsystem.h"
#include "MemorySubsystem.h"

SpillFile::SpillFile(FileSubsystem* file, MemorySubsystem* memory)
{
	this->file = file;
	this->memory = memory;
	TFileName = nullptr;
	TmpFSize = 0;
}

SpillFile::~SpillFile()
{
    if (TempFile != NIL_HANDLE) {
        CloseFile(TempFile);
        FileSubsystem::Delete(TFileName);
        memory->FreeMemory(TFileName);
        TFileName = NULL;
        TempFile = NIL_HANDLE;
    }
}