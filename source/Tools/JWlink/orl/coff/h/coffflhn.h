#ifndef COFF_FLHN_INCLUDED
#define COFF_FLHN_INCLUDED

#include "coffglbl.h"

extern void             CoffAddFileLinks( coff_handle, coff_file_handle );
extern orl_return       CoffRemoveFileLinks( coff_file_handle );

#endif
