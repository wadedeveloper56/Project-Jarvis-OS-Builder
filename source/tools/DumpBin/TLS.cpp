#include "pch.h"
#include "TLS.h"
#include "Public.h"

DWORD TLS(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_TLS, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("TLS empty.\n");
        return ret;
    }

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_TLS_DIRECTORY TLSDirectory = (PIMAGE_TLS_DIRECTORY)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_TLS,
            &size, &FoundHeader);

    printf("TLS Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");

    if (IsPE32Ex(Data, Size)) {
        PIMAGE_TLS_DIRECTORY64 TLSDirectory64 = (PIMAGE_TLS_DIRECTORY64)TLSDirectory;

        printf("StartAddressOfRawData:%#016llX.\n", TLSDirectory64->StartAddressOfRawData);
        printf("EndAddressOfRawData:%#016llX.\n", TLSDirectory64->EndAddressOfRawData);
        printf("AddressOfIndex:%#016llX.\n", TLSDirectory64->AddressOfIndex);
        printf("AddressOfCallBacks:%#016llX.\n", TLSDirectory64->AddressOfCallBacks);
        PIMAGE_TLS_CALLBACK* TlsCallback = (PIMAGE_TLS_CALLBACK*)TLSDirectory64->AddressOfCallBacks;
        printf("SizeOfZeroFill:%#010X.\n", TLSDirectory64->SizeOfZeroFill);
        printf("ReserCharacteristicsved0:%#010X.\n", TLSDirectory64->Characteristics);
        printf("Reserved0:%#010X.\n", TLSDirectory64->Reserved0);
        printf("Alignment:%#010X.\n", TLSDirectory64->Alignment);
        printf("Reserved1:%#010X.\n", TLSDirectory64->Reserved1);
    }
    else {
        PIMAGE_TLS_DIRECTORY32 TLSDirectory32 = (PIMAGE_TLS_DIRECTORY32)TLSDirectory;

        printf("StartAddressOfRawData:%#010X.\n", TLSDirectory32->StartAddressOfRawData);
        printf("EndAddressOfRawData:%#010X.\n", TLSDirectory32->EndAddressOfRawData);
        printf("AddressOfIndex:%#010X.\n", TLSDirectory32->AddressOfIndex);
        printf("AddressOfCallBacks:%#010X.\n", TLSDirectory32->AddressOfCallBacks);
        PIMAGE_TLS_CALLBACK* TlsCallback = (PIMAGE_TLS_CALLBACK*)ULongToHandle(TLSDirectory32->AddressOfCallBacks);
        printf("SizeOfZeroFill:%#010X.\n", TLSDirectory32->SizeOfZeroFill);
        printf("ReserCharacteristicsved0:%#010X.\n", TLSDirectory32->Characteristics);
        printf("Reserved0:%#010X.\n", TLSDirectory32->Reserved0);
        printf("Alignment:%#010X.\n", TLSDirectory32->Alignment);
        printf("Reserved1:%#010X.\n", TLSDirectory32->Reserved1);
    }

    return ret;
}

