#pragma once

#include <cstdio>
#include "File.h"

class FileSubsystem
{
	FileHandle currentFile;
public:
	FileSubsystem();
	~FileSubsystem();
	void Open(const char* filename, const char* mode);
	int Close();
	int Read(void* buffer, size_t size, size_t count);
	int Write(const void* buffer, size_t size, size_t count);
	int WriteStdOut(const void* buffer, size_t size, size_t count);
	__int64 Tell();
	__int64 Seek(__int64 offset, int origin);
};

