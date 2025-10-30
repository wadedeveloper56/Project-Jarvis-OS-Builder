#pragma once

#include "coffglbl.h"

extern orl_return               CoffCreateSymbolHandles(coff_file_handle);
extern orl_return               CoffBuildSecNameHashTable(coff_file_handle);
extern orl_return               CoffCreateRelocs(coff_sec_handle,
    coff_sec_handle);
extern orl_reloc_type           CoffConvertRelocType(coff_file_handle,
    coff_reloc_type);
extern orl_linnum* CoffConvertLines(coff_sec_handle,
    orl_table_index);
extern orl_return               CoffParseDrectve(char*, int len,
    orl_note_callbacks*, void*);

