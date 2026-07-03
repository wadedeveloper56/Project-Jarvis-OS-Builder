#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "MessagingSubsystem.h"

using namespace std;

void ResetMapIO();
void StartTime(void);
void EndTime(MessagingSubsystem* messageSubsystem);
void FreeUndefs();
void FreeUndefs(MemorySubsystem *memorySubsystem);
void BufWrite(char* buffer, int len);
void WriteMapNL(unsigned count);
unsigned MapPrint(MessagingSubsystem* messageSubsystem, char* str, va_list* args);
void DoWriteMap(MessagingSubsystem* messageSubsystem, char* format, va_list* arglist);
void WriteMap(MessagingSubsystem* messageSubsystem, char* format, ...);