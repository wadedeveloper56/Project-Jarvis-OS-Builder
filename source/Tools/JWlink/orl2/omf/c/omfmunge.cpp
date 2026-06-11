#include "pch.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _BSD_SOURCE
#define stricmp strcasecmp
#endif

#include "omfload.h"
#include "omfmunge.h"
#include "orlhash.h"
#include "pcobj.h"

#define STD_INC         256
#define STD_CODE_SIZE   4096
#define BS_ORE(type,a,b,c) (a=((type)((a)|(c))))
#define _IsSymPub( t )  ( t & ( ORL_SYM_TYPE_DEFINED | ORL_SYM_TYPE_ABSOLUTE ) )


static orl_sec_combine getCombine(int combine)
{
	return(ORL_SEC_COMBINE_NONE);
}

static int nameCmp(omf_file_handle ofh, omf_idx n1, omf_idx n2)
{
	return(0);
}

static void* checkArraySize(omf_file_handle ofh, void* old_arr, long num, long inc, long elem)
{
	return(NULL);
}

static omf_symbol_handle findExtDefSym(omf_file_handle ofh, omf_idx ext)
{
	return(NULL);
}

static omf_grp_handle findGroup(omf_file_handle ofh, omf_idx grp)
{
	return(NULL);
}

static omf_sec_handle findComDat(omf_file_handle ofh, omf_idx seg)
{
	return(NULL);
}

static omf_sec_handle findComDatByName(omf_file_handle ofh, omf_idx nameidx)
{
	return NULL;
}

static omf_sec_handle findSegment(omf_file_handle ofh, omf_idx seg)
{
	return(NULL);
}

static omf_symbol_handle newSymbol(omf_file_handle ofh, orl_symbol_type typ, char* name, int len)
{
	return NULL;
}

static omf_sec_handle newSection(omf_file_handle ofh, omf_quantity idx, orl_sec_type typ)
{
	return NULL;
}

static omf_sec_handle newComDatSection(omf_file_handle ofh)
{
	return NULL;
}

static omf_sec_handle newSegSection(omf_file_handle ofh, orl_sec_type typ)
{
	return NULL;
}

static omf_grp_handle newGroup(omf_file_handle ofh)
{
	return NULL;
}

static orl_sec_offset getUWord(omf_bytes buffer, int wordsize)
{
	return(0);
}

static omf_string_struct* getIdx2String(omf_sec_handle sh, omf_idx idx)
{
	return(NULL);
}

static omf_sec_handle newStringTable(omf_file_handle ofh, omf_quantity idx)
{
	return NULL;
}

static orl_return addString(omf_sec_handle sh, omf_bytes buffer, unsigned int len)
{
	return(ORL_OKAY);
}


static orl_return addToSymbolTable(omf_file_handle ofh, omf_symbol_handle sym)
{
	return(ORL_OKAY);
}

static orl_return addReloc(omf_file_handle ofh, omf_reloc_handle orh)
{
	return(ORL_OKAY);
}

static omf_tmp_fixup findMatchingFixup(omf_tmp_fixup tf, int lo, int hi)
{
	return NULL;
}

static orl_return writeAndFixupLIData(omf_file_handle ofh, omf_sec_handle sh, omf_bytes buffer)
{
	return(ORL_OKAY);
}

static orl_return expandPrevLIData(omf_file_handle ofh)
{
	return(ORL_OKAY);
}

static orl_return finishPrevWork(omf_file_handle ofh)
{
	return(ORL_OKAY);
}

static orl_sec_offset   calcLIDataLength(int is32, omf_bytes* input, int* len)
{
	return(0);
}

static orl_return checkSegmentLength(omf_sec_handle sh, uint_32 max)
{
	return(ORL_OKAY);
}

static char* strNUpper(char* str, int len)
{
	return NULL;
}

static orl_sec_flags getSegSecFlags(omf_file_handle ofh, omf_idx name, omf_idx class1, orl_sec_alignment align, int combine, int use32)
{
	return((orl_sec_flags)0);
}

static orl_return OmfAddFileName(omf_file_handle ofh, char* name, unsigned int len)
{
	return(ORL_OKAY);
}

orl_return OmfAddLIData(omf_file_handle ofh, int is32, omf_idx seg, orl_sec_offset offset, omf_bytes buffer, long len, int comdat)
{
	return(ORL_OKAY);
}

orl_return OmfAddLEData(omf_file_handle ofh, int is32, omf_idx seg, orl_sec_offset offset, omf_bytes buffer, long len, int comdat)
{
	return(ORL_OKAY);
}

orl_return OmfAddLName(omf_file_handle ofh, omf_bytes buffer, unsigned int len, omf_rectyp typ)
{
	return(ORL_OKAY);
}

orl_return OmfAddFixupp(omf_file_handle ofh, int is32, int mode, int location, orl_sec_offset offset, int fmethod, omf_idx fidx, int tmethod, omf_idx tidx, orl_sec_offset disp)
{
	return(ORL_OKAY);
}


orl_return OmfAddExtDef(omf_file_handle ofh, omf_bytes buffer, unsigned int len, omf_rectyp typ)
{
	return(ORL_OKAY);
}

orl_return OmfAddComDat(omf_file_handle ofh, int is32, int flags, int attr, int align, orl_sec_offset offset, omf_idx seg, omf_idx group, omf_frame frame, omf_idx name, omf_bytes buffer, long len, omf_rectyp typ)
{
	return(ORL_OKAY);
}

extern orl_return OmfAddLineNum(omf_sec_handle sh, unsigned_16 line, unsigned_32 offset)
{
	return(ORL_OKAY);
}

orl_return OmfAddSegDef(omf_file_handle ofh, int is32, orl_sec_alignment align, int combine, int use32, int max, orl_sec_frame frame, orl_sec_size size, omf_idx name, omf_idx class1)
{
	return(ORL_OKAY);
}

orl_return OmfAddPubDef(omf_file_handle ofh, int is32, omf_idx group, omf_idx seg, omf_frame frame, char* name, int len, orl_sec_offset offset, omf_rectyp typ)
{
	return(ORL_OKAY);
}

orl_return OmfAddGrpDef(omf_file_handle ofh, omf_idx name, omf_idx* segs, int size)
{
	return(ORL_OKAY);
}

orl_return OmfModEnd(omf_file_handle ofh)
{
	return(ORL_OKAY);
}

extern orl_return OmfAddComment(omf_file_handle ofh, uint_8 class1, uint_8 flags, omf_bytes buff, long len)
{
	return(ORL_OKAY);
}


int OmfGetLName(omf_sec_handle lnames, omf_idx idx, char* name)
{
	return(0);
}

char* OmfGetPtrToLName(omf_file_handle ofh, omf_idx idx)
{
	return(NULL);
}

omf_sec_handle OmfFindSegOrComdat(omf_file_handle ofh, omf_idx seg, omf_idx comdat_lname)
{
	return(NULL);
}

orl_return OmfExportSegmentContents(omf_sec_handle sh)
{
	return(ORL_OKAY);
}

orl_return OmfTheadr(omf_file_handle ofh)
{
	return(ORL_OKAY);
}
