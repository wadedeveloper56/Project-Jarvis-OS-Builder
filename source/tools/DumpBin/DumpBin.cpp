#include "pch.h"

DWORD PeHeader(PBYTE Data, LONGLONG Size)
{
	DWORD ret = ERROR_SUCCESS;
	PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
	printf("Dos Header Information:\r\n");
	printf("e_magic:%#06X.\r\n", DosHeader->e_magic);
	printf("e_cblp:%#06X.\r\n", DosHeader->e_cblp);
	printf("e_cp:%#06X.\r\n", DosHeader->e_cp);
	printf("e_crlc:%#06X.\r\n", DosHeader->e_crlc);
	printf("e_cparhdr:%#06X.\r\n", DosHeader->e_cparhdr);
	printf("e_minalloc:%#06X.\r\n", DosHeader->e_minalloc);
	printf("e_maxalloc:%#06X.\r\n", DosHeader->e_maxalloc);
	printf("e_ss:%#06X.\r\n", DosHeader->e_ss);
	printf("e_sp:%#06X.\r\n", DosHeader->e_sp);
	printf("e_csum:%#06X.\r\n", DosHeader->e_csum);
	printf("e_ip:%#06X.\r\n", DosHeader->e_ip);
	printf("e_cs:%#06X.\r\n", DosHeader->e_cs);
	printf("e_lfarlc:%#06X.\r\n", DosHeader->e_lfarlc);
	printf("e_ovno:%#06X.\r\n", DosHeader->e_ovno);
	return ret;
}

int main(int argc, char* argv[])
{
	int ret = ERROR_SUCCESS;
	DWORD LastError = ERROR_SUCCESS;
	HANDLE hMapFile = NULL;
	PBYTE FileContent = NULL;

	LPCSTR fileName = argv[1];
	HANDLE hFile = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		LastError = GetLastError();
	}
	else {
		hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, NULL, NULL, NULL);
		if (hMapFile == NULL) {
			LastError = GetLastError();
		}
		else {
			LARGE_INTEGER FileSize = { 0 };
			GetFileSizeEx(hFile, &FileSize);

			FileContent = (PBYTE)MapViewOfFile(hMapFile, SECTION_MAP_READ, NULL, NULL, 0);
			if (FileContent == NULL) {
				LastError = GetLastError();
			}
			else {
				PeHeader(FileContent, FileSize.QuadPart);
			}
		}

		if (hMapFile) {
			CloseHandle(hMapFile);
		}
		if (INVALID_HANDLE_VALUE != hFile) {
			CloseHandle(hFile);
		}
	}
	return ret;
}
