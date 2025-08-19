#pragma once

void PrintImport(PBYTE Data, DWORD Size, PIMAGE_IMPORT_DESCRIPTOR ImportDirectory);
DWORD Import(PBYTE Data, DWORD Size);
