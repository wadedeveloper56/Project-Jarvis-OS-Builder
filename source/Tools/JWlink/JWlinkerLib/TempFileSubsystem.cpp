#include "pch.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "TempFileSubsystem.h"
#include "debug.h"

TempFileSubsystem::TempFileSubsystem() :handle(NIL_HANDLE)
{
	DEBUG((DBG_OLD, "TempFileSubsystem constructor\n"));
}

TempFileSubsystem::~TempFileSubsystem()
{
	DEBUG((DBG_OLD, "TempFileSubsystem destructor\n"));
	if (handle != NIL_HANDLE)
	{
		FileSubsystem::CloseFile(handle);
		handle = NIL_HANDLE;
	}
}

void TempFileSubsystem::QOpenRW(const char* filename)
{
	handle = FileSubsystem::OpenFile(filename, _O_CREAT | _O_TEMPORARY | _O_RDWR, _S_IREAD | _S_IWRITE);
}

int TempFileSubsystem::CloseFile()
{
	return FileSubsystem::CloseFile(handle);
}

int TempFileSubsystem::FlushFile()
{
	return FileSubsystem::FlushFile(handle);
}

int TempFileSubsystem::ReadFile(void* const buffer, unsigned const buffer_size)
{
	return FileSubsystem::ReadFile(handle, buffer, buffer_size);
}

int TempFileSubsystem::WriteFile(void* const buffer, unsigned const buffer_size)
{
	return FileSubsystem::WriteFile(handle, buffer, buffer_size);
}

__int64 TempFileSubsystem::FileTell()
{
	return FileSubsystem::FileTell(handle);
}

__int64 TempFileSubsystem::QSeek(__int64 offset)
{
	return FileSubsystem::FileSeek(handle, offset, SEEK_SET);
}

__int64 TempFileSubsystem::FileSize()
{
	return FileSubsystem::FileSize(handle);
}


