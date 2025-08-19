#include "pch.h"
#include "GlobalPtr.h"
#include "Public.h"

DWORD Globalptr(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_GLOBALPTR, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("Globalptr empty.\n");
        return ret;
    }

    DebugBreak();

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    LONG_PTR GlobalptrDirectory = (LONG_PTR)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_GLOBALPTR,
            &size, &FoundHeader);

    printf("Architecture Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");





    return ret;
}
