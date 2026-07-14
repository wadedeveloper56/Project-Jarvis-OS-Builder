#include "pch.h"
#include "FileSubsystem.h"
#include "debug.h"

FileSubsystem::FileSubsystem()
{
	DEBUG((DBG_OLD, "FileSubsystem constructor\n"));
}

FileSubsystem::~FileSubsystem()
{
	DEBUG((DBG_OLD, "FileSubsystem destructor\n"));
}

f_handle FileSubsystem::OpenFile(const char* filename, int oflag, int pmode)
{
	return ::OpenFile2(filename, oflag, pmode);
}

int FileSubsystem::CloseFile(f_handle handle)
{
	return ::CloseFile2(handle);
}

int FileSubsystem::FlushFile(f_handle handle)
{
	return ::FlushFile2(handle);
}

int FileSubsystem::ReadFile(f_handle handle, void* const buffer, unsigned const buffer_size)
{
	return ::ReadFile2(handle, buffer, buffer_size);
}

int FileSubsystem::WriteFile(f_handle handle, void* const buffer, unsigned const buffer_size)
{
	return ::WriteFile2(handle, buffer, buffer_size);
}

__int64 FileSubsystem::FileTell(f_handle handle)
{
	return ::FileTell2(handle);
}

__int64 FileSubsystem::FileSeek(f_handle handle, __int64 offset, int origin)
{
	return ::FileSeek2(handle, offset, origin);
}

__int64 FileSubsystem::FileSize(f_handle handle)
{
	return ::FileSize2(handle);
}