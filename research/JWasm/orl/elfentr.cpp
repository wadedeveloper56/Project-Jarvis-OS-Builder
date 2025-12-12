#include "elfentr.h"
#include "elfload.h"
#include "elfflhn.h"
#include "elflwlv.h"
#include "orlhash.h"

elf_handle ELFENTRY ElfInit(orl_funcs* funcs)
{
    elf_handle elf_hnd = (elf_handle)funcs->alloc(sizeof(elf_handle_struct));
    if (!elf_hnd) return(nullptr);
    elf_hnd->funcs = funcs;
    elf_hnd->first_file_hnd = nullptr;
    return elf_hnd;
}

orl_return ELFENTRY ElfFini(elf_handle elf_hnd)
{
    orl_return error;

    while (elf_hnd->first_file_hnd != nullptr) {
        error = ElfRemoveFileLinks(elf_hnd->first_file_hnd);
        if (error != ORL_OKAY) return(error);
    }
    elf_hnd->funcs->free(elf_hnd);
    return ORL_OKAY;
}
