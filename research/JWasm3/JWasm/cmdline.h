#pragma once
#include "globals.h"

#define EXPQUAL

extern struct global_options Options;

char* EXPQUAL ParseCmdline(const char** cmdline, int*);
void EXPQUAL CmdlineFini(void);