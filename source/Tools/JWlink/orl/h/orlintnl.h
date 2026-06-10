
#ifndef ORL_INTERNAL_INCLUDED
#define ORL_INTERNAL_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orlglobl.h"
#include "orlhshdf.h"

#if !defined( __386__ ) && !defined( __GNUC__ )
#define ORLUNALIGNED 
//__unaligned
#else
#define ORLUNALIGNED
#endif

struct orl_sec_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_sec_handle_struct * orl_sec_handle;

struct orl_symbol_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_symbol_handle_struct * orl_symbol_handle;

struct orl_group_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_group_handle_struct * orl_group_handle;

#include "orlcomon.h"

#endif
