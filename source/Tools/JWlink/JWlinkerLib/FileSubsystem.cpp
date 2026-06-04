#include "pch.h"
#include "FileSubsystem.h"

FileSubsystem::FileSubsystem()
{
}

FileSubsystem::~FileSubsystem()
{
}

errno_t FileSubsystem::OpenFile(f_handle* pfh, const char* filename, int oflag, int shflag, int pmode)
{
	return ::OpenFile2(pfh, filename, oflag, shflag, pmode);
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
__int64 FileSize(f_handle handle);