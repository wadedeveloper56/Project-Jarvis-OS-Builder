#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include "walloca.h"

#include "coffimpl.h"

#define MAX_NUM_COFF_LIB_SECTIONS       8
#define MAX_NUM_COFF_LIB_SYMBOLS        32
#define INIT_MAX_SIZE_COFF_STRING_TABLE 1024

typedef struct
{
	coff_file_header    header;
	coff_section_header section[MAX_NUM_COFF_LIB_SECTIONS];
	coff_symbol         symbol[MAX_NUM_COFF_LIB_SYMBOLS];
	unsigned_32         string_table_size;
	unsigned_32         max_string_table_size;
	char* string_table;
	coff_file_handle    coff_file_hnd;
} coff_lib_file;

typedef enum
{
	IMPORT_DESCRIPTOR,
	NULL_IMPORT_DESCRIPTOR,
	NULL_THUNK_DATA,
	ORDINAL,
	NAMED,
	ELF,
	ELFRENAMED,
} importType;

typedef struct
{
	importType  type;
	short       processor;
	char* DLLName;
	long        ordinal;
	char* symName;
	char* exportedName;
	uint_32     time_date_stamp;
} import_sym;

static unsigned_8 CoffImportAxpText[] = {
 0x00,0x00,0x7F,0x27,0x00,0x00,0x7B,0xA3,0x00,0x00,0xFB,0x6B
};

static unsigned_8 CoffImportPpcText[] = {
 0x00,0x00,0x62,0x81,0x00,0x00,0x8B,0x81,0x04,0x00,0x41,0x90,0xA6,0x03,0x89,0x7D,
 0x04,0x00,0x4B,0x80,0x20,0x04,0x80,0x4E
};

static unsigned_8 CoffImportPpcPdata[] = {
 0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,
 0x0D,0x00,0x00,0x00
};

static unsigned_8 CoffImportX86Text[] = {
 0xFF,0x25,0x00,0x00,0x00,0x00
};

static void InitCoffFile(coff_lib_file* c_file)
{}

static void SetCoffFile(coff_lib_file* c_file, short processor, unsigned_32 time_stamp, unsigned_16 opt_hdr_size)
{}

static void FiniCoffLibFile(coff_lib_file* c_file)
{}

static void AddCoffString(coff_lib_file* c_file, char* name, int len)
{}

static int AddCoffSection(coff_lib_file* c_file, char* name, unsigned_32 size, unsigned_16 num_relocs, unsigned_32 flags)
{
	return 0;
}

static int AddCoffSymbol(coff_lib_file* c_file, char* name, unsigned_32 value, signed_16 sec_num, unsigned_16 type, unsigned_8 class1, unsigned_8 num_aux)
{
	return 0;
}

static int AddCoffSymSec(coff_lib_file* c_file, unsigned_8 selection, int sec)
{
	return 0;
}

#define IMPLIB_LEN      (*((int*)coff_file_hnd->implib_data))
#define IMPLIB_POS      (*((long*)(coff_file_hnd->implib_data + sizeof(int))))
#define IMPLIB_DATA     (coff_file_hnd->implib_data + sizeof(int) + sizeof(long))

static int DataImpLibInit(coff_file_handle coff_file_hnd)
{
	return(ORL_OKAY);
}

static int AddDataImpLib(coff_file_handle coff_file_hnd, void* buff, int len)
{
	return(ORL_OKAY);
}

static void* ImportLibRead(void* _coff_file_hnd, size_t len)
{
	return NULL;
}

static long ImportLibSeek(void* _coff_file_hnd, long pos, int where)
{
	return 0;
}

static void CreateCoffFileHeader(coff_file_handle coff_file_hnd, coff_lib_file* c_file)
{}

static void CreateCoffSections(coff_file_handle coff_file_hnd, coff_lib_file* c_file)
{}

static void CreateCoffSymbols(coff_file_handle coff_file_hnd, coff_lib_file* c_file)
{}

static void CreateCoffReloc(coff_file_handle coff_file_hnd, unsigned_32 offset, unsigned_32 sym_tab_index, unsigned_16 type)
{}

static void CreateCoffStringTable(coff_file_handle coff_file_hnd, coff_lib_file* c_file)
{}

char* getImportName(char* src, int type)
{
	return NULL;
}

static int CoffCreateImport(coff_file_handle coff_file_hnd, import_sym* import)
{
	return ORL_OKAY;
}

int convert_import_library(coff_file_handle coff_file_hnd)
{
	return ORL_OKAY;
}

orl_funcs ImportLibData = { ImportLibRead, ImportLibSeek, NULL, NULL };
