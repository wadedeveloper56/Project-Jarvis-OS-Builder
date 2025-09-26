#include "pch.h"
#include "framework.h"
#include "BinaryFormat.h"

using namespace std;

const char* SzDebugFormats[] = {
"UNKNOWN/BORLAND","COFF","CODEVIEW","FPO","MISC","EXCEPTION","FIXUP",
"OMAP_TO_SRC", "OMAP_FROM_SRC" };

DWORD GetImgDirEntryRVA(bool Is32, PVOID pNTHdr, DWORD IDE)
{
	DWORD rva = 0;
	if (Is32) {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHdr;
		rva = p32->OptionalHeader.DataDirectory[IDE].VirtualAddress;
	}
	else {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHdr;
		rva = p64->OptionalHeader.DataDirectory[IDE].VirtualAddress;
	}
	return rva;
}

PIMAGE_SECTION_HEADER GetSectionHeader(PSTR name, PIMAGE_NT_HEADERS32 pNTHeader)
{
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);
	unsigned i;

	for (i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, section++)
	{
		if (0 == strncmp((char*)section->Name, name, IMAGE_SIZEOF_SHORT_NAME))
			return section;
	}

	return 0;
}

DWORD GetImgDirEntrySize(bool Is32, PVOID pNTHdr, DWORD IDE)
{
	DWORD size = 0;
	if (Is32) {
		PIMAGE_NT_HEADERS32 p32 = (PIMAGE_NT_HEADERS32)pNTHdr;
		size = p32->OptionalHeader.DataDirectory[IDE].Size;
	}
	else {
		PIMAGE_NT_HEADERS64 p64 = (PIMAGE_NT_HEADERS64)pNTHdr;
		size = p64->OptionalHeader.DataDirectory[IDE].Size;
	}
	return size;

}

PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(DWORD rva, PIMAGE_NT_HEADERS32 pNTHeader)
{
	PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);

	for (int i = 0; i < pNTHeader->FileHeader.NumberOfSections; i++, section++)
	{
		if ((rva >= section->VirtualAddress) && (rva < (section->VirtualAddress + section->Misc.VirtualSize)))
			return section;
	}

	return 0;
}

LPVOID GetPtrFromRVA(DWORD rva, PIMAGE_NT_HEADERS32 pNTHeader, char* imageBase)
{
	PIMAGE_SECTION_HEADER pSectionHdr;
	INT delta;

	pSectionHdr = GetEnclosingSectionHeader(rva, pNTHeader);
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

void DumpDebugDirectory(EXEFilePtr result, PIMAGE_DEBUG_DIRECTORY debugDir, DWORD size, char* base)
{
	DWORD cDebugFormats = size / sizeof(IMAGE_DEBUG_DIRECTORY);

	if (cDebugFormats == 0)
		return;

	for (int i = 0; i < cDebugFormats; i++)
	{
		PIMAGE_DEBUG_DIRECTORY data = new IMAGE_DEBUG_DIRECTORY;
		data->Characteristics = debugDir->Characteristics;
		data->TimeDateStamp = debugDir->TimeDateStamp;
		data->MajorVersion = debugDir->MajorVersion;
		data->MinorVersion = debugDir->MinorVersion;
		data->Type = debugDir->Type;
		data->SizeOfData = debugDir->SizeOfData;
		data->AddressOfRawData = debugDir->AddressOfRawData;
		data->PointerToRawData = debugDir->PointerToRawData;
		result->debug.push_back(data);
		debugDir++;
	}
}

void loadDebug(EXEFilePtr result, char* buffer)
{
	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)buffer;
	PIMAGE_NT_HEADERS32 pNTHeader = MakePtr(PIMAGE_NT_HEADERS32, dosHeader, dosHeader->e_lfanew);
	PIMAGE_DEBUG_DIRECTORY debugDir;
	DWORD size;
	DWORD va_debug_dir = GetImgDirEntryRVA(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);
	PIMAGE_SECTION_HEADER header = GetSectionHeader((PSTR)".debug", pNTHeader);
	if (header && (header->VirtualAddress == va_debug_dir))
	{
		debugDir = (PIMAGE_DEBUG_DIRECTORY)(header->PointerToRawData + buffer);
		size = GetImgDirEntrySize(result->is64, pNTHeader, (DWORD)IMAGE_DIRECTORY_ENTRY_DEBUG) * sizeof(IMAGE_DEBUG_DIRECTORY);
	}
	else
	{
		header = GetEnclosingSectionHeader(va_debug_dir, pNTHeader);
		if (!header) return;
		size = GetImgDirEntrySize(result->is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_DEBUG);
		debugDir = MakePtr(PIMAGE_DEBUG_DIRECTORY, buffer, header->PointerToRawData + (va_debug_dir - header->VirtualAddress));
	}
	DumpDebugDirectory(result, debugDir, size, buffer);
}

void loadResources(EXEFilePtr result, bool Is64, char* base, PIMAGE_NT_HEADERS32 pNTHeader)
{
	DWORD resourcesRVA = GetImgDirEntryRVA(Is64, pNTHeader, IMAGE_DIRECTORY_ENTRY_RESOURCE);
	if (!resourcesRVA) return;
	PIMAGE_RESOURCE_DIRECTORY resDir = (PIMAGE_RESOURCE_DIRECTORY)GetPtrFromRVA(resourcesRVA, pNTHeader, base);
	if (!resDir) return;
	result->resources.res.Characteristics = resDir->Characteristics;
	result->resources.res.TimeDateStamp = resDir->TimeDateStamp;
	result->resources.res.MajorVersion = resDir->MajorVersion;
	result->resources.res.MinorVersion = resDir->MinorVersion;
	result->resources.res.NumberOfNamedEntries = resDir->NumberOfNamedEntries;
	result->resources.res.NumberOfIdEntries = resDir->NumberOfIdEntries;
	PIMAGE_RESOURCE_DIRECTORY_ENTRY resDirEntry = (PIMAGE_RESOURCE_DIRECTORY_ENTRY)(resDir + 1);
	for (int i = 0; i < resDir->NumberOfNamedEntries; i++) {
		PIMAGE_RESOURCE_DIRECTORY_ENTRY ptr = new IMAGE_RESOURCE_DIRECTORY_ENTRY;
		ptr->DataIsDirectory = resDirEntry->DataIsDirectory;
		ptr->Id = resDirEntry->Id;
		ptr->Name = resDirEntry->Name;
		ptr->NameIsString = resDirEntry->NameIsString;
		ptr->NameOffset = resDirEntry->NameOffset;
		ptr->OffsetToData = resDirEntry->OffsetToData;
		ptr->OffsetToDirectory = resDirEntry->OffsetToDirectory;
		result->resources.entries.push_back(ptr);
		resDirEntry++;
	}
}

EXEFilePtr loadExeFile(char* buffer, LONGLONG fileSize)
{
	EXEFilePtr result = new EXEFile;
	PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)buffer;
	PIMAGE_NT_HEADERS32 pImgFileHdr = MakePtr(PIMAGE_NT_HEADERS32, dosHeader, dosHeader->e_lfanew);
	loadDOSEXE(result, dosHeader);
	loadPEHeaders(result, pImgFileHdr);
	loadPESections(result, buffer, pImgFileHdr);
	loadDebug(result, buffer);
	loadResources(result, result->is64, buffer, pImgFileHdr);
	return result;
}