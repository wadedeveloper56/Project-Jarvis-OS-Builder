#include "pch.h"
#include "common.h"
#include "objdump.h"
#include "exedump.h"
#include "dbgdump.h"
#include "libdump.h"
#include "romimage.h"
#include "extrnvar.h"
#include "pdbdump.h"

typedef enum omf_cmd {
	CMD_MIN_CMD = 0x6e,     /* minimum cmd enum                 */
	CMD_RHEADR = 0x6e,
	CMD_REGINT = 0x70,
	CMD_REDATA = 0x72,
	CMD_RIDATA = 0x74,
	CMD_OVLDEF = 0x76,
	CMD_ENDREC = 0x78,
	CMD_BLKDEF = 0x7a,     /* block definition record          */
	CMD_BLKDEF32 = 0x7b,     /* weird extension for QNX MAX assembler */
	CMD_BLKD32 = 0x7b,     /* weird extension for QNX MAX assembler */
	CMD_BLKEND = 0x7c,     /* block end record                 */
	CMD_BLKEND32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
	CMD_BLKE32 = 0x7d,     /* _might_ be used by QNX MAX assembler */
	CMD_DEBSYM = 0x7e,
	CMD_THEADR = 0x80,     /* header record                    */
	CMD_LHEADR = 0x82,
	CMD_PEDATA = 0x84,
	CMD_PIDATA = 0x86,
	CMD_COMENT = 0x88,     /* comment record                   */
	CMD_MODEND = 0x8a,     /* end of module record             */
	CMD_MODEND32 = 0x8b,     /* 32-bit end of module record      */
	CMD_MODE32 = 0x8b,     /* 32-bit end of module record      */
	CMD_EXTDEF = 0x8c,     /* import names record              */
	CMD_TYPDEF = 0x8e,     /* type definition record           */
	CMD_PUBDEF = 0x90,     /* export names record              */
	CMD_PUBDEF32 = 0x91,     /* 32-bit export names record       */
	CMD_PUBD32 = 0x91,     /* 32-bit export names record       */
	CMD_LOCSYM = 0x92,
	CMD_LINNUM = 0x94,     /* line number record               */
	CMD_LINNUM32 = 0x95,     /* 32-bit line number record.       */
	CMD_LINN32 = 0x95,     /* 32-bit line number record.       */
	CMD_LNAMES = 0x96,     /* list of names record             */
	CMD_SEGDEF = 0x98,     /* segment definition record        */
	CMD_SEGDEF32 = 0x99,     /* 32-bit segment definition        */
	CMD_SEGD32 = 0x99,     /* 32-bit segment definition        */
	CMD_GRPDEF = 0x9a,     /* group definition record          */
	CMD_FIXUPP = 0x9c,     /* relocation record                */
	CMD_FIXUPP32 = 0x9d,     /* 32-bit relocation record         */
	CMD_FIXU32 = 0x9d,     /* 32-bit relocation record         */
	CMD_LEDATA = 0xa0,     /* object record                    */
	CMD_LEDATA32 = 0xa1,     /* 32-bit object record             */
	CMD_LEDA32 = 0xa1,     /* 32-bit object record             */
	CMD_LIDATA = 0xa2,     /* repeated data record             */
	CMD_LIDATA32 = 0xa3,     /* 32-bit repeated data record      */
	CMD_LIDA32 = 0xa3,     /* 32-bit repeated data record      */
	CMD_LIBHED = 0xa4,
	CMD_LIBNAM = 0xa6,
	CMD_LIBLOC = 0xa8,
	CMD_LIBDIC = 0xaa,
	CMD_COMDEF = 0xb0,     /* communal definition              */
	CMD_BAKPAT = 0xb2,     /* backpatch record (for Quick C) */
	CMD_BAKPAT32 = 0xb3,
	CMD_BAKP32 = 0xb3,
	CMD_LEXTDEF = 0xb4,     /*  local import names record */
	CMD_STATIC_EXTDEF = 0xb4,
	CMD_LEXTDEF32 = 0xb5,     /*  32-bit local import names record */
	CMD_STATIC_EXTD32 = 0xb5,
	CMD_LPUBDEF = 0xb6,     /* static export names record */
	CMD_STATIC_PUBDEF = 0xb6,
	CMD_LPUBDEF32 = 0xb7,     /* static export names record */
	CMD_STATIC_PUBD32 = 0xb7,
	CMD_LCOMDEF = 0xb8,     /* local comdev */
	CMD_STATIC_COMDEF = 0xb8,
	CMD_CEXTDEF = 0xbc,     /* external reference to a COMDAT */
	CMD_COMDAT = 0xc2,     /* initialized communal data record */
	CMD_COMDAT32 = 0xc3,     /* initialized 32-bit communal data record */
	CMD_COMD32 = 0xc3,     /* initialized 32-bit communal data record */
	CMD_LINSYM = 0xc4,     /* LINNUM for a COMDAT */
	CMD_LINSYM32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
	CMD_LINS32 = 0xc5,     /* 32-bit LINNUM for a COMDAT */
	CMD_ALIAS = 0xc6,     /* alias definition record          */
	CMD_NBKPAT = 0xc8,     /* named backpatch record (quick c?) */
	CMD_NBKPAT32 = 0xc9,     /* 32-bit named backpatch record */
	CMD_NBKP32 = 0xc9,     /* 32-bit named backpatch record */
	CMD_LLNAMES = 0xca,     /* a "local" lnames */
	CMD_VERNUM = 0xcc,     /* TIS version number record        */
	CMD_VENDEXT = 0xce,     /* TIS vendor extension record      */
	CMD_MAX_CMD = 0xce      /* maximum cmd enum                 */
} omf_cmd;

BOOL fShowRelocations = FALSE;
BOOL fShowRawSectionData = FALSE;
BOOL fShowSymbolTable = FALSE;
BOOL fShowLineNumbers = FALSE;
BOOL fShowIATentries = FALSE;
BOOL fShowPDATA = FALSE;
BOOL fShowResources = FALSE;
BOOL fShowMachineType = FALSE;
BYTE* fileBgn = 0;
BYTE* fileEnd = 0;
__int64 fileSize = 0;
int OutOfRange = 0;
char* filename = 0;

#if defined(IMAGE_SIZEOF_ROM_OPTIONAL_HEADER)
#define ADD_DUMP_ROM_IMAGE
#else
#undef ADD_DUMP_ROM_IMAGE
#endif

void showVersion()
{
	printf("PEDUMP - Win32/Win64 COFF EXE/OBJ/LIB file dumper) v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");
}

void showHelp()
{
	showVersion();
	printf("Syntax: pedump [switches] filename\n\n");
	printf("  /A include everything in dump\n");
	printf("  /B show base relocations (def=%s)\n", fShowRelocations ? "on" : "off");
	printf("  /H include hex dump of sections (def=%s)\n", fShowRawSectionData ? "on" : "off");
	printf("  /I include Import Address Table thunk addresses (def=%s)\n", fShowIATentries ? "on" : "off");
	printf("  /L include line number information (def=%s)\n", fShowLineNumbers ? "on" : "off");
	printf("  /P include PDATA (runtime functions) (def=%s)\n", fShowPDATA ? "on" : "off");
	printf("  /R include detailed resources (stringtables and dialogs) (def=%s)\n", fShowResources ? "on" : "off");
	printf("  /M Show ONLY machine type. (def=%s)\n", fShowMachineType ? "on" : "off");
	printf("  /S show symbol table (def=%s)\n", fShowSymbolTable ? "on" : "off");
	printf("  /? show this help, and exit(0)\n\n");
	printf(" Note machine type is always shown, but with the /M switch, only that will be shown.\n");
	printf(" Switches must be space separated, and may optionally be followed by +|-,\n");
	printf(" denoting ON or OFF. Switch alone will be assumed ON. Switches may also use '-'\n");
	printf(" instead of '/', and may be in lower case.\n\n");
}

int IsAddressInRange(BYTE* bgn, int len)
{
	if (fileBgn && fileEnd && fileSize)
	{
		if (bgn >= fileBgn)
		{
			BYTE* end = bgn + len;
			if ((end >= fileBgn) && (end < fileEnd))
			{
				return 1;
			}
		}
	}
	OutOfRange++;
	return 0;
}

const char* RecNumberToName(byte code)
{
	switch (code & ~1) {
		case CMD_RHEADR:
			return("RHEADR");
		case CMD_REGINT:
			return("REGINT");
		case CMD_REDATA:
			return("REDATA");
		case CMD_RIDATA:
			return("RIDATA");
		case CMD_OVLDEF:
			return("OVLDEF");
		case CMD_ENDREC:
			return("ENDREC");
		case CMD_BLKDEF:
			return("BLKDEF");
		case CMD_BLKEND:
			return("BLKEND");
		case CMD_DEBSYM:
			return("DEBSYM");
		case CMD_THEADR:
			return("THEADR");
		case CMD_LHEADR:
			return("LHEADR");
		case CMD_PEDATA:
			return("PEDATA");
		case CMD_PIDATA:
			return("PIDATA");
		case CMD_COMENT:
			return("COMENT");
		case CMD_MODEND:
			return("MODEND");
		case CMD_EXTDEF:
			return("EXTDEF");
		case CMD_TYPDEF:
			return("TYPDEF");
		case CMD_PUBDEF:
			return("PUBDEF");
		case CMD_LOCSYM:
			return("LOCSYM");
		case CMD_LINNUM:
			return("LINNUM");
		case CMD_LNAMES:
			return("LNAMES");
		case CMD_SEGDEF:
			return("SEGDEF");
		case CMD_GRPDEF:
			return("GRPDEF");
		case CMD_FIXUPP:
			return("FIXUPP");
		case CMD_LEDATA:
			return("LEDATA");
		case CMD_LIDATA:
			return("LIDATA");
		case CMD_LIBHED:
			return("LIBHED");
		case CMD_LIBNAM:
			return("LIBNAM");
		case CMD_LIBLOC:
			return("LIBLOC");
		case CMD_LIBDIC:
			return("LIBDIC");
		case CMD_COMDEF:
			return("COMDEF");
		case CMD_STATIC_EXTDEF:
			return("static EXTDEF");
		case CMD_STATIC_PUBDEF:
			return("static PUBDEF");
		case CMD_STATIC_COMDEF:
			return("static COMDEF");
		case CMD_BAKPAT:
			return("BAKPAT");
		case CMD_CEXTDEF:
			return("CEXTDF");
		case CMD_COMDAT:
			return("COMDAT");
		case CMD_LINSYM:
			return("LINSYM");
		case CMD_ALIAS:
			return("ALIAS");
		case CMD_NBKPAT:
			return("NBKPAT");
		case CMD_LLNAMES:
			return("LLNAME");
		default:
			return("**??**");
	}
}

byte checkSumBuff(unsigned char* RecBuff, unsigned int RecLen)
{
	byte        cksum;
	unsigned char* p;

	cksum = 0;
	p = RecBuff + RecLen;
	while (p > RecBuff) {
		--p;
		cksum += *p;
	}
	return(cksum);
}

int DumpMemMap(LPVOID lpFileBase)
{
	int iret = 0;

	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)lpFileBase;
	WORD eMagic = dosHeader->e_magic;
	PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)lpFileBase;
	DWORD minSize = (sizeof(IMAGE_DOS_HEADER) > sizeof(IMAGE_FILE_HEADER)) ? (DWORD)sizeof(IMAGE_DOS_HEADER) : (DWORD)sizeof(IMAGE_FILE_HEADER);
	int listed = is_listed_machine_type(pImgFileHdr->Machine);

	if (eMagic == IMAGE_DOS_SIGNATURE)
	{
		DumpExeFile(dosHeader);
	}
	else if (eMagic == IMAGE_SEPARATE_DEBUG_SIGNATURE)
	{
		DumpDbgFile((PIMAGE_SEPARATE_DEBUG_HEADER)lpFileBase);
	}
	else if (listed)
	{
		if (0 == pImgFileHdr->SizeOfOptionalHeader)
		{
			DumpObjFile(pImgFileHdr);
		}

#ifdef ADD_DUMP_ROM_IMAGE
		else if (pImgFileHdr->SizeOfOptionalHeader == IMAGE_SIZEOF_ROM_OPTIONAL_HEADER)
		{
			DumpROMImage((PIMAGE_ROM_HEADERS)pImgFileHdr);
		}
#endif  
	}
	else if (0 == strncmp((char*)lpFileBase, IMAGE_ARCHIVE_START, IMAGE_ARCHIVE_START_SIZE))
	{
		DumpLibFile(lpFileBase);
	}

#ifdef ADD_PDB_DUMP
	else if (IsPdbFile((char*)lpFileBase, fileSize))
	{
		DumpPdbFile((char*)lpFileBase, fileSize);
	}
#endif   
	else
	{
		unsigned char cksum = 0;
		unsigned int RecLen = 0, RecNum = 0, offset = 0;
		unsigned char* RecBuff = (unsigned char*)lpFileBase;

		while (true)
		{
			bool IsMS386 = RecBuff[offset] & 1;
			char* tmp = (char*)((IsMS386) ? "386" : "");
			const char* recname = RecNumberToName(RecBuff[offset]);
			unsigned char type = RecBuff[offset];
			RecLen = RecBuff[offset + 1] | (RecBuff[offset + 2] << 8);
			cksum = RecBuff[offset + RecLen + 2];
			printf("\n%s%s(%02x) recnum:%u, offset:0x%08x, len:0x%04x, chksum:0x%02x\n", recname, tmp, RecBuff[offset], ++RecNum, offset, RecLen, cksum);
			char* name = NULL;
			int nameLength = 0;
			byte        c_bits;
			byte        c_class;
			switch (type)
			{
				case CMD_THEADR:
					nameLength = RecBuff[offset + 3];
					name = new char[nameLength + 1];
					for (int i = 0; i <= nameLength; i++) name[i] = RecBuff[offset + i + 3];
					printf("source file name : \"%s\"\n", name);
					break;
				case CMD_COMENT:
					c_bits = RecBuff[offset + 3];
					c_class = RecBuff[offset + 4];
					nameLength = RecBuff[offset + 5];
					if (name != NULL) delete[] name;
					name = new char[nameLength + 1];
					for (int i = 0; i < nameLength; i++) name[i] = RecBuff[offset + i + 6];
					printf("bits 0x%02x, class 0x%02x, language translator : \"%s\"\n", c_bits, c_class,name);
					break;
				default:
					//printf("Unknown : %d (0x%02x)\n", type, type);
					break;
			}
			HexDump(&RecBuff[offset + 3], RecLen - 1);
			offset += RecLen + 3;
			if (!strcmp(recname, "MODEND")) break;
		}

		DWORD hlen = 12800;
		if (fileSize < hlen)
		{
			hlen = (DWORD)fileSize;
		}
		printf("\nHexDump of first %u bytes of file...\n", hlen);
		HexDump((BYTE*)lpFileBase, hlen);
		printf("Error: unrecognized file format\n");
		iret = 2;
	}
	return iret;
}

int DumpFile(LPSTR filename)
{
	int iret = 0;

	DiskType dt = is_file_or_directory64(filename);
	if (dt != MDT_FILE)
	{
		printf("Error: Unable to 'stat' file '%s'!\n", filename);
		return 1;
	}
	fileSize = get_last_file_size64();
	if (fileSize < sizeof(IMAGE_FILE_HEADER))
	{
		printf("Warning: File '%s' appears too small at %I64u bytes...\n", filename, fileSize);
	}

	HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("Error: Couldn't open file '%s' with CreateFile()\n", filename);
		return 1;
	}
	HANDLE hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hFileMapping == 0)
	{
		CloseHandle(hFile);
		printf("Error: Couldn't open file mapping with CreateFileMapping()\n");
		return 1;
	}
	LPVOID lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
	if (lpFileBase == 0)
	{
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		printf("Error: Couldn't map view of file with MapViewOfFile()\n");
		return 1;
	}
	if (!fShowMachineType)
	{
		printf("Dump of file %s, %lld bytes...\n\n", filename, fileSize);
	}
	fileBgn = (BYTE*)lpFileBase;
	fileEnd = fileBgn + fileSize;
	iret = DumpMemMap(lpFileBase);
	UnmapViewOfFile(lpFileBase);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	return iret;
}


int ProcessCommandLine(int argc, char* argv[])
{
	int iret = 0;
	int i, c, c2;
	char* arg;
	char* sarg;
	BOOL sw;

	for (i = 1; i < argc; i++)
	{
		arg = argv[i];
		c = *arg;

		if (strcmp(arg, "--help") == 0)
		{
			showHelp();
			return 2;
		}
		else if (strcmp(arg, "--version") == 0)
		{
			showVersion();
			return 2;
		}
		if ((c == '-') || (c == '/'))
		{
			sarg = &arg[1];
			while (*sarg == '-')
			{
				sarg++;
			}
			c = *sarg;
			c2 = 0;
			sw = TRUE;
			if (c)
			{
				sarg++;
				c2 = *sarg;

				if (c2)
				{
					if (c2 == '+')
					{
						sw = TRUE;
					}
					else if (c2 == '-')
					{
						sw = FALSE;
					}
					else
					{
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
					showHelp();
					return 2;
				default:
					printf("Error: Unknown command '%s'\n",
						arg
					);
					return 1;
			}
		}
		else
		{
			if (filename)
			{
				printf("Error: Already have file '%s'! What is this '%s'\n", filename, arg);
				return 1;
			}
			filename = _strdup(arg);
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int iret = 0;
	if (argc == 1)
	{
		showHelp();
		return 1;
	}
	iret = ProcessCommandLine(argc, argv);
	if (iret)
	{
		if (iret == 2)
		{
			iret = 0;
		}
		return iret;
	}
	if (filename)
	{
		iret = DumpFile(filename);
	}
	else
	{
		showHelp();
		printf("Error: No file name found in command!\n");
		iret = 1;
	}
	if (OutOfRange)
	{
		printf("TODO: Note had %d out-of-range addresses!\n", OutOfRange);
	}
	show_dll_list();
	if (cMachineType[0])
	{
		printf("%s\n", cMachineType);
	}
	if (!fShowMachineType)
	{
		printf("\n");
	}
	return iret;
}

