#include "pch.h"
#include "Architecture.h"
#include "Public.h"

DWORD Architecture(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_ARCHITECTURE, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("Architecture empty.\n");
        return ret;
    }

    DebugBreak();

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_ARCHITECTURE_HEADER BoundImportDirectory = (PIMAGE_ARCHITECTURE_HEADER)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_ARCHITECTURE,
            &size, &FoundHeader);

    printf("Architecture Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");
    return ret;
}

