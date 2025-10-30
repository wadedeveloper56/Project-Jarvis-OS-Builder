#pragma once

#include "elfglbl.h"

extern orl_return       ElfCreateRelocs(elf_sec_handle, elf_sec_handle);
extern orl_return       ElfCreateSymbolHandles(elf_sec_handle);
extern orl_return       ElfBuildSecNameHashTable(elf_file_handle);
extern orl_reloc_type   ElfConvertRelocType(elf_file_handle, elf_reloc_type);
extern orl_return       ElfParseDrectve(char*, int len, orl_note_callbacks*, void*);

