#include "pch.h"
#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"
#include "orlhash.h"
#include "omfdrctv.h"

#define _IsSegType( t )         ( ( t == ORL_SEC_TYPE_PROG_BITS ) || \
                                  ( t == ORL_SEC_TYPE_NO_BITS ) )

omf_handle OMFENTRY OmfInit(orl_funcs* funcs)
{
    omf_handle                                  oh;

    assert(funcs);

    oh = (omf_handle)funcs->alloc(sizeof(omf_handle_struct));
    if (!oh) return(NULL);
    oh->funcs = funcs;
    oh->first_file_hnd = NULL;
    return(oh);
}


orl_return OMFENTRY OmfFini(omf_handle oh)
{
    orl_return                                  err;

    assert(oh);

    while (oh->first_file_hnd != NULL) {
        err = OmfRemoveFileLinks(oh->first_file_hnd);
        if (err != ORL_OKAY) return(err);
    }
    oh->funcs->free(oh);
    return(ORL_OKAY);
}
