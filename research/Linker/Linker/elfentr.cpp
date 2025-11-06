#include "pch.h"
#include "elfentr.h"
#include "elfload.h"
#include "elfflhn.h"
#include "elflwlv.h"
#include "orlhash.h"

elf_handle ElfInit(orl_funcs* funcs)
{
    assert(funcs);
    elf_handle elf_hnd = (elf_handle)funcs->alloc(sizeof(elf_handle_struct));
    if (!elf_hnd) return(NULL);
    elf_hnd->funcs = funcs;
    elf_hnd->first_file_hnd = NULL;
    return(elf_hnd);
}
