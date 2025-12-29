#pragma once

#define PE_DEFAULT_BASE (0x400000UL)
#define PE_DEFAULT_BASE_DLL (0x10000000UL) /* jwlink */
#define PE_DEF_STACK_COMMIT (0xFFFFFFFFUL)

struct import_name {
    struct import_name* next;
    dll_sym_info* dll;
    name_list* imp;
};

typedef struct module_import {
    struct module_import* next;
    struct name_list* mod;
    struct import_name* imports;
    unsigned                    num_entries;
} module_import;

void ResetLoadPE(void);


