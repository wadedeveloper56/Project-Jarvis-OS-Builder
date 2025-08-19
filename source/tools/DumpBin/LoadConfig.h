#pragma once

void PrintLoadConfig64(PIMAGE_LOAD_CONFIG_DIRECTORY64 LoadConfigDirectory64);
void PrintLoadConfig32(PIMAGE_LOAD_CONFIG_DIRECTORY32 LoadConfigDirectory32);
DWORD LoadConfig(PBYTE Data, LONGLONG Size);

