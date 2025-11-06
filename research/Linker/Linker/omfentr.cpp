#include "pch.h"
#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"
#include "orlhash.h"
#include "omfdrctv.h"

#define _IsSegType( t )     ( ( t == ORL_SEC_TYPE_PROG_BITS ) || ( t == ORL_SEC_TYPE_NO_BITS ) )

omf_handle OMFENTRY OmfInit(orl_funcs* funcs)
{
    assert(funcs);
    omf_handle oh = (omf_handle)funcs->alloc(sizeof(omf_handle_struct));
    if (!oh) return(NULL);
    oh->funcs = funcs;
    oh->first_file_hnd = NULL;
    return(oh);
}
