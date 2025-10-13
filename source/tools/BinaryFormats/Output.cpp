#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

WORD_FLAG_DESCRIPTIONS ImageFileHeaderCharacteristics[] =
{
	{IMAGE_FILE_RELOCS_STRIPPED, "Relocation info stripped from file"},
	{IMAGE_FILE_EXECUTABLE_IMAGE, "Executable"},
	{IMAGE_FILE_LINE_NUMS_STRIPPED, "LINE_NUMS_STRIPPED"},
	{IMAGE_FILE_LOCAL_SYMS_STRIPPED, "LOCAL_SYMS_STRIPPED"},
	{IMAGE_FILE_AGGRESIVE_WS_TRIM, "AGGRESIVE_WS_TRIM"},
	{IMAGE_FILE_LARGE_ADDRESS_AWARE, "Application can handle large (>2GB) addresses"},
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

WORD_FLAG_DESCRIPTIONS DllCharacteristics[] =
{
   {IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA,"HIGH_ENTROPY_VIRTUAL_ADDRESSES"},
   {IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE,"DYNAMIC_BASE"},
   {IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY,"CODE_INTEGRITY"},
   {IMAGE_DLLCHARACTERISTICS_NX_COMPAT,"NX_COMPATIBLE"},
   {IMAGE_DLLCHARACTERISTICS_NO_ISOLATION,"NO_ISOLATION"},
   {IMAGE_DLLCHARACTERISTICS_NO_SEH,"NO_SEH"},
   {IMAGE_DLLCHARACTERISTICS_NO_BIND,"NO_BIND"},
   {IMAGE_DLLCHARACTERISTICS_APPCONTAINER,"APP_CONTAINER"},
   {IMAGE_DLLCHARACTERISTICS_WDM_DRIVER, "WDM_DRIVER" },
   {IMAGE_DLLCHARACTERISTICS_GUARD_CF,"CONTROL_FLOW_GUARD"},
   {IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE,"TERMINAL_SERVER_AWARE"}
};
#define NUMBER_DLL_CHARACTERISTICS (sizeof(DllCharacteristics) / sizeof(WORD_FLAG_DESCRIPTIONS))

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
	{IMAGE_SCN_TYPE_NO_PAD, "NO_PAD"},
	{IMAGE_SCN_CNT_CODE, "CODE"},
	{IMAGE_SCN_CNT_INITIALIZED_DATA, "INITIALIZED_DATA"},
	{IMAGE_SCN_CNT_UNINITIALIZED_DATA, "UNINITIALIZED_DATA"},
	{IMAGE_SCN_LNK_OTHER, "OTHER"},
	{IMAGE_SCN_LNK_INFO, "INFO"},
	{IMAGE_SCN_LNK_REMOVE, "REMOVE"},
	{IMAGE_SCN_LNK_COMDAT, "COMDAT"},
	{IMAGE_SCN_GPREL, "GLOBAL_POINTER"},
	{IMAGE_SCN_MEM_PURGEABLE, "PURGEABLE"},
	{IMAGE_SCN_MEM_LOCKED, "LOCKED"},
	{IMAGE_SCN_MEM_PRELOAD, "PRELOAD"},
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
	{IMAGE_SCN_LNK_NRELOC_OVFL,"EXTENDED_RELOCATIONS" },
	{IMAGE_SCN_MEM_DISCARDABLE,"DISCARDABLE" },
	{IMAGE_SCN_MEM_NOT_CACHED,"NO_CACHE" },
	{IMAGE_SCN_MEM_NOT_PAGED,"NOTPAGEABLE" },
	{IMAGE_SCN_MEM_SHARED,"SHARED" },
	{IMAGE_SCN_MEM_EXECUTE,"EXECUTABLE" },
	{IMAGE_SCN_MEM_READ,"READABLE" },
	{IMAGE_SCN_MEM_WRITE,"WRITEABLE" },
};

#define NUMBER_SECTION_CHARACTERISTICS (sizeof(SectionCharacteristics) / sizeof(DWORD_FLAG_DESCRIPTIONS))

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
	printf(")\n\n");
	if (section->PointerToRawData > 0 && section->SizeOfRawData > 0 && ptr->sectionBuffer != nullptr)
	{
		//printf("RAW DATA #%X (%d)\n", i, i);
		//hexdump(ptr->sectionBuffer, section->SizeOfRawData);
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

void DumpDOSHeader(PIMAGE_DOS_HEADER dosHeader)
{
	printf("DOS HEADER VALUES\n");
	printf("  % 16X Magic number\n", dosHeader->e_magic);
	printf("  % 16X Bytes on last page of file\n", dosHeader->e_cblp);
	printf("  % 16X Pages in file\n", dosHeader->e_cp);
	printf("  % 16X Relocations\n", dosHeader->e_crlc);
	printf("  % 16X Size of header in paragraphs\n", dosHeader->e_cparhdr);
	printf("  % 16X Minimum extra paragraphs needed\n", dosHeader->e_minalloc);
	printf("  % 16X Maximum extra paragraphs needed\n", dosHeader->e_maxalloc);
	printf("  % 16X Initial (relative) SS value\n", dosHeader->e_ss);
	printf("  % 16X Initial SP value\n", dosHeader->e_sp);
	printf("  % 16X Checksum\n", dosHeader->e_csum);
	printf("  % 16X Initial IP value\n", dosHeader->e_ip);
	printf("  % 16X Initial (relative) CS value\n", dosHeader->e_cs);
	printf("  % 16X File address of relocation table\n", dosHeader->e_lfarlc);
	printf("  % 16X Overlay number\n", dosHeader->e_ovno);
	printf("  % 16X OEM identifier (for e_oeminfo)\n", dosHeader->e_oemid);
	printf("  % 16X OEM information e_oemid specific\n", dosHeader->e_oeminfo);
	printf("  % 16X File address of new exe header\n", dosHeader->e_lfanew);
}

void DumpFileHeader(PIMAGE_FILE_HEADER pImageFileHeader)
{
	const char* mt = GetMachineTypeName(pImageFileHeader->Machine);
	char* time = get_ctime_stg((time_t*)&pImageFileHeader->TimeDateStamp);
	printf("FILE HEADER VALUES\n");
	printf("  % 16X Machine (%s)\n", pImageFileHeader->Machine, mt);
	printf("  % 16X (%d) Number of Sections\n", pImageFileHeader->NumberOfSections, pImageFileHeader->NumberOfSections);
	printf("  % 16X TimeDateStamp ->  %s", pImageFileHeader->TimeDateStamp, time);
	printf("  % 16X PointerToSymbolTable\n", pImageFileHeader->PointerToSymbolTable);
	printf("  % 16X (%d) NumberOfSymbols\n", pImageFileHeader->NumberOfSymbols, pImageFileHeader->NumberOfSymbols);
	printf("  % 16X (%d) SizeOfOptionalHeader\n", pImageFileHeader->SizeOfOptionalHeader, pImageFileHeader->SizeOfOptionalHeader);
	WORD Chars = pImageFileHeader->Characteristics;
	printf("  % 16X Flags\n", Chars);
	for (int i = 0; i < NUMBER_IMAGE_HEADER_FLAGS; i++)
	{
		WORD flag = ImageFileHeaderCharacteristics[i].flag;
		if (Chars & flag) {
			printf("                     %s\n", ImageFileHeaderCharacteristics[i].name);
			Chars &= ~flag;
			if (Chars == 0)
				break;
		}
	}
	printf("\n");
}

void DumpOptionalHeader64(PIMAGE_OPTIONAL_HEADER64 optionalHeader)
{
	printf("OPTIONAL HEADER VALUES (PE32+)\n");
	printf("  % 16X magic\n", optionalHeader->Magic);
	printf("  % 13u.%02u linker version\n", optionalHeader->MajorLinkerVersion, optionalHeader->MinorLinkerVersion);
	printf("  % 16X (%ld) size of code\n", optionalHeader->SizeOfCode, optionalHeader->SizeOfCode);
	printf("  % 16X (%ld) size of initialized data\n", optionalHeader->SizeOfInitializedData, optionalHeader->SizeOfInitializedData);
	printf("  % 16X (%ld) size of uninitialized data\n", optionalHeader->SizeOfUninitializedData, optionalHeader->SizeOfUninitializedData);
	printf("  % 16X entry point\n", optionalHeader->AddressOfEntryPoint);
	printf("  % 16X base of code\n", optionalHeader->BaseOfCode);
	printf("  % 16llX image base (%llX to %llX)\n", (LONGLONG)optionalHeader->ImageBase, (LONGLONG)optionalHeader->ImageBase, (LONGLONG)(optionalHeader->ImageBase + optionalHeader->SizeOfImage - 1));
	printf("  % 16X section alignment\n", optionalHeader->SectionAlignment);
	printf("  % 16X file alignment\n", optionalHeader->FileAlignment);
	printf("  % 13u.%02u operating system version\n", optionalHeader->MajorOperatingSystemVersion, optionalHeader->MinorOperatingSystemVersion);
	printf("  % 13u.%02u image version\n", optionalHeader->MajorImageVersion, optionalHeader->MinorImageVersion);
	printf("  % 13u.%02u subsystem version\n", optionalHeader->MajorSubsystemVersion, optionalHeader->MinorSubsystemVersion);
	printf("  % 16X Win32 version\n", optionalHeader->Win32VersionValue);
	printf("  % 16X size of image\n", optionalHeader->SizeOfImage);
	printf("  % 16X size of headers\n", optionalHeader->SizeOfHeaders);
	printf("  % 16X checksum\n", optionalHeader->Win32VersionValue);
	const char* s = "Uknown";
	switch (optionalHeader->Subsystem)
	{
		case IMAGE_SUBSYSTEM_NATIVE: s = "Native"; break;
		case IMAGE_SUBSYSTEM_WINDOWS_GUI: s = "Windows GUI"; break;
		case IMAGE_SUBSYSTEM_WINDOWS_CUI: s = "Windows character"; break;
		case IMAGE_SUBSYSTEM_OS2_CUI: s = "OS/2 character"; break;
		case IMAGE_SUBSYSTEM_POSIX_CUI: s = "Posix character"; break;
	}
	printf("  % 16X subsystem (%s)\n", optionalHeader->Subsystem, s);
	printf("  % 16X DLL characteristics\n", optionalHeader->DllCharacteristics);
	for (int i = 0; i < NUMBER_DLL_CHARACTERISTICS; i++)
	{
		if (optionalHeader->DllCharacteristics & DllCharacteristics[i].flag)
			printf("                     %s\n", DllCharacteristics[i].name);
	}
	printf("  % 16llX size of stack reserve\n", optionalHeader->SizeOfStackReserve);
	printf("  % 16llX size of stack commit\n", optionalHeader->SizeOfStackCommit);
	printf("  % 16llX size of heap reserve\n", optionalHeader->SizeOfHeapReserve);
	printf("  % 16llX size of heap commit\n", optionalHeader->SizeOfHeapCommit);
	printf("  % 16X loader flags\n", optionalHeader->LoaderFlags);
	printf("  % 16X number of directories\n", optionalHeader->NumberOfRvaAndSizes);
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		const char* name = "???";
		switch (i)
		{
			case IMAGE_DIRECTORY_ENTRY_EXPORT:name = "Export"; break;
			case IMAGE_DIRECTORY_ENTRY_IMPORT:name = "Import"; break;
			case IMAGE_DIRECTORY_ENTRY_RESOURCE:name = "Resource"; break;
			case IMAGE_DIRECTORY_ENTRY_EXCEPTION:name = "Exception"; break;
			case IMAGE_DIRECTORY_ENTRY_SECURITY:name = "Security"; break;
			case IMAGE_DIRECTORY_ENTRY_BASERELOC:name = "Base Relocation"; break;
			case IMAGE_DIRECTORY_ENTRY_DEBUG:name = "Debug"; break;
			case IMAGE_DIRECTORY_ENTRY_ARCHITECTURE:name = "Architecture"; break;
			case IMAGE_DIRECTORY_ENTRY_GLOBALPTR:name = "Global Pointer"; break;
			case IMAGE_DIRECTORY_ENTRY_TLS:name = "TLS"; break;
			case IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG:name = "Load Configuration"; break;
			case IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT:name = "Bound Import"; break;
			case IMAGE_DIRECTORY_ENTRY_IAT:name = "Import Address Table"; break;
			case IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT:name = "Delay Import"; break;
			case IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR:name = "COM Descriptor"; break;
			case 15:name = "Reserved"; break;
		}
		printf("  % 16X [% 8X] RVA [size] of %s Directory\n", optionalHeader->DataDirectory[i].VirtualAddress, optionalHeader->DataDirectory[i].Size, name);
	}
}

void DumpOptionalHeader32(PIMAGE_OPTIONAL_HEADER32 optionalHeader)
{
	printf("OPTIONAL HEADER VALUES (PE32)\n");
	printf("  % 16X magic\n", optionalHeader->Magic);
	printf("  % 13u.%02u linker version\n", optionalHeader->MajorLinkerVersion, optionalHeader->MinorLinkerVersion);
	printf("  % 16X (%ld) size of code\n", optionalHeader->SizeOfCode, optionalHeader->SizeOfCode);
	printf("  % 16X (%ld) size of initialized data\n", optionalHeader->SizeOfInitializedData, optionalHeader->SizeOfInitializedData);
	printf("  % 16X (%ld) size of uninitialized data\n", optionalHeader->SizeOfUninitializedData, optionalHeader->SizeOfUninitializedData);
	printf("  % 16X entry point\n", optionalHeader->AddressOfEntryPoint);
	printf("  % 16X base of code\n", optionalHeader->BaseOfCode);
	printf("  % 16llX image base (%llX to %llX)\n", (LONGLONG)optionalHeader->ImageBase, (LONGLONG)optionalHeader->ImageBase, (LONGLONG)(optionalHeader->ImageBase + optionalHeader->SizeOfImage - 1));
	printf("  % 16X section alignment\n", optionalHeader->SectionAlignment);
	printf("  % 16X file alignment\n", optionalHeader->FileAlignment);
	printf("  % 13u.%02u operating system version\n", optionalHeader->MajorOperatingSystemVersion, optionalHeader->MinorOperatingSystemVersion);
	printf("  % 13u.%02u image version\n", optionalHeader->MajorImageVersion, optionalHeader->MinorImageVersion);
	printf("  % 13u.%02u subsystem version\n", optionalHeader->MajorSubsystemVersion, optionalHeader->MinorSubsystemVersion);
	printf("  % 16X Win32 version\n", optionalHeader->Win32VersionValue);
	printf("  % 16X size of image\n", optionalHeader->SizeOfImage);
	printf("  % 16X size of headers\n", optionalHeader->SizeOfHeaders);
	printf("  % 16X checksum\n", optionalHeader->Win32VersionValue);
	const char* s = "Uknown";
	switch (optionalHeader->Subsystem)
	{
		case IMAGE_SUBSYSTEM_NATIVE: s = "Native"; break;
		case IMAGE_SUBSYSTEM_WINDOWS_GUI: s = "Windows GUI"; break;
		case IMAGE_SUBSYSTEM_WINDOWS_CUI: s = "Windows character"; break;
		case IMAGE_SUBSYSTEM_OS2_CUI: s = "OS/2 character"; break;
		case IMAGE_SUBSYSTEM_POSIX_CUI: s = "Posix character"; break;
	}
	printf("  % 16X subsystem (%s)\n", optionalHeader->Subsystem, s);
	printf("  % 16X DLL characteristics (", optionalHeader->DllCharacteristics);
	for (int i = 0; i < NUMBER_DLL_CHARACTERISTICS; i++)
	{
		if (optionalHeader->DllCharacteristics & DllCharacteristics[i].flag)
			printf("%s ", DllCharacteristics[i].name);
	}
	printf(")\n");
	printf("  % 16X size of stack reserve\n", optionalHeader->SizeOfStackReserve);
	printf("  % 16X size of stack commit\n", optionalHeader->SizeOfStackCommit);
	printf("  % 16X size of heap reserve\n", optionalHeader->SizeOfHeapReserve);
	printf("  % 16X size of heap commit\n", optionalHeader->SizeOfHeapCommit);
	printf("  % 16X loader flags\n", optionalHeader->LoaderFlags);
	printf("  % 16X number of directories\n", optionalHeader->NumberOfRvaAndSizes);
	for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
	{
		const char* name = "???";
		switch (i)
		{
			case IMAGE_DIRECTORY_ENTRY_EXPORT:name = "Export"; break;
			case IMAGE_DIRECTORY_ENTRY_IMPORT:name = "Import"; break;
			case IMAGE_DIRECTORY_ENTRY_RESOURCE:name = "Resource"; break;
			case IMAGE_DIRECTORY_ENTRY_EXCEPTION:name = "Exception"; break;
			case IMAGE_DIRECTORY_ENTRY_SECURITY:name = "Security"; break;
			case IMAGE_DIRECTORY_ENTRY_BASERELOC:name = "Base Relocation"; break;
			case IMAGE_DIRECTORY_ENTRY_DEBUG:name = "Debug"; break;
			case IMAGE_DIRECTORY_ENTRY_ARCHITECTURE:name = "Architecture"; break;
			case IMAGE_DIRECTORY_ENTRY_GLOBALPTR:name = "Global Pointer"; break;
			case IMAGE_DIRECTORY_ENTRY_TLS:name = "TLS"; break;
			case IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG:name = "Load Configuration"; break;
			case IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT:name = "Bound Import"; break;
			case IMAGE_DIRECTORY_ENTRY_IAT:name = "Import Address Table"; break;
			case IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT:name = "Delay Import"; break;
			case IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR:name = "COM Descriptor"; break;
			case 15:name = "Reserved"; break;
		}
		printf("  % 16X [% 8X] RVA [size] of %s Directory\n", optionalHeader->DataDirectory[i].VirtualAddress, optionalHeader->DataDirectory[i].Size, name);
	}
}

void DumpExportDirectory(ExportsPtr exportDir)
{
	printf("Exports table:\n");
	printf("  Name:            %s\n", exportDir->filename);
	printf("  Characteristics: %08X\n", exportDir->exports.Characteristics);
	printf("  TimeDateStamp:   %08X -> %s", exportDir->exports.TimeDateStamp, get_ctime_stg((time_t*)&exportDir->exports.TimeDateStamp));
	printf("  Version:         %u.%02u\n", exportDir->exports.MajorVersion, exportDir->exports.MinorVersion);
	printf("  Ordinal base:    %08X\n", exportDir->exports.Base);
	printf("  # of functions:  %08X\n", exportDir->exports.NumberOfFunctions);
	printf("  # of Names:      %08X\n", exportDir->exports.NumberOfNames);
	printf("\n  Ordinal   hint   RVA  Name\n");
	int i = 0;
	for (ExportsFunctionsPtr item : exportDir->functions)
	{
		printf("  % 7X  % 4u  % 5X  %s\n", item->ordinal, i, item->entryPoint, item->filename);
		i++;
	}
	printf("\n");
}

void DumpImportDirectory(bool is64, vector<ImportsPtr>* imports)
{
	printf("Exports table:\n");
	for (ImportsPtr ptr : *imports)
	{
		printf("  Name:            %s\n", ptr->filename);
		printf("  OrigFirstThunk:  %08X\n", ptr->imports.Characteristics);
		printf("  TimeDateStamp:   %08X -> %s", ptr->imports.TimeDateStamp, get_ctime_stg((time_t*)&ptr->imports.TimeDateStamp));
		printf("  ForwarderChain:  %08X\n", ptr->imports.ForwarderChain);
		printf("  First thunk RVA: %08X\n", ptr->imports.FirstThunk);
		printf("  Ordn  Name\n");
		int i = 0;
		if (is64)
		{
			for (Thunk64Ptr thunk : ptr->thunk64)
			{
				if (thunk->thunk.u1.Ordinal & IMAGE_ORDINAL_FLAG64)
				{
					printf("  % 8llu", IMAGE_ORDINAL64(thunk->thunk.u1.Ordinal));
				}
				else
				{
					printf("  %4u  %s", thunk->ordinalname->Hint, thunk->ordinalname->Name);
				}
				if (ptr->imports.TimeDateStamp == 0)
				{
					printf(" (Bound to: %08llX)", ptr->thunkIAT64[i]->thunk.u1.Function);
				}
				printf("\n");
				i++;
			}
		}
		else
		{
			for (Thunk32Ptr thunk : ptr->thunk32)
			{
				if (thunk->thunk.u1.Ordinal & IMAGE_ORDINAL_FLAG64)
				{
					printf("  % 8lu", IMAGE_ORDINAL64(thunk->thunk.u1.Ordinal));
				}
				else
				{
					printf("  %4u  %s", thunk->ordinalname->Hint, thunk->ordinalname->Name);
				}
				if (ptr->imports.TimeDateStamp == 0)
				{
					printf(" (Bound to: %08lX)", ptr->thunkIAT32[i]->thunk.u1.Function);
				}
				printf("\n");
				i++;
			}
		}
		printf("\n");
	}
}
