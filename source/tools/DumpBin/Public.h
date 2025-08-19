#pragma once

#include <windows.h>

typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
typedef DWORD(*PeCallBack)(PBYTE Data, DWORD Size);

bool IsValidPE(PBYTE Data, DWORD Size);
bool IsPE32Ex(PBYTE Data, DWORD Size);
PCSTR GetMachine(WORD Machine);
void GetCharacteristics(WORD Characteristics, PCHAR String, size_t cchDest);
void GetTimeDateStamp(DWORD TimeDateStamp, PCHAR String);
PCSTR GetSubsystem(WORD Subsystem);
void GetDllCharacteristics(WORD Characteristics, PCHAR String, size_t cchDest);
void GetSectionCharacteristics(DWORD Characteristics, PCHAR String, size_t cchDest);
UINT Rva2Va(PBYTE Data, UINT rva);
void GetDataDirectory(PBYTE Data, DWORD Size, BYTE index, PIMAGE_DATA_DIRECTORY DataDirectory);
BOOL IsWow64();
void FileTimeToLocalTimeA(PFILETIME ft, char* time);
