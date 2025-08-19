#pragma once

#include <Windows.h>

DWORD DosHeader(PBYTE Data, DWORD Size);
DWORD FileHeader(PBYTE Data, DWORD Size);
DWORD OptionlHeader(PBYTE Data, DWORD Size);
DWORD DataDirectory(PBYTE Data, DWORD Size);
DWORD SectionHeader(PBYTE Data, DWORD Size);
