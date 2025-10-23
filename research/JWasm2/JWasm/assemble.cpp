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
#include "coff.h"
#include "elf.h"
#include "bin.h"

#define EXPQUAL

#define USELSLINE 1       

#define OBJ_EXT "obj"
#define LST_EXT "lst"
#define ERR_EXT "err"
#define BIN_EXT "BIN"
#define EXE_EXT "EXE"

jmp_buf jmpenv;
struct module_info      ModuleInfo;
unsigned int            Parse_Pass;        
struct qdesc            LinnumQueue;         
bool write_to_file;         

int EXPQUAL AssembleModule(const char* source)
{
	return 1;
}

