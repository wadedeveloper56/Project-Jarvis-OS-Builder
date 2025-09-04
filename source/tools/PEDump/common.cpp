#include "pch.h"
#include "common.h"
#include "symboltablesupport.h"
#include "extrnvar.h"

PIMAGE_DEBUG_MISC g_pMiscDebugInfo       = 0;
PDWORD g_pCVHeader                       = 0;
PIMAGE_COFF_SYMBOLS_HEADER g_pCOFFHeader = 0;
COFFSymbolTable* g_pCOFFSymbolTable      = 0;      
vSTR vDllList;                                 
char cMachineType[256] = {0};

void
str_to_upper(std::string& data)
{
    std::transform(
        data.begin(),
        data.end(),
        data.begin(),
        ::toupper
        );
}

bool
in_dll_list(std::string sDll)  
{
    size_t max = vDllList.size();
    size_t ii;
    std::string su(sDll);
    str_to_upper(su);
    std::string s;

    for (ii = 0; ii < max; ii++)
    {
        s = vDllList[ii];
        str_to_upper(s);

        if (s.compare(su) == 0)
        {
            return true;
        }
    }

    return false;
}

void
add_2_dll_list(char* pDLL)  
{
    std::string s(pDLL);

    if (!in_dll_list(s))
    {
        vDllList.push_back(s);
    }
}

void
kill_dll_list()  
{
    vDllList.clear();
}

bool
stringCompare(
    const std::string& left,
    const std::string& right
    )
{
    for (
        std::string::const_iterator lit = left.begin(), rit = right.begin();
        lit != left.end() && rit != right.end();
        ++lit, ++rit
        )
    {
        if (tolower(*lit) < tolower(*rit))
        {
            return true;
        }
        else if (tolower(*lit) > tolower(*rit))
        {
            return false;
        }
    }

    if (left.size() < right.size())
    {
        return true;
    }

    return false;
}

void
show_dll_list()  
{
    size_t max  = vDllList.size();
    size_t mwid = 100;
    size_t ii, len, sz;
    std::string s;

    if (max)
    {
        printf(
            "Total imports: %d, in case insensitive alphabetic order...\n",
            (int) max
            );
        std::sort(
            vDllList.begin(),
            vDllList.end(),
            stringCompare
            );
    }

    len = 0;

    for (ii = 0; ii < max; ii++)
    {
        s  = vDllList[ii];
        sz = s.size();

        if (sz > mwid)
        {
            if (len)
            {
                printf("\n");    
            }

            printf(
                "%s\n",
                s.c_str()
                );   
            len = 0;
        }
        else if ((len + sz) > mwid)
        {
            if (len)
            {
                printf("\n");    
            }

            printf(
                "%s ",
                s.c_str()
                );      
            len = sz;     
        }
        else
        {
            printf(
                "%s ",
                s.c_str()
                );       
            len += sz;     
        }
    }

    if (max)
    {
        if (len)
        {
            printf("\n\n");   
        }
        else
        {
            printf("\n");
        }
    }

    kill_dll_list();
}

typedef struct
{
    WORD flag;
    const char* name;
} WORD_FLAG_DESCRIPTIONS;

typedef struct
{
    DWORD flag;
    const char* name;
} DWORD_FLAG_DESCRIPTIONS;

#if 0   
WORD_FLAG_DESCRIPTIONS ImageFileHeaderCharacteristics[] =
{
    {IMAGE_FILE_RELOCS_STRIPPED, "RELOCS_STRIPPED"},
    {IMAGE_FILE_EXECUTABLE_IMAGE, "EXECUTABLE_IMAGE"},
    {IMAGE_FILE_LINE_NUMS_STRIPPED, "LINE_NUMS_STRIPPED"},
    {IMAGE_FILE_LOCAL_SYMS_STRIPPED, "LOCAL_SYMS_STRIPPED"},
    {IMAGE_FILE_AGGRESIVE_WS_TRIM, "AGGRESIVE_WS_TRIM"},
    {IMAGE_FILE_BYTES_REVERSED_LO, "BYTES_REVERSED_LO"},
    {IMAGE_FILE_32BIT_MACHINE, "32BIT_MACHINE"},
    {IMAGE_FILE_DEBUG_STRIPPED, "DEBUG_STRIPPED"},
    {IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP, "REMOVABLE_RUN_FROM_SWAP"},
    {IMAGE_FILE_NET_RUN_FROM_SWAP, "NET_RUN_FROM_SWAP"},
    {IMAGE_FILE_SYSTEM, "SYSTEM"},
    {IMAGE_FILE_DLL, "DLL"},
    {IMAGE_FILE_UP_SYSTEM_ONLY, "UP_SYSTEM_ONLY"},
    {IMAGE_FILE_BYTES_REVERSED_HI, "BYTES_REVERSED_HI"}
};
#endif  
WORD_FLAG_DESCRIPTIONS ImageFileHeaderCharacteristics[] =
{
    {IMAGE_FILE_RELOCS_STRIPPED, "RELOCS_STRIPPED"},                         
    {IMAGE_FILE_EXECUTABLE_IMAGE, "EXECUTABLE_IMAGE"},                           
    {IMAGE_FILE_LINE_NUMS_STRIPPED, "LINE_NUMS_STRIPPED"},                   
    {IMAGE_FILE_LOCAL_SYMS_STRIPPED, "LOCAL_SYMS_STRIPPED"},                 
    {IMAGE_FILE_AGGRESIVE_WS_TRIM, "AGGRESIVE_WS_TRIM"},                    
    {IMAGE_FILE_LARGE_ADDRESS_AWARE, "LARGE_ADDRESS_AWARE"},                 
    {IMAGE_FILE_BYTES_REVERSED_LO, "BYTES_REVERSED_LO"},                       
    {IMAGE_FILE_32BIT_MACHINE, "32BIT_MACHINE"},                            
    {IMAGE_FILE_DEBUG_STRIPPED, "DEBUG_STRIPPED"},                              
    {IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP, "REMOVABLE_RUN_FROM_SWAP"},                 
    {IMAGE_FILE_NET_RUN_FROM_SWAP, "NET_RUN_FROM_SWAP"},                            
    {IMAGE_FILE_SYSTEM, "SYSTEM"},                                                           
    {IMAGE_FILE_DLL, "DLL"},                                                                      
    {IMAGE_FILE_UP_SYSTEM_ONLY, "UP_SYSTEM_ONLY"},                                          
    {IMAGE_FILE_BYTES_REVERSED_HI, "BYTES_REVERSED_HI"}                
};

#define NUMBER_IMAGE_HEADER_FLAGS \
    (sizeof(ImageFileHeaderCharacteristics) / sizeof(WORD_FLAG_DESCRIPTIONS))

void
DumpHeader(PIMAGE_FILE_HEADER pImageFileHeader)
{
    UINT headerFieldWidth = 30;
    UINT i;

    if (!fShowMachineType)
    {
        printf("File Header:\n");
    }

    if (
        !IsAddressInRange(
            (BYTE*) pImageFileHeader,
            (int) sizeof(IMAGE_FILE_HEADER)
            )
        )
    {
        printf(
            "TODO: PIMAGE_FILE_HEADER out of range - %p\n",
            pImageFileHeader
            );

        return;
    }

    WORD nSects = pImageFileHeader->NumberOfSections;
    PSTR mt     = GetMachineTypeName(pImageFileHeader->Machine);

    if (pImageFileHeader->Machine && (cMachineType[0] == 0))               
    {
        sprintf(
            cMachineType,
            "PE/OBJ: Machine Type: %04x (%s)",
            pImageFileHeader->Machine,
            mt
            );
    }

    if (fShowMachineType)
    {
        return;   
    }

    printf(
        "  %-*s%04X (%s)\n",
        headerFieldWidth,
        "Machine:",
        pImageFileHeader->Machine,
        mt
        );
    printf(
        "  %-*s%04X\n",
        headerFieldWidth,
        "Number of Sections:",
        nSects
        );  
    printf(
        "  %-*s%08X -> %s\n",
        headerFieldWidth,
        "TimeDateStamp:",
        pImageFileHeader->TimeDateStamp,
        get_ctime_stg((time_t*) &pImageFileHeader->TimeDateStamp)
        );
    printf(
        "  %-*s%08X\n",
        headerFieldWidth,
        "PointerToSymbolTable:",
        pImageFileHeader->PointerToSymbolTable
        );
    printf(
        "  %-*s%08X\n",
        headerFieldWidth,
        "NumberOfSymbols:",
        pImageFileHeader->NumberOfSymbols
        );
    printf(
        "  %-*s%04X\n",
        headerFieldWidth,
        "SizeOfOptionalHeader:",
        pImageFileHeader->SizeOfOptionalHeader
        );
    WORD Chars = pImageFileHeader->Characteristics;
    printf(
        "  %-*s%04X\n",
        headerFieldWidth,
        "Characteristics:",
        Chars
        );

    for (i = 0; i < NUMBER_IMAGE_HEADER_FLAGS; i++)
    {
        WORD flag = ImageFileHeaderCharacteristics[i].flag;

        if (Chars & flag)
        {
            printf(
                "    %s\n",
                ImageFileHeaderCharacteristics[i].name
                );
            Chars &= ~flag;

            if (Chars == 0)
            {
                break;
            }
        }
    }

    if (Chars)
    {
        printf(
            "    Unknown bits %u\n",
            Chars
            );
    }
}

#ifndef IMAGE_DLLCHARACTERISTICS_WDM_DRIVER
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000     
#endif

WORD_FLAG_DESCRIPTIONS DllCharacteristics[] =
{
    {IMAGE_DLLCHARACTERISTICS_WDM_DRIVER, "WDM_DRIVER"},
};
#define NUMBER_DLL_CHARACTERISTICS \
    (sizeof(DllCharacteristics) / sizeof(WORD_FLAG_DESCRIPTIONS))

#if 0
DWORD_FLAG_DESCRIPTIONS LoaderFlags[] =
{
    {IMAGE_LOADER_FLAGS_BREAK_ON_LOAD, "BREAK_ON_LOAD"},
    {IMAGE_LOADER_FLAGS_DEBUG_ON_LOAD, "DEBUG_ON_LOAD"}
};
#define NUMBER_LOADER_FLAGS \
    (sizeof(LoaderFlags) / sizeof(DWORD_FLAG_DESCRIPTIONS))
#endif

typedef struct tagIDNAMES
{
    const char* name;
    DWORD dwVirtualAddess;
    DWORD dwSize;
    const char* var;
} IDNAMES, *PIDNAME;

IDNAMES ImageDirectoryNames[] =
{
    {"EXPORT", 0, 0, "IMAGE_DIRECTORY_ENTRY_EXPORT(0)"},                  
    {"IMPORT", 0, 0, "IMAGE_DIRECTORY_ENTRY_IMPORT(1)"},                  
    {"RESOURCE", 0, 0, "IMAGE_DIRECTORY_ENTRY_RESOURCE(2)"},              
    {"EXCEPTION", 0, 0, "IMAGE_DIRECTORY_ENTRY_EXCEPTION(3)"},            
    {"SECURITY", 0, 0, "IMAGE_DIRECTORY_ENTRY_SECURITY(4)"},              
    {"BASERELOC", 0, 0, "IMAGE_DIRECTORY_ENTRY_BASERELOC(5)"},             
    {"DEBUG", 0, 0, "IMAGE_DIRECTORY_ENTRY_DEBUG (6)"},                   
    {"COPYRIGHT", 0, 0, "IMAGE_DIRECTORY_ENTRY_ARCHITECTURE(7)"},          
    {"GLOBALPTR", 0, 0, "IMAGE_DIRECTORY_ENTRY_GLOBALPTR(8)"},             
    {"TLS", 0, 0, "IMAGE_DIRECTORY_ENTRY_TLS(9)"},                        
    {"LOAD_CONFIG", 0, 0, "IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG(10)"},       
    {"BOUND_IMPORT", 0, 0, "IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT(11)"},       
    {"IAT", 0, 0, "IMAGE_DIRECTORY_ENTRY_IAT(12)"},                               
    {"DELAY_IMPORT", 0, 0, "IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT(13)"},             
    {"COM_RUNTIME", 0, 0, "IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR(14)"}     
};

#define NUMBER_IMAGE_DIRECTORY_ENTRYS \
    (sizeof(ImageDirectoryNames) / sizeof(IDNAMES))

BOOL
DoesSectionExist(const char* sect)
{
    int i;

    for (i = 0; i < NUMBER_IMAGE_DIRECTORY_ENTRYS; i++)
    {
        if (
            strcmp(
                ImageDirectoryNames[i].name,
                sect
                ) == 0
            )
        {
            if (ImageDirectoryNames[i].dwVirtualAddess && ImageDirectoryNames[i].dwSize)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }

    return FALSE;
}

void
DumpOptionalHeader32(PIMAGE_OPTIONAL_HEADER32 optionalHeader)
{
    UINT width = 30;
    const char* s;
    UINT i;

    printf("Optional Header - 32-bit\n");

    printf(
        "  %-*s%04X\n",
        width,
        "Magic",
        optionalHeader->Magic
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "linker version",
        optionalHeader->MajorLinkerVersion,
        optionalHeader->MinorLinkerVersion
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of code",
        optionalHeader->SizeOfCode
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of initialized data",
        optionalHeader->SizeOfInitializedData
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of uninitialized data",
        optionalHeader->SizeOfUninitializedData
        );
    printf(
        "  %-*s%X\n",
        width,
        "entrypoint RVA",
        optionalHeader->AddressOfEntryPoint
        );
    printf(
        "  %-*s%X\n",
        width,
        "base of code",
        optionalHeader->BaseOfCode
        );
    printf(
        "  %-*s%X\n",
        width,
        "base of data",
        optionalHeader->BaseOfData
        );
    printf(
        "  %-*s%X\n",
        width,
        "image base",
        optionalHeader->ImageBase
        );

    printf(
        "  %-*s%X\n",
        width,
        "section align",
        optionalHeader->SectionAlignment
        );
    printf(
        "  %-*s%X\n",
        width,
        "file align",
        optionalHeader->FileAlignment
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "required OS version",
        optionalHeader->MajorOperatingSystemVersion,
        optionalHeader->MinorOperatingSystemVersion
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "image version",
        optionalHeader->MajorImageVersion,
        optionalHeader->MinorImageVersion
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "subsystem version",
        optionalHeader->MajorSubsystemVersion,
        optionalHeader->MinorSubsystemVersion
        );
    printf(
        "  %-*s%X\n",
        width,
        "Win32 Version",
        optionalHeader->Win32VersionValue
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of image",
        optionalHeader->SizeOfImage
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of headers",
        optionalHeader->SizeOfHeaders
        );
    printf(
        "  %-*s%X\n",
        width,
        "checksum",
        optionalHeader->CheckSum
        );

    switch (optionalHeader->Subsystem)
    {
        case IMAGE_SUBSYSTEM_NATIVE: s      = "Native"; break;
        case IMAGE_SUBSYSTEM_WINDOWS_GUI: s = "Windows GUI"; break;
        case IMAGE_SUBSYSTEM_WINDOWS_CUI: s = "Windows character"; break;
        case IMAGE_SUBSYSTEM_OS2_CUI: s     = "OS/2 character"; break;
        case IMAGE_SUBSYSTEM_POSIX_CUI: s   = "Posix character"; break;
        default: s                          = "unknown";
    }

    printf(
        "  %-*s%04X (%s)\n",
        width,
        "Subsystem",
        optionalHeader->Subsystem,
        s
        );

    printf(
        "  %-*s%04X\n",
        width,
        "DLL flags",
        optionalHeader->DllCharacteristics
        );

    for (i = 0; i < NUMBER_DLL_CHARACTERISTICS; i++)
    {
        if (optionalHeader->DllCharacteristics & DllCharacteristics[i].flag)
        {
            printf(
                "  %-*s%s",
                width,
                " ",
                DllCharacteristics[i].name
                );
        }
    }

    if (optionalHeader->DllCharacteristics)
    {
        printf("\n");
    }

    printf(
        "  %-*s%X\n",
        width,
        "stack reserve size",
        optionalHeader->SizeOfStackReserve
        );
    printf(
        "  %-*s%X\n",
        width,
        "stack commit size",
        optionalHeader->SizeOfStackCommit
        );
    printf(
        "  %-*s%X\n",
        width,
        "heap reserve size",
        optionalHeader->SizeOfHeapReserve
        );
    printf(
        "  %-*s%X\n",
        width,
        "heap commit size",
        optionalHeader->SizeOfHeapCommit
        );

#if 0
    printf(
        "  %-*s%08X\n",
        width,
        "loader flags",
        optionalHeader->LoaderFlags
        );

    for (i = 0; i < NUMBER_LOADER_FLAGS; i++)
    {
        if (optionalHeader->LoaderFlags & LoaderFlags[i].flag)
            printf(
                "  %s",
                LoaderFlags[i].name
                );
    }

    if (optionalHeader->LoaderFlags)
        printf("\n");
#endif

    printf(
        "  %-*s%X\n",
        width,
        "RVAs & sizes",
        optionalHeader->NumberOfRvaAndSizes
        );

    printf("\nData Directory - 32-bit\n");

    for (i = 0; i < optionalHeader->NumberOfRvaAndSizes; i++)
    {
        DWORD dwVA       = optionalHeader->DataDirectory[i].VirtualAddress;
        DWORD dwSZ       = optionalHeader->DataDirectory[i].Size;
        const char* name = (i >= NUMBER_IMAGE_DIRECTORY_ENTRYS) ? "unused" : ImageDirectoryNames[i].name;
        const char* var  = (i >= NUMBER_IMAGE_DIRECTORY_ENTRYS) ? "none" : (dwVA && dwSZ) ? ImageDirectoryNames[i].var :
            "N/A";
        printf(
            "  %-12s rva: %08X  size: %08X - %s\n",
            name,
            dwVA,  
            dwSZ,  
            var
            );

        if (i < NUMBER_IMAGE_DIRECTORY_ENTRYS)
        {
            ImageDirectoryNames[i].dwVirtualAddess = dwVA;
            ImageDirectoryNames[i].dwSize          = dwSZ;
        }
    }
}

void
DumpOptionalHeader64(PIMAGE_OPTIONAL_HEADER64 optionalHeader)
{
    UINT width = 30;
    const char* s;
    UINT i;

    printf("Optional Header 64-bit\n");

    printf(
        "  %-*s%04X\n",
        width,
        "Magic",
        optionalHeader->Magic
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "linker version",
        optionalHeader->MajorLinkerVersion,
        optionalHeader->MinorLinkerVersion
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of code",
        optionalHeader->SizeOfCode
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of initialized data",
        optionalHeader->SizeOfInitializedData
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of uninitialized data",
        optionalHeader->SizeOfUninitializedData
        );
    printf(
        "  %-*s%X\n",
        width,
        "entrypoint RVA",
        optionalHeader->AddressOfEntryPoint
        );
    printf(
        "  %-*s%X\n",
        width,
        "base of code",
        optionalHeader->BaseOfCode
        );

    printf(
        "  %-*s%llX\n",
        width,
        "image base",
        optionalHeader->ImageBase
        );

    printf(
        "  %-*s%X\n",
        width,
        "section align",
        optionalHeader->SectionAlignment
        );
    printf(
        "  %-*s%X\n",
        width,
        "file align",
        optionalHeader->FileAlignment
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "required OS version",
        optionalHeader->MajorOperatingSystemVersion,
        optionalHeader->MinorOperatingSystemVersion
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "image version",
        optionalHeader->MajorImageVersion,
        optionalHeader->MinorImageVersion
        );
    printf(
        "  %-*s%u.%02u\n",
        width,
        "subsystem version",
        optionalHeader->MajorSubsystemVersion,
        optionalHeader->MinorSubsystemVersion
        );
    printf(
        "  %-*s%X\n",
        width,
        "Win32 Version",
        optionalHeader->Win32VersionValue
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of image",
        optionalHeader->SizeOfImage
        );
    printf(
        "  %-*s%X\n",
        width,
        "size of headers",
        optionalHeader->SizeOfHeaders
        );
    printf(
        "  %-*s%X\n",
        width,
        "checksum",
        optionalHeader->CheckSum
        );

    switch (optionalHeader->Subsystem)
    {
        case IMAGE_SUBSYSTEM_NATIVE: s      = "Native"; break;
        case IMAGE_SUBSYSTEM_WINDOWS_GUI: s = "Windows GUI"; break;
        case IMAGE_SUBSYSTEM_WINDOWS_CUI: s = "Windows character"; break;
        case IMAGE_SUBSYSTEM_OS2_CUI: s     = "OS/2 character"; break;
        case IMAGE_SUBSYSTEM_POSIX_CUI: s   = "Posix character"; break;
        default: s                          = "unknown";
    }

    printf(
        "  %-*s%04X (%s)\n",
        width,
        "Subsystem",
        optionalHeader->Subsystem,
        s
        );

    printf(
        "  %-*s%04X\n",
        width,
        "DLL flags",
        optionalHeader->DllCharacteristics
        );

    for (i = 0; i < NUMBER_DLL_CHARACTERISTICS; i++)
    {
        if (optionalHeader->DllCharacteristics & DllCharacteristics[i].flag)
        {
            printf(
                "  %-*s%s",
                width,
                " ",
                DllCharacteristics[i].name
                );
        }
    }

    if (optionalHeader->DllCharacteristics)
    {
        printf("\n");
    }

    printf(
        "  %-*s%llX\n",
        width,
        "stack reserve size",
        optionalHeader->SizeOfStackReserve
        );
    printf(
        "  %-*s%llX\n",
        width,
        "stack commit size",
        optionalHeader->SizeOfStackCommit
        );
    printf(
        "  %-*s%llX\n",
        width,
        "heap reserve size",
        optionalHeader->SizeOfHeapReserve
        );
    printf(
        "  %-*s%llX\n",
        width,
        "heap commit size",
        optionalHeader->SizeOfHeapCommit
        );

#if 0
    printf(
        "  %-*s%08X\n",
        width,
        "loader flags",
        optionalHeader->LoaderFlags
        );

    for (i = 0; i < NUMBER_LOADER_FLAGS; i++)
    {
        if (optionalHeader->LoaderFlags & LoaderFlags[i].flag)
            printf(
                "  %s",
                LoaderFlags[i].name
                );
    }

    if (optionalHeader->LoaderFlags)
        printf("\n");
#endif

    printf(
        "  %-*s%X\n",
        width,
        "RVAs & sizes",
        optionalHeader->NumberOfRvaAndSizes
        );

    printf("\nData Directory - 64-bit\n");

    for (i = 0; i < optionalHeader->NumberOfRvaAndSizes; i++)
    {
        DWORD dwVA       = optionalHeader->DataDirectory[i].VirtualAddress;
        DWORD dwSZ       = optionalHeader->DataDirectory[i].Size;
        const char* name = (i >= NUMBER_IMAGE_DIRECTORY_ENTRYS) ? "unused" : ImageDirectoryNames[i].name;
        const char* var  = (i >= NUMBER_IMAGE_DIRECTORY_ENTRYS) ? "none" : (dwVA && dwSZ) ? ImageDirectoryNames[i].var :
            "N/A";
        printf(
            "  %-12s rva: %08X  size: %08X - %s\n",
            name,
            dwVA,  
            dwSZ,  
            var
            );

        if (i < NUMBER_IMAGE_DIRECTORY_ENTRYS)
        {
            ImageDirectoryNames[i].dwVirtualAddess = dwVA;
            ImageDirectoryNames[i].dwSize          = dwSZ;
        }
    }
}

#if 0   
PSTR
GetMachineTypeName(WORD wMachineType)
{
    switch (wMachineType)
    {
        case IMAGE_FILE_MACHINE_I386:   return "i386";
        case IMAGE_FILE_MACHINE_R3000:  return "R3000";
        case 160:                       return "R3000 big endian";
        case IMAGE_FILE_MACHINE_R4000:  return "R4000";
        case IMAGE_FILE_MACHINE_R10000: return "R10000";
        case IMAGE_FILE_MACHINE_ALPHA:  return "Alpha";
        case IMAGE_FILE_MACHINE_POWERPC: return "PowerPC";
        default:                        return "unknown";
    }
}
#endif  

PSTR GetMachineTypeName(WORD wMachineType)
{
    switch (wMachineType)
    {
        case IMAGE_FILE_MACHINE_UNKNOWN: return (char*) "Unknown";        
        case IMAGE_FILE_MACHINE_I386: return (char*) "Intel 386";             
        case IMAGE_FILE_MACHINE_R3000: return (char*) "MIPS-LE";                
        case IMAGE_FILE_MACHINE_R4000: return (char*) "MIPS-LE";              
        case IMAGE_FILE_MACHINE_R10000: return (char*) "MIPS-LE";             
        case IMAGE_FILE_MACHINE_WCEMIPSV2: return (char*) "MIPS-LE_WCE";        
        case IMAGE_FILE_MACHINE_ALPHA: return (char*) "Alpha_AXP";           
        case IMAGE_FILE_MACHINE_SH3: return (char*) "SH3-LE";                 
        case IMAGE_FILE_MACHINE_SH3DSP: return (char*) "SH3DSP";          
        case IMAGE_FILE_MACHINE_SH3E: return (char*) "SH3E-LE";               
        case IMAGE_FILE_MACHINE_SH4: return (char*) "SH4-LE";                 
        case IMAGE_FILE_MACHINE_SH5: return (char*) "SH5";                   
        case IMAGE_FILE_MACHINE_ARM: return (char*) "ARM-LE";                 
        case IMAGE_FILE_MACHINE_THUMB: return (char*) "Thumb";            
        case IMAGE_FILE_MACHINE_AM33: return (char*) "ARM33";             
        case IMAGE_FILE_MACHINE_POWERPC: return (char*) "PowerPC-LE";          
        case IMAGE_FILE_MACHINE_POWERPCFP: return (char*) "PowerPCFP";    
        case IMAGE_FILE_MACHINE_IA64: return (char*) "Intel 64";              
        case IMAGE_FILE_MACHINE_MIPS16: return (char*) "MIPS16";             
        case IMAGE_FILE_MACHINE_ALPHA64: return (char*) "Alpha64";           
        case IMAGE_FILE_MACHINE_MIPSFPU: return (char*) "MIPSFPU";           
        case IMAGE_FILE_MACHINE_MIPSFPU16:
        return (char*) "MIPSFPU16";     
        case IMAGE_FILE_MACHINE_TRICORE: return (char*) "infineon";     
        case IMAGE_FILE_MACHINE_CEF: return (char*) "CEF";           
        case IMAGE_FILE_MACHINE_EBC: return (char*) "EFI-BC";             
        case IMAGE_FILE_MACHINE_AMD64: return (char*) "AMD64-K8";        
        case IMAGE_FILE_MACHINE_M32R: return (char*) "M32R-LE";          
        case IMAGE_FILE_MACHINE_CEE: return (char*) "CCE";           
    }

    return (char*) "UNLISTED";
}

int
is_listed_machine_type(WORD wMachineType)
{
    PSTR ps = GetMachineTypeName(wMachineType);

    if (strcmp(ps,"UNLISTED") == 0)
    {
        return 0;
    }

    if (strcmp(ps,"Unknown") == 0)
    {
        return 0;
    }

    return 1;
}

#ifndef IMAGE_SCN_TYPE_DSECT
#define IMAGE_SCN_TYPE_DSECT 0x00000001  
#endif
#ifndef IMAGE_SCN_TYPE_NOLOAD
#define IMAGE_SCN_TYPE_NOLOAD 0x00000002  
#endif
#ifndef IMAGE_SCN_TYPE_GROUP
#define IMAGE_SCN_TYPE_GROUP 0x00000004  
#endif
#ifndef IMAGE_SCN_TYPE_COPY
#define IMAGE_SCN_TYPE_COPY 0x00000010  
#endif
#ifndef IMAGE_SCN_TYPE_OVER
#define IMAGE_SCN_TYPE_OVER 0x00000400  
#endif
#ifndef IMAGE_SCN_MEM_PROTECTED
#define IMAGE_SCN_MEM_PROTECTED 0x00004000
#endif
#ifndef IMAGE_SCN_MEM_SYSHEAP
#define IMAGE_SCN_MEM_SYSHEAP 0x00010000
#endif

DWORD_FLAG_DESCRIPTIONS SectionCharacteristics[] =
{
    {IMAGE_SCN_TYPE_DSECT, "DSECT"},
    {IMAGE_SCN_TYPE_NOLOAD, "NOLOAD"},
    {IMAGE_SCN_TYPE_GROUP, "GROUP"},
    {IMAGE_SCN_TYPE_NO_PAD, "NO_PAD"},
    {IMAGE_SCN_TYPE_COPY, "COPY"},
    {IMAGE_SCN_CNT_CODE, "CODE"},
    {IMAGE_SCN_CNT_INITIALIZED_DATA, "INITIALIZED_DATA"},
    {IMAGE_SCN_CNT_UNINITIALIZED_DATA, "UNINITIALIZED_DATA"},
    {IMAGE_SCN_LNK_OTHER, "OTHER"},
    {IMAGE_SCN_LNK_INFO, "INFO"},
    {IMAGE_SCN_TYPE_OVER, "OVER"},
    {IMAGE_SCN_LNK_REMOVE, "REMOVE"},
    {IMAGE_SCN_LNK_COMDAT, "COMDAT"},
    {IMAGE_SCN_MEM_PROTECTED, "PROTECTED"},
    {IMAGE_SCN_MEM_FARDATA, "FARDATA"},
    {IMAGE_SCN_MEM_SYSHEAP, "SYSHEAP"},
    {IMAGE_SCN_MEM_PURGEABLE, "PURGEABLE"},
    {IMAGE_SCN_MEM_LOCKED, "LOCKED"},
    {IMAGE_SCN_MEM_PRELOAD, "PRELOAD"},
    {IMAGE_SCN_LNK_NRELOC_OVFL, "NRELOC_OVFL"},
    {IMAGE_SCN_MEM_DISCARDABLE, "DISCARDABLE"},
    {IMAGE_SCN_MEM_NOT_CACHED, "NOT_CACHED"},
    {IMAGE_SCN_MEM_NOT_PAGED, "NOT_PAGED"},
    {IMAGE_SCN_MEM_SHARED, "SHARED"},
    {IMAGE_SCN_MEM_EXECUTE, "EXECUTE"},
    {IMAGE_SCN_MEM_READ, "READ"},
    {IMAGE_SCN_MEM_WRITE, "WRITE"},
};

#define NUMBER_SECTION_CHARACTERISTICS \
    (sizeof(SectionCharacteristics) / sizeof(DWORD_FLAG_DESCRIPTIONS))

void
DumpSectionTable(
    PIMAGE_SECTION_HEADER section,
    unsigned cSections,
    BOOL IsEXE,
    const char* caller
    )
{
    unsigned i, j;
    const char* pszAlign;

    printf(
        "Section Table - %u sections...\n",
        cSections
        );

    if (cSections)
    {
        if (
            IsAddressInRange(
                (BYTE*) section,
                (int) sizeof(IMAGE_SECTION_HEADER)
                )
            )
        {
            PIMAGE_SECTION_HEADER last = section + (cSections - 1);

            if (
                IsAddressInRange(
                    (BYTE*) last,
                    (int) sizeof(IMAGE_SECTION_HEADER)
                    )
                )
            {
                for (i = 1; i <= cSections; i++, section++)
                {
                    if (
                        !IsAddressInRange(
                            (BYTE*) section,
                            (int) sizeof(IMAGE_SECTION_HEADER)
                            )
                        )
                    {
                        printf(
                            "TODO: DumpSectionTable by %s - PIMAGE_SECTION_HEADER %u of %u out of range - %p\n",
                            caller,
                            i,
                            cSections,
                            section
                            );

                        return;
                    }

                    printf(
                        "  %02X %-8.8s  %s: %08X  VirtAddr:  %08X\n",
                        i,
                        section->Name,
                        IsEXE ? "VirtSize" : "PhysAddr",
                        section->Misc.VirtualSize,
                        section->VirtualAddress
                        );
                    printf(
                        "    raw data offs:   %08X  raw data size: %08X\n",
                        section->PointerToRawData,
                        section->SizeOfRawData
                        );
                    printf(
                        "    relocation offs: %08X  relocations:   %08X\n",
                        section->PointerToRelocations,
                        section->NumberOfRelocations
                        );
                    printf(
                        "    line # offs:     %08X  line #'s:      %08X\n",
                        section->PointerToLinenumbers,
                        section->NumberOfLinenumbers
                        );
                    DWORD Chars = section->Characteristics;
                    printf(
                        "    characteristics: %08X\n",
                        Chars
                        );

                    printf(" ");

                    for (j = 0; j < NUMBER_SECTION_CHARACTERISTICS; j++)
                    {
                        DWORD flag = SectionCharacteristics[j].flag;

                        if (Chars & flag)
                        {
                            printf(
                                "  %s",
                                SectionCharacteristics[j].name
                                );
                            Chars &= ~flag;

                            if (Chars == 0)
                            {
                                break;
                            }
                        }
                    }

#if 0   
                    switch (section->Characteristics & IMAGE_SCN_ALIGN_64BYTES)
                    {
                        case IMAGE_SCN_ALIGN_1BYTES: pszAlign  = "ALIGN_1BYTES"; break;
                        case IMAGE_SCN_ALIGN_2BYTES: pszAlign  = "ALIGN_2BYTES"; break;
                        case IMAGE_SCN_ALIGN_4BYTES: pszAlign  = "ALIGN_4BYTES"; break;
                        case IMAGE_SCN_ALIGN_8BYTES: pszAlign  = "ALIGN_8BYTES"; break;
                        case IMAGE_SCN_ALIGN_16BYTES: pszAlign = "ALIGN_16BYTES"; break;
                        case IMAGE_SCN_ALIGN_32BYTES: pszAlign = "ALIGN_32BYTES"; break;
                        case IMAGE_SCN_ALIGN_64BYTES: pszAlign = "ALIGN_64BYTES"; break;
                        default: pszAlign                      = "ALIGN_DEFAULT(16)"; break;
                    }
#endif  

                    switch (section->Characteristics & IMAGE_SCN_ALIGN_MASK)
                    {
                        case IMAGE_SCN_ALIGN_1BYTES: pszAlign    = "ALIGN_1BYTES"; break;       
                        case IMAGE_SCN_ALIGN_2BYTES: pszAlign    = "ALIGN_2BYTES"; break;       
                        case IMAGE_SCN_ALIGN_4BYTES: pszAlign    = "ALIGN_4BYTES"; break;       
                        case IMAGE_SCN_ALIGN_8BYTES: pszAlign    = "ALIGN_8BYTES"; break;       
                        case IMAGE_SCN_ALIGN_16BYTES: pszAlign   = "ALIGN_16BYTES"; break;             
                        case IMAGE_SCN_ALIGN_32BYTES: pszAlign   = "ALIGN_32BYTES"; break;      
                        case IMAGE_SCN_ALIGN_64BYTES: pszAlign   = "ALIGN_64BYTES"; break;      
                        case IMAGE_SCN_ALIGN_128BYTES: pszAlign  = "ALIGN_128BYTES"; break;     
                        case IMAGE_SCN_ALIGN_256BYTES: pszAlign  = "ALIGN_256BYTES"; break;     
                        case IMAGE_SCN_ALIGN_512BYTES: pszAlign  = "ALIGN_512BYTES"; break;     
                        case IMAGE_SCN_ALIGN_1024BYTES: pszAlign = "ALIGN_1024BYTES"; break;    
                        case IMAGE_SCN_ALIGN_2048BYTES: pszAlign = "ALIGN_2048BYTES"; break;    
                        case IMAGE_SCN_ALIGN_4096BYTES: pszAlign = "ALIGN_4096BYTES"; break;    
                        case IMAGE_SCN_ALIGN_8192BYTES:
                            pszAlign = "ALIGN_8192BYTES";
                            break;    
                        default: pszAlign = "ALIGN_DEFAULT(16)"; break;
                    }

                    printf(
                        "  %s",
                        pszAlign
                        );
                    Chars &= ~IMAGE_SCN_ALIGN_MASK;

                    if (Chars)
                    {
                        printf(
                            " Unk(%u)",
                            Chars
                            );
                    }

                    printf("\n\n");
                }
            }
            else
            {
                printf(
                    "TODO: DumpSectionTable - last PIMAGE_SECTION_HEADER out of range - %p\n",
                    last
                    );
            }
        }
        else
        {
            printf(
                "TODO: DumpSectionTable - first PIMAGE_SECTION_HEADER out of range - %p\n",
                section
                );
        }
    }
}

LPVOID
GetSectionPtr(
    PSTR name,
    PIMAGE_NT_HEADERS pNTHeader,
    BYTE* imageBase
    )
{
    PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);
    unsigned i;

    for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, section++)
    {
        if (
            strncmp(
                (char*) section->Name,
                name,
                IMAGE_SIZEOF_SHORT_NAME
                ) == 0
            )
        {
            return (LPVOID) ((BYTE*) imageBase + section->PointerToRawData);
        }

    }

    return 0;
}

LPVOID
GetPtrFromRVA(
    DWORD rva,
    PIMAGE_NT_HEADERS pNTHeader,
    BYTE* imageBase
    )
{
    PIMAGE_SECTION_HEADER pSectionHdr;
    INT delta;

    pSectionHdr = GetEnclosingSectionHeader(
        rva,
        pNTHeader
        );

    if (!pSectionHdr)
    {
        return 0;
    }

    delta = (INT) (pSectionHdr->VirtualAddress - pSectionHdr->PointerToRawData);

    return (PVOID) ((BYTE*) imageBase + rva - delta);
}

PIMAGE_SECTION_HEADER
GetSectionHeader(
    PSTR name,
    PIMAGE_NT_HEADERS pNTHeader
    )
{
    PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);
    unsigned i;

    for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, section++)
    {
        if (
            0 == strncmp(
                (char*) section->Name,
                name,
                IMAGE_SIZEOF_SHORT_NAME
                )
            )
        {
            return section;
        }
    }

    return 0;
}

PIMAGE_SECTION_HEADER
GetEnclosingSectionHeader(
    DWORD rva,
    PIMAGE_NT_HEADERS pNTHeader
    )
{
    PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);
    unsigned i;

    for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, section++)
    {
        if (
            (rva >= section->VirtualAddress) &&
            (rva < (section->VirtualAddress + section->Misc.VirtualSize))
            )
        {
            return section;
        }
    }

    return 0;
}

PIMAGE_COFF_SYMBOLS_HEADER PCOFFDebugInfo = 0;

const char* SzDebugFormats[] =
{
    "UNKNOWN/BORLAND",
    "COFF",
    "CODEVIEW",
    "FPO",
    "MISC",
    "EXCEPTION",
    "FIXUP",
    "OMAP_TO_SRC",
    "OMAP_FROM_SRC"
};

void
DumpDebugDirectory(
    PIMAGE_DEBUG_DIRECTORY debugDir,
    DWORD size,
    BYTE* base
    )
{
    DWORD cDebugFormats = size / sizeof(IMAGE_DEBUG_DIRECTORY);
    const char* szDebugFormat;
    unsigned i;

    if (cDebugFormats == 0)
    {
        return;
    }

    printf("Debug Formats in File\n" " Type Size Address FilePtr Charactr TimeDate Version\n" " --------------- -------- -------- -------- -------- -------- --------\n");

    for (i = 0; i < cDebugFormats; i++)
    {
        szDebugFormat = (debugDir->Type <= IMAGE_DEBUG_TYPE_OMAP_FROM_SRC) ? SzDebugFormats[debugDir->Type] : (char*) "???";

        printf(
            "  %-15s %08X %08X %08X %08X %08X %u.%02u\n",
            szDebugFormat,
            debugDir->SizeOfData,
            debugDir->AddressOfRawData,
            debugDir->PointerToRawData,
            debugDir->Characteristics,
            debugDir->TimeDateStamp,
            debugDir->MajorVersion,
            debugDir->MinorVersion
            );

        switch (debugDir->Type)
        {
            case IMAGE_DEBUG_TYPE_COFF:
                g_pCOFFHeader =
                (PIMAGE_COFF_SYMBOLS_HEADER) (base + debugDir->PointerToRawData);
                break;

            case IMAGE_DEBUG_TYPE_MISC:
                g_pMiscDebugInfo =
                (PIMAGE_DEBUG_MISC) (base + debugDir->PointerToRawData);
                break;

            case IMAGE_DEBUG_TYPE_CODEVIEW:
            g_pCVHeader = (PDWORD) (base + debugDir->PointerToRawData);
                break;
        }

        debugDir++;
    }
}

void
DumpRawSectionData(
    PIMAGE_SECTION_HEADER section,
    PVOID base,
    unsigned cSections
    )
{
    unsigned i;
    char name[IMAGE_SIZEOF_SHORT_NAME + 1];

    printf(
        "Section Hex Dumps - %u sections\n\n",
        cSections
        );

    for (i = 0; i < cSections; i++, section++)
    {
        if (
            IsAddressInRange(
                (BYTE*) section,
                (int) sizeof(IMAGE_SECTION_HEADER)
                )
            )
        {
            memcpy(
                name,
                section->Name,
                IMAGE_SIZEOF_SHORT_NAME
                );
            name[IMAGE_SIZEOF_SHORT_NAME] = 0;

            printf(
                "section %02X (%s)  size: %08X  file offs: %08X\n",
                (i + 1),
                name,
                section->SizeOfRawData,
                section->PointerToRawData
                );

            if ((section->PointerToRawData == 0) || (section->SizeOfRawData == 0))
            {
                printf("\n");
                continue;
            }

            PBYTE pb = MakePtr(
                PBYTE,
                base,
                section->PointerToRawData
                );
            DWORD dwSz  = section->SizeOfRawData;
            DWORD dwMax = (dwSz ? (dwSz - 1) : 0);

            if (
                IsAddressInRange(
                    pb,
                    dwMax
                    )
                )
            {
                HexDump(
                    pb,
                    dwSz
                    );
            }
            else
            {
                printf(
                    "TODO: Skipped Hex Dump %u of %u - PBYTE out of range - %p\n",
                    (i + 1),
                    cSections,
                    pb
                    );
            }

            printf("\n");
        }
        else
        {
            printf(
                "TODO: Abandon Hex Dump %u of %u - PIMAGE_SECTION_HEADER out of range - %p\n\n",
                (i + 1),
                cSections,
                section
                );
            break;
        }
    }
}

#define HEX_DUMP_WIDTH 16

void
HexDump(
    PBYTE ptr,
    DWORD length,
    PBYTE pb
    )
{
    char buffer[256];
    PSTR buffPtr, buffPtr2;
    unsigned cOutput, i;
    DWORD bytesToGo = length;
    __int64 off;

    while (bytesToGo)
    {
        cOutput = (bytesToGo >= HEX_DUMP_WIDTH) ? HEX_DUMP_WIDTH : bytesToGo;

        buffPtr = buffer;

        if (pb)
        {
            off      = ptr - pb;
            buffPtr += sprintf(
                buffPtr,
                "%08llX:  ",
                off
                );
        }
        else
        {
            buffPtr += sprintf(
                buffPtr,
                "%08X:  ",
                length - bytesToGo
                );
        }

        buffPtr2 = buffPtr + (HEX_DUMP_WIDTH * 3) + 1;

        for (i = 0; i < HEX_DUMP_WIDTH; i++)
        {
            BYTE value = *(ptr + i);

            if (i >= cOutput)
            {
                *buffPtr++ = ' ';
                *buffPtr++ = ' ';
                *buffPtr++ = ' ';
            }
            else
            {
                if (value < 0x10)
                {
                    *buffPtr++ = '0';
                    _itoa(
                        value,
                        buffPtr++,
                        16
                        );
                }
                else
                {
                    _itoa(
                        value,
                        buffPtr,
                        16
                        );
                    buffPtr += 2;
                }

                *buffPtr++  = ' ';
                *buffPtr2++ = isprint(value) ? value : '.';
            }

            if (i == (HEX_DUMP_WIDTH / 2) - 1)
            {
                *buffPtr++ = ' ';
            }
        }

        *buffPtr2 = 0;    
        strcat(
            buffer,
            "\n"
            );
        direct_out_it(buffer);
        bytesToGo -= cOutput;
        ptr       += HEX_DUMP_WIDTH;
    }
}

DWORD
GetImgDirEntryRVA(
    PVOID pNTHdr,
    DWORD IDE
    )
{
    DWORD rva = 0;

    if (Is32)
    {
        PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32) pNTHdr;
        rva = p32->OptionalHeader.DataDirectory[IDE].VirtualAddress;
    }
    else
    {
        PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64) pNTHdr;
        rva = p64->OptionalHeader.DataDirectory[IDE].VirtualAddress;
    }

    return rva;
}

DWORD
GetImgDirEntrySize(
    PVOID pNTHdr,
    DWORD IDE
    )
{
    DWORD size = 0;

    if (Is32)
    {
        PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32) pNTHdr;
        size = p32->OptionalHeader.DataDirectory[IDE].Size;
    }
    else
    {
        PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64) pNTHdr;
        size = p64->OptionalHeader.DataDirectory[IDE].Size;
    }

    return size;
}

