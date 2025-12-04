#include "elfentr.h"
#include "elfload.h"
#include "elfflhn.h"
#include "elflwlv.h"
#include "orlhash.h"

elf_handle ELFENTRY ElfInit(orl_funcs* funcs)
{
    elf_handle elf_hnd =0;
    return elf_hnd;
}

orl_return ELFENTRY ElfFini(elf_handle elf_hnd)
{
    return(ORL_OKAY);
}
