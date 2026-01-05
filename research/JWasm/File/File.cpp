#include "pch.h"
#include "framework.h"
#include "File.h"

f_handle OpenFile(const char* filename, const char* mode)
{
	return fopen(filename, mode);
}

int CloseFile(f_handle handle)
{
	return fclose(handle);
}

int FlushFile(f_handle handle)
{
	return fflush(handle);
}

int ReadFile(f_handle handle, void* buffer, size_t size, size_t count)
{
	return fread(buffer, size, count, handle);
}

int WriteFile(f_handle handle, const void* buffer, size_t size, size_t count)
{
	return fwrite(buffer, size, count, handle);
}

__int64 FileTell(f_handle handle)
{
	return _ftelli64(handle);
}

__int64 FileSeek(f_handle handle, __int64 offset, int origin)
{
	return _fseeki64(handle, offset, origin);
}
