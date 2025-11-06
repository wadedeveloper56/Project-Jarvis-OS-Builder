#pragma once

#include "orlglobl.h"

typedef struct orl_handle_struct* orl_handle;
typedef struct orl_file_handle_struct* orl_file_handle;
typedef struct orl_sec_handle_struct* orl_sec_handle;
typedef struct orl_symbol_handle_struct* orl_symbol_handle;
typedef struct orl_group_handle_struct* orl_group_handle;

void* read(void*, size_t);
long int seek(void*, long int, int);
void* alloc(size_t);
void  free(void*);
