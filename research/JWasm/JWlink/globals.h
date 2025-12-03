#pragma once

#include "link.h"
#include "File.h"

#define SECTOR_SIZE     512
#define MAX_HEADROOM    (4*1024)

extern int _argc;
extern char** _argv;
extern stateflag      LinkState;      /* flags to indicate linker state */
extern char* TokBuff;        // Multi-purpose large buffer
extern unsigned       TokSize;        // size of above buffer
extern FileHandle       TempFile;
