#include "pch.h"
#include "globals.h"
#include "File.h"

int _argc;
char** _argv;
stateflag      LinkState;      /* flags to indicate linker state */
char* TokBuff;        // Multi-purpose large buffer
unsigned       TokSize;        // size of above buffer
FileHandle       TempFile;