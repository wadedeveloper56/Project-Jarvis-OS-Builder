#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

const char* SzDebugFormats[] = { 
"UNKNOWN"                ,//0 An unknown value that is ignored by all tools.
"COFF"                   ,//1 The COFF debug information(line numbers, symbol table, and string table).This type of debug information is also pointed to by fields in the file headers.
"CODEVIEW"               ,//2 The Visual C++ debug information.
"FPO"                    ,//3 The frame pointer omission(FPO) information.This information tells the debugger how to interpret nonstandard stack frames, which use the EBP register for a purpose other than as a frame pointer.
"MISC"                   ,//4 The location of DBG file.
"EXCEPTION"              ,//5 A copy of.pdata section.
"FIXUP"                  ,//6 Reserved.
"OMAP_TO_SRC"            ,//7 The mapping from an RVA in image to an RVA in source image.
"OMAP_FROM_SRC"          ,//8 The mapping from an RVA in source image to an RVA in image.
"BORLAND"                ,//9 Reserved for Borland.
"RESERVED10"             ,//10 Reserved.
"CLSID"                  ,//11 Reserved.
"feat"                   ,//12 unknown
"coffgrp"                ,//13 unknown
"iltcg"                  ,//14 unknown
"Undefined"              ,//15 unknown
"REPRO"                  ,//16 PE determinism or reproducibility.
"Undefined"              ,//17 Debugging information is embedded in the PE file at location specified by PointerToRawData.
"Undefined"              ,//18 unknown
"Undefined"              ,//19 Stores crypto hash for the content of the symbol file used to build the PE / COFF file.
"EX_DLLCHARACTERISTICS"	 ,//20	Extended DLL characteristics bits.
};

const char* SzRelocTypes[] = { "ABSOLUTE","HIGH","LOW","HIGHLOW","HIGHADJ","MIPS/ARM", "SECTION","REL32","MIPS16","DIR64", "TYPE10" };
#define RELOC_TYPE_COUNT (sizeof(SzRelocTypes) / sizeof(char *))

DWORD GetImgDirEntryRVA(bool Is64, PVOID pNTHdr, DWORD IDE)
{
	DWORD rva = 0;
	if (Is64) {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHdr;
		rva = p64->OptionalHeader.DataDirectory[IDE].VirtualAddress;
	}
	else {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHdr;
		rva = p32->OptionalHeader.DataDirectory[IDE].VirtualAddress;
	}
	return rva;
}

PIMAGE_SECTION_HEADER GetSectionHeader(bool Is64, PSTR name, PVOID pNTHeader)
{
	PIMAGE_SECTION_HEADER section;
	int numberOfSections;
	if (Is64) {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHeader;
		section = IMAGE_FIRST_SECTION(p64);
		numberOfSections = p64->FileHeader.NumberOfSections;
	}
	else {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHeader;
		section = IMAGE_FIRST_SECTION(p32);
		numberOfSections = p32->FileHeader.NumberOfSections;
	}

	for (int i = 0; i < numberOfSections; i++, section++)
	{
		if (0 == strncmp((char*)section->Name, name, IMAGE_SIZEOF_SHORT_NAME))
			return section;
	}

	return 0;
}

DWORD GetImgDirEntrySize(bool Is64, PVOID pNTHdr, DWORD IDE)
{
	DWORD size = 0;
	if (Is64) {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHdr;
		size = p64->OptionalHeader.DataDirectory[IDE].Size;
	}
	else {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHdr;
		size = p32->OptionalHeader.DataDirectory[IDE].Size;
	}
	return size;

}

PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(bool Is64, DWORD rva, PVOID pNTHeader)
{
	PIMAGE_SECTION_HEADER section;
	int numberOfSections;
	if (Is64) {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHeader;
		section = IMAGE_FIRST_SECTION(p64);
		numberOfSections = p64->FileHeader.NumberOfSections;
	}
	else {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHeader;
		section = IMAGE_FIRST_SECTION(p32);
		numberOfSections = p32->FileHeader.NumberOfSections;
	}

	for (int i = 0; i < numberOfSections; i++, section++)
	{
		if ((rva >= section->VirtualAddress) && (rva < (section->VirtualAddress + section->Misc.VirtualSize)))
			return section;
	}

	return 0;
}

LPVOID GetPtrFromRVA(bool Is64, DWORD rva, PIMAGE_NT_HEADERS32 pNTHeader, char* imageBase)
{
	PIMAGE_SECTION_HEADER pSectionHdr;
	INT delta;

	pSectionHdr = GetEnclosingSectionHeader(Is64, rva, pNTHeader);
	if (!pSectionHdr)
		return 0;

	delta = (INT)(pSectionHdr->VirtualAddress - pSectionHdr->PointerToRawData);
	return (PVOID)((BYTE*)imageBase + rva - delta);
}

void loadDOSEXE(EXEFilePtr result, PIMAGE_DOS_HEADER dosHeader)
{
	result->dosHeader.e_magic = dosHeader->e_magic;
	result->dosHeader.e_cblp = dosHeader->e_cblp;
	result->dosHeader.e_cp = dosHeader->e_cp;
	result->dosHeader.e_crlc = dosHeader->e_crlc;
	result->dosHeader.e_cparhdr = dosHeader->e_cparhdr;
	result->dosHeader.e_minalloc = dosHeader->e_minalloc;
	result->dosHeader.e_maxalloc = dosHeader->e_maxalloc;
	result->dosHeader.e_ss = dosHeader->e_ss;
	result->dosHeader.e_sp = dosHeader->e_sp;
	result->dosHeader.e_csum = dosHeader->e_csum;
	result->dosHeader.e_ip = dosHeader->e_ip;
	result->dosHeader.e_cs = dosHeader->e_cs;
	result->dosHeader.e_lfarlc = dosHeader->e_lfarlc;
	result->dosHeader.e_ovno = dosHeader->e_ovno;
	result->dosHeader.e_res[0] = dosHeader->e_res[0];
	result->dosHeader.e_res[1] = dosHeader->e_res[1];
	result->dosHeader.e_res[2] = dosHeader->e_res[2];
	result->dosHeader.e_res[3] = dosHeader->e_res[3];
	result->dosHeader.e_oemid = dosHeader->e_oemid;
	result->dosHeader.e_oeminfo = dosHeader->e_oeminfo;
	for (int j = 0; j < 10; j++) result->dosHeader.e_res2[j] = dosHeader->e_res2[j];
	result->dosHeader.e_lfanew = dosHeader->e_lfanew;
}

void loadPEHeaders(EXEFilePtr result, PIMAGE_NT_HEADERS32 pImgFileHdr)
{
	result->is64 = false;
	result->Signature = pImgFileHdr->Signature;
	result->FileHeader.Machine = pImgFileHdr->FileHeader.Machine;
	result->FileHeader.NumberOfSections = pImgFileHdr->FileHeader.NumberOfSections;
	result->FileHeader.TimeDateStamp = pImgFileHdr->FileHeader.TimeDateStamp;
	result->FileHeader.PointerToSymbolTable = pImgFileHdr->FileHeader.PointerToSymbolTable;
	result->FileHeader.NumberOfSymbols = pImgFileHdr->FileHeader.NumberOfSymbols;
	result->FileHeader.SizeOfOptionalHeader = pImgFileHdr->FileHeader.SizeOfOptionalHeader;
	result->FileHeader.Characteristics = pImgFileHdr->FileHeader.Characteristics;
	PIMAGE_OPTIONAL_HEADER64 opt64 = nullptr;
	PIMAGE_OPTIONAL_HEADER32 opt32 = nullptr;
	if (pImgFileHdr->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC)
	{
		opt32 = (PIMAGE_OPTIONAL_HEADER32)&pImgFileHdr->OptionalHeader;
		result->OptionalHeader32.Magic = opt32->Magic;
		result->OptionalHeader32.MajorLinkerVersion = opt32->MajorLinkerVersion;
		result->OptionalHeader32.MinorLinkerVersion = opt32->MinorLinkerVersion;
		result->OptionalHeader32.SizeOfCode = opt32->SizeOfCode;
		result->OptionalHeader32.SizeOfInitializedData = opt32->SizeOfInitializedData;
		result->OptionalHeader32.SizeOfUninitializedData = opt32->SizeOfUninitializedData;
		result->OptionalHeader32.AddressOfEntryPoint = opt32->AddressOfEntryPoint;
		result->OptionalHeader32.BaseOfCode = opt32->BaseOfCode;
		result->OptionalHeader32.ImageBase = opt32->ImageBase;
		result->OptionalHeader32.SectionAlignment = opt32->SectionAlignment;
		result->OptionalHeader32.FileAlignment = opt32->FileAlignment;
		result->OptionalHeader32.MajorOperatingSystemVersion = opt32->MajorOperatingSystemVersion;
		result->OptionalHeader32.MinorOperatingSystemVersion = opt32->MinorOperatingSystemVersion;
		result->OptionalHeader32.MajorImageVersion = opt32->MajorImageVersion;
		result->OptionalHeader32.MinorImageVersion = opt32->MinorImageVersion;
		result->OptionalHeader32.MajorSubsystemVersion = opt32->MajorSubsystemVersion;
		result->OptionalHeader32.MinorSubsystemVersion = opt32->MinorSubsystemVersion;
		result->OptionalHeader32.Win32VersionValue = opt32->Win32VersionValue;
		result->OptionalHeader32.SizeOfImage = opt32->SizeOfImage;
		result->OptionalHeader32.SizeOfHeaders = opt32->SizeOfHeaders;
		result->OptionalHeader32.CheckSum = opt32->CheckSum;
		result->OptionalHeader32.Subsystem = opt32->Subsystem;
		result->OptionalHeader32.DllCharacteristics = opt32->DllCharacteristics;
		result->OptionalHeader32.SizeOfStackReserve = opt32->SizeOfStackReserve;
		result->OptionalHeader32.SizeOfStackCommit = opt32->SizeOfStackCommit;
		result->OptionalHeader32.SizeOfHeapReserve = opt32->SizeOfHeapReserve;
		result->OptionalHeader32.SizeOfHeapCommit = opt32->SizeOfHeapCommit;
		result->OptionalHeader32.LoaderFlags = opt32->LoaderFlags;
		result->OptionalHeader32.NumberOfRvaAndSizes = opt32->NumberOfRvaAndSizes;
		for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
		{
			result->OptionalHeader32.DataDirectory[i].Size = opt32->DataDirectory[i].Size;
			result->OptionalHeader32.DataDirectory[i].VirtualAddress = opt32->DataDirectory[i].VirtualAddress;
		}
	}
	else if (pImgFileHdr->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
	{
		result->is64 = true;
		opt64 = (PIMAGE_OPTIONAL_HEADER64)&pImgFileHdr->OptionalHeader;
		result->OptionalHeader64.Magic = opt64->Magic;
		result->OptionalHeader64.MajorLinkerVersion = opt64->MajorLinkerVersion;
		result->OptionalHeader64.MinorLinkerVersion = opt64->MinorLinkerVersion;
		result->OptionalHeader64.SizeOfCode = opt64->SizeOfCode;
		result->OptionalHeader64.SizeOfInitializedData = opt64->SizeOfInitializedData;
		result->OptionalHeader64.SizeOfUninitializedData = opt64->SizeOfUninitializedData;
		result->OptionalHeader64.AddressOfEntryPoint = opt64->AddressOfEntryPoint;
		result->OptionalHeader64.BaseOfCode = opt64->BaseOfCode;
		result->OptionalHeader64.ImageBase = opt64->ImageBase;
		result->OptionalHeader64.SectionAlignment = opt64->SectionAlignment;
		result->OptionalHeader64.FileAlignment = opt64->FileAlignment;
		result->OptionalHeader64.MajorOperatingSystemVersion = opt64->MajorOperatingSystemVersion;
		result->OptionalHeader64.MinorOperatingSystemVersion = opt64->MinorOperatingSystemVersion;
		result->OptionalHeader64.MajorImageVersion = opt64->MajorImageVersion;
		result->OptionalHeader64.MinorImageVersion = opt64->MinorImageVersion;
		result->OptionalHeader64.MajorSubsystemVersion = opt64->MajorSubsystemVersion;
		result->OptionalHeader64.MinorSubsystemVersion = opt64->MinorSubsystemVersion;
		result->OptionalHeader64.Win32VersionValue = opt64->Win32VersionValue;
		result->OptionalHeader64.SizeOfImage = opt64->SizeOfImage;
		result->OptionalHeader64.SizeOfHeaders = opt64->SizeOfHeaders;
		result->OptionalHeader64.CheckSum = opt64->CheckSum;
		result->OptionalHeader64.Subsystem = opt64->Subsystem;
		result->OptionalHeader64.DllCharacteristics = opt64->DllCharacteristics;
		result->OptionalHeader64.SizeOfStackReserve = opt64->SizeOfStackReserve;
		result->OptionalHeader64.SizeOfStackCommit = opt64->SizeOfStackCommit;
		result->OptionalHeader64.SizeOfHeapReserve = opt64->SizeOfHeapReserve;
		result->OptionalHeader64.SizeOfHeapCommit = opt64->SizeOfHeapCommit;
		result->OptionalHeader64.LoaderFlags = opt64->LoaderFlags;
		result->OptionalHeader64.NumberOfRvaAndSizes = opt64->NumberOfRvaAndSizes;
		for (int i = 0; i < IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++)
		{
			result->OptionalHeader64.DataDirectory[i].Size = opt64->DataDirectory[i].Size;
			result->OptionalHeader64.DataDirectory[i].VirtualAddress = opt64->DataDirectory[i].VirtualAddress;
		}
	}
	else
	{
		printf("Is NOT a PE32 nor PE32+ magic value! Got %x\n", pImgFileHdr->OptionalHeader.Magic);
		return;
	}
}

void loadPESections(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pImgFileHdr)
{
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pImgFileHdr);
	for (int i = 1; i <= pImgFileHdr->FileHeader.NumberOfSections; i++)
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
		char* sectionBuffer = MakePtr(char*, buffer, section->PointerToRawData);
		if (section->PointerToRawData > 0 && section->SizeOfRawData > 0)
		{
			ptr->sectionBuffer = new char[section->SizeOfRawData];
			for (int j = 0; j < section->SizeOfRawData; j++) ptr->sectionBuffer[j] = sectionBuffer[j];
		}
		else
		{
			ptr->sectionBuffer = nullptr;
		}
		result->sectionTable.push_back(ptr);
		section = MakePtr(PIMAGE_SECTION_HEADER, section, sizeof(IMAGE_SECTION_HEADER));
	}
}

PSTR GetSafeFileName(PSTR fn1, PSTR filename)
{
	PSTR cp = new char[1024];
	int i, c, len, max = 256;
	int got0 = 0;
	*cp = 0;
	len = 0;
	for (i = 0; i < max; i++) {
		c = fn1[i] & 0xff;
		if (c == 0) {
			got0 = 1;
			break;
		}
		else if ((c >= 0x20) && (c < 128)) {
			cp[len++] = c;
			cp[len] = 0;
		}
		else
			break;
	}
	if (got0 && len)
		return cp;
	*cp = 0;
	len = 0;
	for (i = 0; i < max; i++) {
		c = fn1[i] & 0xff;
		if (c == 0) {
			got0 = 1;
			break;
		}
		else if ((c >= 0x20) && (c < 128)) {
			cp[len++] = c;
			cp[len] = 0;
		}
		else
			break;
	}
	if (got0 && len)
		return cp;
	cp = (PSTR)"N/A";
	return cp;
}

void loadExportsDirectory(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pNTHeader)
{
	DWORD exportRVAStart = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_EXPORT);
	DWORD exportRVASize = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_EXPORT);
	PIMAGE_SECTION_HEADER headerExports = GetEnclosingSectionHeader(result->is64, exportRVAStart, pNTHeader);
	if (headerExports != NULL)
	{
		DWORD delta = headerExports->VirtualAddress - headerExports->PointerToRawData;
		PIMAGE_EXPORT_DIRECTORY exportDir = MakePtr(PIMAGE_EXPORT_DIRECTORY, buffer, exportRVAStart - delta);
		DWORD Rva = exportDir->Name;
		PSTR fn1 = (PSTR)(buffer + (Rva - delta));
		result->exports = new Exports;
		result->exports->filename = (PSTR)(buffer + Rva);
		result->exports->filename = GetSafeFileName(fn1, result->exports->filename);
		result->exports->exports.Characteristics = exportDir->Characteristics;
		result->exports->exports.TimeDateStamp = exportDir->TimeDateStamp;
		result->exports->exports.MajorVersion = exportDir->MajorVersion;
		result->exports->exports.MinorVersion = exportDir->MinorVersion;
		result->exports->exports.Name = exportDir->Name;
		result->exports->exports.Base = exportDir->Base;
		result->exports->exports.NumberOfFunctions = exportDir->NumberOfFunctions;
		result->exports->exports.NumberOfNames = exportDir->NumberOfNames;
		result->exports->exports.AddressOfFunctions = exportDir->AddressOfFunctions;
		result->exports->exports.AddressOfNames = exportDir->AddressOfNames;
		result->exports->exports.AddressOfNameOrdinals = exportDir->AddressOfNameOrdinals;
		PDWORD functions = (PDWORD)(buffer + (exportDir->AddressOfFunctions - delta));
		PWORD ordinals = (PWORD)(buffer + (exportDir->AddressOfNameOrdinals - delta));
		PDWORD dwpname = (PDWORD)(buffer + (exportDir->AddressOfNames - delta));
		for (int i = 0; i < exportDir->NumberOfFunctions; i++)
		{
			DWORD entryPointRVA = functions[i];
			if (entryPointRVA == 0) continue;
			ExportsFunctionsPtr function = new ExportsFunctions;
			function->entryPoint = entryPointRVA;
			function->ordinal = i + exportDir->Base;
			for (int j = 0; j < exportDir->NumberOfNames; j++)
			{
				if (ordinals[j] == i) {
					INT off = dwpname[j];
					if (off > delta) {
						char* pn = buffer + (off - delta);
						function->filename = pn;
					}
				}
			}
			result->exports->functions.push_back(function);
		}
	}
}

void loadImportsDirectory(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pNTHeader)
{
	DWORD importRVAStart = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_IMPORT);
	DWORD importRVASize = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_IMPORT);
	PIMAGE_SECTION_HEADER headerImports = GetEnclosingSectionHeader(result->is64, importRVAStart, pNTHeader);
	PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR)GetPtrFromRVA(result->is64, importRVAStart, pNTHeader, buffer);
	while (1)
	{
		if ((importDesc->TimeDateStamp == 0) && (importDesc->Name == 0))
			break;
		ImportsPtr ptr = new Imports;
		ptr->imports.Characteristics = importDesc->Characteristics;
		ptr->imports.TimeDateStamp = importDesc->TimeDateStamp;
		ptr->imports.ForwarderChain = importDesc->ForwarderChain;
		ptr->imports.Name = importDesc->Name;
		ptr->imports.FirstThunk = importDesc->FirstThunk;
		ptr->filename = (char*)GetPtrFromRVA(result->is64, importDesc->Name, pNTHeader, buffer);
		DWORD dwthunk = importDesc->Characteristics;
		DWORD dwthunkIAT = importDesc->FirstThunk;
		if (result->is64)
		{
			PIMAGE_THUNK_DATA64 thunk = (PIMAGE_THUNK_DATA64)GetPtrFromRVA(result->is64, dwthunk, pNTHeader, buffer);
			PIMAGE_THUNK_DATA64 thunkIAT = (PIMAGE_THUNK_DATA64)GetPtrFromRVA(result->is64, dwthunkIAT, pNTHeader, buffer);
			while (1)
			{
				if (thunk->u1.AddressOfData == 0)
					break;
				DWORD dwOff = (DWORD)thunk->u1.AddressOfData;
				Thunk64Ptr tempThunk = new Thunk64;
				Thunk64Ptr tempIATThunk = new Thunk64;
				tempThunk->ordinalname = (PIMAGE_IMPORT_BY_NAME)GetPtrFromRVA(result->is64, dwOff, pNTHeader, buffer);
				tempThunk->thunk.u1.AddressOfData = thunk->u1.AddressOfData;
				tempIATThunk->thunk.u1.AddressOfData = thunkIAT->u1.AddressOfData;
				ptr->thunk64.push_back(tempThunk);
				ptr->thunkIAT64.push_back(tempIATThunk);
				thunk++;
				thunkIAT++;
			}
		}
		else
		{
			PIMAGE_THUNK_DATA32 thunk = (PIMAGE_THUNK_DATA32)GetPtrFromRVA(result->is64, dwthunk, pNTHeader, buffer);
			PIMAGE_THUNK_DATA32 thunkIAT = (PIMAGE_THUNK_DATA32)GetPtrFromRVA(result->is64, dwthunkIAT, pNTHeader, buffer);
			while (1)
			{
				if (thunk->u1.AddressOfData == 0)
					break;
				Thunk32Ptr tempThunk = new Thunk32;
				Thunk32Ptr tempIATThunk = new Thunk32;
				tempThunk->thunk.u1.AddressOfData = thunk->u1.AddressOfData;
				tempIATThunk->thunk.u1.AddressOfData = thunkIAT->u1.AddressOfData;
				ptr->thunk32.push_back(tempThunk);
				ptr->thunkIAT32.push_back(tempIATThunk);
				thunk++;
				thunkIAT++;
			}
		}
		result->imports.push_back(ptr);
		importDesc++;
	}
}

void loadResourcesDirectory(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pNTHeader)
{
	DWORD resourceRVA = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_RESOURCE);
	DWORD resourceRVASize = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_RESOURCE);
	PIMAGE_RESOURCE_DIRECTORY resDir = (PIMAGE_RESOURCE_DIRECTORY)GetPtrFromRVA(result->is64, resourceRVA, pNTHeader, buffer);
	PIMAGE_RESOURCE_DIRECTORY_ENTRY resDirEntry = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)(resDir + 1);
	WORD nNamed = resDir->NumberOfNamedEntries;
	WORD nIds = resDir->NumberOfIdEntries;
	PIMAGE_RESOURCE_DATA_ENTRY  pResDataEntry;
	result->resources.header.Characteristics = resDir->Characteristics;
	result->resources.header.TimeDateStamp = resDir->TimeDateStamp;
	result->resources.header.MajorVersion = resDir->MajorVersion;
	result->resources.header.MinorVersion = resDir->MinorVersion;
	result->resources.header.NumberOfNamedEntries = resDir->NumberOfNamedEntries;
	result->resources.header.NumberOfIdEntries = resDir->NumberOfIdEntries;
	for (WORD i = 0; i <= nNamed; i++, resDirEntry++)
	{
		ResourcesEntryPtr entry = new ResourcesEntry;
		if (resDirEntry->OffsetToData & IMAGE_RESOURCE_DATA_IS_DIRECTORY) {
			entry->isDirectory++;
		}
		else if (resDirEntry->Name & IMAGE_RESOURCE_NAME_IS_STRING) {
			entry->isString++;
		}
		entry->entry.OffsetToData = resDirEntry->OffsetToData;
		entry->entry.Name = resDirEntry->Name;
		result->resources.entries.push_back(entry);
	}
}

void loadBaseRelocationsDirectory(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pNTHeader)
{
	DWORD baseRelocRVA = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_BASERELOC);
	DWORD baseRelocRVASize = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_BASERELOC);
	PIMAGE_BASE_RELOCATION baseReloc = (PIMAGE_BASE_RELOCATION)GetPtrFromRVA(result->is64, baseRelocRVA, pNTHeader, buffer);
	while (baseReloc->SizeOfBlock != 0)
	{
		if (0 == baseReloc->VirtualAddress)
			break;
		if (baseReloc->SizeOfBlock < sizeof(*baseReloc))
			break;
		RelocsPtr relocs = new Relocs;
		relocs->baseReloc.VirtualAddress = baseReloc->VirtualAddress;
		relocs->baseReloc.SizeOfBlock = baseReloc->SizeOfBlock;
		int cEntries = (baseReloc->SizeOfBlock - sizeof(*baseReloc)) / sizeof(WORD);
		PWORD pEntry = MakePtr(PWORD, baseReloc, sizeof(*baseReloc));
		for (int i = 0; i < cEntries; i++)
		{
			RelocsEntryPtr relocsEntry = new RelocsEntry;
			relocsEntry->relocType = *pEntry;
			WORD relocType = (*pEntry & 0xF000) >> 12;
			relocsEntry->szRelocType = (relocType < RELOC_TYPE_COUNT) ? SzRelocTypes[relocType] : "unknown";
			relocs->entries.push_back(relocsEntry);
			if (IMAGE_REL_BASED_HIGHADJ == relocType)
			{
				pEntry++;
				cEntries--;
			}
			pEntry++;
		}
		result->relocs.push_back(relocs);
		baseReloc = MakePtr(PIMAGE_BASE_RELOCATION, baseReloc, baseReloc->SizeOfBlock);
	}
}

EXEFilePtr loadExeFile(char* buffer, LONGLONG fileSize)
{
	EXEFilePtr result = new EXEFile;
	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)buffer;
	PIMAGE_NT_HEADERS32 pNTHeader = MakePtr(PIMAGE_NT_HEADERS32, dosHeader, dosHeader->e_lfanew);
	loadDOSEXE(result, dosHeader);
	loadPEHeaders(result, pNTHeader);
	loadPESections(result, buffer, pNTHeader);
	loadExportsDirectory(result, buffer, pNTHeader);
	loadImportsDirectory(result, buffer, pNTHeader);
	loadResourcesDirectory(result, buffer, pNTHeader);

	DWORD debugRVA = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);
	DWORD debugRVASize = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);
	if (debugRVA != 0)
	{
		PIMAGE_SECTION_HEADER header = GetSectionHeader(result->is64, (PSTR)".debug", pNTHeader);
		PIMAGE_DEBUG_DIRECTORY debugDir;
		DWORD size;
		if (header && (header->VirtualAddress == debugRVA))
		{
			debugDir = (PIMAGE_DEBUG_DIRECTORY)(header->PointerToRawData + buffer);
			size = debugRVASize * sizeof(IMAGE_DEBUG_DIRECTORY);
		}
		else
		{
			header = GetEnclosingSectionHeader(result->is64, debugRVA, pNTHeader);
			if (!header) return NULL;
			size = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);
			debugDir = MakePtr(PIMAGE_DEBUG_DIRECTORY, buffer, header->PointerToRawData	+ (debugRVA - header->VirtualAddress));
		}
		DWORD cDebugFormats = size / sizeof(IMAGE_DEBUG_DIRECTORY);
		printf(
			"Debug Formats in File\n"
			"  Type            Type      Size     Address  FilePtr  Charactr TimeDate Version\n"
			"  --------------- --------  -------- -------- -------- -------- -------- --------\n"
		);
		for (DWORD i = 0; i < cDebugFormats; i++)
		{
			const char * szDebugFormat = (debugDir->Type <= IMAGE_DEBUG_TYPE_EX_DLLCHARACTERISTICS)	? SzDebugFormats[debugDir->Type] : "???";
			printf("  %-15s % 8ld  % 8ld %08X %08X %08X %08X %u.%02u\n",
				szDebugFormat, debugDir->Type, debugDir->SizeOfData, debugDir->AddressOfRawData,
				debugDir->PointerToRawData, debugDir->Characteristics,
				debugDir->TimeDateStamp, debugDir->MajorVersion,
				debugDir->MinorVersion);
			debugDir++;
		}
	}

	DWORD configRVA = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG);
	DWORD iatRVA = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_IAT);
	return result;
}