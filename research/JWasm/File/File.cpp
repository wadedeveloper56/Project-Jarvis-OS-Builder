#include "pch.h"
#include "framework.h"
#include "File.h"

FileHandle OpenFile(const char* filename, int oflag, int pmode)
{
	return _open(filename, oflag, pmode);
}

void CloseFile(FileHandle handle)
{
	_close(handle);
}

int ReadFile(FileHandle handle, void* const buffer, unsigned const buffer_size)
{
	return _read(handle, buffer, buffer_size);
}

int WriteFile(FileHandle handle, void* const buffer, unsigned int count)
{
	return _write(handle, buffer, count);
}

int setFileMode(FileHandle handle, int mode)
{
	return _setmode(handle, mode);
}

int FileAccess(const char* path, int mode)
{
	return _access(path, mode);
}

__int64 FileTell(FileHandle handle)
{
	return _telli64(handle);
}

__int64 FileSeek(FileHandle handle, __int64 offset, int origin)
{
	return _lseeki64(handle, offset, origin);
}

int FileRemove(const char* path)
{
	return remove(path);
}

int FileStat(FileHandle handle, struct _stati64* buffer)
{
	return _fstati64(handle, buffer);
}

