#include "FileSubsystem.h"
#include "File.h"

FileSubsystem::FileSubsystem()
{
}

FileSubsystem::~FileSubsystem()
{
}

void FileSubsystem::Open(const char* filename, const char* mode)
{
	currentFile = OpenFile(filename, mode);
}	

int FileSubsystem::Close()
{
	return CloseFile(currentFile);
}	

int FileSubsystem::Read(void* buffer, size_t size, size_t count)
{
	return ReadFile(currentFile, buffer, size, count);
}	

int FileSubsystem::Write(const void* buffer, size_t size, size_t count)
{
	return WriteFile(currentFile, buffer, size, count);
}

__int64 FileSubsystem::Tell()
{
	return FileTell(currentFile);
}

__int64 FileSubsystem::Seek(__int64 offset, int origin)
{
	return FileSeek(currentFile, offset, origin);
}

