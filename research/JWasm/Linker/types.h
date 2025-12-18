#pragma once

typedef unsigned long stateflag;
typedef unsigned char   uint_8;
typedef unsigned short  uint_16;
typedef unsigned int    uint_32;

typedef unsigned char   unsigned_8;
typedef unsigned short  unsigned_16;
typedef unsigned int    unsigned_32;

typedef signed char     int_8;
typedef signed short    int_16;
typedef signed int      int_32;

typedef signed char     signed_8;
typedef signed short    signed_16;
typedef signed int      signed_32;

typedef unsigned_32 offset;
typedef unsigned_16 segment;
typedef unsigned long   virt_mem;

typedef enum mapflag {
    MAP_FLAG = 0x0001,
    MAP_STATICS = 0x0002,       // put statics in the map file
    MAP_ARTIFICIAL = 0x0004,       // put artificial syms in the map file
    MAP_SORT = 0x0008,       // sort symbols in the map file
    MAP_ALPHA = 0x0010,       // sort symbols in alphabetical order
    MAP_GLOBAL = 0x0020,       // sort symbols globally.
    MAP_VERBOSE = 0x0040
} mapflag; 

typedef struct targ_addr {
    offset              off;
    segment             seg;
} targ_addr;

/*------------------ Linker Global State Flags -----------------------*/
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
#define HAVE_16BIT_CODE         0x00001000      // true if we have 16 bit code.
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

typedef unsigned long linkflag;

#define DWARF_DBI_FLAG  0x00000001UL    // set if making DWARF debug info
#define STK_SIZE_FLAG   0x00000002UL
#define GOT_CHGD_FILES  0x00000004UL
#define TRACE_FLAG      0x00000008UL
#define __UNUSED_FLAG_0 0x00000010UL
#define CV_DBI_FLAG     0x00000020UL
#define UNDEFS_ARE_OK   0x00000040UL
#define REDEFS_OK       0x00000080UL
#define QUIET_FLAG      0x00000100UL
#define PACKCODE_FLAG   0x00000200UL    // set if packcode specified
#define VF_REMOVAL      0x00000400UL
#define NOVELL_DBI_FLAG 0x00000800UL    // set if generating novell debug info
#define PACKDATA_FLAG   0x00001000UL
#define CASE_FLAG       0x00002000UL    // set for case sensitive operation
#define OLD_DBI_FLAG    0x00004000UL    // set if making WATCOM debug info
#define SHOW_DEAD       0x00008000UL
#define STRIP_CODE      0x00010000UL    // strip dead code.
#define CVPACK_FLAG     0x00020000UL
#define MAX_ERRORS_FLAG 0x00040000UL    // there is a max. number of errors.
#define DONT_UNMANGLE   0x00080000UL    // don't unmangle the names
#define INC_LINK_FLAG   0x00100000UL
#define NOCACHE_FLAG    0x00200000UL
#define CACHE_FLAG      0x00400000UL
#define FAR_CALLS_FLAG  0x00800000UL    // optimize far calls
#define __UNUSED_FLAG_8 0x01000000UL
#define __UNUSED_FLAG_7 0x02000000UL
#define __UNUSED_FLAG_6 0x04000000UL
#define __UNUSED_FLAG_5 0x08000000UL
#define __UNUSED_FLAG_4 0x10000000UL
#define __UNUSED_FLAG_3 0x20000000UL
#define __UNUSED_FLAG_2 0x40000000UL
#define __UNUSED_FLAG_1 0x80000000UL
