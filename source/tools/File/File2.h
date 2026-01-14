#pragma once

#include <stdio.h>

typedef FILE *FileHandle;
#define NIL_HANDLE -1

errno_t OpenFile2(FileHandle* pfh, const char* filename, const char* pmode);
int CloseFile2(FileHandle handle);
int FlushFile2(FileHandle handle);
int ReadFile2(FileHandle handle, void* buffer, size_t size, size_t count);
int WriteFile2(FileHandle handle, void* buffer, size_t size, size_t count);
__int64 FileTell2(FileHandle handle);
__int64 FileSeek2(FileHandle handle, __int64 offset, int origin);
__int64 FileSize2(FileHandle handle);
