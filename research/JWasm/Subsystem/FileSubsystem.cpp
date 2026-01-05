#include "pch.h"
#include "FileSubsystem.h"
#include "File.h"

FileSubsystem::FileSubsystem()
{
}

FileSubsystem::~FileSubsystem()
{
}

int FileSubsystem::Delete(char* name)
{
	if (name == NULL) return -1;
	return remove(name);
}

f_handle FileSubsystem::Open(const char* filename, int oflag, int pmode)
{
	f_handle handle;
	::OpenFile(&handle, filename, oflag, _SH_DENYNO, pmode);
	return handle;
}

int FileSubsystem::FlushFile(f_handle handle)
{
	return ::FlushFile(handle);
}

int FileSubsystem::Close(f_handle handle)
{
	return CloseFile(handle);
}

int FileSubsystem::Read(f_handle handle, void* buffer, unsigned size)
{
	return ::ReadFile(handle, buffer, size);
}

int FileSubsystem::Write(f_handle handle, void* buffer, unsigned size)
{
	return ::WriteFile(handle, buffer, size);
}

int FileSubsystem::WriteStdOut(void* buffer, unsigned size)
{
	return ::WriteFile(_fileno(stdout), buffer, size);
}

char NLSeq[] = { "\r\n" };

int FileSubsystem::WriteNLStdOut(void)
{
	return WriteStdOut(NLSeq, sizeof(NLSeq) - 1);
}

__int64 FileSubsystem::Tell(f_handle handle)
{
	return FileTell(handle);
}

__int64 FileSubsystem::Seek(f_handle handle, __int64 offset, int origin)
{
	return FileSeek(handle, offset, origin);
}

