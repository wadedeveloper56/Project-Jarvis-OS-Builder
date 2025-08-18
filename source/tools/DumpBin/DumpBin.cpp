#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <DbgHelp.h>
#pragma comment (lib,"DbgHelp.lib")

void TimeStampToFileTime(INT64 timeStamp, FILETIME& fileTime)
{
	INT64 nll = timeStamp * 10000000 + 116444736000000000;
	fileTime.dwLowDateTime = (DWORD)nll;
	fileTime.dwHighDateTime = nll >> 32;
}

void FileTimeToLocalTimeA(PFILETIME ft, char* time)
{
	FILETIME lft;
	BOOL B = FileTimeToLocalFileTime(ft, &lft);
	_ASSERTE(B);

	SYSTEMTIME st;
	//GetLocalTime(&st);
	B = FileTimeToSystemTime(&lft, &st);
	_ASSERTE(B);

	//SystemTimeToTzSpecificLocalTime

	//¸ñÊ½£º2016-07-11 17:35:54      
	wsprintfA(time,
		"%04d-%02d-%02d %02d:%02d:%02d",
		st.wYear,
		st.wMonth,
		st.wDay,
		st.wHour,
		st.wMinute,
		st.wSecond);

	//size_t cb = lstrlen(time) * sizeof(wchar_t);
}

void GetTimeDateStamp(DWORD TimeDateStamp, PCHAR String)
{
	FILETIME FileTime = { 0 };
	TimeStampToFileTime(TimeDateStamp, FileTime);
	FileTimeToLocalTimeA(&FileTime, String);
}

PCSTR GetMachine(WORD Machine)
{
	PCSTR MachineString = NULL;

	switch (Machine) {
		case IMAGE_FILE_MACHINE_UNKNOWN:
			MachineString = "Unknown";
			break;
		case IMAGE_FILE_MACHINE_TARGET_HOST:
			MachineString = "Useful for indicating we want to interact with the host and not a WoW guest";
			break;
		case IMAGE_FILE_MACHINE_I386:
			MachineString = "Intel 386";
			break;
		case IMAGE_FILE_MACHINE_R3000:
			MachineString = "MIPS little-endian, 0x160 big-endian";
			break;
		case IMAGE_FILE_MACHINE_R4000:
			MachineString = "MIPS little-endian";
			break;
		case IMAGE_FILE_MACHINE_R10000:
			MachineString = "MIPS little-endian";
			break;
		case IMAGE_FILE_MACHINE_WCEMIPSV2:
			MachineString = "MIPS little-endian WCE v2";
			break;
		case IMAGE_FILE_MACHINE_ALPHA:
			MachineString = "Alpha_AXP";
			break;
		case IMAGE_FILE_MACHINE_SH3:
			MachineString = "SH3 little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH3DSP:
			MachineString = "IMAGE_FILE_MACHINE_SH3DSP";
			break;
		case IMAGE_FILE_MACHINE_SH3E:
			MachineString = "SH3E little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH4:
			MachineString = "SH4 little-endian";
			break;
		case IMAGE_FILE_MACHINE_SH5:
			MachineString = "SH5";
			break;
		case IMAGE_FILE_MACHINE_ARM:
			MachineString = "ARM Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_THUMB:
			MachineString = "ARM Thumb/Thumb-2 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_ARMNT:
			MachineString = "ARM Thumb-2 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_AM33:
			MachineString = "IMAGE_FILE_MACHINE_AM33";
			break;
		case IMAGE_FILE_MACHINE_POWERPC:
			MachineString = "IBM PowerPC Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_POWERPCFP:
			MachineString = "IMAGE_FILE_MACHINE_POWERPCFP";
			break;
		case IMAGE_FILE_MACHINE_IA64:
			MachineString = "Intel 64";
			break;
		case IMAGE_FILE_MACHINE_MIPS16:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_ALPHA64:
			MachineString = "ALPHA64";
			break;
		case IMAGE_FILE_MACHINE_MIPSFPU:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_MIPSFPU16:
			MachineString = "MIPS";
			break;
		case IMAGE_FILE_MACHINE_TRICORE:
			MachineString = "Infineon";
			break;
		case IMAGE_FILE_MACHINE_CEF:
			MachineString = "IMAGE_FILE_MACHINE_CEF";
			break;
		case IMAGE_FILE_MACHINE_EBC:
			MachineString = "EFI Byte Code";
			break;
		case IMAGE_FILE_MACHINE_AMD64:
			MachineString = "AMD64 (K8)";
			break;
		case IMAGE_FILE_MACHINE_M32R:
			MachineString = "M32R little-endian";
			break;
		case IMAGE_FILE_MACHINE_ARM64:
			MachineString = "ARM64 Little-Endian";
			break;
		case IMAGE_FILE_MACHINE_CEE:
			MachineString = "IMAGE_FILE_MACHINE_CEE";
			break;
		default:
			MachineString = "Î´Öª";
			break;
	}

	return MachineString;
}

void Dump(PBYTE Data, LARGE_INTEGER Size)
{
	PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
	PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
	PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;

	printf("Dos Header Information:\n");
	printf("e_magic    : %#06x.\n", DosHeader->e_magic);
	printf("e_cblp     : %#06x.\n", DosHeader->e_cblp);
	printf("e_cp       : %#06x.\n", DosHeader->e_cp);
	printf("e_crlc     : %#06x.\n", DosHeader->e_crlc);
	printf("e_cparhdr  : %#06x.\n", DosHeader->e_cparhdr);
	printf("e_minalloc : %#06x.\n", DosHeader->e_minalloc);
	printf("e_maxalloc : %#06x.\n", DosHeader->e_maxalloc);
	printf("e_ss       : %#06x.\n", DosHeader->e_ss);
	printf("e_sp       : %#06x.\n", DosHeader->e_sp);
	printf("e_csum     : %#06x.\n", DosHeader->e_csum);
	printf("e_ip       : %#06x.\n", DosHeader->e_ip);
	printf("e_cs       : %#06x.\n", DosHeader->e_cs);
	printf("e_lfarlc   : %#06x.\n", DosHeader->e_lfarlc);
	printf("e_ovno     : %#06x.\n", DosHeader->e_ovno);
	CHAR e_res[MAX_PATH] = { 0 };
	for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res); i++) {
		wsprintfA(&e_res[i * 4], "%04X", DosHeader->e_res[i]);
	}
	printf("e_res[4]   : 0x%s.\n", e_res);
	printf("e_oemid    : %#06x.\n", DosHeader->e_oemid);
	printf("e_oeminfo  : %#06x.\n", DosHeader->e_oeminfo);
	CHAR e_res2[MAX_PATH] = { 0 };
	for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res2); i++) {
		wsprintfA(&e_res2[i * 4], "%04X", DosHeader->e_res2[i]);
	}
	printf("e_res2[10] : 0x%s.\n", e_res2);
	printf("e_lfanew   : %#010x.\n", DosHeader->e_lfanew);
	//-------------------------------------------------------
	printf("\nFile Header Information : \n");
	printf("Machine               : %#06x (%s)\n", FileHeader->Machine, GetMachine(FileHeader->Machine));
	printf("NumberOfSections      : %d.\n", FileHeader->NumberOfSections);
	CHAR TimeDateStamp[MAX_PATH] = { 0 };
	GetTimeDateStamp(FileHeader->TimeDateStamp, TimeDateStamp);
	printf("TimeDateStamp         : %d (%#010x), %s.\n", FileHeader->TimeDateStamp, FileHeader->TimeDateStamp, TimeDateStamp);

	printf("PointerToSymbolTable  : %#010x.\n", FileHeader->PointerToSymbolTable);
	printf("NumberOfSymbols       : %d.\n", FileHeader->NumberOfSymbols);
	printf("SizeOfOptionalHeader  : %d.\n", FileHeader->SizeOfOptionalHeader);
}

int main(int argc, char* argv[])
{
	DWORD LastError = ERROR_SUCCESS;
	HANDLE hFile = INVALID_HANDLE_VALUE;
	HANDLE hMapFile = NULL;
	PBYTE FileContent = NULL;

	hFile = CreateFileA(argv[1],
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		LastError = GetLastError();
		return LastError;
	}

	LARGE_INTEGER FileSize = { 0 };
	if (0 == GetFileSizeEx(hFile, &FileSize)) {
		LastError = GetLastError();
		return LastError;
	}

	if (0 == FileSize.QuadPart) {
		LastError = ERROR_EMPTY;
		return LastError;
	}

	if (FileSize.HighPart) {
		LastError = ERROR_EMPTY;
		return LastError;
	}

	hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, NULL, NULL, NULL);
	if (hMapFile == NULL) {
		LastError = GetLastError();
		return LastError;
	}

	FileContent = (PBYTE)MapViewOfFile(hMapFile, SECTION_MAP_READ, NULL, NULL, 0);
	if (FileContent == NULL) {
		LastError = GetLastError();
		return LastError;
	}

	Dump(FileContent, FileSize);

	if (FileContent) {
		UnmapViewOfFile(FileContent);
	}

	if (hMapFile) {
		CloseHandle(hMapFile);
	}

	if (INVALID_HANDLE_VALUE != hFile) {
		CloseHandle(hFile);
	}

	return LastError;
}
