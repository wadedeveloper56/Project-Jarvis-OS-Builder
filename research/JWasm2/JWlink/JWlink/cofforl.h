#pragma once

#include "cofftype.h"

coff_handle             COFFENTRY CoffInit(orl_funcs*);
orl_return              COFFENTRY CoffFini(coff_handle);

coff_file_handle        COFFENTRY CoffFileInit(coff_handle, void*);
orl_return              COFFENTRY CoffFileFini(coff_file_handle);
orl_return              COFFENTRY CoffFileScan(coff_file_handle, char*, orl_sec_return_func);
orl_machine_type        COFFENTRY CoffFileGetMachineType(coff_file_handle);
orl_file_flags          COFFENTRY CoffFileGetFlags(coff_file_handle);
orl_file_type           COFFENTRY CoffFileGetType(coff_file_handle);
orl_file_size           COFFENTRY CoffFileGetSize(coff_file_handle);
coff_sec_handle         COFFENTRY CoffFileGetSymbolTable(coff_file_handle);

char* COFFENTRY CoffSecGetName(coff_sec_handle);
orl_sec_offset          COFFENTRY CoffSecGetBase(coff_sec_handle);
orl_sec_size            COFFENTRY CoffSecGetSize(coff_sec_handle);
orl_sec_type            COFFENTRY CoffSecGetType(coff_sec_handle);
orl_sec_flags           COFFENTRY CoffSecGetFlags(coff_sec_handle);
orl_sec_alignment       COFFENTRY CoffSecGetAlignment(coff_sec_handle);
coff_sec_handle         COFFENTRY CoffSecGetStringTable(coff_sec_handle);
coff_sec_handle         COFFENTRY CoffSecGetSymbolTable(coff_sec_handle);
coff_sec_handle         COFFENTRY CoffSecGetRelocTable(coff_sec_handle);
orl_linnum* COFFENTRY CoffSecGetLines(coff_sec_handle);
orl_table_index         COFFENTRY CoffSecGetNumLines(coff_sec_handle);
orl_sec_offset          COFFENTRY CoffSecGetOffset(coff_sec_handle);
orl_return              COFFENTRY CoffSecGetContents(coff_sec_handle, char**);
orl_return              COFFENTRY CoffSecQueryReloc(coff_sec_handle, coff_sec_offset, orl_reloc_return_func);
orl_return              COFFENTRY CoffSecScanReloc(coff_sec_handle, orl_reloc_return_func);

orl_table_index         COFFENTRY CoffCvtSecHdlToIdx(coff_sec_handle);
coff_sec_handle         COFFENTRY CoffCvtIdxToSecHdl(coff_file_handle,
    orl_table_index);

orl_return              COFFENTRY CoffRelocSecScan(coff_sec_handle,
    orl_reloc_return_func);
orl_return              COFFENTRY CoffSymbolSecScan(coff_sec_handle,
    orl_symbol_return_func);
orl_return              COFFENTRY CoffNoteSecScan(coff_sec_handle,
    orl_note_callbacks*, void*);

char* COFFENTRY CoffSymbolGetName(coff_symbol_handle);
orl_symbol_value        COFFENTRY CoffSymbolGetValue(coff_symbol_handle);
orl_symbol_binding      COFFENTRY CoffSymbolGetBinding(coff_symbol_handle);
orl_symbol_type         COFFENTRY CoffSymbolGetType(coff_symbol_handle);
coff_sec_handle         COFFENTRY CoffSymbolGetSecHandle(coff_symbol_handle);
coff_symbol_handle      COFFENTRY CoffSymbolGetAssociated(coff_symbol_handle);

unsigned long           COFFENTRY CoffExportTableRVA(coff_file_handle);

