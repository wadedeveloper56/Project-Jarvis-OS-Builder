#pragma once

#include "MemoryMappedFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

#define HEX_DUMP_WIDTH 16

// Subsystem Values

#define IMAGE_SUBSYSTEM_UNKNOWN              0   // Unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE               1   // Image doesn't require a subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI          2   // Image runs in the Windows GUI subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI          3   // Image runs in the Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI              5   // image runs in the OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI            7   // image runs in the Posix character subsystem.
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS       8   // image is a native Win9x driver.
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI       9   // Image runs in the Windows CE subsystem.
#define IMAGE_SUBSYSTEM_EFI_APPLICATION      10  //
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11   //
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER   12  //
#define IMAGE_SUBSYSTEM_EFI_ROM              13
#define IMAGE_SUBSYSTEM_XBOX                 14
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16
#define IMAGE_SUBSYSTEM_XBOX_CODE_CATALOG    17

#define IMAGE_SCN_TYPE_DSECT 0x00000001  
#define IMAGE_SCN_TYPE_NOLOAD 0x00000002  
#define IMAGE_SCN_TYPE_GROUP 0x00000004  
#define IMAGE_SCN_TYPE_COPY 0x00000010  
#define IMAGE_SCN_TYPE_OVER 0x00000400  
#define IMAGE_SCN_MEM_PROTECTED 0x00004000
#define IMAGE_SCN_MEM_SYSHEAP 0x00010000


typedef struct
{
	WORD flag;
	const char* name;
} WORD_FLAG_DESCRIPTIONS;

typedef struct
{
	DWORD flag;
	const char* name;
} DWORD_FLAG_DESCRIPTIONS;

typedef struct _i386RelocTypes
{
	WORD type;
	const char* name;
} i386RelocTypes;

class COFFSymbolTable;

class COFFSymbol
{
	PSTR 			m_pStringTable;
	PIMAGE_SYMBOL 	m_pSymbolData;
	DWORD			m_index;
	PSTR			m_pszShortString;
	char			m_szTypeName[16];
	void	CleanUp(void);
public:
	COFFSymbol(PIMAGE_SYMBOL pSymbolData, PSTR pStringTable, DWORD index);
	~COFFSymbol();
	PIMAGE_SYMBOL GetSymbol();
	DWORD GetIndex();
	PSTR  GetName();
	DWORD GetValue();
	SHORT GetSectionNumber();
	WORD  GetType();
	PSTR  GetTypeName();
	BYTE  GetStorageClass();
	PSTR  GetStorageClassName();
	BOOL  GetNumberOfAuxSymbols();
	BOOL  GetAuxSymbolAsString(PSTR pszBuffer, unsigned cbBuffer);
	friend class COFFSymbolTable;
};
typedef COFFSymbol* PCOFFSymbol;
class COFFSymbolTable
{
private:
	PIMAGE_SYMBOL	m_pSymbolBase;
	unsigned 		m_cSymbols;
	PSTR			m_pStringTable;
public:
	COFFSymbolTable(PVOID pSymbolBase, unsigned cSymbols);
	~COFFSymbolTable();
	unsigned GetNumberOfSymbols(void) { return m_cSymbols; }
	PCOFFSymbol GetNextSymbol(PCOFFSymbol);
	PCOFFSymbol GetNearestSymbolFromRVA(DWORD rva, BOOL fExact);
	PCOFFSymbol GetSymbolFromIndex(DWORD index);
};
typedef COFFSymbolTable* PCOFFSymbolTable;

typedef struct OBJSection
{
	IMAGE_SECTION_HEADER header;
	PIMAGE_RELOCATION relocation;
	PIMAGE_LINENUMBER lineNumbers;
	char* sectionBuffer;
}OBJSection, * OBJSectionPtr;

typedef struct _OBJFile
{
	IMAGE_FILE_HEADER header;
	vector<OBJSectionPtr> sectionTable;
	PCOFFSymbolTable symbolTable;
	DWORD stringTableSize;
	vector<string> stringTable;
}OBJFile, * OBJFilePtr, ** OBJFilePtrPtr;

typedef struct _Resources
{
	IMAGE_RESOURCE_DIRECTORY res;
	vector<PIMAGE_RESOURCE_DIRECTORY_ENTRY> entries;
}Resources, * ResourcesPtr;

typedef struct _EXEFile
{
	bool is64;
	IMAGE_DOS_HEADER dosHeader;
	DWORD Signature;
	IMAGE_FILE_HEADER FileHeader;
	IMAGE_OPTIONAL_HEADER32 OptionalHeader32;
	IMAGE_OPTIONAL_HEADER64 OptionalHeader64;
	vector<OBJSectionPtr> sectionTable;
	vector<PIMAGE_DEBUG_DIRECTORY> debug;
	Resources resources;
}EXEFile, * EXEFilePtr, ** EXEFilePtrPtr;

#define MakePtr( cast, ptr, addValue ) (cast)( (BYTE *)(ptr) + (DWORD)(addValue))


typedef enum _FileType { UNKNOWN, EXE, DEBUG, OBJ, ANONYMOUS, LIB }FileType;

WORD getFileMagic(char* buffer);
FileType getFileType(char* buffer);
const char* GetMachineTypeName(WORD wMachineType);
int islistedMachineType(WORD wMachineType);
void hexdump(const void* data, size_t size);
char* get_ctime_stg(time_t* pt);
OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize);

DWORD GetImgDirEntryRVA(bool Is32, PVOID pNTHdr, DWORD IDE);
PIMAGE_SECTION_HEADER GetSectionHeader(bool Is64, PSTR name, PVOID pNTHeader);
DWORD GetImgDirEntrySize(bool Is32, PVOID pNTHdr, DWORD IDE);
PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(bool Is64, DWORD rva, PVOID pNTHeader);
LPVOID GetPtrFromRVA(DWORD rva, PIMAGE_NT_HEADERS32 pNTHeader, char* imageBase);
void loadDOSEXE(EXEFilePtr result, PIMAGE_DOS_HEADER dosHeader);
void loadPEHeaders(EXEFilePtr result, PIMAGE_NT_HEADERS32 pImgFileHdr);
void loadPESections(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pImgFileHdr);
void LoadDebugDirectory(EXEFilePtr result, PIMAGE_DEBUG_DIRECTORY debugDir, DWORD size, char* base);
void loadDebug(EXEFilePtr result, char* buffer);
void loadResources(EXEFilePtr result, bool Is64, char* base, PIMAGE_NT_HEADERS32 pNTHeader);
EXEFilePtr loadExeFile(char* buffer, LONGLONG fileSize);

void GetObjRelocationName(WORD type, PSTR buffer, DWORD cBytes);
void DumpSection(int i, OBJSectionPtr ptr);
void GetSectionName(WORD section, PSTR buffer, unsigned cbBuffer);
void DumpSymbolTable(COFFSymbolTable* pSymTab);
void DumpDOSHeader(PIMAGE_DOS_HEADER dosHeader);
void DumpFileHeader(PIMAGE_FILE_HEADER pImageFileHeader);
void DumpOptionalHeader64(PIMAGE_OPTIONAL_HEADER64 optionalHeader);
void DumpOptionalHeader32(PIMAGE_OPTIONAL_HEADER32 optionalHeader);

