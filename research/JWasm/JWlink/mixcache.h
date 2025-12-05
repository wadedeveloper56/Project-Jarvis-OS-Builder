#pragma once

#include "objstruct.h"

void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void CacheFini(void);
