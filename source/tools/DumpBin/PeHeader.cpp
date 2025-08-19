#include "pch.h"
#include "PeHeader.h"
#include "Public.h"

DWORD DosHeader(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
    _ASSERTE(IMAGE_DOS_SIGNATURE == DosHeader->e_magic);
    _ASSERTE(Size >= sizeof(IMAGE_DOS_HEADER));

    printf("Dos Header Information:\n");

    printf("e_magic:%#06X.\n", DosHeader->e_magic);
    printf("e_cblp:%#06X.\n", DosHeader->e_cblp);
    printf("e_cp:%#06X.\n", DosHeader->e_cp);
    printf("e_crlc:%#06X.\n", DosHeader->e_crlc);
    printf("e_cparhdr:%#06X.\n", DosHeader->e_cparhdr);
    printf("e_minalloc:%#06X.\n", DosHeader->e_minalloc);
    printf("e_maxalloc:%#06X.\n", DosHeader->e_maxalloc);
    printf("e_ss:%#06X.\n", DosHeader->e_ss);
    printf("e_sp:%#06X.\n", DosHeader->e_sp);
    printf("e_csum:%#06X.\n", DosHeader->e_csum);
    printf("e_ip:%#06X.\n", DosHeader->e_ip);
    printf("e_cs:%#06X.\n", DosHeader->e_cs);
    printf("e_lfarlc:%#06X.\n", DosHeader->e_lfarlc);
    printf("e_ovno:%#06X.\n", DosHeader->e_ovno);

    CHAR e_res[MAX_PATH] = { 0 };
    for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res); i++) {
        wsprintfA(&e_res[i * 4], "%04X", DosHeader->e_res[i]);
    }
    printf("e_res[4]:0X%s.\n", e_res);

    printf("e_oemid:%#06X.\n", DosHeader->e_oemid);
    printf("e_oeminfo:%#06X.\n", DosHeader->e_oeminfo);

    CHAR e_res2[MAX_PATH] = { 0 };
    for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res2); i++) {
        wsprintfA(&e_res2[i * 4], "%04X", DosHeader->e_res2[i]);
    }
    printf("e_res2[10]:0X%s.\n", e_res2);

    printf("e_lfanew:%#010X.\n", DosHeader->e_lfanew);

    return ret;
}

DWORD FileHeader(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
    _ASSERTE(NtHeader);
    PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;

    printf("File Header Information:\n");

    printf("Machine:%#06X, %s.\n", FileHeader->Machine, GetMachine(FileHeader->Machine));

    printf("NumberOfSections:%#06X.\n", FileHeader->NumberOfSections);

    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(FileHeader->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp:%d(%#010X), %s.\n",
        FileHeader->TimeDateStamp,
        FileHeader->TimeDateStamp,
        TimeDateStamp);

    printf("PointerToSymbolTable:%#010X.\n", FileHeader->PointerToSymbolTable);
    printf("NumberOfSymbols:%#010X.\n", FileHeader->NumberOfSymbols);
    printf("SizeOfOptionalHeader:%#06X.\n", FileHeader->SizeOfOptionalHeader);

    CHAR Characteristics[MAX_PATH] = { 0 };
    GetCharacteristics(FileHeader->Characteristics, Characteristics, _countof(Characteristics));
    printf("Characteristics:%#06X, ( %s).\n", FileHeader->Characteristics, Characteristics);

    return ret;
}

DWORD OptionlHeader(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
    _ASSERTE(NtHeader);

    printf("\nFile Header Information:\n");

    CHAR DllCharacteristics[MAX_PATH] = { 0 };

    switch (NtHeader->OptionalHeader.Magic) {
        case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
        {
            PIMAGE_OPTIONAL_HEADER32 OptionalHeader = (PIMAGE_OPTIONAL_HEADER32)&NtHeader->OptionalHeader;

            printf("Magic:%#06X.\n", OptionalHeader->Magic);
            printf("LinkerVersion:%d.%d.\n", OptionalHeader->MajorLinkerVersion, OptionalHeader->MinorLinkerVersion);
            printf("SizeOfCode:%#010X.\n", OptionalHeader->SizeOfCode);
            printf("SizeOfInitializedData:%#010X.\n", OptionalHeader->SizeOfInitializedData);
            printf("SizeOfUninitializedData:%#010X.\n", OptionalHeader->SizeOfUninitializedData);
            printf("AddressOfEntryPoint:%#010X.\n", OptionalHeader->AddressOfEntryPoint);
            printf("BaseOfCode:%#010X.\n", OptionalHeader->BaseOfCode);

            printf("BaseOfData:%#010X.\n", OptionalHeader->BaseOfData);

            printf("ImageBase:%#010X.\n", OptionalHeader->ImageBase);
            printf("SectionAlignment:%#010X.\n", OptionalHeader->SectionAlignment);
            printf("FileAlignment:%#010X.\n", OptionalHeader->FileAlignment);
            printf("OperatingSystemVersion:%d.%d.\n", OptionalHeader->MajorOperatingSystemVersion, OptionalHeader->MinorOperatingSystemVersion);
            printf("ImageVersion:%d.%d.\n", OptionalHeader->MajorImageVersion, OptionalHeader->MinorImageVersion);
            printf("SubsystemVersion:%d.%d.\n", OptionalHeader->MajorSubsystemVersion, OptionalHeader->MinorSubsystemVersion);
            printf("Win32VersionValue:%#010X.\n", OptionalHeader->Win32VersionValue);
            printf("SizeOfImage:%#010X.\n", OptionalHeader->SizeOfImage);
            printf("SizeOfHeaders:%#010X.\n", OptionalHeader->SizeOfHeaders);
            printf("CheckSum:%#010X.\n", OptionalHeader->CheckSum);
            printf("Subsystem:%#06X(%s).\n", OptionalHeader->Subsystem, GetSubsystem(OptionalHeader->Subsystem));
            GetDllCharacteristics(OptionalHeader->DllCharacteristics, DllCharacteristics, _countof(DllCharacteristics));
            printf("DllCharacteristics:%#06X( %s).\n", OptionalHeader->DllCharacteristics, DllCharacteristics);
            printf("SizeOfStackReserve:%#010X.\n", OptionalHeader->SizeOfStackReserve);
            printf("SizeOfStackCommit:%#010X.\n", OptionalHeader->SizeOfStackCommit);
            printf("SizeOfHeapReserve:%#010X.\n", OptionalHeader->SizeOfHeapReserve);
            printf("SizeOfHeapCommit:%#010X.\n", OptionalHeader->SizeOfHeapCommit);
            printf("LoaderFlags:%#010X.\n", OptionalHeader->LoaderFlags);
            printf("NumberOfRvaAndSizes:%#010X.\n", OptionalHeader->NumberOfRvaAndSizes);

            //DataDirectory另外打印。
            break;
        }
        case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
        {
            PIMAGE_OPTIONAL_HEADER64 OptionalHeader = (PIMAGE_OPTIONAL_HEADER64)&NtHeader->OptionalHeader;

            printf("Magic:%#06X.\n", OptionalHeader->Magic);
            printf("LinkerVersion:%d.%d.\n", OptionalHeader->MajorLinkerVersion, OptionalHeader->MinorLinkerVersion);
            printf("SizeOfCode:%#010X.\n", OptionalHeader->SizeOfCode);
            printf("SizeOfInitializedData:%#010X.\n", OptionalHeader->SizeOfInitializedData);
            printf("SizeOfUninitializedData:%#010X.\n", OptionalHeader->SizeOfUninitializedData);
            printf("AddressOfEntryPoint:%#010X.\n", OptionalHeader->AddressOfEntryPoint);
            printf("BaseOfCode:%#010X.\n", OptionalHeader->BaseOfCode);

            printf("ImageBase:%#I64X.\n", OptionalHeader->ImageBase);
            printf("SectionAlignment:%#010X.\n", OptionalHeader->SectionAlignment);
            printf("FileAlignment:%#010X.\n", OptionalHeader->FileAlignment);
            printf("OperatingSystemVersion:%d.%d.\n", OptionalHeader->MajorOperatingSystemVersion, OptionalHeader->MinorOperatingSystemVersion);
            printf("ImageVersion:%d.%d.\n", OptionalHeader->MajorImageVersion, OptionalHeader->MinorImageVersion);
            printf("SubsystemVersion:%d.%d.\n", OptionalHeader->MajorSubsystemVersion, OptionalHeader->MinorSubsystemVersion);
            printf("Win32VersionValue:%#010X.\n", OptionalHeader->Win32VersionValue);
            printf("SizeOfImage:%#010X.\n", OptionalHeader->SizeOfImage);
            printf("SizeOfHeaders:%#010X.\n", OptionalHeader->SizeOfHeaders);
            printf("CheckSum:%#010X.\n", OptionalHeader->CheckSum);
            printf("Subsystem:%#06X(%s).\n", OptionalHeader->Subsystem, GetSubsystem(OptionalHeader->Subsystem));
            GetDllCharacteristics(OptionalHeader->DllCharacteristics, DllCharacteristics, _countof(DllCharacteristics));
            printf("DllCharacteristics:%#06X( %s).\n", OptionalHeader->DllCharacteristics, DllCharacteristics);
            printf("SizeOfStackReserve:%#I64X.\n", OptionalHeader->SizeOfStackReserve);
            printf("SizeOfStackCommit:%#I64X.\n", OptionalHeader->SizeOfStackCommit);
            printf("SizeOfHeapReserve:%#I64X.\n", OptionalHeader->SizeOfHeapReserve);
            printf("SizeOfHeapCommit:%#I64X.\n", OptionalHeader->SizeOfHeapCommit);
            printf("LoaderFlags:%#010X.\n", OptionalHeader->LoaderFlags);
            printf("NumberOfRvaAndSizes:%#010X.\n", OptionalHeader->NumberOfRvaAndSizes);

            //DataDirectory另外打印。
            break;
        }
        case IMAGE_ROM_OPTIONAL_HDR_MAGIC:
            //LOGA(ERROR_LEVEL, "恭喜你:发现一个ROM映像!");
            break;
        default:
            //LOGA(ERROR_LEVEL, "Magic:%#X!", NtHeader->OptionalHeader.Magic);
            break;
    }

    return ret;
}

DWORD DataDirectory(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
    _ASSERTE(NtHeader);

    PIMAGE_DATA_DIRECTORY data_directory = NULL;

    bool IsPe64 = IsPE32Ex(Data, Size);
    if (IsPe64) {
        PIMAGE_OPTIONAL_HEADER64 OptionalHeader = (PIMAGE_OPTIONAL_HEADER64)&NtHeader->OptionalHeader;

        data_directory = &OptionalHeader->DataDirectory[0];

        _ASSERTE(IMAGE_NUMBEROF_DIRECTORY_ENTRIES == OptionalHeader->NumberOfRvaAndSizes);
    }
    else {
        PIMAGE_OPTIONAL_HEADER32 OptionalHeader = (PIMAGE_OPTIONAL_HEADER32)&NtHeader->OptionalHeader;

        data_directory = &OptionalHeader->DataDirectory[0];

        _ASSERTE(IMAGE_NUMBEROF_DIRECTORY_ENTRIES == OptionalHeader->NumberOfRvaAndSizes);
    }

    printf("Data Directory Information:\n");

    //for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++) {
    //    PIMAGE_DATA_DIRECTORY temp = &data_directory[i];
    //    printf("index:%d, \tVirtualAddress:%#010X, \tSize:%#010X.\n", i, temp->VirtualAddress, temp->Size);
    //}

    printf("EXPORT: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size);

    printf("IMPORT: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size);

    printf("RESOURCE: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_RESOURCE].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_RESOURCE].Size);

    printf("EXCEPTION: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_EXCEPTION].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_EXCEPTION].Size);

    printf("SECURITY: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_SECURITY].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_SECURITY].Size);

    printf("BASERELOC: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size);

    printf("DEBUG: \t\t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_DEBUG].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size);

    printf("ARCHITECTURE: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_ARCHITECTURE].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_ARCHITECTURE].Size);

    printf("GLOBALPTR: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].Size);

    printf("TLS: \t\t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_TLS].Size);

    printf("LOAD_CONFIG: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].Size);

    printf("BOUND_IMPORT: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].Size);

    printf("IAT: \t\t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_IAT].Size);

    printf("DELAY_IMPORT: \t\tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].Size);

    printf("COM_DESCRIPTOR: \tVirtualAddress:%#010X, \tSize:%#010X.\n",
        data_directory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress,
        data_directory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].Size);

    return ret;
}

DWORD SectionHeader(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
    _ASSERTE(NtHeader);
    PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;
    PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
    PIMAGE_SECTION_HEADER SectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)OptionalHeader + FileHeader->SizeOfOptionalHeader);//必须加(ULONG),不然出错.

    printf("Section Header Information:\n");

    printf("\n");

    for (int i = 0; i < FileHeader->NumberOfSections; i++) {
        CHAR SectionCharacteristics[MAX_PATH] = { 0 };

        printf("index:%d.\n", i + 1);
        printf("Name:%s.\n", SectionHeader[i].Name);
        printf("VirtualSize:%#010X.\n", SectionHeader[i].Misc.VirtualSize);
        printf("VirtualAddress:%#010X.\n", SectionHeader[i].VirtualAddress);
        printf("SizeOfRawData:%#010X.\n", SectionHeader[i].SizeOfRawData);
        printf("PointerToRawData:%#010X.\n", SectionHeader[i].PointerToRawData);
        printf("PointerToRelocations:%#010X.\n", SectionHeader[i].PointerToRelocations);
        printf("PointerToLinenumbers:%#010X.\n", SectionHeader[i].PointerToLinenumbers);
        printf("NumberOfRelocations:%#06X.\n", SectionHeader[i].NumberOfRelocations);
        printf("NumberOfLinenumbers:%#06X.\n", SectionHeader[i].NumberOfLinenumbers);
        GetSectionCharacteristics(SectionHeader[i].Characteristics, SectionCharacteristics, _countof(SectionCharacteristics));
        printf("Characteristics:%#010X( %s).\n", SectionHeader[i].Characteristics, SectionCharacteristics);

        printf("\n");
    }

    return ret;
}

