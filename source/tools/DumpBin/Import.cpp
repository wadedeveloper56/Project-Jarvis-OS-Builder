#include "pch.h"
#include "Import.h"
#include "Public.h"

void PrintImport(PBYTE Data, LONGLONG Size, PIMAGE_IMPORT_DESCRIPTOR ImportDirectory)
{
    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    printf("OriginalFirstThunk:%#010X.\n", ImportDirectory->OriginalFirstThunk);
    printf("TimeDateStamp:%#010X.\n", ImportDirectory->TimeDateStamp);
    printf("ForwarderChain:%#010X.\n", ImportDirectory->ForwarderChain);
    printf("Name:%#010X.\n", ImportDirectory->Name);
    printf("FirstThunk:%#010X.\n", ImportDirectory->FirstThunk);

    PCHAR DllName = (PCHAR)ImageRvaToVa(NtHeaders, Data, (ULONG)ImportDirectory->Name, NULL);
    printf("DllName:%s.\n", DllName);

    PIMAGE_THUNK_DATA ThunkData = (PIMAGE_THUNK_DATA)
        ImageRvaToVa(NtHeaders, Data, ImportDirectory->OriginalFirstThunk, NULL);

    if (IsPE32Ex(Data, Size)) {
        PIMAGE_THUNK_DATA64 ThunkData64 = (PIMAGE_THUNK_DATA64)ThunkData;

        for (;; ThunkData64++) {
            ULONGLONG AddressOfData = ThunkData64->u1.AddressOfData;

            if (ThunkData64->u1.AddressOfData == 0) {
                break;
            }

            if (IMAGE_SNAP_BY_ORDINAL64(AddressOfData)) {//AddressOfData > MAXLONG64
                printf("\tOrdinal:%d.\n", (WORD)IMAGE_ORDINAL64(AddressOfData));
            }
            else {
                PIMAGE_IMPORT_BY_NAME ImportByName = (PIMAGE_IMPORT_BY_NAME)
                    ImageRvaToVa(NtHeaders,
                        Data,
                        (ULONG)AddressOfData & 0xffffffff,
                        NULL);

                printf("\tHint:%#06X(%04d), ApiName:%s.\n",
                    ImportByName->Hint,
                    ImportByName->Hint,
                    ImportByName->Name);
            }
        }
    }
    else {
        PIMAGE_THUNK_DATA32 ThunkData32 = (PIMAGE_THUNK_DATA32)ThunkData;

        for (;; ThunkData32++) {
            DWORD AddressOfData = ThunkData32->u1.AddressOfData;

            if (ThunkData32->u1.AddressOfData == 0) {
                break;
            }

            if (IMAGE_SNAP_BY_ORDINAL32(AddressOfData)) {//AddressOfData > MAXINT
                printf("\tOrdinal:%d.\n", (WORD)IMAGE_ORDINAL32(AddressOfData));
            }
            else {
                PIMAGE_IMPORT_BY_NAME ImportByName = (PIMAGE_IMPORT_BY_NAME)
                    ImageRvaToVa(NtHeaders, Data, ThunkData32->u1.AddressOfData, NULL);

                printf("\tHint:%#06X(%04d), ApiName:%s.\n",
                    ImportByName->Hint,
                    ImportByName->Hint,
                    ImportByName->Name);
            }
        }
    }

    printf("\n");
}

DWORD Import(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_IMPORT, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("���ļ�û��Import.\n");
        return ret;
    }

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_IMPORT_DESCRIPTOR ImportDirectory = (PIMAGE_IMPORT_DESCRIPTOR)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_IMPORT,
            &size, &FoundHeader);



    printf("Import Directory Information:\n");

    for (;; ImportDirectory++) {
        if (ImportDirectory->OriginalFirstThunk == 0 &&
            ImportDirectory->TimeDateStamp == NULL &&
            ImportDirectory->ForwarderChain == NULL &&
            ImportDirectory->Name == NULL &&
            ImportDirectory->FirstThunk == NULL) {
            break;
        }

        //if (ImportDirectory->Characteristics == 0) {
        //    LOGA(ERROR_LEVEL, "Characteristics == 0.\n");
        //    continue;
        //}

        PrintImport(Data, Size, ImportDirectory);
    }

    return ret;
}
