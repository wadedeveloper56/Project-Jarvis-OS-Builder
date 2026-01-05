#pragma once

#include <cstdio>

typedef FILE * f_handle;
#define NIL_HANDLE nullptr

f_handle OpenFile(const char* filename, const char* mode);
int FlushFile(f_handle handle);
int CloseFile(f_handle handle);
int ReadFile(f_handle handle, void* buffer, size_t size, size_t count);
int WriteFile(f_handle handle, const void* buffer, size_t size, size_t count);
__int64 FileTell(f_handle handle);
__int64 FileSeek(f_handle handle, __int64 offset, int origin);

