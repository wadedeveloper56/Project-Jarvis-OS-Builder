#include "pch.h"
#include "elfentr.h"
#include "elfload.h"
#include "elfflhn.h"
#include "elflwlv.h"
#include "orlhash.h"
#include "debug.h"

elf_handle ElfInit(orl_funcs* funcs)
{
	return(NULL);
}

orl_return ElfFini(elf_handle elf_hnd)
{
	return(ORL_OKAY);
}

elf_file_handle ElfFileInit(elf_handle elf_hnd, void* file)
{
	return(NULL);
}

orl_return ElfFileFini(elf_file_handle elf_file_hnd)
{
	return(ORL_OKAY);
}

orl_return ElfFileScan(elf_file_handle elf_file_hnd, unsigned long desired, orl_sec_return_func return_func)
{
	return(ORL_OKAY);
}

orl_machine_type ElfFileGetMachineType(elf_file_handle elf_file_hnd)
{
	return(elf_file_hnd->machine_type);
}

orl_file_flags ElfFileGetFlags(elf_file_handle elf_file_hnd)
{
	return(elf_file_hnd->flags);
}

orl_file_type ElfFileGetType(elf_file_handle elf_file_hnd)
{
	return(elf_file_hnd->type);
}

orl_file_size ElfFileGetSize(elf_file_handle elf_file_hnd)
{
	return(elf_file_hnd->size);
}

elf_sec_handle ElfFileGetSymbolTable(elf_file_handle elf_file_hnd)
{
	return(elf_file_hnd->symbol_table);
}

char* ElfSecGetName(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->name);
}

orl_sec_offset ElfSecGetBase(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->base);
}

orl_sec_size ElfSecGetSize(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->size);
}

orl_sec_type ElfSecGetType(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->type);
}

orl_sec_flags ElfSecGetFlags(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->flags);
}

orl_sec_alignment ElfSecGetAlignment(elf_sec_handle elf_sec_hnd)
{
	return(elf_sec_hnd->alignment);
}

elf_sec_handle ElfSecGetStringTable(elf_sec_handle elf_sec_hnd)
{
	return(NULL);
}

elf_sec_handle ElfSecGetSymbolTable(elf_sec_handle elf_sec_hnd)
{
	return(NULL);
}

elf_sec_handle ElfSecGetRelocTable(elf_sec_handle elf_sec_hnd)
{
	return(NULL);
}

orl_return ElfSecGetContents(elf_sec_handle elf_sec_hnd, char** buffer)
{
	return(ORL_ERROR);
}

orl_return ElfSecQueryReloc(elf_sec_handle elf_sec_hnd, elf_sec_offset sec_offset, orl_reloc_return_func return_func)
{
	return(ORL_ERROR);
}

orl_return ElfSecScanReloc(elf_sec_handle elf_sec_hnd, orl_reloc_return_func return_func)
{
	return(ORL_TRUE);
}

orl_table_index ElfCvtSecHdlToIdx(elf_sec_handle shdl)
{
	return 0;
}

elf_sec_handle ElfCvtIdxToSecHdl(elf_file_handle fhdl, orl_table_index idx)
{
	return 0;
}

orl_return ElfRelocSecScan(elf_sec_handle elf_sec_hnd, orl_reloc_return_func return_func)
{
	return(ORL_TRUE);
}

orl_return ElfSymbolSecScan(elf_sec_handle elf_sec_hnd, orl_symbol_return_func return_func)
{
	return(ORL_OKAY);
}

orl_return ElfNoteSecScan(elf_sec_handle hnd, orl_note_callbacks* cb, void* cookie)
{
	return ORL_OKAY;
}

char* ElfSymbolGetName(elf_symbol_handle elf_symbol_hnd)
{
	return(elf_symbol_hnd->name);
}

orl_symbol_value ElfSymbolGetValue(elf_symbol_handle elf_symbol_hnd)
{
	return(elf_symbol_hnd->value);
}

orl_symbol_binding ElfSymbolGetBinding(elf_symbol_handle elf_symbol_hnd)
{
	return(elf_symbol_hnd->binding);
}

orl_symbol_type ElfSymbolGetType(elf_symbol_handle elf_symbol_hnd)
{
	return(elf_symbol_hnd->type);
}

unsigned char ElfSymbolGetRawInfo(elf_symbol_handle elf_symbol_hnd)
{
	return(elf_symbol_hnd->info);
}

elf_sec_handle ElfSymbolGetSecHandle(elf_symbol_handle elf_symbol_hnd)
{
	return NULL;
}

elf_symbol_handle ElfSymbolGetAssociated(elf_symbol_handle elf_symbol_hnd)
{
	return elf_symbol_hnd;
}
