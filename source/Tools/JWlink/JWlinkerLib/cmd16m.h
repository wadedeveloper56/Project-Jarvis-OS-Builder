#pragma once

#define TRANSPARENT 0x8000

#define NUM_RESERVED_SELS    16         // number of reserved selectors.

/* memory strategy constants */
#define MPreferExt      0       /* prefer, but not force, extended */
#define MPreferLow      1       /* prefer, but not force, conventional memory */
#define MForceExt       2       /* force extended */
#define MForceLow       3       /* force conventional */
#define MNoStrategy     0       /* no strategy specified */

#define D16M_ACC_CODE   0x9A    /* present, DPL 0, code, read, not accessed */
#define D16M_ACC_DATA   0x92    /* present, DPL 0, data, write, not accessed */

#define D16M_USER_SEL   0x80    /* first user selector (user_gdt << 3) */

#define DOS16M_SIGNATURE    0x5742      /* 'BW' */

#include <memory>
#include "MemorySubsystem.h"

using namespace std;

void SetD16MFmt(void);
void FreeD16MFmt(shared_ptr<MemorySubsystem> memorySubsystem);