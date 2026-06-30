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

using namespace std;

void SetNovFmt(shared_ptr<MemorySubsystem> memorySubsystem);
void FreeNovFmt(shared_ptr<MemorySubsystem> memorySubsystem);
