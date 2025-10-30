#pragma once

/* included in the ORL level through the lower level */
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

/* NB The following are sort of fake.  We are hiding the contents of
   the file-specific section and symbol handles from the ORL
   level, allowing it only to check their type. */
struct orl_sec_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_sec_handle_struct* orl_sec_handle;

struct orl_symbol_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_symbol_handle_struct* orl_symbol_handle;

struct orl_group_handle_struct {
    orl_file_format                     type;
};
typedef struct orl_group_handle_struct* orl_group_handle;

#include "orlcomon.h"
