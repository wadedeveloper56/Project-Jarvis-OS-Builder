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
}OBJFile, * OBJFilePtr, ** OBJFilePtrPtr;

#define MakePtr( cast, ptr, addValue ) (cast)( (BYTE *)(ptr) + (DWORD)(addValue))


typedef enum _FileType { UNKNOWN, EXE, DEBUG, OBJ, ANONYMOUS, LIB }FileType;
WORD getFileMagic(char* buffer);
FileType getFileType(char* buffer);
PSTR GetMachineTypeName(WORD wMachineType);
int islistedMachineType(WORD wMachineType);
OBJFilePtr loadObjFile(char* buffer, LONGLONG fileSize);

