#pragma once

#include <cstdio>
#include "File.h"

class FileSubsystem
{
public:
	FileSubsystem();
	~FileSubsystem();
	f_handle Open(const char* filename, const char* mode);
	int Close(f_handle handle);
	int Read(f_handle handle,void* buffer, size_t size, size_t count);
	int Write(f_handle handle,const void* buffer, size_t size, size_t count);
	int WriteStdOut(const void* buffer, size_t size, size_t count);
	int WriteNLStdOut(void);
	__int64 Tell(f_handle handle);
	__int64 Seek(f_handle handle,__int64 offset, int origin);
	static int Delete(char* name);
};

