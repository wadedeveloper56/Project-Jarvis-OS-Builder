#include "coffentr.h"
#include "coffflhn.h"
#include "cofflwlv.h"
#include "coffload.h"
#include "orlhash.h"

coff_handle COFFENTRY CoffInit(orl_funcs* funcs)
{
    coff_handle coff_hnd = 0;
    return coff_hnd;
}

orl_return COFFENTRY CoffFini(coff_handle coff_hnd)
{
    return(ORL_OKAY);
}