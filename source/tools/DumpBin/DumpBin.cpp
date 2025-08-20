#include "pch.h"
#include "Public.h"
#include "PeHeader.h"
#include "Export.h"
#include "Import.h"
#include "Resource.h"
#include "Exception.h"
#include "Security.h"
#include "BaseReloc.h"
#include "Debug.h"
#include "Architecture.h"
#include "GlobalPtr.h"
#include "TLS.h"
#include "LoadConfig.h"
#include "BoundImport.h"
#include "IAT.h"
#include "DelayImport.h"
#include "ComDescriptor.h"
#include "coff.h"

int main(int argc, char* argv[])
{
	DWORD LastError = ERROR_SUCCESS;
	HANDLE hFile = INVALID_HANDLE_VALUE;
	HANDLE hMapFile = NULL;
	PBYTE FileContent = NULL;
	LARGE_INTEGER FileSize = { 0 };

	hFile = CreateFileA(argv[1], GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		LastError = GetLastError();
	}
	else {

		if (!GetFileSizeEx(hFile, &FileSize)) {
			LastError = GetLastError();
		}

		if (0 == FileSize.QuadPart) {
			LastError = ERROR_EMPTY;
		}

		if (FileSize.HighPart) {
			LastError = ERROR_EMPTY;
		}

		hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, NULL, NULL, NULL);
		if (hMapFile == NULL) {
			LastError = GetLastError();
		}
		else {

			FileContent = (PBYTE)MapViewOfFile(hMapFile, SECTION_MAP_READ, NULL, NULL, 0);
			if (FileContent == NULL) {
				LastError = GetLastError();
			}
		}
	}
	LastError = DosHeader(FileContent, FileSize.QuadPart);
	LastError = FileHeader(FileContent, FileSize.QuadPart);
	LastError = OptionlHeader(FileContent, FileSize.QuadPart);
	LastError = DataDirectory(FileContent, FileSize.QuadPart);
	LastError = SectionHeader(FileContent, FileSize.QuadPart);
	LastError = Export(FileContent, FileSize.QuadPart);
	LastError = Import(FileContent, FileSize.QuadPart);
	LastError = Resource(FileContent, FileSize.QuadPart);
	LastError = Exception(FileContent, FileSize.QuadPart);
	LastError = Security(FileContent, FileSize.QuadPart);
	LastError = BaseReloc(FileContent, FileSize.QuadPart);
	LastError = Debug(FileContent, FileSize.QuadPart);
	LastError = Architecture(FileContent, FileSize.QuadPart);
	LastError = Globalptr(FileContent, FileSize.QuadPart);
	LastError = TLS(FileContent, FileSize.QuadPart);
	LastError = LoadConfig(FileContent, FileSize.QuadPart);
	LastError = BoundImport(FileContent, FileSize.QuadPart);
	LastError = IAT(FileContent, FileSize.QuadPart);
	LastError = DelayImport(FileContent, FileSize.QuadPart);
	LastError = ComDescriptor(FileContent, FileSize.QuadPart);
	LastError = coff(FileContent, FileSize.QuadPart);
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
