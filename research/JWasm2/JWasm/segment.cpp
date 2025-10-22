#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "reswords.h"
#include "segment.h"
#include "expreval.h"
#include "omf.h"
#include "omfspec.h"
#include "fastpass.h"
#include "coffspec.h"
#include "assume.h"
#include "listing.h"
#include "msgtext.h"
#include "types.h"
#include "fixup.h"

#include "myassert.h"

extern ret_code    EndstructDirective(int, struct asm_tok tokenarray[]);

struct asym* symCurSeg;        

#define INIT_ATTR         0x01    
#define INIT_ALIGN        0x02       
#define INIT_ALIGN_PARAM  (0x80 | INIT_ALIGN)   
#define INIT_COMBINE      0x04      
#define INIT_COMBINE_AT   (0x80 | INIT_COMBINE)   
#if COMDATSUPP
#define INIT_COMBINE_COMDAT (0xC0 | INIT_COMBINE)   
#endif
#define INIT_OFSSIZE      0x08     
#define INIT_OFSSIZE_FLAT (0x80 | INIT_OFSSIZE)   
#define INIT_ALIAS        0x10   
#define INIT_CHAR         0x20      
#define INIT_CHAR_INFO    (0x80 | INIT_CHAR)   

#define INIT_EXCL_MASK    0x1F     

struct typeinfo {
    uint_8    value;            
    uint_8    init;           
};

static const char* const SegAttrToken[] = {
#define sitem( text, value, init ) text,
#include "segattr.h"
#undef sitem
};
static const struct typeinfo SegAttrValue[] = {
#define sitem( text, value, init ) { value, init },
#include "segattr.h"
#undef sitem
};

static unsigned         grpdefidx;             
static struct dsym* SegStack[MAX_SEG_NESTING];      
static int              stkindex;            

#if FASTPASS
static struct dsym* saved_CurrSeg;
static struct dsym** saved_SegStack;
static int              saved_stkindex;
#endif

static uint_8           codebuf[1024];
static uint_32          buffer_size;       

static const uint_16 min_cpu[] = { P_86, P_386,
#if AMD64_SUPPORT
P_64
#endif
};

uint_32 GetCurrOffset(void)
{
    return(CurrSeg ? CurrSeg->e.seginfo->current_loc : 0);
}


