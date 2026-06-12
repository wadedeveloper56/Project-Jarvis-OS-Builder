#include "pch.h"
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "pcobj.h"

omf_handle OmfInit(orl_funcs* funcs)
{
	omf_handle oh = (omf_handle)funcs->alloc(sizeof(omf_handle_struct));
	if (!oh) return(NULL);
	oh->funcs = funcs;
	oh->first_file_hnd = NULL;
	return(oh);
}

orl_return OmfRemoveFileLinks(omf_file_handle ofh)
{
	return(ORL_OKAY);
}

orl_return OmfFini(omf_handle oh)
{
	orl_return err;

	while (oh->first_file_hnd != NULL)
	{
		err = OmfRemoveFileLinks(oh->first_file_hnd);
		if (err != ORL_OKAY) return(err);
	}
	oh->funcs->free(oh);
	return(ORL_OKAY);
}

