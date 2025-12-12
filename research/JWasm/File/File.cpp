#include "pch.h"
#include "framework.h"
#include "File.h"

FileHandle OpenFile(const char* filename, const char* mode)
{
	return fopen(filename, mode);
}

int CloseFile(FileHandle handle)
{
	return fclose(handle);
}

int ReadFile(FileHandle handle, void* buffer, size_t size, size_t count)
{
	return fread(buffer, size, count, handle);
}

int WriteFile(FileHandle handle, const void* buffer, size_t size, size_t count)
{
	return fwrite(buffer, size, count, handle);
}

__int64 FileTell(FileHandle handle)
{
	return _ftelli64(handle);
}

__int64 FileSeek(FileHandle handle, __int64 offset, int origin)
{
	return _fseeki64(handle, offset, origin);
}
