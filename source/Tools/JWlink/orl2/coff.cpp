#include "pch.h"
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "pcobj.h"

coff_handle CoffInit(orl_funcs* funcs)
{
	coff_handle coff_hnd = (coff_handle)funcs->alloc(sizeof(coff_handle_struct));
	if (!coff_hnd) return(NULL);
	coff_hnd->funcs = funcs;
	coff_hnd->first_file_hnd = NULL;
	return(coff_hnd);
}

orl_return CoffRemoveFileLinks(coff_file_handle coff_file_hnd)
{
	return(ORL_OKAY);
}

orl_return CoffFini(coff_handle coff_hnd)
{
	orl_return error;

	while (coff_hnd->first_file_hnd != NULL)
	{
		error = CoffRemoveFileLinks(coff_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	coff_hnd->funcs->free(coff_hnd);
	return(ORL_OKAY);
}

