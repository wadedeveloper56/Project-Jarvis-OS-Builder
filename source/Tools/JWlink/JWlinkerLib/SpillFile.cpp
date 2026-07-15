#include "pch.h"
#include "SpillFile.h"
#include "MemorySubsystem.h"
#include "debug.h"
#include "TempFileSubsystem.h"
#include "utils.h"

SpillFile::SpillFile(MemorySubsystem* memorySubsystem)
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

char* SpillFile::MakeTempName(char* name)
{
	memcpy(name, TEMPFNAME, sizeof(TEMPFNAME));
	return(name + sizeof(TEMPFNAME) - 2);
}

char* GetEnvString(char* envname)
{
	return(getenv(envname));
}

TempFileSubsystem* SpillFile::OpenTempFile(char** fname)
{
	char* ptr;
	unsigned    tlen;
	char* tptr;
	TempFileSubsystem* fhdl;

	ptr = GetEnvString("WLINKTMP");
	if (ptr == NULL) ptr = GetEnvString("TMP");
	if (ptr == NULL) ptr = GetEnvString("TMPDIR");
	if (ptr == NULL)
	{
		_ChkAlloc(char*, *fname, TEMPFNAME_SIZE);
		tptr = *fname;
	}
	else
	{
		tlen = strlen(ptr);
		_ChkAlloc(char*, *fname, tlen + 1 + TEMPFNAME_SIZE);
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
			//LnkMsg(FTL + MSG_CANT_OPEN_SPILL, NULL);
		}
		*ptr += 1;
		fhdl = new TempFileSubsystem();
		fhdl->QOpenRW(*fname);
		if (fhdl->GetHandle() == NIL_HANDLE) break;
		fhdl->CloseFile();
		delete fhdl;
		++tlen;
	}
	TempFile->QOpenRW(*fname);
	return(TempFile);
}

unsigned long SpillFile::SpillAlloc(unsigned amt)
{
	unsigned long           stg;

	if (TempFile->GetHandle() == NIL_HANDLE)
	{
		TempFile = OpenTempFile(&TFileName);
		//LnkMsg(INF + MSG_USING_SPILL, NULL);
	}
	TmpFSize += SECTOR_SIZE - 1;
	TmpFSize &= ~(SECTOR_SIZE - 1);
	stg = TmpFSize;
	TmpFSize += amt;
	return(stg + 1);
}

void SpillFile::SpillNull(unsigned long base, unsigned off, unsigned size)
{
	TempFile->QSeek(base + off - 1);
	WriteNulls(TempFile, TempFile->GetHandle(), size, TFileName);
}

void SpillFile::SpillWrite(unsigned long base, unsigned off, void* mem, unsigned size)
{
	TempFile->QSeek(base + off - 1);
	TempFile->WriteFile(mem, size);
}

void SpillFile::SpillRead(unsigned long base, unsigned off, void* mem, unsigned size)
{
	TempFile->QSeek(base + off - 1);
	TempFile->ReadFile(mem, size);
}

void SpillFile::CloseSpillFile(void)
{
	if (TempFile->GetHandle() != NIL_HANDLE)
	{
		//RestoreBreak();
		TempFile->CloseFile();
		//QDelete(TFileName);
		_LnkFree(TFileName);
		delete TempFile;
		TFileName = NULL;
		TempFile = NULL;
	}
}

