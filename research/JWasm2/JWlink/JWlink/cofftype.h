#pragma once

#include "coff.h"

#define COFFENTRY

// handle definitions

typedef enum {
    COFF_FALSE = 0,
    COFF_TRUE = 1
} coff_bool;

typedef uint_8                          coff_file_flags;
typedef uint_32                         coff_file_index;
typedef uint_32                         coff_headers_size;

typedef uint_32                         coff_sec_size;
typedef uint_32                         coff_sec_flags;
typedef uint_32                         coff_sec_offset;

typedef uint_16                         coff_reloc_type;

typedef uint_32                         coff_symbol_table_index;
typedef uint_32                         coff_symbol_type;
typedef uint_32                         coff_symbol_value;
typedef uint_32                         coff_symbol_storage_class;
typedef uint_32                         coff_function_size;
typedef uint_32                         coff_symbol_characteristics;
typedef uint_32                         coff_comdat_checksum;
typedef uint_8                          coff_comdat_selection;

typedef uint_32                         coff_quantity;

typedef struct coff_handle_struct       coff_handle_struct;
typedef coff_handle_struct* coff_handle;

typedef struct coff_file_handle_struct  coff_file_handle_struct;
typedef coff_file_handle_struct* coff_file_handle;

typedef struct coff_sec_handle_struct   coff_sec_handle_struct;
typedef coff_sec_handle_struct* coff_sec_handle;

typedef struct coff_symbol_handle_struct coff_symbol_handle_struct;
typedef coff_symbol_handle_struct* coff_symbol_handle;

struct coff_handle_struct {
    orl_funcs* funcs;
    coff_file_handle    first_file_hnd;
};

struct coff_file_handle_struct {
    coff_handle         coff_hnd;
    coff_file_handle    next;
    coff_sec_handle* coff_sec_hnd;
    coff_sec_handle* orig_sec_hnd;
    void* file;
    coff_quantity       initial_size;
    coff_file_header* f_hdr_buffer;
    char* s_hdr_table_buffer;
    char* rest_of_file_buffer;
    orl_machine_type    machine_type;
    orl_file_type       type;
    orl_file_size       size;
    orl_file_flags      flags;
    coff_quantity       num_sections;
    coff_quantity       num_symbols;
    coff_symbol_handle  symbol_handles;
    coff_sec_handle     symbol_table;
    coff_sec_handle     string_table;
    orl_hash_table      sec_name_hash_table;
    unsigned long       export_table_rva;
    char* implib_data;
};

#define SEC_NAME_HASH_TABLE_SIZE 53

struct coff_normal_assoc_struct {
    coff_sec_handle     reloc_sec;
};

struct coff_reloc_assoc_struct {
    coff_sec_handle     orig_sec;
    unsigned            num_relocs;
    orl_reloc* relocs;
};

struct coff_sec_handle_struct {
    orl_file_format     file_format;
    coff_file_handle    coff_file_hnd;
    coff_sec_handle     next;
    char* name;
    orl_sec_size        size;
    orl_file_offset     offset;
    orl_sec_type        type;
    orl_sec_flags       flags;
    orl_sec_alignment   align;
    char* contents;
    coff_section_header* hdr;
    orl_sec_offset      base;
    union {
        struct coff_normal_assoc_struct         normal;
        struct coff_reloc_assoc_struct          reloc;
    } assoc;
    coff_bool           name_alloced : 1;
    coff_bool           relocs_done : 1;
};

struct coff_symbol_handle_struct {
    orl_file_format     file_format;
    coff_file_handle    coff_file_hnd;
    orl_symbol_binding  binding;
    orl_symbol_type     type;
    coff_symbol ORLUNALIGNED* symbol;
    char* name;
    unsigned            name_alloced : 1;
    unsigned            has_bf : 1;
};

typedef struct pe_header_struct pe_header;

struct pe_header_struct {
    char        MZ[2];
    char        space[0x3a];
    short       offset;
};

typedef struct pe_opt_hdr_struct pe_opt_hdr;

struct pe_opt_hdr_struct
{
    unsigned short magic;
    char           space[94];
    unsigned long  export_table_rva;
};

/*
// these may be useless, or they might come in handy sometime

typedef enum {
    COFF_AUX_SYMBOL_FUNCDEF,
    COFF_AUX_SYMBOL_BFEF,
    COFF_AUX_SYMBOL_WEAK_EXTERN,
    COFF_AUX_SYMBOL_FILE,
    COFF_AUX_SYMBOL_SECDEF
} coff_aux_symbol_type;

struct coff_aux_symbol_struct {
    coff_aux_symbol_type                                type;
    struct coff_aux_symbol_struct *                     next;
    union {
        struct coff_aux_symbol_func_def_struct *        func_def;
        struct coff_aux_symbol_bfef_struct *            bfef;
        struct coff_aux_symbol_weak_extern_struct *     weak_extern;
        struct coff_aux_symbol_file_struct *            file;
        struct coff_aux_symbol_sec_def_struct *         sec_def;
    };
};

struct coff_aux_symbol_func_def_struct {
    coff_symbol_table_index     bf_symbol;
    coff_function_size          function_size;
    coff_symbol_table_index     next_function;
};

struct coff_aux_symbol_bfef_struct {
    coff_line_number            line_number;
    coff_symbol_table_index     next_function;
};

struct coff_aux_symbol_weak_extern_struct {
    coff_symbol_table_index     symbol_2;
    coff_symbol_characteristics characteristics;
};

struct coff_aux_symbol_file_struct {
    char        filename[18];
};

struct coff_aux_symbol_sec_def_struct {
    coff_sec_size               size;
    coff_quantity               num_relocs;
    coff_quantity               num_line_numbers;
    coff_comdat_checksum        checksum;
    coff_sec_handle             coff_sec_hnd;
    coff_comdat_selection       selection;
};
*/
