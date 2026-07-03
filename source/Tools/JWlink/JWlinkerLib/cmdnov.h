#pragma once

#include <memory>
#include "MemorySubsystem.h"
#include "cmdline.h"
#include "Structs.h"
#include "globals.h"
#include "Linkutil.h"
#include "cmd16m.h"
#include "cmdqnx.h"
#include "cmdelf.h"
#include "cmdos2.h"
#include "cmdphar.h"
#include "MessagingSubsystem.h"

using namespace std;

void SetNovFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
void FreeNovFmt(MemorySubsystem *memorySubsystem, MessagingSubsystem *messagingSubsystem);
