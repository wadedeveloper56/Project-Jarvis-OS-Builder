#pragma once

#define BINARYFORMATS_API 
#define BINARYFORMATS_TEMPLATE 

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


typedef struct BINARYFORMATS_API
{
	WORD flag;
	const char* name;
} WORD_FLAG_DESCRIPTIONS;

typedef struct BINARYFORMATS_API
{
	DWORD flag;
	const char* name;
} DWORD_FLAG_DESCRIPTIONS;

typedef struct BINARYFORMATS_API _i386RelocTypes
{
	WORD type;
	const char* name;
} i386RelocTypes;

class COFFSymbolTable;

class BINARYFORMATS_API COFFSymbol
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

typedef BINARYFORMATS_API COFFSymbol* PCOFFSymbol;
class BINARYFORMATS_API COFFSymbolTable
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
typedef BINARYFORMATS_API COFFSymbolTable* PCOFFSymbolTable;

typedef struct BINARYFORMATS_API _OBJSection
{
	IMAGE_SECTION_HEADER header;
	PIMAGE_RELOCATION relocation;
	PIMAGE_LINENUMBER lineNumbers;
	char* sectionBuffer;
}OBJSection, * OBJSectionPtr;

typedef struct BINARYFORMATS_API _OBJFile
{
	vector<OBJSectionPtr> sectionTable;
	vector<string> stringTable;
	IMAGE_FILE_HEADER header;
	PCOFFSymbolTable symbolTable;
	DWORD stringTableSize;
	_OBJFile();
} OBJFile, * OBJFilePtr, ** OBJFilePtrPtr;

typedef struct BINARYFORMATS_API _Resources
{
	vector<PIMAGE_RESOURCE_DIRECTORY_ENTRY> entries;
	IMAGE_RESOURCE_DIRECTORY res;
	_Resources();
}Resources, * ResourcesPtr, ** ResourcesPtrPtr;

typedef struct BINARYFORMATS_API _ExportsFunctions
{
	DWORD entryPoint;
	DWORD ordinal;
	char* filename;
	_ExportsFunctions();
} ExportsFunctions, * ExportsFunctionsPtr, ** ExportsFunctionsPtrPtr;

typedef struct BINARYFORMATS_API _Exports
{
	IMAGE_EXPORT_DIRECTORY exports;
	char* filename;
	vector<ExportsFunctionsPtr> functions;
	_Exports();
} Exports, * ExportsPtr;

typedef struct BINARYFORMATS_API _Thunk64
{
	IMAGE_THUNK_DATA64 thunk;
	PIMAGE_IMPORT_BY_NAME ordinalname;
	_Thunk64();
} Thunk64, * Thunk64Ptr;

typedef struct BINARYFORMATS_API _Thunk32
{
	IMAGE_THUNK_DATA32 thunk;
	PIMAGE_IMPORT_BY_NAME ordinalname;
	_Thunk32();
} Thunk32, * Thunk32Ptr;

typedef struct BINARYFORMATS_API _Imports
{
	IMAGE_IMPORT_DESCRIPTOR imports;
	vector<Thunk64Ptr> thunk64;
	vector<Thunk64Ptr> thunkIAT64;
	vector<Thunk32Ptr> thunk32;
	vector<Thunk32Ptr> thunkIAT32;
	char* filename;
	_Imports();
} Imports, * ImportsPtr;

typedef struct BINARYFORMATS_API _EXEFile
{
	vector<OBJSectionPtr> sectionTable;
	bool is64;
	IMAGE_DOS_HEADER dosHeader;
	DWORD Signature;
	IMAGE_FILE_HEADER FileHeader;
	IMAGE_OPTIONAL_HEADER32 OptionalHeader32;
	IMAGE_OPTIONAL_HEADER64 OptionalHeader64;
	Resources resources;
	ExportsPtr exports;
	vector<ImportsPtr> imports;
	_EXEFile();
} EXEFile, * EXEFilePtr, ** EXEFilePtrPtr;

#define MakePtr( cast, ptr, addValue ) (cast)( (BYTE *)(ptr) + (DWORD)(addValue))


typedef enum _FileType { UNKNOWN, EXE, DEBUG, OBJ, ANONYMOUS, LIB }FileType;

BINARYFORMATS_API WORD getFileMagic(char* buffer);
BINARYFORMATS_API FileType getFileType(char* buffer);
BINARYFORMATS_API const char* GetMachineTypeName(WORD wMachineType);
BINARYFORMATS_API int islistedMachineType(WORD wMachineType);
BINARYFORMATS_API void hexdump(const void* data, size_t size);
BINARYFORMATS_API char* get_ctime_stg(time_t* pt);
BINARYFORMATS_API OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize);

BINARYFORMATS_API DWORD GetImgDirEntryRVA(bool Is64, PVOID pNTHdr, DWORD IDE);
BINARYFORMATS_API PIMAGE_SECTION_HEADER GetSectionHeader(bool Is64, PSTR name, PVOID pNTHeader);
BINARYFORMATS_API DWORD GetImgDirEntrySize(bool Is64, PVOID pNTHdr, DWORD IDE);
BINARYFORMATS_API PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(bool Is64, DWORD rva, PVOID pNTHeader);
BINARYFORMATS_API LPVOID GetPtrFromRVA(bool Is64, DWORD rva, PIMAGE_NT_HEADERS32 pNTHeader, char* imageBase);
BINARYFORMATS_API void loadDOSEXE(EXEFilePtr result, PIMAGE_DOS_HEADER dosHeader);
BINARYFORMATS_API void loadPEHeaders(EXEFilePtr result, PIMAGE_NT_HEADERS32 pImgFileHdr);
BINARYFORMATS_API void loadPESections(EXEFilePtr result, char* buffer, PIMAGE_NT_HEADERS32 pImgFileHdr);
BINARYFORMATS_API EXEFilePtr loadExeFile(char* buffer, LONGLONG fileSize);

BINARYFORMATS_API void GetObjRelocationName(WORD type, PSTR buffer, DWORD cBytes);
BINARYFORMATS_API void DumpSection(int i, OBJSectionPtr ptr);
BINARYFORMATS_API void GetSectionName(WORD section, PSTR buffer, unsigned cbBuffer);
BINARYFORMATS_API void DumpSymbolTable(COFFSymbolTable* pSymTab);
BINARYFORMATS_API void DumpDOSHeader(PIMAGE_DOS_HEADER dosHeader);
BINARYFORMATS_API void DumpFileHeader(PIMAGE_FILE_HEADER pImageFileHeader);
BINARYFORMATS_API void DumpOptionalHeader64(PIMAGE_OPTIONAL_HEADER64 optionalHeader);
BINARYFORMATS_API void DumpOptionalHeader32(PIMAGE_OPTIONAL_HEADER32 optionalHeader);
BINARYFORMATS_API void DumpExportDirectory(ExportsPtr exportDir);
BINARYFORMATS_API void DumpImportDirectory(bool is64, vector<ImportsPtr>* imports);
