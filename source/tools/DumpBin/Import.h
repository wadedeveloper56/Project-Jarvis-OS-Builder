#pragma once

void PrintImport(PBYTE Data, LONGLONG Size, PIMAGE_IMPORT_DESCRIPTOR ImportDirectory);
DWORD Import(PBYTE Data, LONGLONG Size);
