#include "pch.h"
#include "linkstd.h"
#include "exeos2.h"
#include "loados2.h"
#include "exepe.h"
#include "reloc.h"
#include "specials.h"
#include "alloc.h"
#include "pcobj.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "virtmem.h"
#include "objnode.h"
#include "loadfile.h"
#include "objcalc.h"
#include "fileio.h"
#include "dbgcomm.h"
#include "dbgall.h"
#include "dbgcv.h"
#include "objpass1.h"
#include "ring.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "loadpe.h"
#include "reserr.h"
#include "wres.h"
#include "exerespe.h"
#include "param.h"
#include "pass2.h"
#include "sharedio.h"
#include "impexp.h"
#include "toc.h"
#include "objstrip.h"

#define I386_TRANSFER_OP1       0xff    /* first byte of a "JMP [FOO]" */
#define I386_TRANSFER_OP2       0x25    /* second byte of a "JMP [FOO]" */

#define MINIMUM_SEG_SHIFT       2       /* Corresponds to 2^2 == 4 bytes */
#define DEFAULT_SEG_SHIFT       9       /* Corresponds to 2^9 == 512 bytes */

#define STUB_ALIGN 8    /* for PE format */

#pragma pack(1)

typedef struct {
    unsigned_8  op1;
    unsigned_8  op2;
    unsigned_32 dest;
} i386_transfer;

static i386_transfer    I386Jump = { I386_TRANSFER_OP1, I386_TRANSFER_OP2, 0 };

#define I386_TRANSFER_SIZE (sizeof(i386_transfer))

#define ALPHA_TRANSFER_OP1      0x277F
#define ALPHA_TRANSFER_OP2      0xA37B
#define ALPHA_TRANSFER_OP3      0x6BFB

typedef struct {
    unsigned_16 high;
    unsigned_16 op1;
    unsigned_16 low;
    unsigned_16 op2;
    unsigned_16 zero;
    unsigned_16 op3;
} alpha_transfer;

#pragma pack()

typedef struct local_import {
    struct local_import* next;
    symbol* iatsym;
    symbol* locsym;
} local_import;

static alpha_transfer   AlphaJump = { 0, ALPHA_TRANSFER_OP1,
                                        0, ALPHA_TRANSFER_OP2,
                                        0, ALPHA_TRANSFER_OP3 };

#define ALPHA_TRANSFER_SIZE (sizeof(alpha_transfer))

static unsigned_32 PPCJump[] = {
    0x81620000,         //   lwz        r11,[tocv]__imp_RtlMoveMemory(rtoc)
    0x818B0000,         //   lwz        r12,(r11)
    0x90410004,         //   stw        rtoc,0x4(sp)
    0x7D8903A6,         //   mtctr      r12
    0x804B0004,         //   lwz        rtoc,0x4(r11)
    0x4E800420          //   bctr
};

#define PPC_TRANSFER_SIZE (sizeof(PPCJump))

#define TRANSFER_SEGNAME "TRANSFER CODE"

static module_import* PEImpList;  /* list of imported modules */
static unsigned         NumMods;
static segdata* XFerSegData; /* linker-generated thunk data */
static local_import* PELocalImpList;
static unsigned         NumLocalImports;

static struct {
    offset      ilt_off;
    offset      eof_ilt_off;
    offset      iat_off;
    offset      mod_name_off;
    offset      hint_off;
    offset      total_size;
    segdata* sdata;
} IData;

#if 1 /* JWLink */
static struct {
    segdata* sdata;
} EData;
#endif

#define WALK_IMPORT_SYMBOLS(sym) \
    for( (sym) = HeadSym; (sym) != NULL; (sym) = (sym)->link ) \
        if( IS_SYM_IMPORTED(sym) && (sym)->p.import != NULL \
            /*&& !((sym)->info & SYM_DEAD)*/)

void ResetLoadPE(void)
{
    PEImpList = NULL;
    XFerSegData = NULL;
    NumMods = 0;
    NumImports = 0;
    memset(&IData, 0, sizeof(IData));
#if 1 /* JWLink: exports */
    memset(&EData, 0, sizeof(EData));
#endif
}