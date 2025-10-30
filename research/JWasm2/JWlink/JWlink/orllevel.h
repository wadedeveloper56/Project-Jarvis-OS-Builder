#pragma once

#include "orlintnl.h"
#include "cofforl.h"
#include "elforl.h"
#include "omforl.h"

/* NB _handle = a type, _hnd = a variable */

struct orl_handle_struct {
    orl_funcs* funcs;
    elf_handle                          elf_hnd;
    coff_handle                         coff_hnd;
    omf_handle                          omf_hnd;
    struct orl_file_handle_struct* first_file_hnd;
    orl_return                          error;
};

typedef struct orl_handle_struct orl_handle_struct;
typedef orl_handle_struct* orl_handle;

struct orl_file_handle_struct {
    orl_handle                          orl_hnd;
    struct orl_file_handle_struct* next;
    orl_file_format                     type;
    union {
        elf_file_handle                 elf;
        coff_file_handle                coff;
        omf_file_handle                 omf;
    } file_hnd;
};

typedef struct orl_file_handle_struct orl_file_handle_struct;

typedef orl_file_handle_struct* orl_file_handle;
