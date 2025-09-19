#include "pch.h"
#include "common.h"
#include "objdump.h"
#include "exedump.h"
#include "dbgdump.h"
#include "libdump.h"
#include "romimage.h"
#include "extrnvar.h"
#include "pdbdump.h"

extern bool fShowRelocations;
extern bool fShowRawSectionData;
extern bool fShowSymbolTable;
extern bool fShowLineNumbers;
extern bool fShowIATentries;
extern bool fShowPDATA;
extern bool fShowResources;
extern bool fShowMachineType;
extern BYTE* fileBgn;
extern BYTE* fileEnd;
extern __int64 fileSize;
extern int OutOfRange;
extern char* filename;

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
		int index;

		while (true)
		{
			bool IsMS386 = RecBuff[offset] & 1;
			char* tmp = (char*)((IsMS386) ? "386" : "");
			const char* recname = RecNumberToName(RecBuff[offset]);
			unsigned char type = RecBuff[offset];
			RecLen = RecBuff[offset + 1] | (RecBuff[offset + 2] << 8);
			cksum = RecBuff[offset + RecLen + 2];
			printf("\n%s%s(%02x) recnum:%u, offset:0x%08x, len:0x%04x, chksum:0x%02x\n", recname, tmp, RecBuff[offset], ++RecNum, offset, RecLen, cksum);
			//char* name = NULL;
			int nameLength = 0;
			byte        c_bits;
			byte        c_class;
			unsigned int start = 0;
			switch (type)
			{
				case CMD_THEADR: {
					nameLength = RecBuff[offset + 3];
					char* name = new char[nameLength + 1];
					for (int i = 0; i <= nameLength; i++) name[i] = RecBuff[offset + i + 3];
					printf("source file name : \"%s\"\n", name);
					break;
				}
				case CMD_COMENT: {
					c_bits = RecBuff[offset + 3];
					c_class = RecBuff[offset + 4];
					nameLength = RecBuff[offset + 5];
					char* name = new char[nameLength + 1];
					for (int i = 0; i < nameLength; i++) name[i] = RecBuff[offset + i + 6];
					printf("bits 0x%02x, class 0x%02x, language translator : \"%s\"\n", c_bits, c_class, name);
					break;
				}
				case CMD_LNAMES: {
					index = 1;
					start = offset + 3;
					while ((start - offset + 3) <= RecLen) {
						nameLength = RecBuff[start];
						char* name1 = new char[nameLength + 1];
						for (int i = 0; i < nameLength; i++) name1[i] = RecBuff[start + i + 1];
						printf("%d - \"%s\"\n", index, name1);
						start += nameLength + 1;
						index++;
					}
					break;
				case CMD_SEGDEF: {
					start = offset + 3;
					byte acbp = RecBuff[start];
					byte align = acbp >> 5;
					break;
				}
				default:
					//printf("Unknown : %d (0x%02x)\n", type, type);
					break;
				}
			}
			HexDump(&RecBuff[offset + 3], RecLen - 1);
			offset += RecLen + 3;
			if (!strcmp(recname, "MODEND")) break;
			iret = 2;
		}
	}
	HexDump((BYTE*)lpFileBase, (DWORD)fileSize);
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

