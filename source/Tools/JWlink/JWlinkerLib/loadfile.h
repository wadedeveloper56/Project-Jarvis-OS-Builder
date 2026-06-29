#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "Structs.h"

using namespace std;

void FreeOutFiles(shared_ptr<FileSubsystem> fileSubsystem, shared_ptr<MemorySubsystem> memorySubsystem);
void ClearStartAddr();
void ResetLoadFile();
void CleanLoadFile();
void WriteLoad(void* buff, unsigned long size);
void WriteBuffer(char* info, unsigned long len, outfilelist* outfile, void* (*rtn)(void*, const void*, size_t));
