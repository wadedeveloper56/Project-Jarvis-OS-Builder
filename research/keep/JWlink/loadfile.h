#pragma once

#include "globals.h"

void InitBuffFile(outfilelist* outfile, char* filename, bool executable);
void CloseBuffFile(outfilelist* outfile);
void FreeOutFiles(void);
void CleanLoadFile(void);
void WriteLoad(void* buff, unsigned long size);
