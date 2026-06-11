#include "pch.h"
#include <ctype.h>
#include "cofflwlv.h"
#include "orlhash.h"
#include "walloca.h"
#ifdef _BSD_SOURCE
#define stricmp strcasecmp
#endif

#define BS_ORE(type,a,b,c) (a=((type)((a)|(c))))

orl_return CoffCreateSymbolHandles(coff_file_handle file_hnd)
{
	return(ORL_OKAY);
}

orl_return CoffBuildSecNameHashTable(coff_file_handle coff_file_hnd)
{
	return(ORL_OKAY);
}

orl_reloc_type CoffConvertRelocType(coff_file_handle coff_file_hnd, coff_reloc_type coff_type)
{
	return((orl_reloc_type)0);
}

orl_return CoffCreateRelocs(coff_sec_handle orig_sec, coff_sec_handle reloc_sec)
{
	return(ORL_OKAY);
}

orl_linnum* CoffConvertLines(coff_sec_handle hdl, orl_table_index numlines)
{
	return NULL;
}

static void EatWhite(char** contents, int* len)
{}

static orl_return ParseLnkCmd(char* cmd, char** contents, int* len, orl_return(*callback_fn)(char*, char*, void*), void* cookie)
{
	return(ORL_OKAY);
}

orl_return CoffParseDrectve(char* contents, int len, orl_note_callbacks* cb, void* cookie)
{
	return(ORL_OKAY);
}
