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

void hexdump(const void* data, size_t size) {
	const unsigned char* p = reinterpret_cast<const unsigned char*>(data);
	const int bytes_per_row = 16;
	size_t offset = 0;

	while (offset < size) {
		// Print the address offset
		cout << hex << setw(8) << setfill('0') << offset << "  ";

		// Print the hexadecimal representation
		for (int i = 0; i < bytes_per_row; ++i) {
			if (i > 0 && i % 8 == 0) {
				cout << " "; // Add extra space after 8 bytes
			}
			if (offset + i < size) {
				cout << hex << setw(2) << setfill('0') << static_cast<unsigned int>(p[offset + i]) << " ";
			}
			else {
				cout << "   "; // Pad with spaces for the last line
			}
		}

		// Print the ASCII character representation
		cout << " ";
		for (int i = 0; i < bytes_per_row; ++i) {
			if (offset + i < size) {
				char ch = static_cast<char>(p[offset + i]);
				// Check if the character is printable; otherwise, print a dot
				cout << (isprint(static_cast<unsigned char>(ch)) ? ch : '.');
			}
		}
		cout << endl;
		offset += bytes_per_row;
	}
}

string getStringFromTable(const char* stringTable, size_t index) 
{
	if (index < 4) {
		throw out_of_range("Invalid string table index.");
	}
	const char* str = stringTable + index;
	return string(str);
}

OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize)
{
	OBJFilePtr result = new OBJFile;
	PIMAGE_FILE_HEADER pImgFileHdr = (PIMAGE_FILE_HEADER)buffer;
	PIMAGE_SECTION_HEADER section = MakePtr(PIMAGE_SECTION_HEADER, (pImgFileHdr + 1), pImgFileHdr->SizeOfOptionalHeader);
	PIMAGE_SYMBOL symbolTableEntry = MakePtr(PIMAGE_SYMBOL, pImgFileHdr, pImgFileHdr->PointerToSymbolTable);
	DWORD* stringtable = MakePtr(DWORD*, symbolTableEntry, (sizeof(IMAGE_SYMBOL)*pImgFileHdr->NumberOfSymbols));
	result->stringTableSize = *stringtable;
	const char* pStringTable = reinterpret_cast<char*>(stringtable);
	for (size_t i = 4; i < result->stringTableSize; ++i) {
		if (pStringTable[i] != '\0') {
			result->stringTable.push_back(getStringFromTable(pStringTable, i));
			while (i < result->stringTableSize && pStringTable[i] != '\0') {
				i++;
			}
		}
	}
	result->header.Machine = pImgFileHdr->Machine;
	result->header.NumberOfSections = pImgFileHdr->NumberOfSections;
	result->header.TimeDateStamp = pImgFileHdr->TimeDateStamp;
	result->header.PointerToSymbolTable = pImgFileHdr->PointerToSymbolTable;
	result->header.NumberOfSymbols = pImgFileHdr->NumberOfSymbols;
	result->header.SizeOfOptionalHeader = pImgFileHdr->SizeOfOptionalHeader;
	result->header.Characteristics = pImgFileHdr->Characteristics;
	result->symbolTable = new COFFSymbolTable(symbolTableEntry, pImgFileHdr->NumberOfSymbols);
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
		char* sectionBuffer = MakePtr(char*, pImgFileHdr, section->PointerToRawData);
		PIMAGE_RELOCATION pir = MakePtr(PIMAGE_RELOCATION, pImgFileHdr, section->PointerToRelocations);
		PIMAGE_LINENUMBER pln = MakePtr(PIMAGE_LINENUMBER, pImgFileHdr, section->PointerToLinenumbers);
		if (section->PointerToRawData > 0 && section->SizeOfRawData > 0)
		{
			ptr->sectionBuffer = new char[section->SizeOfRawData];
			for (int j = 0; j < section->SizeOfRawData; j++) ptr->sectionBuffer[j] = sectionBuffer[j];
		}
		else
		{
			ptr->sectionBuffer = nullptr;
		}
		if (section->PointerToRelocations > 0 && section->NumberOfRelocations > 0)
		{
			ptr->relocation = new IMAGE_RELOCATION[section->NumberOfRelocations];
			//char szTypeName[32];
			//printf("SECTION HEADER #%X (%d) RELOCATIONS\n", i, i);
			for (int k = 0; k < section->NumberOfRelocations; k++)
			{
				ptr->relocation[k].RelocCount = pir->RelocCount;
				ptr->relocation[k].SymbolTableIndex = pir->SymbolTableIndex;
				ptr->relocation[k].Type = pir->Type;
				ptr->relocation[k].VirtualAddress = pir->VirtualAddress;

				//GetObjRelocationName(pir->Type, szTypeName, sizeof(szTypeName));
				//printf("  Address: %08X  SymIndex: %08X  Type: %s\n", pir->VirtualAddress, pir->SymbolTableIndex, szTypeName);
				pir = MakePtr(PIMAGE_RELOCATION, pir, sizeof(IMAGE_RELOCATION));
			}
			//printf("\n");
		}
		else
		{
			ptr->relocation = nullptr;
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
					//printf("Symbol Table Index: %08X  Line: %04u\n", pln->Type.SymbolTableIndex, pln->Linenumber);
				}
				else
				{
					//printf("Virtual Address   : %08X  Line: %04u\n", pln->Type.VirtualAddress, pln->Linenumber);
				}
				pln = MakePtr(PIMAGE_LINENUMBER, pln, sizeof(IMAGE_LINENUMBER));

			}
		}
		else
		{
			ptr->lineNumbers = nullptr;
		}
		//last
		result->sectionTable.push_back(ptr);
		section = MakePtr(PIMAGE_SECTION_HEADER, section, sizeof(IMAGE_SECTION_HEADER));
	}

	return result;
}