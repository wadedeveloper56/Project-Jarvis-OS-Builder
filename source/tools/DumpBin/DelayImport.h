#pragma once

void PrintOneDelayImport(PBYTE Data, LONGLONG Size, PIMAGE_DELAYLOAD_DESCRIPTOR DelayImportDirectory);
DWORD DelayImport(PBYTE Data, LONGLONG Size);

