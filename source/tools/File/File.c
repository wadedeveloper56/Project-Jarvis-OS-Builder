#include "pch.h"
#include "framework.h"
#include "File.h"

errno_t OpenFile(f_handle* pfh, const char* filename, int oflag, int shflag, int pmode)
{
	return _sopen_s(pfh, filename, oflag, shflag, pmode);
}

int CloseFile(f_handle handle)
{
	return _close(handle);
}

int FlushFile(f_handle handle)
{
	return _commit(handle);
}

int ReadFile(f_handle handle, void* const buffer, unsigned const buffer_size)
{
	return _read(handle, buffer, buffer_size);
}

int WriteFile(f_handle handle, void* const buffer, unsigned const buffer_size)
{
	return _write(handle, buffer, buffer_size);
}

__int64 FileTell(f_handle handle)
{
	return _telli64(handle);
}

__int64 FileSeek(f_handle handle, __int64 offset, int origin)
{
	return _lseeki64(handle, offset, origin);
}

__int64 FileSize(f_handle handle)
{
	return _filelengthi64(handle);
}
