#include "pch.h"
#include "Export.h"
#include "Public.h"

DWORD Export(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    IMAGE_DATA_DIRECTORY DataDirectory = { 0 };
    GetDataDirectory(Data, Size, IMAGE_DIRECTORY_ENTRY_EXPORT, &DataDirectory);

    if (0 == DataDirectory.VirtualAddress) {
        printf("EXPORT empty.\r\n");
        return ret;
    }

    //��ȡ�ķ���һ��
    PIMAGE_EXPORT_DIRECTORY ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)ULongToHandle(Rva2Va(Data, DataDirectory.VirtualAddress));
    ExportDirectory = (PIMAGE_EXPORT_DIRECTORY)(Data + (SIZE_T)ExportDirectory);

    //��ȡ�ķ�������
    ULONG size = 0;
    PIMAGE_SECTION_HEADER FoundHeader = NULL;
    PIMAGE_EXPORT_DIRECTORY ExportDirectory2 = (PIMAGE_EXPORT_DIRECTORY)
        ImageDirectoryEntryToDataEx(Data,
            FALSE,
            IMAGE_DIRECTORY_ENTRY_EXPORT,
            &size, &FoundHeader);
    _ASSERTE(ExportDirectory == ExportDirectory2);
    _ASSERTE(size == DataDirectory.Size);

    //��ȡ�ķ�������
    PIMAGE_NT_HEADERS NtHeaders = ImageNtHeader(Data);
    _ASSERTE(NtHeaders);
    PIMAGE_EXPORT_DIRECTORY ExportDirectory3 = (PIMAGE_EXPORT_DIRECTORY)
        ImageRvaToVa(NtHeaders, Data, DataDirectory.VirtualAddress, NULL);
    _ASSERTE(ExportDirectory == ExportDirectory3);

    //��ȡ����������ĸ�SECTION�
    PIMAGE_SECTION_HEADER SectionHeader = ImageRvaToSection(NtHeaders, Data, DataDirectory.VirtualAddress);

    printf("Export Directory Information:\r\n");

    printf("Characteristics:%#010X.\r\n", ExportDirectory->Characteristics);//����������Ϊ 0�� 
    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(ExportDirectory->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp:%d(%#010X), ʱ�����%s.\r\n",
        ExportDirectory->TimeDateStamp,
        ExportDirectory->TimeDateStamp,
        TimeDateStamp);
    printf("Version:%d.%d.\r\n", ExportDirectory->MajorVersion, ExportDirectory->MinorVersion);
    printf("Name:%#010X.\r\n", ExportDirectory->Name);
    printf("Base:%#010X.\r\n", ExportDirectory->Base);
    printf("NumberOfFunctions:%d(%#010X).\r\n", ExportDirectory->NumberOfFunctions, ExportDirectory->NumberOfFunctions);
    printf("NumberOfNames:%d(%#010X).\r\n", ExportDirectory->NumberOfNames, ExportDirectory->NumberOfNames);
    printf("AddressOfFunctions:%#010X.\r\n", ExportDirectory->AddressOfFunctions);
    printf("AddressOfNames:%#010X.\r\n", ExportDirectory->AddressOfNames);
    printf("AddressOfNameOrdinals:%#010X.\r\n", ExportDirectory->AddressOfNameOrdinals);

    PCHAR DllName = (PCHAR)ImageRvaToVa(NtHeaders, Data, (ULONG)ExportDirectory->Name, NULL);
    printf("Name:%s.\r\n", DllName);

    printf("ֻ������û�����ֵĺ����ĸ���:%d.\r\n", ExportDirectory->NumberOfFunctions - ExportDirectory->NumberOfNames);

    PULONG FunctionsTableBase = (PULONG)ImageRvaToVa(NtHeaders, Data, (ULONG)ExportDirectory->AddressOfFunctions, NULL);
    PULONG NameTableBase = (PULONG)ImageRvaToVa(NtHeaders, Data, (ULONG)ExportDirectory->AddressOfNames, NULL);
    PUSHORT OrdinalTableBase = (PUSHORT)ImageRvaToVa(NtHeaders, Data, (ULONG)ExportDirectory->AddressOfNameOrdinals, NULL);

    //ֻ��ӡ�����ֵĺ�����
    for (DWORD i = 0; i < ExportDirectory->NumberOfNames; i++) {
        PCHAR ApiName = (PCHAR)ImageRvaToVa(NtHeaders, Data, (ULONG)NameTableBase[i], NULL);
        DWORD Ordinal = ExportDirectory->Base + OrdinalTableBase[i];
        ULONG FunctionRVA = FunctionsTableBase[OrdinalTableBase[i]];//Ordinal - 1 == Ordinal - ExportDirectory->Base

        if (FunctionRVA > DataDirectory.VirtualAddress && FunctionRVA < DataDirectory.VirtualAddress + DataDirectory.Size) {
            PCHAR forwarded = (PCHAR)ImageRvaToVa(NtHeaders, Data, FunctionRVA, NULL);

            printf("hint:%04d, Ordinal:%04d, FunctionRVA:%#010X, ApiName:%s, Forwarded:%s.\r\n",
                i + 1,
                Ordinal,
                FunctionRVA,
                ApiName,
                forwarded);
        }
        else {
            printf("hint:%04d, Ordinal:%04d, FunctionRVA:%#010X, ApiName:%s.\r\n",
                i + 1,
                Ordinal,
                FunctionRVA,
                ApiName);
        }
    }

    return ret;
}

