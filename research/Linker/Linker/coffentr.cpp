#include "pch.h"
#include "coffentr.h"
#include "coffflhn.h"
#include "cofflwlv.h"
#include "coffload.h"
#include "orlhash.h"

coff_handle CoffInit(orl_funcs* funcs)
{
    assert(funcs);
    coff_handle coff_hnd = (coff_handle)funcs->alloc(sizeof(coff_handle_struct));
    if (!coff_hnd) return(NULL);
    coff_hnd->funcs = funcs;
    coff_hnd->first_file_hnd = NULL;
    return(coff_hnd);
}
