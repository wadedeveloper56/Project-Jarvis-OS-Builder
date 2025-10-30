#pragma once

#include "TRMem.h"

#define MAKE_RELOCS             0x00000001
#define SEARCHING_LIBRARIES     0x00000002
#define LIBRARIES_ADDED         0x00000004
#define LINK_ERROR              0x00000008
#define FMT_SPECIFIED           0x00000010
#define FMT_DECIDED             0x00000020
#define FMT_SEEN_32_BIT         0x00000040
#define FMT_SEEN_IMPORT_CMT     0x00000080
#define PROC_LIBS_ADDED         0x00000100
#define FMT_INITIALIZED         0x00000200
#define UNDEFED_SYM_ERROR       0x00000400
#define GENERATE_LIB_LIST       0x00000800
#define HAVE_16BIT_CODE         0x00001000      // TRUE if we have 16 bit code.
#define HAVE_ALPHA_CODE         0x00002000
#define HAVE_PPC_CODE           0x00004000
#define HAVE_I86_CODE           0x00008000
#define HAVE_MIPS_CODE          0x00010000
#define CAN_REMOVE_SEGMENTS     0x00020000
#define STOP_WORKING            0x00040000      // IDE wants us to stop now
#define INTERNAL_DEBUG          0x00080000
#define GOT_PREV_STRUCTS        0x00100000
#define DOSSEG_FLAG             0x00200000
#define SPEC_ORDER_FLAG         0x00400000
#define FMT_SEEN_64_BIT         0x00800000      /* jwlink */
#define HAVE_MACHTYPE_MASK      (HAVE_I86_CODE | HAVE_ALPHA_CODE | HAVE_PPC_CODE | HAVE_MIPS_CODE)
#define CLEAR_ON_INC    (STOP_WORKING | INTERNAL_DEBUG | GOT_PREV_STRUCTS | MAKE_RELOCS | FMT_SPECIFIED | FMT_DECIDED | FMT_INITIALIZED)
#define ORDER_FLAG_MASK (DOSSEG_FLAG | SPEC_ORDER_FLAG)

typedef unsigned long StateFlag;

extern StateFlag LinkState;
extern TRMem *trmem;