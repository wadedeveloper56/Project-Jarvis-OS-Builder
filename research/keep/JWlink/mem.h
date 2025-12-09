#pragma once

void LnkMemInit(void);
void LnkMemFini(void);
void DbgZapAlloc(void* tgt, size_t size);
void DbgZapFreed(void* tgt, size_t size);
