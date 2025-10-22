#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "reswords.h"
#include "segment.h"
#include "tokenize.h"
#include "macro.h"
#include "fastpass.h"
#include "listing.h"
#include "input.h"
#include "msgtext.h"
#include "types.h"
#include "omfspec.h"

#define CODEBYTES 9
#define OFSSIZE 8
#define PREFFMTSTR "25"
#define USELSLINE 1     

#ifdef __UNIX__
#define NLSIZ 1
#define NLSTR "\n"
#else
#define NLSIZ 2
#define NLSTR "\r\n"
#endif

extern int_32  LastCodeBufSize;
#if STACKBASESUPP==0
extern enum special_token basereg[];
#endif

uint_32 list_pos;       

#define DOTSMAX 32
static const char  dots[] = " . . . . . . . . . . . . . . . .";

static const char  szFmtProcStk[] = "  %s %s        %-17s %s %c %04" I32_SPEC "X";

enum list_strings {
#define ltext( index, string ) LS_ ## index,
#include "ltext.h"
#undef ltext
};

static const char* const strings[] = {
#define ltext( index, string ) string ,
#include "ltext.h"
#undef ltext
};

static const char szCount[] = "count";

enum list_queues {
	LQ_MACROS,
	LQ_STRUCTS,
#ifdef DEBUG_OUT
	LQ_UNDEF_TYPES,
#endif
	LQ_RECORDS,
	LQ_TYPEDEFS,
	LQ_SEGS,
	LQ_GRPS,
	LQ_PROCS,
	LQ_LAST
};

enum pr_flags {
	PRF_ADDSEG = 0x01
};

struct print_item {
	short type;
	short flags;
	const short* capitems;
	void (*function1)(const struct asym*);
	void (*function2)(const struct asym*, const char* name, int_32);
	void (*function3)(const struct asym*, const struct asym* group);
	void (*function4)(const struct asym*, const struct dsym*);
};


static const short maccap[] = { LS_TXT_MACROS,  LS_TXT_MACROCAP  ,0 };
static const short strcap[] = { LS_TXT_STRUCTS, LS_TXT_STRUCTCAP, 0 };
static const short reccap[] = { LS_TXT_RECORDS, LS_TXT_RECORDCAP, 0 };
static const short tdcap[] = { LS_TXT_TYPEDEFS,LS_TXT_TYPEDEFCAP, 0 };
static const short segcap[] = { LS_TXT_SEGS,    LS_TXT_SEGCAP, 0 };
static const short prccap[] = { LS_TXT_PROCS,   LS_TXT_PROCCAP, 0 };

static void log_macro(const struct asym*);
static void log_struct(const struct asym*, const char* name, int_32);
static void log_record(const struct asym*);
static void log_typedef(const struct asym*);
static void log_segment(const struct asym*, const struct asym* group);
static void log_group(const struct asym*, const struct dsym*);
static void log_proc(const struct asym*);

static const struct print_item cr[] = {
	{ LQ_MACROS,          0, maccap, log_macro   },
	{ LQ_STRUCTS,         0, strcap, NULL, log_struct  },
#ifdef DEBUG_OUT
	{ LQ_UNDEF_TYPES,     0, strcap, log_struct  },
#endif
	{ LQ_RECORDS,         0, reccap, log_record  },
	{ LQ_TYPEDEFS,        0, tdcap,  log_typedef },
	{ LQ_SEGS,            0, segcap, NULL,NULL,log_segment },
	{ LQ_GRPS,   PRF_ADDSEG, NULL,   NULL,NULL,NULL,log_group   },
	{ LQ_PROCS,           0, prccap, log_proc    },
};

struct lstleft {
	struct lstleft* next;
	char buffer[4 * 8];
	char last;
};

void LstWrite(enum lsttype type, uint_32 oldofs, void* value)
{
}

void LstPrintf(const char* format, ...)
{
}	

void LstNL(void)
{
}

static void log_macro(const struct asym*)
{
}

static void log_struct(const struct asym*, const char* name, int_32)
{
}

static void log_record(const struct asym*)
{
}

static void log_typedef(const struct asym*)
{
}

static void log_segment(const struct asym*, const struct asym* group)
{
}

static void log_group(const struct asym*, const struct dsym*)
{
}

static void log_proc(const struct asym*)
{
}
