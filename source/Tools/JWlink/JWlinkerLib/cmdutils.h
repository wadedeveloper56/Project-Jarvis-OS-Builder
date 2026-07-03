#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"
#include "MessagingSubsystem.h"

using namespace std;

extern cmdfilelist* CmdFile;

section* NewSection(MemorySubsystem *memorySubsystem);
char* FileName(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem, char* buff, unsigned len, file_defext etype, bool force);
