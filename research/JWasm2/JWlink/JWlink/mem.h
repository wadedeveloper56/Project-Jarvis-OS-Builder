#pragma once

void* LnkReAlloc(void* src, size_t size);
void LFree(void* p);
void* ChkLAlloc(size_t size);
void LnkMemInit(void);
void LnkMemFini(void);
