#include "pch.h"
#include "Public.h"

void GetDataDirectory(PBYTE Data,LONGLONG Size,BYTE index,PIMAGE_DATA_DIRECTORY DataDirectory)
{
    DataDirectory->VirtualAddress = 0;
    DataDirectory->Size = 0;

    if (!IsValidPE(Data, Size)) {
        return;
    }

    _ASSERTE(index <= IMAGE_NUMBEROF_DIRECTORY_ENTRIES);

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

    DataDirectory->VirtualAddress = data_directory[index].VirtualAddress;
    DataDirectory->Size = data_directory[index].Size;
}


UINT Rva2Va(_In_ PBYTE Data, _In_ UINT rva)
/*
����0��ʾʧ�ܣ������������ļ��е�ƫ�ơ�
*/
{
    UINT offset = 0;//����ֵ��

    PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
    _ASSERTE(NtHeader);
    PIMAGE_FILE_HEADER FileHeader = (PIMAGE_FILE_HEADER)&NtHeader->FileHeader;
    PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
    PIMAGE_SECTION_HEADER SectionHeader = (PIMAGE_SECTION_HEADER)((PBYTE)OptionalHeader + FileHeader->SizeOfOptionalHeader);//�����(ULONG),��Ȼ����.

    //ע�⣺�и����IMAGE_FIRST_SECTION��

    for (WORD i = 0; i < FileHeader->NumberOfSections; i++)
    {
        if (rva >= SectionHeader[i].VirtualAddress && rva <= (SectionHeader[i].VirtualAddress + SectionHeader[i].Misc.VirtualSize)) {
            offset = rva - SectionHeader[i].VirtualAddress + SectionHeader[i].PointerToRawData;
            break;
        }
    }

    return offset;
}


void GetSectionCharacteristics(_In_ DWORD Characteristics,
    _Out_writes_(cchDest) PCHAR String,
    _In_ size_t cchDest
)
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


void GetDllCharacteristics(_In_ WORD Characteristics,
    _Out_writes_(cchDest) PCHAR String,
    _In_ size_t cchDest
)
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


PCSTR GetSubsystem(_In_ WORD Subsystem)
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
           // LOGA(ERROR_LEVEL, "SUBSYSTEM:%#X", Subsystem);
            SubsystemString = "unknown";
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
/*
��FileTimeת��Ϊ����ʱ���ӡ��
*/
{
    FILETIME lft;
    BOOL B = FileTimeToLocalFileTime(ft, &lft);
    _ASSERTE(B);

    SYSTEMTIME st;
    //GetLocalTime(&st);
    B = FileTimeToSystemTime(&lft, &st);
    _ASSERTE(B);

    //SystemTimeToTzSpecificLocalTime

    //��ʽ��2016-07-11 17:35:54      
    wsprintfA(time,
        "%04d-%02d-%02d %02d:%02d:%02d",
        st.wYear,
        st.wMonth,
        st.wDay,
        st.wHour,
        st.wMinute,
        st.wSecond);

    //size_t cb = lstrlen(time) * sizeof(wchar_t);
}


void GetTimeDateStamp(_In_ DWORD TimeDateStamp, _Out_writes_(MAX_PATH) PCHAR String)
{
    FILETIME FileTime = { 0 };
    TimeStampToFileTime(TimeDateStamp, FileTime);

    FileTimeToLocalTimeA(&FileTime, String);
}


void GetCharacteristics(_In_ WORD Characteristics,
    _Out_writes_(cchDest) PCHAR String,
    _In_ size_t cchDest
)
/*
�������������BitTest����Ϊ���Ǵ��㿪ʼ�ģ���������ṹû��0����1��ʼ�ġ�

BitTest�ĵڶ����������Ǵ�����ģ������Ǹ�����
_bittest64��Ҫ_AMD64_��
*/
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


PCSTR GetMachine(_In_ WORD Machine)
{
    PCSTR MachineString = NULL;

    switch (Machine) {
        case IMAGE_FILE_MACHINE_UNKNOWN:
            MachineString = "�������κ����ʹ�����";
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
            MachineString = "unknown";
            break;
    }

    return MachineString;
}


BOOL IsWow64()
{
    BOOL bIsWow64 = FALSE;

#ifdef _WIN64
    // 64-bit code, obviously not running in a 32-bit process
    return false;
#endif

#pragma warning(push)
#pragma warning(disable:4702)
    HMODULE ModuleHandle = GetModuleHandle(TEXT("kernel32"));
    if (NULL != ModuleHandle) {
        LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(ModuleHandle,
            "IsWow64Process");
        if (NULL != fnIsWow64Process) {
            if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64)) {
                // handle error
            }
        }
    }

    return bIsWow64;
#pragma warning(pop)
}


bool IsValidPE(PBYTE Data, LONGLONG Size)
{
    bool ret = false;

    __try {
        PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
        if (IMAGE_DOS_SIGNATURE != DosHeader->e_magic) {
            __leave;
        }

        PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
        switch (NtHeader->Signature) {
            case IMAGE_OS2_SIGNATURE:
                //LOGA(ERROR_LEVEL, "��ϲ��:����һ��NE�ļ�!");
                break;
            case IMAGE_OS2_SIGNATURE_LE://IMAGE_VXD_SIGNATURE
                //LOGA(ERROR_LEVEL, "��ϲ��:����һ��LE�ļ�!");
                break;
            case IMAGE_NT_SIGNATURE:
                ret = true;
                break;
            default:
                //LOGA(ERROR_LEVEL, "Signature:%X", nt_headers->Signature);
                break;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        ret = GetExceptionCode();
        //LOGA(ERROR_LEVEL, "ExceptionCode:%#x", ret);
    }

    return ret;
}


bool IsPE32Ex(PBYTE Data, LONGLONG Size)
{
    bool ret = false;

    if (!IsValidPE(Data, Size)) {
        return ret;
    }

    __try {
        PIMAGE_DOS_HEADER DosHeader = (PIMAGE_DOS_HEADER)Data;
        _ASSERTE(IMAGE_DOS_SIGNATURE == DosHeader->e_magic);

        PIMAGE_NT_HEADERS NtHeader = ImageNtHeader(Data);
        _ASSERTE(NtHeader);
        PIMAGE_OPTIONAL_HEADER OptionalHeader = (PIMAGE_OPTIONAL_HEADER)&NtHeader->OptionalHeader;
        switch (OptionalHeader->Magic) {
            case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
                //����һ����ͨ��PE�ļ�
                break;
            case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
                ret = true;//����һ����PE32+�ļ�
                break;
            case IMAGE_ROM_OPTIONAL_HDR_MAGIC:
                //LOGA(ERROR_LEVEL, "��ϲ��:����һ��ROMӳ��!");
                break;
            default:
                //LOGA(ERROR_LEVEL, "Magic:%#X!", OptionalHeader->Magic);
                break;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        ret = GetExceptionCode();
        //LOGA(ERROR_LEVEL, "ExceptionCode:%#x", ret);
    }

    return ret;
}

