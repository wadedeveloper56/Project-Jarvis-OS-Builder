#pragma once

void* CacheRead(file_list* list, unsigned long pos, unsigned len);
void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void CacheFini(void);
