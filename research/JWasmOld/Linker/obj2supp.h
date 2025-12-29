#pragma once

typedef enum {
    FIX_CHANGE_SEG = 0x00000001,   // has to be 1.  used in pointers!
    FIX_ADDEND_ZERO = 0x00000002,
    FIX_UNSAFE = 0x00000004,
    FIX_ABS = 0x00000008,

    FIX_BASE = 0x00000010,
    FIX_HIGH = 0x00000020,
    FIX_REL = 0x00000040,
    FIX_SHIFT = 0x00000080,

    FIX_TARGET_SHIFT = 8,            // contains frame_type
    FIX_TARGET_MASK = 0x00000700,

    FIX_NOADJ = 0x00000800,   // flags no adjustment for FIX_REL

    FIX_NO_BASE = 0x00001000,
    FIX_SIGNED = 0x00002000,
    FIX_LOADER_RES = 0x00004000,
    FIX_SEC_REL = 0x00008000,

    FIX_NO_OFFSET = 0,
    FIX_OFFSET_8 = 0x00010000,   // If a new FIX_OFFSET constant is
    FIX_OFFSET_16 = 0x00020000,   // added, the OffsetSizes array in
    FIX_OFFSET_21 = 0x00030000,   // obj2supp.c also has to be updated!
    FIX_OFFSET_32 = 0x00040000,
    FIX_OFFSET_24 = 0x00050000,
    FIX_OFFSET_26 = 0x00060000,
    FIX_OFFSET_64 = 0x00080000,   // jwlink
    FIX_OFFSET_SHIFT = 16,
    FIX_OFFSET_MASK = 0x000F0000,   // jwlink

    FIX_TOC = 0x00100000,   // PPC PE
    FIX_TOCV = 0x00200000,   // PPC PE
    FIX_IFGLUE = 0x00300000,   // PPC PE
    FIX_SPECIAL_MASK = 0x00300000,

    FIX_FRAME_SHIFT = 24,           // contains frame_type
    FIX_FRAME_MASK = 0x07000000,


    // now for some handy constants which use these

    FIX_BASE_OFFSET_16 = (FIX_BASE | FIX_OFFSET_16),
    FIX_BASE_OFFSET_32 = (FIX_BASE | FIX_OFFSET_32),
    FIX_HIGH_OFFSET_8 = (FIX_HIGH | FIX_OFFSET_8),
    FIX_HIGH_OFFSET_16 = (FIX_HIGH | FIX_OFFSET_16),
} fix_type;

#define FIX_GET_OFFSET(x) (((x) & FIX_OFFSET_MASK) >> FIX_OFFSET_SHIFT)
#define FIX_GET_FRAME(x)  (((x) & FIX_FRAME_MASK) >> FIX_FRAME_SHIFT)
#define FIX_GET_TARGET(x) (((x) & FIX_TARGET_MASK) >> FIX_TARGET_SHIFT)

/* This ordering is roughly the same as intel's - don't mess it up without
   a good reason (and make sure the code that depends on it is fixed!) */

typedef enum {
    FIX_FRAME_SEG,      /* segdata */
    FIX_FRAME_GRP,      /* group_entry */
    FIX_FRAME_EXT,      /* symbol */
    FIX_FRAME_ABS,      /* absolute value */
    FIX_FRAME_LOC,      /* frame containing location */
    FIX_FRAME_TARG,     /* frame same as target */
    FIX_FRAME_FLAT      /* frame is flat group */
} frame_type;

#define FRAME_HAS_DATA( fix ) ((fix) < FIX_FRAME_LOC)

typedef struct {
    union {
        segdata* sdata;
        group_entry* group;
        symbol* sym;
        segment         abs;
        void* ptr;
        unsigned        val;
    } u;
    frame_type  type;
} frame_spec;

typedef struct {
    unsigned_32 flags;
    unsigned_32 off;
    void* target;
} save_fixup;

void ResetObj2Supp(void);
