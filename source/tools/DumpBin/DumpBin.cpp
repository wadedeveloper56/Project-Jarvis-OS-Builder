#include "pch.h"
#include "Public.h"
#include "PeHeader.h"

int main(int argc, char* argv[])
{
    DWORD LastError = ERROR_SUCCESS;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    HANDLE hMapFile = NULL;
    PBYTE FileContent = NULL;
    LARGE_INTEGER FileSize = { 0 };

    hFile = CreateFileA(argv[1],
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        LastError = GetLastError();
    }
    else {

        if (0 == GetFileSizeEx(hFile, &FileSize)) {
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
    LastError = DosHeader(FileContent, FileSize.LowPart);
    LastError = FileHeader(FileContent, FileSize.LowPart);
    LastError = OptionlHeader(FileContent, FileSize.LowPart);
    LastError = DataDirectory(FileContent, FileSize.LowPart);
    LastError = SectionHeader(FileContent, FileSize.LowPart);
	//ret = Export(argv[2]);
	//ret = Import(argv[2]);
	//ret = Resource(argv[2]);
	//ret = Exception(argv[2]);
	//ret = Security(argv[2]);
	//ret = BaseReloc(argv[2]);
	//ret = Debug(argv[2]);
	//ret = Architecture(argv[2]);
	//ret = Globalptr(argv[2]);
	//ret = TLS(argv[2]);
	//ret = LoadConfig(argv[2]);
	//ret = BoundImport(argv[2]);
	//ret = IAT(argv[2]);
	//ret = DelayImport(argv[2]);
	//ret = ComDescriptor(argv[2]);
	//ret = coff(argv[2]);
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
