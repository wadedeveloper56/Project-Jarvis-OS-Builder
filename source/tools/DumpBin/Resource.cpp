#include "pch.h"
#include "Import.h"
#include "Public.h"

const char* GetResourceTypeString(WORD Id)
{
    const char* str = "未知";

    switch (Id) {
        case (SIZE_T)RT_CURSOR:
            str = "CURSOR";
            break;
        case (SIZE_T)RT_BITMAP:
            str = "BITMAP";
            break;
        case (SIZE_T)RT_ICON:
            str = "ICON";
            break;
        case (SIZE_T)RT_MENU:
            str = "MENU";
            break;
        case (SIZE_T)RT_DIALOG:
            str = "DIALOG";
            break;
        case (SIZE_T)RT_STRING:
            str = "STRING";
            break;
        case (SIZE_T)RT_FONTDIR:
            str = "FONTDIR";
            break;
        case (SIZE_T)RT_FONT:
            str = "FONT";
            break;
        case (SIZE_T)RT_ACCELERATOR:
            str = "ACCELERATOR";
            break;
        case (SIZE_T)RT_RCDATA:
            str = "RCDATA";
            break;
        case (SIZE_T)RT_MESSAGETABLE:
            str = "MESSAGETABLE";
            break;
        case (SIZE_T)RT_GROUP_CURSOR:
            str = "GROUP_CURSOR";
            break;
        case (SIZE_T)RT_GROUP_ICON:
            str = "GROUP_ICON";
            break;
        case (SIZE_T)RT_VERSION:
            str = "VERSION";
            break;
        case (SIZE_T)RT_DLGINCLUDE:
            str = "DLGINCLUDE";
            break;
        case (SIZE_T)RT_PLUGPLAY:
            str = "PLUGPLAY";
            break;
        case (SIZE_T)RT_VXD:
            str = "VXD";
            break;
        case (SIZE_T)RT_ANICURSOR:
            str = "ANICURSOR";
            break;
        case (SIZE_T)RT_ANIICON:
            str = "ANIICON";
            break;
        case (SIZE_T)RT_HTML:
            str = "HTML";
            break;
        case (SIZE_T)RT_MANIFEST:
            str = "MANIFEST";
            break;
        default:
            printf("Id:%#x.\n", Id);
            break;
    }

    return str;
}


void PrintNameString(PIMAGE_RESOURCE_DIRECTORY ResourceDirectory,PIMAGE_RESOURCE_DIRECTORY_ENTRY ResourceDirectoryEntry)
{
    if (ResourceDirectoryEntry->NameIsString) {
        PIMAGE_RESOURCE_DIR_STRING_U ResourceNameString = (PIMAGE_RESOURCE_DIR_STRING_U)
            ((PCHAR)ResourceDirectory + ResourceDirectoryEntry->NameOffset);

        WCHAR* buf = (WCHAR*)HeapAlloc(GetProcessHeap(),
            HEAP_ZERO_MEMORY,
            ResourceNameString->Length + sizeof(WCHAR));
        if (buf) {
            RtlCopyMemory(buf, ResourceNameString->NameString, ResourceNameString->Length);

            printf("NameString:%ls.\n", buf);

            HeapFree(GetProcessHeap(), 0, buf);
        }
        else {
            _ASSERTE(false);
        }
    }
}


DWORD Resource(PBYTE Data, DWORD Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_RESOURCE, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("此文件没有Resource.\n");
        return ret;
    }

    printf("Resource Descriptor Directory Information:\n");
    printf("VirtualAddress:%#010X.\n", DataDirectory.VirtualAddress);
    printf("Size:%#010X.\n", DataDirectory.Size);
    printf("\n");

    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_RESOURCE_DIRECTORY ResourceDirectory = (PIMAGE_RESOURCE_DIRECTORY)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_RESOURCE,
            &size, &FoundHeader);
    if (FoundHeader) {
        printf("SectionName:%s.\n", FoundHeader->Name);
    }

    printf("Characteristics:%#010X.\n", ResourceDirectory->Characteristics);

    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(ResourceDirectory->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp:%d(%#010X), 时间戳：%s.\n",
        ResourceDirectory->TimeDateStamp,
        ResourceDirectory->TimeDateStamp,
        TimeDateStamp);

    printf("Version:%d.%d.\n", ResourceDirectory->MajorVersion, ResourceDirectory->MinorVersion);
    printf("NumberOfNamedEntries:%#06X.\n", ResourceDirectory->NumberOfNamedEntries);
    printf("NumberOfIdEntries:%#06X.\n", ResourceDirectory->NumberOfIdEntries);
    printf("\n");

    //////////////////////////////////////////////////////////////////////////////////////////////

    WORD NumberOfEntries = ResourceDirectory->NumberOfNamedEntries + ResourceDirectory->NumberOfIdEntries;

    PIMAGE_RESOURCE_DIRECTORY_ENTRY ResourceDirectoryEntry = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)
        ((PCHAR)ResourceDirectory + sizeof(IMAGE_RESOURCE_DIRECTORY));

    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);

    printf("\n");

    for (int i = 0; i < NumberOfEntries; i++) {
        if (ResourceDirectoryEntry->DataIsDirectory) {
            PIMAGE_RESOURCE_DIRECTORY ResourceDirectory2 = (PIMAGE_RESOURCE_DIRECTORY)
                ((PCHAR)ResourceDirectory + ResourceDirectoryEntry->OffsetToDirectory);
            WORD NumberOfEntries2 = ResourceDirectory2->NumberOfNamedEntries +
                ResourceDirectory2->NumberOfIdEntries;
            PIMAGE_RESOURCE_DIRECTORY_ENTRY ResourceDirectoryEntry2 = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)
                ((PCHAR)ResourceDirectory2 + sizeof(IMAGE_RESOURCE_DIRECTORY));

            for (int j = 0; j < NumberOfEntries2; j++) { 
                if (ResourceDirectoryEntry2->DataIsDirectory) {
                    PIMAGE_RESOURCE_DIRECTORY ResourceDirectory3 = (PIMAGE_RESOURCE_DIRECTORY)
                        ((PCHAR)ResourceDirectory + ResourceDirectoryEntry2->OffsetToDirectory);
                    WORD NumberOfEntries3 = ResourceDirectory3->NumberOfNamedEntries +
                        ResourceDirectory3->NumberOfIdEntries;
                    PIMAGE_RESOURCE_DIRECTORY_ENTRY ResourceDirectoryEntry3 = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)
                        ((PCHAR)ResourceDirectory3 + sizeof(IMAGE_RESOURCE_DIRECTORY));

                    for (int k = 0; k < NumberOfEntries3; k++) {
                        if (ResourceDirectoryEntry3->DataIsDirectory) {
                            _ASSERTE(false);
                        }
                        else {
                            PIMAGE_RESOURCE_DATA_ENTRY DataEntry = (PIMAGE_RESOURCE_DATA_ENTRY)
                                ((PCHAR)ResourceDirectory + ResourceDirectoryEntry3->OffsetToData);

                            PCHAR OffsetToData = (PCHAR)ImageRvaToVa(NtHeaders, Data, DataEntry->OffsetToData, NULL);

                            PrintNameString(ResourceDirectory, ResourceDirectoryEntry);
                            PrintNameString(ResourceDirectory, ResourceDirectoryEntry2);
                            PrintNameString(ResourceDirectory, ResourceDirectoryEntry3);

                            printf("Resource %12s, %#06X, %#06X, OffsetToData:%#010X, Size:%#010X(%d).\n",
                                GetResourceTypeString(ResourceDirectoryEntry->Id),
                                ResourceDirectoryEntry2->Id,
                                ResourceDirectoryEntry3->Id,
                                DataEntry->OffsetToData,
                                DataEntry->Size,
                                DataEntry->Size);
                        }

                        ResourceDirectoryEntry3++;
                    }
                }
                else {
                    _ASSERTE(false);
                }

                ResourceDirectoryEntry2++;
            }
        }
        else {
            _ASSERTE(false);
        }

        ResourceDirectoryEntry++;

        printf("\n");
    }

    return ret;
}

