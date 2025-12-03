#pragma once

#include "types.h"

typedef unsigned_32 offset;
typedef unsigned_16 segment;

typedef struct targ_addr {
    offset              off;
    segment             seg;
} targ_addr;
