#include "pch.h"
#include <assert.h>
#include <ctype.h>
#include "walloca.h"
#include "elflwlv.h"
#include "orlhash.h"
#include "debug.h"
#ifdef _BSD_SOURCE
#define stricmp strcasecmp
#endif

#define BS_ORE(type,a,b,c) (a=((type)((a)|(c))))

static void fix_sym_byte_order(elf_file_handle elf_file_hnd, Elf32_Sym* e_sym)
{}

static void fix_sym64_byte_order(elf_file_handle elf_file_hnd, Elf64_Sym* e_sym)
{}


static void fix_rel_byte_order(elf_file_handle elf_file_hnd, Elf32_Rel* e_rel)
{}


static void fix_rela_byte_order(elf_file_handle elf_file_hnd, Elf32_Rela* e_rela)
{}


static void fix_rel64_byte_order(elf_file_handle elf_file_hnd, Elf64_Rel* e_rel)
{}


static void fix_rela64_byte_order(elf_file_handle elf_file_hnd, Elf64_Rela* e_rela)
{}


orl_return ElfCreateSymbolHandles(elf_sec_handle elf_sec_hnd)
{
	return(ORL_OKAY);
}


orl_return ElfBuildSecNameHashTable(elf_file_handle elf_file_hnd)
{
	return(ORL_OKAY);
}


static orl_reloc_type convertPPCReloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


static orl_reloc_type convert386Reloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


static orl_reloc_type convertAMD64Reloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


static orl_reloc_type convertSPARCReloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


static orl_reloc_type convertMIPSReloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


static orl_reloc_type convertAlphaReloc(elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


orl_reloc_type ElfConvertRelocType(elf_file_handle elf_file_hnd, elf_reloc_type elf_type)
{
	return(ORL_RELOC_TYPE_NONE);
}


orl_return ElfCreateRelocs(elf_sec_handle orig_sec, elf_sec_handle reloc_sec)
{
	return(ORL_OKAY);
}

static void EatWhite(char** contents, int* len)
{}

static orl_return ParseLnkCmd(char* cmd, char** contents, int* len, orl_return(*callback_fn)(char*, char*, void*), void* cookie)
{
	return(ORL_OKAY);
}

orl_return ElfParseDrectve(char* contents, int len, orl_note_callbacks* cb, void* cookie)
{
	return(ORL_OKAY);
}
