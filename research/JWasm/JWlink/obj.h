#pragma once

#include "globals.h"
#include "MemorySubsystem.h"
#include "FileSubsystem.h"
#include "MessagingSubsystem.h"

bool DoObjOpen(FileSubsystem* files, MessagingSubsystem* msg, infilelist* list);
