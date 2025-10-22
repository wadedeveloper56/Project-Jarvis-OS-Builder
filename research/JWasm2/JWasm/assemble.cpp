#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "input.h"
#include "parser.h"
#include "reswords.h"
#include "tokenize.h"
#include "condasm.h"
#include "segment.h"
#include "assume.h"
#include "proc.h"
#include "expreval.h"
#include "hll.h"
#include "context.h"
#include "types.h"
#include "label.h"
#include "macro.h"
#include "extern.h"
#include "fixup.h"
#include "omf.h"
#include "fastpass.h"
#include "listing.h"
#include "msgtext.h"
#include "myassert.h"
#include "linnum.h"
#include "cpumodel.h"
#include "lqueue.h"
#if DLLIMPORT
#include "mangle.h"
#endif

#if COFF_SUPPORT
#include "coff.h"
#endif
#if ELF_SUPPORT
#include "elf.h"
#endif
#if BIN_SUPPORT
#include "bin.h"
#endif

#if 1  
#include <setjmp.h>
jmp_buf jmpenv;
#endif

#ifdef __SW_BD
#define EXPQUAL __stdcall
#else
#define EXPQUAL
#endif

#define USELSLINE 1       

#ifdef __UNIX__
#define OBJ_EXT "o"
#else
#define OBJ_EXT "obj"
#endif
#define LST_EXT "lst"
#define ERR_EXT "err"
#define BIN_EXT "BIN"
#define EXE_EXT "EXE"

struct module_info      ModuleInfo;
unsigned int            Parse_Pass;        
struct qdesc            LinnumQueue;         
bool write_to_file;         



