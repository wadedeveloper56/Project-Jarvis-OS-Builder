#include "pch.h"
#include "SpillFile.h"
#include "ntio.h"
#include "MemorySubsystem.h"

SpillFile::SpillFile(shared_ptr<MemorySubsystem> memorySubsystem) : TempFile(NIL_HANDLE), TFileName(nullptr), TmpFSize(0)
{
    this->memorySubsystem = memorySubsystem;
}

SpillFile::~SpillFile()
{
}

void SpillFile::CloseSpillFile()
{
    if (TempFile != NIL_HANDLE)
    {
        //RestoreBreak();
        QClose(TempFile, TFileName);
        QDelete(TFileName);
        memorySubsystem->FreeMemory(TFileName);
        TFileName = NULL;
        TempFile = NIL_HANDLE;
    }
}
