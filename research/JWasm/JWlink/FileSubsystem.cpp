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

f_handle FileSubsystem::Open(const char* filename, const char* mode)
{
	return OpenFile(filename, mode);
}	

int FileSubsystem::Close(f_handle handle)
{
	return CloseFile(handle);
}	

int FileSubsystem::Read(f_handle handle,void* buffer, size_t size, size_t count)
{
	return ReadFile(handle, buffer, size, count);
}	

int FileSubsystem::Write(f_handle handle,const void* buffer, size_t size, size_t count)
{
	return WriteFile(handle, buffer, size, count);
}

int FileSubsystem::WriteStdOut(const void* buffer, size_t size, size_t count) 
{
	return WriteFile(stdout, buffer, size, count);
}

char NLSeq[] = { "\r\n" };

int FileSubsystem::WriteNLStdOut(void)
{
	return WriteStdOut(NLSeq, sizeof(NLSeq) - 1, 1);
}

__int64 FileSubsystem::Tell(f_handle handle)
{
	return FileTell(handle);
}

__int64 FileSubsystem::Seek(f_handle handle,__int64 offset, int origin)
{
	return FileSeek(handle, offset, origin);
}

