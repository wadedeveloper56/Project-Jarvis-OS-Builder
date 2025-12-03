#pragma once

typedef int FileHandle;
#define NIL_HANDLE      ((FileHandle)-1)

FileHandle OpenFile(const char* filename, int oflag, int pmode);
void CloseFile(FileHandle handle);
int ReadFile(FileHandle handle, void* const buffer, unsigned const buffer_size);
int WriteFile(FileHandle handle, void* const buffer, unsigned int count);
int setFileMode(FileHandle handle, int mode);
int FileAccess(const char* path, int mode);
