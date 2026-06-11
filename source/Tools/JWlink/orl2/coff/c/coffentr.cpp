#include "pch.h"
#include "coffentr.h"
#include "coffflhn.h"
#include "cofflwlv.h"
#include "coffload.h"
#include "orlhash.h"
#include "debug.h"

coff_handle CoffInit(orl_funcs* funcs)
{
	return(NULL);
}

orl_return CoffFini(coff_handle coff_hnd)
{
	return(ORL_OKAY);
}

coff_file_handle CoffFileInit(coff_handle coff_hnd, void* file)
{
	return(NULL);
}

orl_return CoffFileFini(coff_file_handle coff_file_hnd)
{
	return(ORL_OKAY);
}

orl_return CoffFileScan(coff_file_handle coff_file_hnd, unsigned long desired, orl_sec_return_func return_func)
{
	return(ORL_OKAY);
}

unsigned long CoffExportTableRVA(coff_file_handle coff_file_hnd)
{
	return coff_file_hnd->export_table_rva;
}

orl_machine_type CoffFileGetMachineType(coff_file_handle coff_file_hnd)
{
	return(coff_file_hnd->machine_type);
}

orl_file_flags CoffFileGetFlags(coff_file_handle coff_file_hnd)
{
	return(coff_file_hnd->flags);
}

orl_file_type CoffFileGetType(coff_file_handle coff_file_hnd)
{
	return(coff_file_hnd->type);
}

orl_file_size CoffFileGetSize(coff_file_handle coff_file_hnd)
{
	return(coff_file_hnd->size);
}

coff_sec_handle CoffFileGetSymbolTable(coff_file_handle coff_file_hnd)
{
	return(coff_file_hnd->symbol_table);
}


coff_sec_handle CoffSecGetStringTable(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->coff_file_hnd->string_table);
}

coff_sec_handle CoffSecGetSymbolTable(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->coff_file_hnd->symbol_table);
}

char* CoffSecGetName(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->name);
}

orl_sec_offset CoffSecGetBase(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->base);
}

orl_sec_size CoffSecGetSize(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->size);
}

orl_sec_type CoffSecGetType(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->type);
}

orl_sec_flags CoffSecGetFlags(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->flags);
}

orl_sec_alignment CoffSecGetAlignment(coff_sec_handle coff_sec_hnd)
{
	return(coff_sec_hnd->align);
}

coff_sec_handle CoffSecGetRelocTable(coff_sec_handle coff_sec_hnd)
{
	return(NULL);
}

orl_table_index offSecGetNumLines(coff_sec_handle coff_sec_hnd)
{
	return(0);
}

orl_linnum* CoffSecGetLines(coff_sec_handle coff_sec_hnd)
{
	return(NULL);
}

orl_sec_offset CoffSecGetOffset(coff_sec_handle coff_sec_hnd)
{
	return(0);
}

orl_return CoffSecGetContents(coff_sec_handle coff_sec_hnd, char** buffer)
{
	return(ORL_OKAY);
}

orl_return CoffSecQueryReloc(coff_sec_handle coff_sec_hnd, coff_sec_offset sec_offset, orl_reloc_return_func return_func)
{
	return(ORL_OKAY);
}

orl_table_index CoffCvtSecHdlToIdx(coff_sec_handle shdl)
{
	return 0;
}

coff_sec_handle CoffCvtIdxToSecHdl(coff_file_handle fhdl, orl_table_index idx)
{
	return fhdl->orig_sec_hnd[idx - 1];
}

orl_return CoffSecScanReloc(coff_sec_handle coff_sec_hnd, orl_reloc_return_func return_func)
{
	return(ORL_OKAY);
}

orl_return CoffRelocSecScan(coff_sec_handle coff_sec_hnd, orl_reloc_return_func return_func)
{
	return(ORL_OKAY);
}

orl_return CoffSymbolSecScan(coff_sec_handle coff_sec_hnd, orl_symbol_return_func return_func)
{
	return(ORL_OKAY);
}

orl_return CoffNoteSecScan(coff_sec_handle hnd, orl_note_callbacks* cb, void* cookie)
{
	return ORL_OKAY;
}

char* CoffSymbolGetName(coff_symbol_handle coff_symbol_hnd)
{
	return(coff_symbol_hnd->name);
}

orl_symbol_value CoffSymbolGetValue(coff_symbol_handle coff_symbol_hnd)
{
	return(coff_symbol_hnd->symbol->value);
}

orl_symbol_binding CoffSymbolGetBinding(coff_symbol_handle coff_symbol_hnd)
{
	return(coff_symbol_hnd->binding);
}

orl_symbol_type CoffSymbolGetType(coff_symbol_handle coff_symbol_hnd)
{
	return(coff_symbol_hnd->type);
}

coff_sec_handle CoffSymbolGetSecHandle(coff_symbol_handle coff_symbol_hnd)
{
	return(NULL);
}

coff_symbol_handle CoffSymbolGetAssociated(coff_symbol_handle hnd)
{
	return NULL;
}

