#include "pch.h"
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "pcobj.h"

orl_handle ORLENTRY ORLInit(orl_funcs* funcs)
{
    orl_handle                  orl_hnd;

    orl_hnd = (orl_handle)funcs->alloc(sizeof(orl_handle_struct));
    if (!orl_hnd) return(NULL);
    orl_hnd->error = ORL_OKAY;
    orl_hnd->funcs = funcs;
    orl_hnd->elf_hnd = ElfInit(funcs);
    if (!(orl_hnd->elf_hnd)) {
        funcs->free(orl_hnd);
        return(NULL);
    }
    orl_hnd->coff_hnd = CoffInit(funcs);
    if (!(orl_hnd->coff_hnd)) {
        funcs->free(orl_hnd);
        return(NULL);
    }
    orl_hnd->omf_hnd = OmfInit(funcs);
    if (!(orl_hnd->omf_hnd)) {
        funcs->free(orl_hnd);
        return(NULL);
    }
    orl_hnd->first_file_hnd = NULL;
    return(orl_hnd);
}

orl_return ORLENTRY ORLFini(orl_handle orl_hnd) {
    orl_return                  error;

    if ((error = ElfFini(orl_hnd->elf_hnd)) != ORL_OKAY) return(error);
    if ((error = CoffFini(orl_hnd->coff_hnd)) != ORL_OKAY) return(error);
    if ((error = OmfFini(orl_hnd->omf_hnd)) != ORL_OKAY) return(error);
    while (orl_hnd->first_file_hnd) {
        error = ORLRemoveFileLinks(orl_hnd->first_file_hnd);
        if (error != ORL_OKAY) return(error);
    }
    orl_hnd->funcs->free(orl_hnd);
    return(ORL_OKAY);
}
