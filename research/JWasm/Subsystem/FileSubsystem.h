#pragma once

#include <cstdio>
#include "File.h"

class FileSubsystem
{
public:
	FileSubsystem();
	~FileSubsystem();
	f_handle Open(const char* filename, int oflag, int pmode);
	int FlushFile(f_handle handle);
	int Close(f_handle handle);
	int Read(f_handle handle, void* buffer, unsigned size);
	int Write(f_handle handle, void* buffer, unsigned size);
	int WriteStdOut(void* buffer, unsigned size);
	int WriteNLStdOut(void);
	__int64 Tell(f_handle handle);
	__int64 Seek(f_handle handle, __int64 offset, int origin);
	static int Delete(char* name);
};

