#include "pch.h"
#include "BoundImport.h"
#include "Public.h"

DWORD IAT(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_IAT, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("IAT mpty.\n");
        return ret;
    }

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PULONG_PTR IATBase = (PULONG_PTR)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_IAT,
            &size, &FoundHeader);

    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    printf("IAT Directory Information:\n");

    printf("IAT Directory Numbers:%zd.\n", DataDirectory.Size / sizeof(ULONG));

    for (DWORD i = 0; i * sizeof(ULONG) < DataDirectory.Size; i++) {
        ULONG_PTR ImportThunk = IATBase[i];
        printf("%06d] ImportThunk:%zd.\n", i, ImportThunk);
        i++;
    }

    return ret;
}

