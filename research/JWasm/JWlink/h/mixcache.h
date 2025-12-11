#pragma once

void CacheFini(void);
void* CacheRead(file_list* list, unsigned long pos, unsigned len);
void* CachePermRead(file_list* list, unsigned long pos, unsigned len);
void CacheFree(file_list* list, void* mem);
void FreeObjCache(file_list* list);
bool DumpObjCache(void);
void CacheClose(file_list* list, unsigned pass);
void FreeObjCache(file_list* list);
