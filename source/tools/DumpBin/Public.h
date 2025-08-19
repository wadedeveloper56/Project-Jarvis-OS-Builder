#pragma once

#include <windows.h>

void GetCharacteristics(WORD Characteristics, PCHAR String, size_t cchDest);
void TimeStampToFileTime(INT64 timeStamp, FILETIME& fileTime);
void FileTimeToLocalTimeA(PFILETIME ft, char* time);
void GetTimeDateStamp(DWORD TimeDateStamp, PCHAR String);
PCSTR GetMachine(WORD Machine);
bool IsValidPE(PBYTE Data, LARGE_INTEGER Size);
bool IsPE32Ex(PBYTE Data, LARGE_INTEGER Size);
