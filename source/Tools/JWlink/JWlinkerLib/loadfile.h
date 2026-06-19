#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "FileSubsystem.h"

using namespace std;

void FreeOutFiles(shared_ptr<FileSubsystem> fileSubsystem, shared_ptr<MemorySubsystem> memorySubsystem);
void ClearStartAddr();
void ResetLoadFile();