#include "pch.h"

void GetSectionCharacteristics(DWORD Characteristics,PCHAR String,size_t cchDest)
{
    if (Characteristics & IMAGE_SCN_SCALE_INDEX) {
        StringCchCatA(String, cchDest, "SCALE_INDEX ");
    }

    if (Characteristics & IMAGE_SCN_TYPE_NO_PAD) {
        StringCchCatA(String, cchDest, "TYPE_NO_PAD ");
    }

    if (Characteristics & IMAGE_SCN_CNT_CODE) {
        StringCchCatA(String, cchDest, "CNT_CODE ");
    }

    if (Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) {
        StringCchCatA(String, cchDest, "INITIALIZED_DATA ");
    }

    if (Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) {
        StringCchCatA(String, cchDest, "CNT_UNINITIALIZED_DATA ");
    }

    if (Characteristics & IMAGE_SCN_LNK_OTHER) {
        StringCchCatA(String, cchDest, "LNK_OTHER ");
    }

    if (Characteristics & IMAGE_SCN_LNK_INFO) {
        StringCchCatA(String, cchDest, "LNK_INFO ");
    }

    if (Characteristics & IMAGE_SCN_LNK_REMOVE) {
        StringCchCatA(String, cchDest, "LNK_REMOVE ");
    }

    if (Characteristics & IMAGE_SCN_LNK_COMDAT) {
        StringCchCatA(String, cchDest, "LNK_COMDAT ");
    }

    if (Characteristics & IMAGE_SCN_NO_DEFER_SPEC_EXC) {
        StringCchCatA(String, cchDest, "NO_DEFER_SPEC_EXC ");
    }

    if (Characteristics & IMAGE_SCN_GPREL) {
        StringCchCatA(String, cchDest, "GPREL ");
    }

    if (Characteristics & IMAGE_SCN_MEM_FARDATA) {
        StringCchCatA(String, cchDest, "MEM_FARDATA ");
    }

    if (Characteristics & IMAGE_SCN_MEM_PURGEABLE) {
        StringCchCatA(String, cchDest, "MEM_PURGEABLE ");
    }

    if (Characteristics & IMAGE_SCN_MEM_16BIT) {
        StringCchCatA(String, cchDest, "MEM_16BIT ");
    }

    if (Characteristics & IMAGE_SCN_MEM_LOCKED) {
        StringCchCatA(String, cchDest, "MEM_LOCKED ");
    }

    if (Characteristics & IMAGE_SCN_MEM_PRELOAD) {
        StringCchCatA(String, cchDest, "MEM_PRELOAD ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_1BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_1BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_2BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_2BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_4BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_4BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_8BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_8BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_16BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_16BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_32BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_32BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_64BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_64BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_128BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_128BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_256BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_256BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_512BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_512BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_1024BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_1024BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_2048BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_2048BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_4096BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_4096BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_8192BYTES) {
        StringCchCatA(String, cchDest, "ALIGN_8192BYTES ");
    }

    if (Characteristics & IMAGE_SCN_ALIGN_MASK) {
        StringCchCatA(String, cchDest, "ALIGN_MASK ");
    }

    if (Characteristics & IMAGE_SCN_LNK_NRELOC_OVFL) {
        StringCchCatA(String, cchDest, "LNK_NRELOC_OVFL ");
    }

    if (Characteristics & IMAGE_SCN_MEM_DISCARDABLE) {
        StringCchCatA(String, cchDest, "MEM_DISCARDABLE ");
    }

    if (Characteristics & IMAGE_SCN_MEM_NOT_CACHED) {
        StringCchCatA(String, cchDest, "MEM_NOT_CACHED ");
    }

    if (Characteristics & IMAGE_SCN_MEM_NOT_PAGED) {
        StringCchCatA(String, cchDest, "MEM_NOT_PAGED ");
    }

    if (Characteristics & IMAGE_SCN_MEM_SHARED) {
        StringCchCatA(String, cchDest, "MEM_SHARED ");
    }

    if (Characteristics & IMAGE_SCN_MEM_EXECUTE) {
        StringCchCatA(String, cchDest, "MEM_EXECUTE ");
    }

    if (Characteristics & IMAGE_SCN_MEM_READ) {
        StringCchCatA(String, cchDest, "MEM_READ ");
    }

    if (Characteristics & IMAGE_SCN_MEM_WRITE) {
        StringCchCatA(String, cchDest, "MEM_WRITE ");
    }
}

void GetDllCharacteristics(WORD Characteristics,PCHAR String,size_t cchDest)
{
    if (Characteristics & IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA) {
        StringCchCatA(String, cchDest, "HIGH_ENTROPY_VA ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE) {
        StringCchCatA(String, cchDest, "DYNAMIC_BASE ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY) {
        StringCchCatA(String, cchDest, "FORCE_INTEGRITY ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_NX_COMPAT) {
        StringCchCatA(String, cchDest, "NX_COMPAT ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_NO_ISOLATION) {
        StringCchCatA(String, cchDest, "NO_ISOLATION ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_NO_SEH) {
        StringCchCatA(String, cchDest, "NO_SEH ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_NO_BIND) {
        StringCchCatA(String, cchDest, "NO_BIND ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_APPCONTAINER) {
        StringCchCatA(String, cchDest, "APPCONTAINER ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_WDM_DRIVER) {
        StringCchCatA(String, cchDest, "WDM_DRIVER ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_GUARD_CF) {
        StringCchCatA(String, cchDest, "GUARD_CF ");
    }

    if (Characteristics & IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE) {
        StringCchCatA(String, cchDest, "TERMINAL_SERVER_AWARE ");
    }
}

PCSTR GetSubsystem(WORD Subsystem)
{
    PCSTR SubsystemString = NULL;

    switch (Subsystem) {
        case IMAGE_SUBSYSTEM_UNKNOWN:
            SubsystemString = "UNKNOWN";
            break;
        case IMAGE_SUBSYSTEM_NATIVE:
            SubsystemString = "NATIVE";
            break;
        case IMAGE_SUBSYSTEM_WINDOWS_GUI:
            SubsystemString = "WINDOWS_GUI";
            break;
        case IMAGE_SUBSYSTEM_WINDOWS_CUI:
            SubsystemString = "WINDOWS_CUI";
            break;
        case IMAGE_SUBSYSTEM_OS2_CUI:
            SubsystemString = "OS2_CUI";
            break;
        case IMAGE_SUBSYSTEM_POSIX_CUI:
            SubsystemString = "POSIX_CUI";
            break;
        case IMAGE_SUBSYSTEM_NATIVE_WINDOWS:
            SubsystemString = "NATIVE_WINDOWS";
            break;
        case IMAGE_SUBSYSTEM_WINDOWS_CE_GUI:
            SubsystemString = "WINDOWS_CE_GUI";
            break;
        case IMAGE_SUBSYSTEM_EFI_APPLICATION:
            SubsystemString = "EFI_APPLICATION";
            break;
        case IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER:
            SubsystemString = "EFI_BOOT_SERVICE_DRIVER";
            break;
        case IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER:
            SubsystemString = "EFI_RUNTIME_DRIVER";
            break;
        case IMAGE_SUBSYSTEM_EFI_ROM:
            SubsystemString = "EFI_ROM";
            break;
        case IMAGE_SUBSYSTEM_XBOX:
            SubsystemString = "XBOX";
            break;
        case IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION:
            SubsystemString = "WINDOWS_BOOT_APPLICATION";
            break;
        case IMAGE_SUBSYSTEM_XBOX_CODE_CATALOG:
            SubsystemString = "XBOX_CODE_CATALOG";
            break;
        default:
            //LOGA(ERROR_LEVEL, "SUBSYSTEM:%#X", Subsystem);
            SubsystemString = "Î´¶¨Òå";
            break;
    }

    return SubsystemString;
}

void TimeStampToFileTime(INT64 timeStamp, FILETIME& fileTime)
{
    INT64 nll = timeStamp * 10000000 + 116444736000000000;
    fileTime.dwLowDateTime = (DWORD)nll;
    fileTime.dwHighDateTime = nll >> 32;
}

void FileTimeToLocalTimeA(PFILETIME ft, char* time)
{
    FILETIME lft;
    BOOL B = FileTimeToLocalFileTime(ft, &lft);
    _ASSERTE(B);

    SYSTEMTIME st;
    B = FileTimeToSystemTime(&lft, &st);
    _ASSERTE(B);

    wsprintfA(time, "%04d-%02d-%02d %02d:%02d:%02d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
}

void GetTimeDateStamp(DWORD TimeDateStamp, PCHAR String)
{
    FILETIME FileTime = { 0 };
    TimeStampToFileTime(TimeDateStamp, FileTime);
    FileTimeToLocalTimeA(&FileTime, String);
}

void GetCharacteristics(WORD Characteristics, PCHAR String, size_t cchDest)
{
    _ASSERTE(String);
    //String[0] = 0;

    if (Characteristics & IMAGE_FILE_RELOCS_STRIPPED) {
        StringCchCatA(String, cchDest, "RELOCS_STRIPPED ");
    }

    if (Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE) {
        StringCchCatA(String, cchDest, "EXECUTABLE_IMAGE ");
    }

    if (Characteristics & IMAGE_FILE_LINE_NUMS_STRIPPED) {
        StringCchCatA(String, cchDest, "LINE_NUMS_STRIPPED ");
    }

    if (Characteristics & IMAGE_FILE_LOCAL_SYMS_STRIPPED) {
        StringCchCatA(String, cchDest, "LOCAL_SYMS_STRIPPED ");
    }

    if (Characteristics & IMAGE_FILE_AGGRESIVE_WS_TRIM) {
        StringCchCatA(String, cchDest, "AGGRESIVE_WS_TRIM ");
    }

    if (Characteristics & IMAGE_FILE_LARGE_ADDRESS_AWARE) {
        StringCchCatA(String, cchDest, "LARGE_ADDRESS_AWARE ");
    }

    if (Characteristics & IMAGE_FILE_BYTES_REVERSED_LO) {
        StringCchCatA(String, cchDest, "BYTES_REVERSED_LO ");
    }

    if (Characteristics & IMAGE_FILE_32BIT_MACHINE) {
        StringCchCatA(String, cchDest, "32BIT_MACHINE ");
    }

    if (Characteristics & IMAGE_FILE_DEBUG_STRIPPED) {
        StringCchCatA(String, cchDest, "DEBUG_STRIPPED ");
    }

    if (Characteristics & IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP) {
        StringCchCatA(String, cchDest, "REMOVABLE_RUN_FROM_SWAP ");
    }

    if (Characteristics & IMAGE_FILE_NET_RUN_FROM_SWAP) {
        StringCchCatA(String, cchDest, "NET_RUN_FROM_SWAP ");
    }

    if (Characteristics & IMAGE_FILE_SYSTEM) {
        StringCchCatA(String, cchDest, "SYSTEM ");
    }

    if (Characteristics & IMAGE_FILE_DLL) {
        StringCchCatA(String, cchDest, "DLL ");
    }

    if (Characteristics & IMAGE_FILE_UP_SYSTEM_ONLY) {
        StringCchCatA(String, cchDest, "UP_SYSTEM_ONLY ");
    }

    if (Characteristics & IMAGE_FILE_BYTES_REVERSED_HI) {
        StringCchCatA(String, cchDest, "BYTES_REVERSED_HI ");
    }
}

PCSTR GetMachine(WORD Machine)
{
    PCSTR MachineString = NULL;

    switch (Machine) {
        case IMAGE_FILE_MACHINE_UNKNOWN:
            MachineString = "ÊÊÓÃÓÚÈÎºÎÀàÐÍ´¦ÀíÆ÷";
            break;
        case IMAGE_FILE_MACHINE_TARGET_HOST:
            MachineString = "Useful for indicating we want to interact with the host and not a WoW guest";
            break;
        case IMAGE_FILE_MACHINE_I386:
            MachineString = "Intel 386";
            break;
        case IMAGE_FILE_MACHINE_R3000:
            MachineString = "MIPS little-endian, 0x160 big-endian";
            break;
        case IMAGE_FILE_MACHINE_R4000:
            MachineString = "MIPS little-endian";
            break;
        case IMAGE_FILE_MACHINE_R10000:
            MachineString = "MIPS little-endian";
            break;
        case IMAGE_FILE_MACHINE_WCEMIPSV2:
            MachineString = "MIPS little-endian WCE v2";
            break;
        case IMAGE_FILE_MACHINE_ALPHA:
            MachineString = "Alpha_AXP";
            break;
        case IMAGE_FILE_MACHINE_SH3:
            MachineString = "SH3 little-endian";
            break;
        case IMAGE_FILE_MACHINE_SH3DSP:
            MachineString = "IMAGE_FILE_MACHINE_SH3DSP";
            break;
        case IMAGE_FILE_MACHINE_SH3E:
            MachineString = "SH3E little-endian";
            break;
        case IMAGE_FILE_MACHINE_SH4:
            MachineString = "SH4 little-endian";
            break;
        case IMAGE_FILE_MACHINE_SH5:
            MachineString = "SH5";
            break;
        case IMAGE_FILE_MACHINE_ARM:
            MachineString = "ARM Little-Endian";
            break;
        case IMAGE_FILE_MACHINE_THUMB:
            MachineString = "ARM Thumb/Thumb-2 Little-Endian";
            break;
        case IMAGE_FILE_MACHINE_ARMNT:
            MachineString = "ARM Thumb-2 Little-Endian";
            break;
        case IMAGE_FILE_MACHINE_AM33:
            MachineString = "IMAGE_FILE_MACHINE_AM33";
            break;
        case IMAGE_FILE_MACHINE_POWERPC:
            MachineString = "IBM PowerPC Little-Endian";
            break;
        case IMAGE_FILE_MACHINE_POWERPCFP:
            MachineString = "IMAGE_FILE_MACHINE_POWERPCFP";
            break;
        case IMAGE_FILE_MACHINE_IA64:
            MachineString = "Intel 64";
            break;
        case IMAGE_FILE_MACHINE_MIPS16:
            MachineString = "MIPS";
            break;
        case IMAGE_FILE_MACHINE_ALPHA64:
            MachineString = "ALPHA64";
            break;
        case IMAGE_FILE_MACHINE_MIPSFPU:
            MachineString = "MIPS";
            break;
        case IMAGE_FILE_MACHINE_MIPSFPU16:
            MachineString = "MIPS";
            break;
        case IMAGE_FILE_MACHINE_TRICORE:
            MachineString = "Infineon";
            break;
        case IMAGE_FILE_MACHINE_CEF:
            MachineString = "IMAGE_FILE_MACHINE_CEF";
            break;
        case IMAGE_FILE_MACHINE_EBC:
            MachineString = "EFI Byte Code";
            break;
        case IMAGE_FILE_MACHINE_AMD64:
            MachineString = "AMD64 (K8)";
            break;
        case IMAGE_FILE_MACHINE_M32R:
            MachineString = "M32R little-endian";
            break;
        case IMAGE_FILE_MACHINE_ARM64:
            MachineString = "ARM64 Little-Endian";
            break;
        case IMAGE_FILE_MACHINE_CEE:
            MachineString = "IMAGE_FILE_MACHINE_CEE";
            break;
        default:
            //LOGA(ERROR_LEVEL, "Machine:%#X", Machine);
            MachineString = "Unknown";
            break;
    }

    return MachineString;
}


DWORD PeHeader(PBYTE Data, LONGLONG Size)
{
    DWORD ret = ERROR_SUCCESS;
	PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
	_ASSERTE(IMAGE_DOS_SIGNATURE == DosHeader->e_magic);
	_ASSERTE(Size >= sizeof(IMAGE_DOS_HEADER));
	printf("Dos Header Information:\n");
	printf("e_magic   : %#06x\n", DosHeader->e_magic);
	printf("e_cblp    : %#06x\n", DosHeader->e_cblp);
	printf("e_cp      : %#06x\n", DosHeader->e_cp);
	printf("e_crlc    : %#06x\n", DosHeader->e_crlc);
	printf("e_cparhdr : %#06x\n", DosHeader->e_cparhdr);
	printf("e_minalloc: %#06x\n", DosHeader->e_minalloc);
	printf("e_maxalloc: %#06x\n", DosHeader->e_maxalloc);
	printf("e_ss      : %#06x\n", DosHeader->e_ss);
	printf("e_sp      : %#06x\n", DosHeader->e_sp);
	printf("e_csum    : %#06x\n", DosHeader->e_csum);
	printf("e_ip      : %#06x\n", DosHeader->e_ip);
	printf("e_cs      : %#06x\n", DosHeader->e_cs);
	printf("e_lfarlc  : %#06X\n", DosHeader->e_lfarlc);
	printf("e_ovno    : %#06X\n", DosHeader->e_ovno);
	CHAR e_res[MAX_PATH] = { 0 };
	for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res); i++) {
		sprintf(&e_res[i * 4], "%04x", DosHeader->e_res[i]);
	}
	printf("e_res[4]  : 0x%s\n", e_res);
	printf("e_oemid   : %#06x\n", DosHeader->e_oemid);
	printf("e_oeminfo : %#06x\n", DosHeader->e_oeminfo);
	CHAR e_res2[MAX_PATH] = { 0 };
	for (int i = 0; i < _ARRAYSIZE(DosHeader->e_res2); i++) {
		sprintf(&e_res2[i * 4], "%04x", DosHeader->e_res2[i]);
	}
	printf("e_res2[10]: 0x%s\n", e_res2);
	printf("e_lfanew  : %#010x\n", DosHeader->e_lfanew);

	PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
	_ASSERTE(NtHeader);
	PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;
	printf("\nFile Header Information:\n");
	printf("Machine              : %#06x, %s\n", FileHeader->Machine, GetMachine(FileHeader->Machine));
	printf("NumberOfSections     : %d\n", FileHeader->NumberOfSections);
    CHAR TimeDateStamp[MAX_PATH] = { 0 };
    GetTimeDateStamp(FileHeader->TimeDateStamp, TimeDateStamp);
    printf("TimeDateStamp        : %d (%#010x), %s\n", FileHeader->TimeDateStamp, FileHeader->TimeDateStamp, TimeDateStamp);
    printf("PointerToSymbolTable : %#010x\n", FileHeader->PointerToSymbolTable);
    printf("NumberOfSymbols      : %#010x\n", FileHeader->NumberOfSymbols);
    printf("SizeOfOptionalHeader : %d\n", FileHeader->SizeOfOptionalHeader);
    CHAR Characteristics[MAX_PATH] = { 0 };
    GetCharacteristics(FileHeader->Characteristics, Characteristics, _countof(Characteristics));
    printf("Characteristics      : %#06x, (%s)\n", FileHeader->Characteristics, Characteristics);

    printf("\nOptional Header Information:\n");
    CHAR DllCharacteristics[MAX_PATH] = { 0 };
    switch (NtHeader->OptionalHeader.Magic) {
        case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
        {
            PIMAGE_OPTIONAL_HEADER32 OptionalHeader = (PIMAGE_OPTIONAL_HEADER32)&NtHeader->OptionalHeader;

            printf("Magic                :%#06X\n", OptionalHeader->Magic);
            printf("LinkerVersion        :%d.%d\n", OptionalHeader->MajorLinkerVersion, OptionalHeader->MinorLinkerVersion);
            printf("SizeOfCode           :%#010X\n", OptionalHeader->SizeOfCode);
            printf("SizeOfInitializedData:%#010X\n", OptionalHeader->SizeOfInitializedData);
            printf("SizeOfUninitializedData:%#010X\n", OptionalHeader->SizeOfUninitializedData);
            printf("AddressOfEntryPoint:%#010X\n", OptionalHeader->AddressOfEntryPoint);
            printf("BaseOfCode:%#010X\n", OptionalHeader->BaseOfCode);
            printf("BaseOfData:%#010X\n", OptionalHeader->BaseOfData);
            printf("ImageBase:%#010X\n", OptionalHeader->ImageBase);
            printf("SectionAlignment:%#010X\n", OptionalHeader->SectionAlignment);
            printf("FileAlignment:%#010X\n", OptionalHeader->FileAlignment);
            printf("OperatingSystemVersion:%d.%d\n", OptionalHeader->MajorOperatingSystemVersion, OptionalHeader->MinorOperatingSystemVersion);
            printf("ImageVersion:%d.%d\n", OptionalHeader->MajorImageVersion, OptionalHeader->MinorImageVersion);
            printf("SubsystemVersion:%d.%d\n", OptionalHeader->MajorSubsystemVersion, OptionalHeader->MinorSubsystemVersion);
            printf("Win32VersionValue:%#010X\n", OptionalHeader->Win32VersionValue);
            printf("SizeOfImage:%#010X\n", OptionalHeader->SizeOfImage);
            printf("SizeOfHeaders:%#010X\n", OptionalHeader->SizeOfHeaders);
            printf("CheckSum:%#010X\n", OptionalHeader->CheckSum);
            printf("Subsystem:%#06X(%s)\n", OptionalHeader->Subsystem, GetSubsystem(OptionalHeader->Subsystem));
            GetDllCharacteristics(OptionalHeader->DllCharacteristics, DllCharacteristics, _countof(DllCharacteristics));
            printf("DllCharacteristics:%#06X( %s)\n", OptionalHeader->DllCharacteristics, DllCharacteristics);
            printf("SizeOfStackReserve:%#010X\n", OptionalHeader->SizeOfStackReserve);
            printf("SizeOfStackCommit:%#010X\n", OptionalHeader->SizeOfStackCommit);
            printf("SizeOfHeapReserve:%#010X\n", OptionalHeader->SizeOfHeapReserve);
            printf("SizeOfHeapCommit:%#010X\n", OptionalHeader->SizeOfHeapCommit);
            printf("LoaderFlags:%#010X\n", OptionalHeader->LoaderFlags);
            printf("NumberOfRvaAndSizes:%#010X\n", OptionalHeader->NumberOfRvaAndSizes);
            break;
        }
        case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
        {
            PIMAGE_OPTIONAL_HEADER64 OptionalHeader = (PIMAGE_OPTIONAL_HEADER64)&NtHeader->OptionalHeader;
            printf("Magic                   : %#06x\n", OptionalHeader->Magic);
            printf("LinkerVersion           : %d.%d\n", OptionalHeader->MajorLinkerVersion, OptionalHeader->MinorLinkerVersion);
            printf("SizeOfCode              : %#010x\n", OptionalHeader->SizeOfCode);
            printf("SizeOfInitializedData   : %ld\n", OptionalHeader->SizeOfInitializedData);
            printf("SizeOfUninitializedData : %ld\n", OptionalHeader->SizeOfUninitializedData);
            printf("AddressOfEntryPoint     : %#010x\n", OptionalHeader->AddressOfEntryPoint);
            printf("BaseOfCode              : %#010x\n", OptionalHeader->BaseOfCode);
            printf("ImageBase               : %#I64x\n", OptionalHeader->ImageBase);
            printf("SectionAlignment        : %#010x\n", OptionalHeader->SectionAlignment);
            printf("FileAlignment           : %#010x\n", OptionalHeader->FileAlignment);
            printf("OperatingSystemVersion:%d.%d\n", OptionalHeader->MajorOperatingSystemVersion, OptionalHeader->MinorOperatingSystemVersion);
            printf("ImageVersion:%d.%d\n", OptionalHeader->MajorImageVersion, OptionalHeader->MinorImageVersion);
            printf("SubsystemVersion:%d.%d\n", OptionalHeader->MajorSubsystemVersion, OptionalHeader->MinorSubsystemVersion);
            printf("Win32VersionValue:%#010X\n", OptionalHeader->Win32VersionValue);
            printf("SizeOfImage:%#010X\n", OptionalHeader->SizeOfImage);
            printf("SizeOfHeaders:%#010X\n", OptionalHeader->SizeOfHeaders);
            printf("CheckSum:%#010X\n", OptionalHeader->CheckSum);
            printf("Subsystem:%#06X(%s)\n", OptionalHeader->Subsystem, GetSubsystem(OptionalHeader->Subsystem));
            GetDllCharacteristics(OptionalHeader->DllCharacteristics, DllCharacteristics, _countof(DllCharacteristics));
            printf("DllCharacteristics:%#06X( %s)\n", OptionalHeader->DllCharacteristics, DllCharacteristics);
            printf("SizeOfStackReserve:%#I64X\n", OptionalHeader->SizeOfStackReserve);
            printf("SizeOfStackCommit:%#I64X\n", OptionalHeader->SizeOfStackCommit);
            printf("SizeOfHeapReserve:%#I64X\n", OptionalHeader->SizeOfHeapReserve);
            printf("SizeOfHeapCommit:%#I64X\n", OptionalHeader->SizeOfHeapCommit);
            printf("LoaderFlags:%#010X\n", OptionalHeader->LoaderFlags);
            printf("NumberOfRvaAndSizes:%#010X\n", OptionalHeader->NumberOfRvaAndSizes);
            break;
        }
        case IMAGE_ROM_OPTIONAL_HDR_MAGIC:
            //LOGA(ERROR_LEVEL, "¹§Ï²Äã:·¢ÏÖÒ»¸öROMÓ³Ïñ!");
            break;
        default:
            printf("Magic                   : %#06x\n", NtHeader->OptionalHeader.Magic);
            break;
    }
    PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
    PIMAGE_SECTION_HEADER SectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)OptionalHeader + FileHeader->SizeOfOptionalHeader);//±ØÐë¼Ó(ULONG),²»È»³ö´í.

    printf("\nSection Header Information:\n");
    for (int i = 0; i < FileHeader->NumberOfSections; i++) {
        CHAR SectionCharacteristics[MAX_PATH] = { 0 };        

        printf("index                : %d.\n", i + 1);
        printf("Name                 : %s.\n", SectionHeader[i].Name);
        printf("VirtualSize          : %ld.\n", SectionHeader[i].Misc.VirtualSize);
        printf("VirtualAddress       : %#010x.\n", SectionHeader[i].VirtualAddress);
        printf("SizeOfRawData        : %ld.\n", SectionHeader[i].SizeOfRawData);
        printf("PointerToRawData     : %#010x.\n", SectionHeader[i].PointerToRawData);
        printf("PointerToRelocations : %#010x.\n", SectionHeader[i].PointerToRelocations);
        printf("PointerToLinenumbers : %#010x.\n", SectionHeader[i].PointerToLinenumbers);
        printf("NumberOfRelocations  : %d.\n", SectionHeader[i].NumberOfRelocations);
        printf("NumberOfLinenumbers  : %d.\n", SectionHeader[i].NumberOfLinenumbers);
        GetSectionCharacteristics(SectionHeader[i].Characteristics, SectionCharacteristics, _countof(SectionCharacteristics));
        printf("Characteristics      : %#010x ( %s).\n", SectionHeader[i].Characteristics, SectionCharacteristics);

        printf("\n");
    }

    return ret;
}

int main(int argc, char* argv[])
{
	int ret = ERROR_SUCCESS;
	DWORD LastError = ERROR_SUCCESS;
	HANDLE hMapFile = NULL;
	PBYTE FileContent = NULL;

	LPCSTR fileName = argv[1];
	HANDLE hFile = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		LastError = GetLastError();
	}
	else {
		hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, NULL, NULL, NULL);
		if (hMapFile == NULL) {
			LastError = GetLastError();
		}
		else {
			LARGE_INTEGER FileSize = { 0 };
			GetFileSizeEx(hFile, &FileSize);

			FileContent = (PBYTE)MapViewOfFile(hMapFile, SECTION_MAP_READ, NULL, NULL, 0);
			if (FileContent == NULL) {
				LastError = GetLastError();
			}
			else {
				PeHeader(FileContent, FileSize.QuadPart);
			}
		}

		if (hMapFile) {
			CloseHandle(hMapFile);
		}
		if (INVALID_HANDLE_VALUE != hFile) {
			CloseHandle(hFile);
		}
	}
	return ret;
}
