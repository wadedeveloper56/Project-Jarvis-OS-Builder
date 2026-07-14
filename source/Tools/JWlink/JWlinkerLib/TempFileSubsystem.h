#pragma once

#include "FileSubsystem.h"

class TempFileSubsystem : public FileSubsystem
{
	f_handle handle;
public:
	TempFileSubsystem();
	~TempFileSubsystem();
	void OpenFile(const char* filename);
	int CloseFile();
	int FlushFile();
	int ReadFile(void* const buffer, unsigned const buffer_size);
	int WriteFile(void* const buffer, unsigned const buffer_size);
	__int64 FileTell();
	__int64 FileSeek(__int64 offset, int origin);
	__int64 FileSize();
	f_handle GetHandle() { return handle; }
};

