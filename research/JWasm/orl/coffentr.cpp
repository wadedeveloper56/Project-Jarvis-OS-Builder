#include "coffentr.h"
#include "coffflhn.h"
#include "cofflwlv.h"
#include "coffload.h"
#include "orlhash.h"

coff_handle COFFENTRY CoffInit(orl_funcs* funcs)
{
	coff_handle coff_hnd = (coff_handle)funcs->alloc(sizeof(coff_handle_struct));
	if (!coff_hnd) return(nullptr);
	coff_hnd->funcs = funcs;
	coff_hnd->first_file_hnd = nullptr;
	return(coff_hnd);
}

orl_return COFFENTRY CoffFini(coff_handle coff_hnd)
{
	orl_return error;

	while (coff_hnd->first_file_hnd != nullptr) {
		error = CoffRemoveFileLinks(coff_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	coff_hnd->funcs->free(coff_hnd);
	return(ORL_OKAY);
}
