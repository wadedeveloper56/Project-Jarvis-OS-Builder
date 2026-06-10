
#ifndef ELF_FLHN_INCLUDED
#define ELF_FLHN_INCLUDED

#include "elfglbl.h"

extern void                     ElfAddFileLinks( elf_handle, elf_file_handle );
extern orl_return               ElfRemoveFileLinks( elf_file_handle );

#endif
