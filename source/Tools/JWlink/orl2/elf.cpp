#include "pch.h"
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "pcobj.h"

elf_handle ElfInit(orl_funcs* funcs)
{
	elf_handle elf_hnd = (elf_handle)funcs->alloc(sizeof(elf_handle_struct));
	if (!elf_hnd) return(NULL);
	elf_hnd->funcs = funcs;
	elf_hnd->first_file_hnd = NULL;
	return(elf_hnd);
}

orl_return ElfRemoveFileLinks(elf_file_handle elf_file_hnd)
{
	return(ORL_OKAY);
}

orl_return ElfFini(elf_handle elf_hnd)
{
	orl_return error;

	while (elf_hnd->first_file_hnd != NULL)
	{
		error = ElfRemoveFileLinks(elf_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	elf_hnd->funcs->free(elf_hnd);
	return(ORL_OKAY);
}

