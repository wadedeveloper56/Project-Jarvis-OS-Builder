#include <assert.h>
#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"
#include "orlhash.h"
#include "omfdrctv.h"

omf_handle OMFENTRY OmfInit(orl_funcs* funcs)
{
	assert(funcs);
	omf_handle oh = (omf_handle)funcs->alloc(sizeof(omf_handle_struct));
	if (!oh) return(nullptr);
	oh->funcs = funcs;
	oh->first_file_hnd = nullptr;
	return(oh);
}

orl_return OMFENTRY OmfFini(omf_handle oh)
{
	assert(oh);
	orl_return err;
	while (oh->first_file_hnd != nullptr) {
		err = OmfRemoveFileLinks(oh->first_file_hnd);
		if (err != ORL_OKAY) return(err);
	}
	oh->funcs->free(oh);
	return(ORL_OKAY);
}

