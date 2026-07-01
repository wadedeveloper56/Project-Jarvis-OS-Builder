#pragma once

#include "File.h"

class FileSubsystem
{
public:
	FileSubsystem();
	~FileSubsystem();
	f_handle OpenFile(const char* filename, int oflag, int pmode);
	int CloseFile(f_handle handle);
	int FlushFile(f_handle handle);
	int ReadFile(f_handle handle, void* const buffer, unsigned const buffer_size);
	int WriteFile(f_handle handle, void* const buffer, unsigned const buffer_size);
	__int64 FileTell(f_handle handle);
	__int64 FileSeek(f_handle handle, __int64 offset, int origin);
	__int64 FileSize(f_handle handle);
};	

