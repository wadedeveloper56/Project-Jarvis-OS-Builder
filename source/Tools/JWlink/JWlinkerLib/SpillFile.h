#pragma once

#include "MemorySubsystem.h"
#include "File.h"
#include "Structs.h"
#include "TempFileSubsystem.h"

#define TEMPFNAME "WLK02112.xx`"        // "'" will be an "a" when processed.
#define TEMPFNAME_SIZE 13
#define SECTOR_SIZE     512

class SpillFile
{
	MemorySubsystem *memorySubsystem;
	TempFileSubsystem * TempFile;
	char* TFileName;
	unsigned long    TmpFSize;
public:
	SpillFile(MemorySubsystem *memorySubsystem);
	~SpillFile();
    char* MakeTempName(char* name);
    TempFileSubsystem *OpenTempFile(char** fname);
    unsigned long SpillAlloc(unsigned amt);
    void SpillNull(unsigned long base, unsigned off, unsigned size);
    void SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size);
    void SpillRead(unsigned long base, unsigned off, void* mem, unsigned size);
    void CloseSpillFile(void);
};

char* GetEnvString(char* envname);
