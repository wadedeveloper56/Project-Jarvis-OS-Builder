#pragma once

DWORD Resource(PBYTE Data, LONGLONG Size);
const char* GetResourceTypeString(WORD Id);
void PrintNameString(PIMAGE_RESOURCE_DIRECTORY ResourceDirectory, PIMAGE_RESOURCE_DIRECTORY_ENTRY ResourceDirectoryEntry);
