#include "pch.h"
#include "common.h"
#include "objdump.h"
#include "exedump.h"
#include "dbgdump.h"
#include "libdump.h"
#include "romimage.h"
#include "extrnvar.h"
#include "pdbdump.h"

// Global variables set here, and used in EXEDUMP.C and OBJDUMP.C
BOOL fShowRelocations = FALSE;
BOOL fShowRawSectionData = FALSE;
BOOL fShowSymbolTable = FALSE;
BOOL fShowLineNumbers = FALSE;
BOOL fShowIATentries = FALSE;
BOOL fShowPDATA = FALSE;
BOOL fShowResources = FALSE;
BOOL fShowMachineType = FALSE;

#if defined(IMAGE_SIZEOF_ROM_OPTIONAL_HEADER)
#define ADD_DUMP_ROM_IMAGE
#else
#undef ADD_DUMP_ROM_IMAGE
#endif

void show_version()
{
    printf("PEDUMP - Win32/Win64 COFF EXE/OBJ/LIB file dumper.\n");
}

void show_help()
{
    show_version();
    printf("Syntax: pedump [switches] filename\n\n");
    printf("  /A    include everything in dump\n");
    printf("  /B    show base relocations (def=%s)\n", fShowRelocations ? "on" : "off");
    printf("  /H    include hex dump of sections (def=%s)\n", fShowRawSectionData ? "on" : "off");
    printf("  /I    include Import Address Table thunk addresses (def=%s)\n", fShowIATentries ? "on" : "off");
    printf("  /L    include line number information (def=%s)\n", fShowLineNumbers ? "on" : "off");
    printf("  /P    include PDATA (runtime functions) (def=%s)\n", fShowPDATA ? "on" : "off");
    printf("  /R    include detailed resources (stringtables and dialogs) (def=%s)\n", fShowResources ? "on" : "off");
    printf("  /M    Show ONLY machine type. (def=%s)\n", fShowMachineType ? "on" : "off");
    printf("  /S    show symbol table (def=%s)\n", fShowSymbolTable ? "on" : "off");
    printf("  /?    show this help, and exit(0)\n\n");
    printf(" Note machine type is always shown, but with the /M switch, only that will be shown.\n");
    printf(" Switches must be space separated, and may optionally be followed by +|-,\n");
    printf(" denoting ON or OFF. Switch alone will be assumed ON. Switches may also use '-'\n");
    printf(" instead of '/', and may be in lower case.\n\n");
}

BYTE *fileBgn = 0;
BYTE *fileEnd = 0;
__int64 fileSize = 0;
int OutOfRange = 0;
// 1 = SUCCESS
// 0 = FAILED
int IsAddressInRange(BYTE *bgn, int len)
{
    if (fileBgn && fileEnd && fileSize) {
        if (bgn >= fileBgn) {
            BYTE *end = bgn + len;
            if ((end >= fileBgn) &&
                (end < fileEnd)) {
                return 1;   // SUCCESS == is in range
            }
        }
    }
    OutOfRange++;
    return 0;   // FAILED == is out of range
}

int DumpMemMap(LPVOID lpFileBase)
{
    int iret = 0;
    PIMAGE_DOS_HEADER dosHeader;
    dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
    WORD eMagic = dosHeader->e_magic;
    PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)lpFileBase;
    DWORD minSize = (sizeof(IMAGE_DOS_HEADER) > sizeof(IMAGE_FILE_HEADER)) ? (DWORD)sizeof(IMAGE_DOS_HEADER) : (DWORD)sizeof(IMAGE_FILE_HEADER);
    int listed = is_listed_machine_type(pImgFileHdr->Machine); // do we have a list machine type

    if (eMagic == IMAGE_DOS_SIGNATURE)
    {
        DumpExeFile(dosHeader);
    }
    else if (eMagic == IMAGE_SEPARATE_DEBUG_SIGNATURE)
    {
        DumpDbgFile((PIMAGE_SEPARATE_DEBUG_HEADER)lpFileBase);
    }
    //else if ((pImgFileHdr->Machine == IMAGE_FILE_MACHINE_I386)	// FIX THIS!!!
    //    || (pImgFileHdr->Machine == IMAGE_FILE_MACHINE_ALPHA))
    else if (listed)
    {
        if (0 == pImgFileHdr->SizeOfOptionalHeader)	// 0 optional header
            DumpObjFile(pImgFileHdr);					// means it's an OBJ
#ifdef ADD_DUMP_ROM_IMAGE
        else if (pImgFileHdr->SizeOfOptionalHeader
            == IMAGE_SIZEOF_ROM_OPTIONAL_HEADER)
        {
            DumpROMImage((PIMAGE_ROM_HEADERS)pImgFileHdr);
        }
#endif // ADD_DUMP_ROM_IMAGE
    }
    else if (0 == strncmp((char *)lpFileBase, IMAGE_ARCHIVE_START,
        IMAGE_ARCHIVE_START_SIZE))
    {
        DumpLibFile(lpFileBase);
    }
#ifdef ADD_PDB_DUMP
    else if (IsPdbFile((char *)lpFileBase, fileSize)) {
        DumpPdbFile((char *)lpFileBase, fileSize);
    }
#endif // #ifdef ADD_PDB_DUMP
    else {
        printf("Unknown e_magic or machine value %u\n", eMagic);
        DWORD hlen = 32;
        if (fileSize < hlen)
            hlen = (DWORD)fileSize;
        printf("HexDump of first %u bytes of file...\n", hlen);
        HexDump((BYTE *)lpFileBase, hlen);
        printf("Error: unrecognized file format\n");
        iret = 2;   // specific EXIT for unknown format
    }

    return iret;
}

//
// Open up a file, memory map it, and call the appropriate dumping routine
//
int DumpFile(LPSTR filename)
{
    int iret = 0;
    HANDLE hFile;
    HANDLE hFileMapping;
    LPVOID lpFileBase;
    DiskType dt = is_file_or_directory64(filename);
    if (dt != MDT_FILE) {
        printf("Error: Unable to 'stat' file '%s'!\n", filename);
        return 1;
    }
    fileSize = get_last_file_size64();
    if (fileSize < sizeof(IMAGE_FILE_HEADER)) {
        printf("Warning: File '%s' appears too small at %I64u bytes...\n", filename, fileSize);
    }

    hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL,
                        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
                    
    if ( hFile == INVALID_HANDLE_VALUE )
    {
        printf("Error: Couldn't open file '%s' with CreateFile()\n", filename);
        return 1;
    }

    hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if ( hFileMapping == 0 )
    {
        CloseHandle(hFile);
        printf("Error: Couldn't open file mapping with CreateFileMapping()\n");
        return 1;
    }

    lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
    if ( lpFileBase == 0 )
    {
        CloseHandle(hFileMapping);
        CloseHandle(hFile);
        printf("Error: Couldn't map view of file with MapViewOfFile()\n");
        return 1;
    }

    if (!fShowMachineType)
        printf("Dump of file %s, %s bytes...\n\n", filename, get_nice_number64u(fileSize));
    
    fileBgn = (BYTE *)lpFileBase;
    fileEnd = fileBgn + fileSize;

    //////////////////////////////////////////////////////////////
    iret = DumpMemMap(lpFileBase);
    //////////////////////////////////////////////////////////////

    UnmapViewOfFile(lpFileBase);
    CloseHandle(hFileMapping);
    CloseHandle(hFile);

    return iret;
}

//
// process all the command line arguments and return result
//
char *filename = 0;

int ProcessCommandLine(int argc, char *argv[])
{
    int iret = 0;
    int i, c, c2;
    char *arg;
    char *sarg;
    BOOL sw;
    for ( i = 1; i < argc; i++ )
    {
        // nope - strupr(argv[i]);
        arg = argv[i];
        c = *arg;
        if (strcmp(arg, "--help") == 0) {
            show_help();
            return 2;
        } else if (strcmp(arg, "--version") == 0) {
            show_version();
            return 2;
        }
        // Is it a switch character?
        if ( (c == '-') || (c == '/') )
        {
            sarg = &arg[1];
            while (*sarg == '-')
                sarg++;
            c = *sarg;
            c2 = 0;
            sw = TRUE;
            if (c) {
                sarg++;
                c2 = *sarg;
                if (c2) {
                    if (c2 == '+')
                        sw = TRUE;
                    else if (c2 == '-')
                        sw = FALSE;
                    else {
                        printf("Error: Switches can only be followed by '+' or '-', not %c!\n", c2);
                        return 1;
                    }
                }
            }
            switch (c)
            {
            case 'A':
            case 'a':
                fShowRelocations = sw;
                fShowRawSectionData = sw;
                fShowSymbolTable = sw;
                fShowLineNumbers = sw;
                fShowIATentries = sw;
                fShowPDATA = sw;
                fShowResources = sw;
                break;
            case 'H':
            case 'h':
                fShowRawSectionData = sw;
                break;
            case 'L':
            case 'l':
                fShowLineNumbers = sw;
                break;
            case 'P':
            case 'p':
                fShowPDATA = sw;
                break;
            case 'B':
            case 'b':
                fShowRelocations = sw;
                break;
            case 'S':
            case 's':
                fShowSymbolTable = sw;
                break;
            case 'I':
            case 'i':
                fShowIATentries = sw;
                break;
            case 'R':
            case 'r':
                fShowResources = sw;
                break;
            case 'M':
            case 'm':
                fShowMachineType = sw;
                break;
            case '?':
                show_help();
                return 2;
            default:
                printf("Error: Unknown command '%s'\n", arg);
                return 1;
            }
        }
        else    // Not a switch character.  Must be the filename
        {
            if (filename) {
                printf("Error: Already have file '%s'! What is this '%s'\n", filename, arg);
                return 1;
            }
            filename = _strdup(arg);
        }
    }

	return 0;
}

int main(int argc, char *argv[])
{
    int iret = 0;
    if ( argc == 1 )
    {
        show_help();
        return 1;
    }
    
    iret = ProcessCommandLine(argc, argv);
    if (iret) {
        if (iret == 2)
            iret = 0;
        return iret;
    }
    if (filename) {
        iret = DumpFile(filename);
    }
    else {
        show_help();
        printf("Error: No file name found in command!\n");
        iret = 1;
    }

    if (OutOfRange)
        printf("TODO: Note had %d out-of-range addresses!\n", OutOfRange);

    show_dll_list();  // FIX20171017

    if (cMachineType[0])
        printf("%s\n", cMachineType);

    if (!fShowMachineType)
        printf("\n");

    return iret;
}

/* eof */
