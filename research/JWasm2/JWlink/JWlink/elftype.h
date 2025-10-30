#pragma once

#include "elfspec.h"

#define ELFENTRY

// handle definitions

typedef uint_8          elf_file_flags;
typedef uint_32         elf_file_index;
typedef uint_32         elf_headers_size;

typedef uint_32         elf_sec_size;
typedef uint_32         elf_sec_flags;
typedef uint_32         elf_sec_offset;

typedef uint_16         elf_reloc_type;

typedef int_32          elf_quantity;

typedef struct elf_handle_struct elf_handle_struct;
typedef elf_handle_struct* elf_handle;

typedef struct elf_file_handle_struct elf_file_handle_struct;
typedef elf_file_handle_struct* elf_file_handle;

typedef struct elf_sec_handle_struct elf_sec_handle_struct;
typedef elf_sec_handle_struct* elf_sec_handle;

typedef struct elf_symbol_handle_struct elf_symbol_handle_struct;
typedef elf_symbol_handle_struct* elf_symbol_handle;

struct elf_handle_struct {
    orl_funcs* funcs;
    elf_file_handle     first_file_hnd;
};

struct elf_file_handle_struct {
    elf_handle          elf_hnd;
    elf_file_handle     next;
    elf_sec_handle* elf_sec_hnd;
    elf_sec_handle* orig_sec_hnd;
    void* file;
    char* contents_buffer1;
    char* contents_buffer2;
    uint16_t            shentsize;
    orl_machine_type    machine_type;
    orl_file_type       type;
    orl_file_size       size;
    orl_file_flags      flags;
    elf_quantity        num_sections;
    elf_sec_handle      symbol_table;
    orl_hash_table      sec_name_hash_table;
};

#define SEC_NAME_HASH_TABLE_SIZE 53

struct elf_normal_assoc_struct {
    elf_sec_handle      reloc_sec;
    char                unused[8];
};

struct elf_reloc_assoc_struct {
    elf_sec_handle      orig_sec;
    elf_sec_handle      symbol_table;
    orl_reloc* relocs;
};

struct elf_sym_assoc_struct {
    elf_sec_handle      string_table;
    elf_symbol_handle   symbols;
    char                unused[4];
};

struct elf_import_assoc_struct {
    elf_sec_handle      string_table;
    char                unused[8];
};

struct elf_export_assoc_struct {
    elf_sec_handle      symbol_table;
    char                unused[8];
};

struct elf_sec_handle_struct {
    orl_file_format     file_format;
    elf_file_handle     elf_file_hnd;
    elf_sec_handle      next;
    char* name;
    orl_sec_size        size;
    orl_file_offset     offset;
    orl_sec_type        type;
    orl_sec_flags       flags;
    orl_sec_alignment   alignment;
    char* contents;
    orl_sec_offset      base;
    elf_quantity        index;
    uint64_t            entsize;
    // assoc - things associated with the section
    union {
        struct elf_normal_assoc_struct  normal;
        struct elf_reloc_assoc_struct   reloc;
        struct elf_sym_assoc_struct     sym;
        struct elf_import_assoc_struct  import;
        struct elf_export_assoc_struct  export1;
    } assoc;
};

struct elf_symbol_handle_struct {
    orl_file_format     file_format;
    elf_file_handle     elf_file_hnd;
    orl_symbol_binding  binding;
    orl_symbol_type     type;
    char* name;
    uint64_t            value;
    uint16_t            shndx;
    uint8_t             info;
};


