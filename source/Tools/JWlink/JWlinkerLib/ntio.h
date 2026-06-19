#pragma once

#include "File.h"

void QClose(f_handle file, char* name);
void QDelete(char* name);
unsigned QWrite(f_handle file, void* buffer, unsigned len, char* name);
