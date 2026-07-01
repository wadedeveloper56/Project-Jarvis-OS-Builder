#include "pch.h"
#include "SpillFile.h"
#include "ntio.h"
#include "MemorySubsystem.h"
#include "globals.h"
#include "ntio.h"
#include "debug.h"

#define TEMPFNAME "WLK02112.xx`"               
#define TEMPFNAME_SIZE 13

SpillFile::SpillFile(MemorySubsystem *memorySubsystem) : TempFile(NIL_HANDLE), TFileName(nullptr), TmpFSize(0)
{
	this->memorySubsystem = memorySubsystem;
}

SpillFile::~SpillFile()
{
	DEBUG((DBG_OLD, "SpillFile destructor\n"));
}

void SpillFile::CloseSpillFile()
{
	if (TempFile != NIL_HANDLE)
	{
		QClose(TempFile, TFileName);
		QDelete(TFileName);
		memorySubsystem->FreeMemory(TFileName);
		TFileName = NULL;
		TempFile = NIL_HANDLE;
	}
}

char* SpillFile::MakeTempName(char* name)
{
	memcpy(name, TEMPFNAME, sizeof(TEMPFNAME));
	return(name + sizeof(TEMPFNAME) - 2);
}

f_handle SpillFile::OpenTempFile(char** fname)
{
	char* ptr;
	unsigned    tlen;
	char* tptr;
	f_handle    fhdl;

	ptr = getenv("WLINKTMP");
	if (ptr == NULL) ptr = getenv("TMP");
	if (ptr == NULL) ptr = getenv("TMPDIR");
	if (ptr == NULL)
	{
		*fname = (char*)memorySubsystem->AllocateMemory(TEMPFNAME_SIZE);
		tptr = *fname;
	}
	else
	{
		tlen = strlen(ptr);
		*fname = (char*)memorySubsystem->AllocateMemory(tlen + 1 + TEMPFNAME_SIZE);
		memcpy(*fname, ptr, tlen);
		switch ((*fname)[tlen - 1])
		{
		CASE_PATH_SEP:
			break;
			default:
				(*fname)[tlen++] = PATH_SEP;
				break;
		}
		tptr = *fname + tlen;
	}
	ptr = MakeTempName(tptr);
	tlen = 0;
	for (;; )
	{
		if (tlen >= 26)
		{
		}
		*ptr += 1;
		fhdl = TempFileOpen(*fname);
		if (fhdl == NIL_HANDLE) break;
		QClose(fhdl, *fname);
		++tlen;
	}
	return QOpenRW(*fname);
}

unsigned long SpillFile::SpillAlloc(unsigned amt)
{
	unsigned long           stg;

	if (TempFile == NIL_HANDLE)
	{
		TempFile = OpenTempFile(&TFileName);
	}
	TmpFSize += SECTOR_SIZE - 1;
	TmpFSize &= ~(SECTOR_SIZE - 1);
	stg = TmpFSize;
	TmpFSize += amt;
	return(stg + 1);
}

void SpillFile::SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size)
{
	QSeek(TempFile, base + off - 1, TFileName);
	QWrite(TempFile, mem, size, TFileName);
}

void SpillFile::SpillRead(unsigned long base, unsigned off, void* mem, unsigned size)
{
	QSeek(TempFile, base + off - 1, TFileName);
	QRead(TempFile, mem, size, TFileName);
}
