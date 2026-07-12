#pragma once

#include "cmddos.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"
#include "Structs.h"
#include "globals.h"
#include "cmdline.h"

extern ::byte            OvlLevel;

void SetOvlClasses(MemorySubsystem* memorySubsystem);
void NewArea(MemorySubsystem* memorySubsystem, section* sect);
void MakeNonArea(MemorySubsystem* memorySubsystem);
void CmdOvlFini(MemorySubsystem* memorySubsystem, FileSubsystem* fileSubsystem, MessagingSubsystem* messagingSubsystem);
