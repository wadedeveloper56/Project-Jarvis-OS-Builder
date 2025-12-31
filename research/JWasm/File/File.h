#pragma once

#include <cstdio>

typedef FILE *FileHandle;
#define NIL_HANDLE nullptr

FileHandle OpenFile(const char* filename, const char* mode);
int CloseFile(FileHandle handle);
int ReadFile(FileHandle handle, void* buffer, size_t size, size_t count);
int WriteFile(FileHandle handle, const void* buffer, size_t size, size_t count);
__int64 FileTell(FileHandle handle);
__int64 FileSeek(FileHandle handle, __int64 offset, int origin);

