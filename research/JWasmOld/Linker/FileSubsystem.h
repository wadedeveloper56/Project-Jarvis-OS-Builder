#pragma once

#include <cstdio>
#include "File.h"

class FileSubsystem
{
public:
	FileSubsystem();
	~FileSubsystem();
	FileHandle Open(const char* filename, const char* mode);
	int Close(FileHandle handle);
	int Read(FileHandle handle,void* buffer, size_t size, size_t count);
	int Write(FileHandle handle,const void* buffer, size_t size, size_t count);
	int WriteStdOut(const void* buffer, size_t size, size_t count);
	int WriteNLStdOut(void);
	__int64 Tell(FileHandle handle);
	__int64 Seek(FileHandle handle,__int64 offset, int origin);
	static int Delete(char* name);
};

