#pragma once

#include <Windows.h>

DWORD DosHeader(PBYTE Data, LONGLONG Size);
DWORD FileHeader(PBYTE Data, LONGLONG Size);
DWORD OptionlHeader(PBYTE Data, LONGLONG Size);
DWORD DataDirectory(PBYTE Data, LONGLONG Size);
DWORD SectionHeader(PBYTE Data, LONGLONG Size);
