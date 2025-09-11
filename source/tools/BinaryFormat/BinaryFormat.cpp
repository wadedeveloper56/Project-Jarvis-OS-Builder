#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

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

#define NUMBER_IMAGE_HEADER_FLAGS (sizeof(ImageFileHeaderCharacteristics) / sizeof(WORD_FLAG_DESCRIPTIONS))


WORD getFileMagic(char* buffer)
{
	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)buffer;
	return dosHeader->e_magic;
}

PSTR GetMachineTypeName(WORD wMachineType)
{
	switch (wMachineType)
	{
		case IMAGE_FILE_MACHINE_UNKNOWN: return (char*)"Unknown";
		case IMAGE_FILE_MACHINE_I386: return (char*)"Intel 386";
		case IMAGE_FILE_MACHINE_R3000: return (char*)"MIPS-LE";
		case IMAGE_FILE_MACHINE_R4000: return (char*)"MIPS-LE";
		case IMAGE_FILE_MACHINE_R10000: return (char*)"MIPS-LE";
		case IMAGE_FILE_MACHINE_WCEMIPSV2: return (char*)"MIPS-LE_WCE";
		case IMAGE_FILE_MACHINE_ALPHA: return (char*)"Alpha_AXP";
		case IMAGE_FILE_MACHINE_SH3: return (char*)"SH3-LE";
		case IMAGE_FILE_MACHINE_SH3DSP: return (char*)"SH3DSP";
		case IMAGE_FILE_MACHINE_SH3E: return (char*)"SH3E-LE";
		case IMAGE_FILE_MACHINE_SH4: return (char*)"SH4-LE";
		case IMAGE_FILE_MACHINE_SH5: return (char*)"SH5";
		case IMAGE_FILE_MACHINE_ARM: return (char*)"ARM-LE";
		case IMAGE_FILE_MACHINE_THUMB: return (char*)"Thumb";
		case IMAGE_FILE_MACHINE_AM33: return (char*)"ARM33";
		case IMAGE_FILE_MACHINE_POWERPC: return (char*)"PowerPC-LE";
		case IMAGE_FILE_MACHINE_POWERPCFP: return (char*)"PowerPCFP";
		case IMAGE_FILE_MACHINE_IA64: return (char*)"Intel 64";
		case IMAGE_FILE_MACHINE_MIPS16: return (char*)"MIPS16";
		case IMAGE_FILE_MACHINE_ALPHA64: return (char*)"Alpha64";
		case IMAGE_FILE_MACHINE_MIPSFPU: return (char*)"MIPSFPU";
		case IMAGE_FILE_MACHINE_MIPSFPU16:
			return (char*)"MIPSFPU16";
		case IMAGE_FILE_MACHINE_TRICORE: return (char*)"infineon";
		case IMAGE_FILE_MACHINE_CEF: return (char*)"CEF";
		case IMAGE_FILE_MACHINE_EBC: return (char*)"EFI-BC";
		case IMAGE_FILE_MACHINE_AMD64: return (char*)"AMD64-K8";
		case IMAGE_FILE_MACHINE_M32R: return (char*)"M32R-LE";
		case IMAGE_FILE_MACHINE_CEE: return (char*)"CCE";
	}

	return (char*)"UNLISTED";
}

int islistedMachineType(WORD wMachineType)
{
	PSTR ps = GetMachineTypeName(wMachineType);

	if (strcmp(ps, "UNLISTED") == 0)
	{
		return 0;
	}

	if (strcmp(ps, "Unknown") == 0)
	{
		return 0;
	}

	return 1;
}

FileType getFileType(char* buffer)
{
	WORD magic = getFileMagic(buffer);
	PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)buffer;
	DWORD minSize = (sizeof(IMAGE_DOS_HEADER) > sizeof(IMAGE_FILE_HEADER)) ? (DWORD)sizeof(IMAGE_DOS_HEADER) : (DWORD)sizeof(IMAGE_FILE_HEADER);
	int listed = islistedMachineType(pImgFileHdr->Machine);
	if (magic == IMAGE_DOS_SIGNATURE)
	{
		return EXE;
	}
	else if (magic == IMAGE_SEPARATE_DEBUG_SIGNATURE)
	{
		return DEBUG;
	}
	else if (listed)
	{
		if (0 == pImgFileHdr->SizeOfOptionalHeader)
		{
			return OBJ;
		}
		else
		{
			return UNKNOWN;
		}
	}
	else if (0 == strncmp(buffer, IMAGE_ARCHIVE_START, IMAGE_ARCHIVE_START_SIZE))
	{
		return LIB;
	}
	else
	{
		return ANONYMOUS;
	}
	return UNKNOWN;
}

void DumpHeader(PIMAGE_FILE_HEADER pImageFileHeader)
{
	UINT headerFieldWidth = 30;
	UINT i;

	WORD nSects = pImageFileHeader->NumberOfSections;
	PSTR mt = GetMachineTypeName(pImageFileHeader->Machine);

	if (pImageFileHeader)
	{
		printf((char*)"PE/OBJ: Machine Type: %04x (%s)\n", pImageFileHeader->Machine, mt);

		printf("  %-*s%04X (%s)\n", headerFieldWidth, "Machine:", pImageFileHeader->Machine, mt);
		printf("  %-*s%04X\n", headerFieldWidth, "Number of Sections:", nSects);
		printf("  %-*s%08X\n", headerFieldWidth, "TimeDateStamp:", pImageFileHeader->TimeDateStamp);
		printf("  %-*s%08X\n", headerFieldWidth, "PointerToSymbolTable:", pImageFileHeader->PointerToSymbolTable);
		printf("  %-*s%08X\n", headerFieldWidth, "NumberOfSymbols:", pImageFileHeader->NumberOfSymbols);
		printf("  %-*s%04X\n", headerFieldWidth, "SizeOfOptionalHeader:", pImageFileHeader->SizeOfOptionalHeader);
		WORD Chars = pImageFileHeader->Characteristics;
		printf("  %-*s%04X\n", headerFieldWidth, "Characteristics:", Chars);

		for (i = 0; i < NUMBER_IMAGE_HEADER_FLAGS; i++)
		{
			WORD flag = ImageFileHeaderCharacteristics[i].flag;
			if (Chars & flag)
			{
				printf("    %s\n", ImageFileHeaderCharacteristics[i].name);
				Chars &= ~flag;
				if (Chars == 0)
				{
					break;
				}
			}
		}
		if (Chars)
		{
			printf("    Unknown bits %u\n", Chars);
		}
	}
}

OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize)
{
	OBJFilePtr result = new OBJFile;
	PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)buffer;
	PIMAGE_SECTION_HEADER pSections = MakePtr(PIMAGE_SECTION_HEADER, (pImgFileHdr + 1), pImgFileHdr->SizeOfOptionalHeader);


	result->header.Machine = pImgFileHdr->Machine;
	result->header.NumberOfSections = pImgFileHdr->NumberOfSections;
	result->header.TimeDateStamp = pImgFileHdr->TimeDateStamp;
	result->header.PointerToSymbolTable = pImgFileHdr->PointerToSymbolTable;
	result->header.NumberOfSymbols = pImgFileHdr->NumberOfSymbols;
	result->header.SizeOfOptionalHeader = pImgFileHdr->SizeOfOptionalHeader;
	result->header.Characteristics = pImgFileHdr->Characteristics;

	DumpHeader(&result->header);
	return result;
}