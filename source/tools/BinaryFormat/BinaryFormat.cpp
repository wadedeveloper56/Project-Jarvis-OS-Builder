#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

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
	{IMAGE_SCN_ALIGN_1BYTES,"1_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_2BYTES,"2_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_4BYTES,"4_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_8BYTES,"8_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_16BYTES,"16_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_32BYTES,"32_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_64BYTES,"64_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_128BYTES,"128_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_256BYTES,"256_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_512BYTES,"512_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_1024BYTES,"1024_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_2048BYTES,"2048_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_4096BYTES,"4096_BYTE_ALIGN"},
	{IMAGE_SCN_ALIGN_8192BYTES,"8192_BYTE_ALIGN"},

};

#define NUMBER_SECTION_CHARACTERISTICS (sizeof(SectionCharacteristics) / sizeof(DWORD_FLAG_DESCRIPTIONS))

i386RelocTypes i386Relocations[] =
{
	{IMAGE_REL_I386_ABSOLUTE, "ABSOLUTE"},
	{IMAGE_REL_I386_DIR16, "DIR16"},
	{IMAGE_REL_I386_REL16, "REL16"},
	{IMAGE_REL_I386_DIR32, "DIR32"},
	{IMAGE_REL_I386_DIR32NB, "DIR32NB"},
	{IMAGE_REL_I386_SEG12, "SEG12"},
	{IMAGE_REL_I386_SECTION, "SECTION"},
	{IMAGE_REL_I386_SECREL, "SECREL"},
	{IMAGE_REL_I386_REL32, "REL32"}
};
#define I386RELOCTYPECOUNT (sizeof(i386Relocations) / sizeof(i386RelocTypes))

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
	WORD nSects = pImageFileHeader->NumberOfSections;
	PSTR mt = GetMachineTypeName(pImageFileHeader->Machine);

	if (pImageFileHeader)
	{
		printf((char*)"PE/OBJ: Machine Type: %04x (%s)\n", pImageFileHeader->Machine, mt);

		printf("  %-*s%04X (%s)\n", headerFieldWidth, "Machine:", pImageFileHeader->Machine, mt);
		printf("  %-*s%08X (%d)\n", headerFieldWidth, "Number of Sections:", nSects, nSects);
		printf("  %-*s%08X\n", headerFieldWidth, "TimeDateStamp:", pImageFileHeader->TimeDateStamp);
		printf("  %-*s%08X\n", headerFieldWidth, "PointerToSymbolTable:", pImageFileHeader->PointerToSymbolTable);
		printf("  %-*s%08X (%d)\n", headerFieldWidth, "NumberOfSymbols:", pImageFileHeader->NumberOfSymbols, pImageFileHeader->NumberOfSymbols);
		printf("  %-*s%04X (%d)\n", headerFieldWidth, "SizeOfOptionalHeader:", pImageFileHeader->SizeOfOptionalHeader, pImageFileHeader->SizeOfOptionalHeader);
		WORD Chars = pImageFileHeader->Characteristics;
		printf("  %-*s%04X\n", headerFieldWidth, "Characteristics:", Chars);
	}
}

void hexdump(const void* data, size_t size) {
	const unsigned char* p = static_cast<const unsigned char*>(data);
	cout << hex << setfill('0');
	for (size_t i = 0; i < size; i += 16) {
		cout << setw(8) << i << "  ";
		for (size_t j = 0; j < 16; ++j) {
			if (i + j < size) {
				cout << setw(2) << static_cast<unsigned int>(p[i + j]) << " ";
			}
			else {
				cout << "   ";
			}
			if (j == 7) {
				cout << " ";
			}
		}
		cout << " ";
		for (size_t j = 0; j < 16 && i + j < size; ++j) {
			char ch = static_cast<char>(p[i + j]);
			cout << (isprint(ch) ? ch : '.');
		}
		cout << endl;
	}
}

void GetObjRelocationName(WORD type, PSTR buffer, DWORD cBytes)
{
	DWORD i;

	for (i = 0; i < I386RELOCTYPECOUNT; i++)
	{
		if (type == i386Relocations[i].type)
		{
			strncpy(buffer, i386Relocations[i].name, cBytes);
			return;
		}
	}
	sprintf(buffer, "???_%X", type);
}

void
GetSectionName(
	WORD section,
	PSTR buffer,
	unsigned cbBuffer
)
{
	char tempbuffer[10];

	switch ((SHORT)section)
	{
		case IMAGE_SYM_UNDEFINED: strcpy(
			tempbuffer,
			"UNDEF"
		); break;
		case IMAGE_SYM_ABSOLUTE: strcpy(
			tempbuffer,
			"ABS"
		); break;
		case IMAGE_SYM_DEBUG: strcpy(
			tempbuffer,
			"DEBUG"
		); break;
		default: sprintf(
			tempbuffer,
			"%X",
			section
		);
	}

	strncpy(
		buffer,
		tempbuffer,
		cbBuffer - 1
	);
}

void DumpSymbolTable(COFFSymbolTable* pSymTab)
{
	printf("Symbol Table - %d entries  (* = auxillary symbol)\n",pSymTab->GetNumberOfSymbols());
	printf("Indx Sectn   Value   Type  Storage Name\n");
	printf("---- ----- -------- ----- -------  --------\n");
	PCOFFSymbol pSymbol = pSymTab->GetNextSymbol(0);
	while (pSymbol)
	{
		char szSection[10];
		GetSectionName(pSymbol->GetSectionNumber(),szSection,sizeof(szSection));
		printf("%04X %5s %08X  %s %-8s %s\n",pSymbol->GetIndex(),szSection,pSymbol->GetValue(),pSymbol->GetTypeName(),pSymbol->GetStorageClassName(),pSymbol->GetName());
		if (pSymbol->GetNumberOfAuxSymbols())
		{
			char szAuxSymbol[1024];

			if (pSymbol->GetAuxSymbolAsString(szAuxSymbol,sizeof(szAuxSymbol)))
			{
				printf("     * %s\n",szAuxSymbol);
			}
		}
		pSymbol = pSymTab->GetNextSymbol(pSymbol);
	}
}

OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize)
{
	printf("file size %lld\n", fileSize);

	OBJFilePtr result = new OBJFile;
	PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)buffer;

	result->header.Machine = pImgFileHdr->Machine;
	result->header.NumberOfSections = pImgFileHdr->NumberOfSections;
	result->header.TimeDateStamp = pImgFileHdr->TimeDateStamp;
	result->header.PointerToSymbolTable = pImgFileHdr->PointerToSymbolTable;
	result->header.NumberOfSymbols = pImgFileHdr->NumberOfSymbols;
	result->header.SizeOfOptionalHeader = pImgFileHdr->SizeOfOptionalHeader;
	result->header.Characteristics = pImgFileHdr->Characteristics;

	DumpHeader(&result->header);

	PIMAGE_SYMBOL symbolTableEntry = MakePtr(PIMAGE_SYMBOL, pImgFileHdr, pImgFileHdr->PointerToSymbolTable);
	PIMAGE_SECTION_HEADER section = MakePtr(PIMAGE_SECTION_HEADER, (pImgFileHdr + 1), pImgFileHdr->SizeOfOptionalHeader);

	PCOFFSymbolTable symbolTable = new COFFSymbolTable(symbolTableEntry, pImgFileHdr->NumberOfSymbols);
	DumpSymbolTable(symbolTable);

	for (int i = 1; i <= pImgFileHdr->NumberOfSections; i++)
	{
		OBJSectionPtr ptr = new OBJSection;
		for (int j = 0; j < IMAGE_SIZEOF_SHORT_NAME; j++) ptr->header.Name[j] = section->Name[j];
		ptr->header.Misc.PhysicalAddress = section->Misc.PhysicalAddress;
		ptr->header.Misc.VirtualSize = section->Misc.VirtualSize;
		ptr->header.VirtualAddress = section->VirtualAddress;
		ptr->header.SizeOfRawData = section->SizeOfRawData;
		ptr->header.PointerToRawData = section->PointerToRawData;
		ptr->header.PointerToRelocations = section->PointerToRelocations;
		ptr->header.PointerToLinenumbers = section->PointerToLinenumbers;
		ptr->header.NumberOfRelocations = section->NumberOfRelocations;
		ptr->header.NumberOfLinenumbers = section->NumberOfLinenumbers;
		ptr->header.Characteristics = section->Characteristics;

		printf("SECTION HEADER #%X (%d)\n", i, i);
		printf("%8.8s name\n", section->Name);
		printf("% 8X physical address\n", section->Misc.PhysicalAddress);
		printf("% 8X virtual address\n", section->VirtualAddress);
		printf("% 8X (%d) size of raw data\n", section->SizeOfRawData, section->SizeOfRawData);
		printf("% 8X file pointer to raw data(%08X to %08X)\n", section->PointerToRawData, section->PointerToRawData, (section->PointerToRawData + section->SizeOfRawData - 1));
		printf("% 8X file pointer to relocation table\n", section->PointerToRelocations);
		printf("% 8X file pointer to line numbers\n", section->PointerToLinenumbers);
		printf("% 8X number of relocations\n", section->NumberOfRelocations);
		printf("% 8X number of line numbers\n", section->NumberOfLinenumbers);
		DWORD Chars = section->Characteristics;
		printf("% 8X flags (", Chars);
		for (int j = 0; j < NUMBER_SECTION_CHARACTERISTICS; j++)
		{
			DWORD flag = SectionCharacteristics[j].flag;

			if (Chars & flag)
			{
				printf("  %s",SectionCharacteristics[j].name);
				Chars &= ~flag;

				if (Chars == 0)
				{
					break;
				}
			}
		}
		printf(")\n\n");

		char *sectionBuffer = MakePtr(char*, pImgFileHdr, section->PointerToRawData);
		PIMAGE_RELOCATION pir = MakePtr(PIMAGE_RELOCATION, pImgFileHdr, section->PointerToRelocations);
		PIMAGE_LINENUMBER pln = MakePtr(PIMAGE_LINENUMBER, pImgFileHdr, section->PointerToLinenumbers);

		if (section->PointerToRawData > 0 && section->SizeOfRawData > 0)
		{
			ptr->sectionBuffer = new char[section->SizeOfRawData];
			for (int j = 0; j < section->SizeOfRawData; j++) ptr->sectionBuffer[j] = sectionBuffer[j];
		    printf("SECTION HEADER #%X (%d) RAW DATA\n", i, i);
			hexdump(sectionBuffer, section->SizeOfRawData);
			printf("\n");
		}
		
		if (section->PointerToRelocations > 0 && section->NumberOfRelocations > 0)
		{
			ptr->relocation = new IMAGE_RELOCATION[section->NumberOfRelocations];
			char szTypeName[32];
			printf("SECTION HEADER #%X (%d) RELOCATIONS\n", i, i);
			for (int k = 0; k < section->NumberOfRelocations; k++)
			{
				ptr->relocation[k].RelocCount = pir->RelocCount;
				ptr->relocation[k].SymbolTableIndex = pir->SymbolTableIndex;
				ptr->relocation[k].Type = pir->Type;
				ptr->relocation[k].VirtualAddress = pir->VirtualAddress;

				GetObjRelocationName(pir->Type, szTypeName, sizeof(szTypeName));
				printf("  Address: %08X  SymIndex: %08X  Type: %s\n", pir->VirtualAddress, pir->SymbolTableIndex, szTypeName);
				pir = MakePtr(PIMAGE_RELOCATION, pir, sizeof(IMAGE_RELOCATION));
			}
			printf("\n");
		}
		
		if (section->PointerToLinenumbers > 0 && section->NumberOfLinenumbers > 0)
		{
			ptr->lineNumbers = new IMAGE_LINENUMBER[section->NumberOfLinenumbers];
			for (int j = 0; j < section->NumberOfLinenumbers; j++)
			{
				ptr->lineNumbers[j].Linenumber = pln->Linenumber;
				ptr->lineNumbers[j].Type.SymbolTableIndex = pln->Type.SymbolTableIndex;
				ptr->lineNumbers[j].Type.VirtualAddress = pln->Type.VirtualAddress;
				if (pln->Linenumber == 0)
				{
					printf("Symbol Table Index: %08X  Line: %04u\n",pln->Type.SymbolTableIndex, pln->Linenumber);
				}
				else
				{
					printf("Virtual Address   : %08X  Line: %04u\n",pln->Type.VirtualAddress,pln->Linenumber);
				}
				pln = MakePtr(PIMAGE_LINENUMBER, pln, sizeof(IMAGE_LINENUMBER));

			}
		}

		//last
		result->sectionTable.push_back(ptr);
		section = MakePtr(PIMAGE_SECTION_HEADER, section, sizeof(IMAGE_SECTION_HEADER));
	}

	return result;
}