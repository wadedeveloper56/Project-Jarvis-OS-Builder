#pragma once

void PrintOneDelayImport(PBYTE Data, DWORD Size, PIMAGE_DELAYLOAD_DESCRIPTOR DelayImportDirectory);
DWORD DelayImport(PBYTE Data, DWORD Size);

