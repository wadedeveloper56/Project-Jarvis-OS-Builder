#include "pch.h"
#include "ArgumentTable.h"
#include "BinaryFormat.h"
#include "MemoryMappedFile.h"
#include "common.h"

using namespace std;
using namespace BinaryFormat;

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

bool fShowRelocations = false;
bool fShowRawSectionData = false;
bool fShowSymbolTable = false;
bool fShowLineNumbers = false;
bool fShowIATentries = false;
bool fShowPDATA = false;
bool fShowResources = false;
bool fShowMachineType = false;
BYTE* fileBgn = 0;
BYTE* fileEnd = 0;
__int64 fileSize = 0;
int OutOfRange = 0;
char* filename = 0;


int ProcessCommandLine(int argc, char* argv[])
{
	ArgLitPtr help = argLit0("hH?", "help", "print this help and exit");
	ArgLitPtr version = argLit0("vV", "version", "print version information and exit");
	ArgLitPtr all = argLit0("aA", "ALL", "include everything in dump");
	ArgLitPtr base = argLit0("bB", "BASE", "show base relocations");
	ArgLitPtr hex = argLit0("eE", "HEX", "include hex dump of sections");
	ArgLitPtr import = argLit0("iI", "IMPORT", "include Import Address Table thunk addresses");
	ArgLitPtr line = argLit0("lL", "LINE", "include line number information");
	ArgLitPtr pdata = argLit0("pP", "PDATA", "include PDATA (runtime functions)");
	ArgLitPtr resources = argLit0("rR", "RESOURCES", "include detailed resources (stringtables and dialogs)");
	ArgLitPtr machine = argLit0("mM", "MACHINE", "Show ONLY machine type");
	ArgLitPtr symbol = argLit0("sS", "SYMBOL", "show symbol table");
	ArgFilePtr infile = argFile1(NULL, NULL, NULL, "input file");
	ArgEndPtr end = argEnd(20);
	const char* progname = "PEDump";
	int exitcode = 0, nerrors = 0;
	void* argtable[] = { all, base, hex, import, line,  pdata, resources, machine, symbol, help, version, infile, end };
	printf("PEDUMP - Win32/Win64 COFF EXE/OBJ/LIB file dumper v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
	printf("All Rights Reserved\n");

	if (argNullCheck(argtable) != 0)
	{
		printf("%s: insufficient memory\n", progname);
		exit(1);
	}
	nerrors = argParse(argc, argv, argtable);
	if (help->count > 0 || argc == 1)
	{
		printf("\nUsage: %s", progname);
		argPrintSyntax(stdout, argtable, "\n\n");
		argPrintGlossary(stdout, argtable, "  %-35s %s\n");
		exit(1);
	}
	if (version->count > 0)
	{
		printf("PEDUMP - Win32/Win64 COFF EXE/OBJ/LIB file dumper v1.0 (C) Copyright 2025 Christopher D. Wade.\n");
		printf("All Rights Reserved\n");
		exit(1);
	}
	if (nerrors > 0)
	{
		argPrintErrors(stdout, end, progname);
		printf("Try '%s --help' for more information.\n", progname);
		exit(1);
	}
	fShowRawSectionData = hex->count > 0;
	fShowLineNumbers = line->count > 0;
	fShowPDATA = pdata->count > 0;
	fShowRelocations = base->count > 0;
	fShowSymbolTable = symbol->count > 0;
	fShowIATentries = import->count > 0;
	fShowResources = resources->count > 0;
	fShowMachineType = machine->count > 0;
	if (all->count > 0)
	{
		fShowRelocations = true;
		fShowRawSectionData = true;
		fShowSymbolTable = true;
		fShowLineNumbers = true;
		fShowIATentries = true;
		fShowPDATA = true;
		fShowResources = true;
		fShowMachineType = true;
	}
	if (infile->count > 0)
	{
		filename = (char*)infile->filename[0];
	}
	return 0;
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

void DumpFileHeader(PIMAGE_FILE_HEADER pImageFileHeader)
{
	UINT headerFieldWidth = 30;
	WORD nSects = pImageFileHeader->NumberOfSections;
	PSTR mt = GetMachineTypeName(pImageFileHeader->Machine);

	if (pImageFileHeader)
	{
		printf("FILE HEADER VALUES\n");
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

void DumpSection(int i, OBJSectionPtr ptr)
{
	PIMAGE_SECTION_HEADER section = &ptr->header;
	printf("SECTION HEADER #%X (%d)\n", i, i);
	printf("%8.8s name\n", section->Name);
	printf("% 8X physical address\n", section->Misc.PhysicalAddress);
	printf("% 8X virtual address\n", section->VirtualAddress);
	printf("% 8X (%d) size of raw data\n", section->SizeOfRawData, section->SizeOfRawData);
	printf("% 8X file pointer to raw data (%08X to %08X)\n", section->PointerToRawData, section->PointerToRawData, (section->PointerToRawData + section->SizeOfRawData - 1));
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
			printf("%s ", SectionCharacteristics[j].name);
			Chars &= ~flag;

			if (Chars == 0)
			{
				break;
			}
		}
	}
	printf("\b)\n\n");
	if (section->PointerToRawData > 0 && section->SizeOfRawData > 0 && ptr->sectionBuffer != nullptr)
	{
		printf("RAW DATA #%X (%d)\n", i, i);
		hexdump(ptr->sectionBuffer, section->SizeOfRawData);
	}
	if (section->PointerToRelocations > 0 && section->NumberOfRelocations > 0 && ptr->relocation != nullptr)
	{
		char szTypeName[32];
		printf("SECTION HEADER #%X (%d) RELOCATIONS\n", i, i);
		for (int k = 0; k < section->NumberOfRelocations; k++)
		{
			GetObjRelocationName(ptr->relocation[k].Type, szTypeName, sizeof(szTypeName));
			printf("  Address: %08X  SymIndex: %08X  Type: %s\n", ptr->relocation[k].VirtualAddress, ptr->relocation[k].SymbolTableIndex, szTypeName);
		}
	}
	if (section->PointerToLinenumbers > 0 && section->NumberOfLinenumbers > 0 && ptr->lineNumbers != nullptr)
	{
		for (int j = 0; j < section->NumberOfLinenumbers; j++)
		{
			if (ptr->lineNumbers[j].Linenumber == 0)
			{
				printf("Symbol Table Index: %08X  Line: %04u\n", ptr->lineNumbers[j].Type.SymbolTableIndex, ptr->lineNumbers[j].Linenumber);
			}
			else
			{
				printf("Virtual Address   : %08X  Line: %04u\n", ptr->lineNumbers[j].Type.VirtualAddress, ptr->lineNumbers[j].Linenumber);
			}

		}
	}
	printf("\n\n");
}

void GetSectionName(WORD section, PSTR buffer, unsigned cbBuffer)
{
	char tempbuffer[10];

	switch ((SHORT)section)
	{
		case IMAGE_SYM_UNDEFINED:
			strcpy(tempbuffer, "UNDEF");
			break;
		case IMAGE_SYM_ABSOLUTE:
			strcpy(tempbuffer, "ABS");
			break;
		case IMAGE_SYM_DEBUG:
			strcpy(tempbuffer, "DEBUG");
			break;
		default:
			sprintf(tempbuffer, "%X", section);
	}
	strncpy(buffer, tempbuffer, cbBuffer - 1);
}

void DumpSymbolTable(COFFSymbolTable* pSymTab)
{
	printf("Symbol Table - %d entries  (* = auxillary symbol)\n", pSymTab->GetNumberOfSymbols());
	printf("Indx Sectn   Value   Type  Storage Name\n");
	printf("---- ----- -------- ----- -------  --------\n");
	PCOFFSymbol pSymbol = pSymTab->GetNextSymbol(0);
	while (pSymbol)
	{
		char szSection[10];
		GetSectionName(pSymbol->GetSectionNumber(), szSection, sizeof(szSection));
		printf("%04X %5s %08X  %s %-8s %s\n", pSymbol->GetIndex(), szSection, pSymbol->GetValue(), pSymbol->GetTypeName(), pSymbol->GetStorageClassName(), pSymbol->GetName());
		if (pSymbol->GetNumberOfAuxSymbols())
		{
			char szAuxSymbol[1024];

			if (pSymbol->GetAuxSymbolAsString(szAuxSymbol, sizeof(szAuxSymbol)))
			{
				printf("     * %s\n", szAuxSymbol);
			}
		}
		pSymbol = pSymTab->GetNextSymbol(pSymbol);
	}
}
int main(int argc, char* argv[])
{
	ProcessCommandLine(argc, argv);
	printf("Dump of file %s\n", filename);
	MemoryMappedFile* mmfile = new MemoryMappedFile((char*)filename);
	char* buffer = mmfile->getBuffer();
	FileType fileType = getFileType(buffer);
	LONGLONG fileSize = mmfile->getFileSize();
	printf("file size %lld bytes\n", fileSize);
	switch (fileType)
	{
		case EXE:
			printf("exe file\n");
			break;
		case DEBUG:
			break;
		case OBJ:
		{
			printf("File Type: COFF OBJECT\n\n");
			OBJFilePtr data = loadObjFile(buffer, fileSize);
			DumpFileHeader(&data->header);
			printf("\n");
			int i = 1;
			for (OBJSectionPtr ptr : data->sectionTable)
			{
				DumpSection(i, ptr);
				i++;
			}
			DumpSymbolTable(data->symbolTable);
			break;
		}
		case ANONYMOUS:
			printf("anonymous obj file\n");
			break;
		case LIB:
			printf("lib file\n");
			break;
		default:
			cout << "unknown file type" << endl;
			break;
	}
	delete mmfile;
	return 0;
}

