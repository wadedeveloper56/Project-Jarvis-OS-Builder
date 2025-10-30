#pragma once
#include "elftype.h"

elf_handle              ELFENTRY ElfInit(orl_funcs*);
orl_return              ELFENTRY ElfFini(elf_handle);

elf_file_handle         ELFENTRY ElfFileInit(elf_handle, void*);
orl_return              ELFENTRY ElfFileFini(elf_file_handle);
orl_return              ELFENTRY ElfFileScan(elf_file_handle, char*, orl_sec_return_func);
orl_machine_type        ELFENTRY ElfFileGetMachineType(elf_file_handle);
orl_file_flags          ELFENTRY ElfFileGetFlags(elf_file_handle);
orl_file_type           ELFENTRY ElfFileGetType(elf_file_handle);
orl_file_size           ELFENTRY ElfFileGetSize(elf_file_handle);
elf_sec_handle          ELFENTRY ElfFileGetSymbolTable(elf_file_handle);

char* ELFENTRY ElfSecGetName(elf_sec_handle);
orl_sec_offset          ELFENTRY ElfSecGetBase(elf_sec_handle);
orl_sec_size            ELFENTRY ElfSecGetSize(elf_sec_handle);
orl_sec_type            ELFENTRY ElfSecGetType(elf_sec_handle);
orl_sec_flags           ELFENTRY ElfSecGetFlags(elf_sec_handle);
orl_sec_alignment       ELFENTRY ElfSecGetAlignment(elf_sec_handle);
elf_sec_handle          ELFENTRY ElfSecGetStringTable(elf_sec_handle);
elf_sec_handle          ELFENTRY ElfSecGetSymbolTable(elf_sec_handle);
elf_sec_handle          ELFENTRY ElfSecGetRelocTable(elf_sec_handle);
orl_sec_offset          ELFENTRY ElfSecGetNonLocalSymbolLoc(elf_sec_handle);
orl_return              ELFENTRY ElfSecGetContents(elf_sec_handle, char**);
orl_return              ELFENTRY ElfSecQueryReloc(elf_sec_handle, elf_sec_offset, orl_reloc_return_func);
orl_return              ELFENTRY ElfSecScanReloc(elf_sec_handle, orl_reloc_return_func);

orl_table_index         ELFENTRY ElfCvtSecHdlToIdx(elf_sec_handle);
elf_sec_handle          ELFENTRY ElfCvtIdxToSecHdl(elf_file_handle,
    orl_table_index);

orl_return              ELFENTRY ElfRelocSecScan(elf_sec_handle, orl_reloc_return_func);
orl_return              ELFENTRY ElfSymbolSecScan(elf_sec_handle, orl_symbol_return_func);
orl_return              ELFENTRY ElfNoteSecScan(elf_sec_handle, orl_note_callbacks*, void*);

char* ELFENTRY ElfSymbolGetName(elf_symbol_handle);
orl_symbol_value        ELFENTRY ElfSymbolGetValue(elf_symbol_handle);
orl_symbol_binding      ELFENTRY ElfSymbolGetBinding(elf_symbol_handle);
orl_symbol_type         ELFENTRY ElfSymbolGetType(elf_symbol_handle);
unsigned char           ELFENTRY ElfSymbolGetRawInfo(elf_symbol_handle);
elf_sec_handle          ELFENTRY ElfSymbolGetSecHandle(elf_symbol_handle);
elf_symbol_handle       ELFENTRY ElfSymbolGetAssociated(elf_symbol_handle elf_symbol_hnd);

