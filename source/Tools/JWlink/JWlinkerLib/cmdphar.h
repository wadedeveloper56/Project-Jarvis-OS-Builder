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

void SetPharFmt(shared_ptr<MemorySubsystem> memorySubsystem);
void FreePharFmt(shared_ptr<MemorySubsystem> memorySubsystem);
