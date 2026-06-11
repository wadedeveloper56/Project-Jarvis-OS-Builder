#include "pch.h"
#ifdef _INT_DEBUG
#include <stddef.h>
#endif

#include "coffload.h"
#include "coffimpl.h"

#include "debug.h"

#define BS_ORE(type,a,b,c) (a=((type)((a)|(c))))

static char SectionNames[3][COFF_SEC_NAME_LEN] =
{ ".rel", ".symtab", ".strtab" };

static int determine_file_specs(coff_file_handle coff_file_hnd, coff_file_header* f_hdr)
{
	return(ORL_OKAY);
}

static void determine_section_specs(coff_sec_handle coff_sec_hnd, coff_section_header* s_hdr)
{}

static void free_coff_sec_handles(coff_file_handle coff_file_hnd, int num_alloced)
{}

static orl_return load_coff_sec_handles(coff_file_handle coff_file_hnd, coff_file_header* f_hdr)
{
	return(ORL_OKAY);
}

orl_return CoffLoadFileStructure(coff_file_handle coff_file_hnd)
{
	return(ORL_OKAY);
}
