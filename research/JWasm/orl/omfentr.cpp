#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"
#include "orlhash.h"
#include "omfdrctv.h"

omf_handle OMFENTRY OmfInit(orl_funcs* funcs)
{
    omf_handle  oh = 0;
    return(oh);
}

orl_return OMFENTRY OmfFini(omf_handle oh)
{
    return(ORL_OKAY);
}
