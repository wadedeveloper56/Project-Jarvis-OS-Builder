#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "msgtext.h"
#include "dbgcv.h"
#include "cmdline.h"
#include "myassert.h"
#include "input.h"   

#if defined(__UNIX__) || defined(__CYGWIN__) || defined(__DJGPP__)

#define HANDLECTRLZ 0
#define SWITCHCHAR 0

#else

#define HANDLECTRLZ 1
#define SWITCHCHAR 1

#endif

#ifdef __I86__
#define OPTQUAL __near
#else
#define OPTQUAL
#endif

extern char     banner_printed;

struct global_options Options = {
						   FALSE,
					FALSE,
				   0,
					   0,
				  FPO_NO_EMULATION,

					 50,
				  FALSE,
				   2,
				   FALSE,
#ifdef DEBUG_OUT
						   FALSE,
					 FALSE,
#if FASTPASS
					  FALSE,
				 FALSE,
#endif
					  0,
			   0,
				   0,
				   FALSE,
			  FALSE,
					FALSE,
			   FALSE,
#endif
						   {
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#if BUILD_TARGET
		NULL,
#endif
#if MANGLERSUPP
		NULL
#endif
	},
						  { NULL, NULL, NULL },
#if COCTALS
				  FALSE,
#endif
		 FALSE,
				  FALSE,
#if COFF_SUPPORT
				   FALSE,
				 FALSE,
			FALSE,
#endif
			 FALSE,
			  STDCALL_FULL,
			FALSE,
				 FALSE,
				   FALSE,
					FALSE,
				  FALSE,
			   FALSE,
			 FALSE,
				   FALSE,
			  FALSE,
			 FALSE,
		   FALSE,

						  FALSE,
			 FALSE,
					  LM_LISTMACRO,
			   FALSE,
			  FALSE,

			  FALSE,
						 FALSE,
				  FALSE,
				   OFORMAT_OMF,
					  SFORMAT_NONE,
			   0,
						LANG_NONE,
						   MODEL_NONE,
							 P_86,
					FCT_MSC,
				 FALSE,
#if MANGLERSUPP
			   NC_DO_NOTHING,
#endif
};

char* DefaultDir[NUM_FILE_TYPES] = { NULL, NULL, NULL, NULL };
#define MAX_RSP_NESTING 15       

static unsigned         OptValue;
static char* OptName;
static const char* cmdsave[MAX_RSP_NESTING];
static const char* cmdbuffers[MAX_RSP_NESTING];
static int              rspidx = 0;

static const enum cpu_info cpuoption[] = {
	P_86, P_186, P_286, P_386,
	P_486, P_586, P_686,
	(enum cpu_info)(P_686 | P_MMX),
	(enum cpu_info)(P_686 | P_MMX | P_SSE1),
	(enum cpu_info)(P_686 | P_MMX | P_SSE1 | P_SSE2),
#if AMD64_SUPPORT
	P_64,
#endif
};

#if 0        
static void StripQuotes(char* fname)
{
	char* s;
	char* d;

	if (*fname == '"') {
		d = fname;
		for (s = d + 1; *s && *s != '"'; ++s) {
			if (s[0] == '\\' && s[1] == '\\') {
				++s;
			}
			else if (s[0] == '\\' && s[1] == '"') {
				++s;
			}
			*d++ = *s;
		}
		*d = '\0';
	}
}

static char* GetAFileName(void)
{
	DebugMsg(("GetAFileName() enter, OptName=>%s<\n", OptName));
	StripQuotes(OptName);
	return(OptName);
}
#else
#define GetAFileName() OptName
#endif
