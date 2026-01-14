#include "pch.h"
#include "framework.h"
#include "File2.h"

errno_t OpenFile2(FileHandle* pfh, const char* filename, const char* pmode)
{
	return fopen_s(pfh, filename, pmode);
}

int CloseFile2(FileHandle handle)
{
	return fclose(handle);
}

int FlushFile2(FileHandle handle)
{
	return fflush(handle);
}

int ReadFile2(FileHandle handle, void* buffer, size_t size, size_t count)
{
	return fread(buffer, size, count, handle);
}

int WriteFile2(FileHandle handle, void* buffer, size_t size, size_t count)
{
	return fwrite(buffer, size, count, handle);
}

__int64 FileTell2(FileHandle handle)
{
	return _ftelli64(handle);
}

__int64 FileSeek2(FileHandle handle, __int64 offset, int origin)
{
	return _fseeki64(handle, offset, origin);
}

__int64 FileSize2(FileHandle handle)
{
	return _filelengthi64(_fileno(handle));
}
