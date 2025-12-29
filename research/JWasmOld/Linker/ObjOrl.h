#pragma once

#include <stdint.h>
#include "globals.h"
#include "structures.h"
#include "MemorySubsystem.h"

typedef struct readcache READCACHE;

typedef struct readcache {
	READCACHE* next;
	void* data;
} readcache;

#include "orlglobl.h"
#include "orl.h"
#include "MixCache.h"
#include "cofftype.h"
#include "elftype.h"
#include "omftype.h"

#define _HashAlloc( a, b ) a->funcs->memory->AllocateMemory( b )
#define _HashFree( a, b ) a->funcs->memory->FreeMemory( b )
#define _HashCompare( a, b, c ) a->compare( b, c )

class ObjOrl
{
	orl_funcs ORLFuncs;
	orl_reloc SavedReloc;
	orl_handle ORLHandle;
	long ORLFilePos;
	char* ImpExternalName;
	char* ImpModName;
	char* FirstCodeSymName;
	char* FirstDataSymName;
	unsigned_32      ImpOrdinal;
	readcache* ReadCacheList;
	MemorySubsystem* memory;
	MixCache* mixcache;
	FileSubsystem* file;
	TokenBuffer* tokenBuffer;
public:
	ObjOrl(MemorySubsystem* memory, FileSubsystem* file, TokenBuffer* tokenBuffer);
	~ObjOrl();
	long seek(void* _list, long pos, int where);
	void* read(void* _list, size_t len);
private:
	orl_handle ORLInit(orl_funcs* funcs);
	elf_handle ElfInit(orl_funcs* funcs);
	coff_handle CoffInit(orl_funcs* funcs);
	omf_handle OmfInit(orl_funcs* funcs);
	
	orl_return ORLFini(orl_handle orl_hnd);
	orl_return ElfFini(elf_handle elf_hnd);
	orl_return CoffFini(coff_handle coff_hnd);
	orl_return OmfFini(omf_handle oh);

	orl_return ORLRemoveFileLinks(orl_file_handle orl_file_hnd);
	orl_return ElfRemoveFileLinks(elf_file_handle elf_file_hnd);
	orl_return OmfRemoveFileLinks(omf_file_handle ofh);
	orl_return CoffRemoveFileLinks(coff_file_handle coff_file_hnd);

	void free_orl_file_hnd(orl_file_handle orl_file_hnd);
	void free_elf_file_hnd(elf_file_handle elf_file_hnd);
	void free_coff_file_hnd(coff_file_handle coff_file_hnd);
	
	orl_return freeFileHandle(omf_file_handle ofh);

	void ORLHashTableFree(orl_hash_table hash_table);
};

