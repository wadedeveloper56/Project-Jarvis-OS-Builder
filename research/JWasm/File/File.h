#pragma once

typedef int FileHandle;
#define NIL_HANDLE      ((FileHandle)-1)

FileHandle OpenFile(const char* filename, int oflag, int pmode);
int CloseFile(FileHandle handle);
int ReadFile(FileHandle handle, void* const buffer, unsigned const buffer_size);
int WriteFile(FileHandle handle, void* const buffer, unsigned int count);
int setFileMode(FileHandle handle, int mode);
int FileAccess(const char* path, int mode);
__int64 FileTell(FileHandle handle);
__int64 FileSeek(FileHandle handle, __int64 offset, int origin);
int FileRemove(const char* path);
int FileStat(FileHandle handle, struct _stati64* buffer);
