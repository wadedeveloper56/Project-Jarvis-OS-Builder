#include "pch.h"
#include "Public.h"

void Dump(PBYTE Data, LARGE_INTEGER Size)
{
	PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
	PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
	PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;
	PIMAGE_DATA_DIRECTORY data_directory = NULL;
	bool IsPe64 = IsPE32Ex(Data, Size);
	if (IsPe64) {
		PIMAGE_OPTIONAL_HEADER64 OptionalHeader = (PIMAGE_OPTIONAL_HEADER64)&NtHeader->OptionalHeader;
		data_directory = &OptionalHeader->DataDirectory[0];
	}
	else {
		PIMAGE_OPTIONAL_HEADER32 OptionalHeader = (PIMAGE_OPTIONAL_HEADER32)&NtHeader->OptionalHeader;
		data_directory = &OptionalHeader->DataDirectory[0];
	}
	PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
	PIMAGE_SECTION_HEADER SectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)OptionalHeader + FileHeader->SizeOfOptionalHeader);

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
	CHAR Characteristics[MAX_PATH] = { 0 };
	GetCharacteristics(FileHeader->Characteristics, Characteristics, _countof(Characteristics));
	printf("Characteristics       : %#06x, ( %s).\n", FileHeader->Characteristics, Characteristics);
	//----------------------------------------------------------
	printf("\nData Directory Information:\n");
	printf("EXPORT         : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size);
	printf("IMPORT         : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size);
	printf("RESOURCE       : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_RESOURCE].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_RESOURCE].Size);
	printf("EXCEPTION      : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_EXCEPTION].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_EXCEPTION].Size);
	printf("SECURITY       : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_SECURITY].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_SECURITY].Size);
	printf("BASERELOC      : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size);
	printf("DEBUG          : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_DEBUG].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size);
	printf("ARCHITECTURE   : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_ARCHITECTURE].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_ARCHITECTURE].Size);
	printf("GLOBALPTR      : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].Size);
	printf("TLS            : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_TLS].Size);
	printf("LOAD_CONFIG    : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].Size);
    printf("BOUND_IMPORT   : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].Size);
	printf("IAT            : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_IAT].Size);
	printf("DELAY_IMPORT   : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].Size);
	printf("COM_DESCRIPTOR : VirtualAddress: %#010x, \tSize:%10d.\n",data_directory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress,data_directory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].Size);
	//---------------------------------------------------------------
	printf("\nSection Header Information:\n");
	printf("\n");
	for (int i = 0; i < FileHeader->NumberOfSections; i++) {
		CHAR SectionCharacteristics[MAX_PATH] = { 0 };

		printf("index                : %d.\n", i + 1);
		printf("Name                 : %s.\n", SectionHeader[i].Name);
		printf("VirtualSize          : %ld.\n", SectionHeader[i].Misc.VirtualSize);
		printf("VirtualAddress       : %#010x.\n", SectionHeader[i].VirtualAddress);
		printf("SizeOfRawData        : %ld.\n", SectionHeader[i].SizeOfRawData);
		printf("PointerToRawData     : %#010x.\n", SectionHeader[i].PointerToRawData);
		printf("PointerToRelocations : %#010x.\n", SectionHeader[i].PointerToRelocations);
		printf("PointerToLinenumbers : %#010x.\n", SectionHeader[i].PointerToLinenumbers);
		printf("NumberOfRelocations  : %d.\n", SectionHeader[i].NumberOfRelocations);
		printf("NumberOfLinenumbers  : %d.\n", SectionHeader[i].NumberOfLinenumbers);
		GetSectionCharacteristics(SectionHeader[i].Characteristics, SectionCharacteristics, _countof(SectionCharacteristics));
		printf("Characteristics      : %#010x  ( %s).\n", SectionHeader[i].Characteristics, SectionCharacteristics);

		printf("\n");
	}

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
