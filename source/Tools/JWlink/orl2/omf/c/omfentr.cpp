#include "pch.h"
#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"
#include "orlhash.h"
#include "omfdrctv.h"

#define _IsSegType( t )         ( ( t == ORL_SEC_TYPE_PROG_BITS ) || ( t == ORL_SEC_TYPE_NO_BITS ) )

omf_handle OmfInit(orl_funcs* funcs)
{
	return(NULL);
}

orl_return OmfFini(omf_handle oh)
{
	return(ORL_OKAY);
}

omf_file_handle OmfFileInit(omf_handle oh, void* file)
{
	return(NULL);
}

orl_return OmfFileFini(omf_file_handle ofh)
{
	return(ORL_OKAY);
}

orl_return OmfFileScan(omf_file_handle ofh, unsigned long desired, orl_sec_return_func func)
{
	return(ORL_OKAY);
}

orl_machine_type OmfFileGetMachineType(omf_file_handle ofh)
{
	return(ORL_MACHINE_TYPE_UNKNOWN);
}

orl_file_flags OmfFileGetFlags(omf_file_handle ofh)
{
	return(ORL_FILE_FLAG_NONE);
}

orl_file_type OmfFileGetType(omf_file_handle ofh)
{
	return((orl_file_type)0);
}

orl_file_size OmfFileGetSize(omf_file_handle ofh)
{
	return(0);
}

omf_sec_handle OmfFileGetSymbolTable(omf_file_handle ofh)
{
	return(ofh->symbol_table);
}

char* OmfSecGetName(omf_sec_handle sh)
{
	return(NULL);
}

orl_sec_offset OmfSecGetBase(omf_sec_handle sh)
{
	return(0);
}

orl_sec_size OmfSecGetSize(omf_sec_handle sh)
{
	return(sh->size);
}

orl_sec_type OmfSecGetType(omf_sec_handle sh)
{
	return(sh->type);
}

orl_sec_flags OmfSecGetFlags(omf_sec_handle sh)
{
	return(sh->flags);
}

orl_sec_alignment OmfSecGetAlignment(omf_sec_handle sh)
{
	return(0);
}

char* OmfSecGetClassName(omf_sec_handle sh)
{
	return(NULL);
}

orl_sec_combine OmfSecGetCombine(omf_sec_handle sh)
{
	return(ORL_SEC_COMBINE_NONE);
}

orl_sec_frame OmfSecGetAbsFrame(omf_sec_handle sh)
{
	return(ORL_SEC_NO_ABS_FRAME);
}

orl_sec_handle OmfSecGetAssociated(omf_sec_handle sh)
{
	return(NULL);
}

orl_group_handle OmfSecGetGroup(omf_sec_handle sh)
{
	return(NULL);
}

omf_sec_handle OmfSecGetStringTable(omf_sec_handle sh)
{
	return(NULL);
}

omf_sec_handle OmfSecGetSymbolTable(omf_sec_handle sh)
{
	return(sh->omf_file_hnd->symbol_table);
}

omf_sec_handle OmfSecGetRelocTable(omf_sec_handle sh)
{
	return(NULL);
}

orl_return OmfSecGetContents(omf_sec_handle sh, unsigned_8** buffer)
{
	return(ORL_OKAY);
}

static orl_return relocScan(omf_sec_handle sh, omf_sec_offset offset, orl_reloc_return_func func, int check)
{
	return(ORL_TRUE);
}

orl_return OmfSecQueryReloc(omf_sec_handle sh, omf_sec_offset offset, orl_reloc_return_func func)
{
	return(ORL_OKAY);
}

orl_return OmfSecScanReloc(omf_sec_handle sh, orl_reloc_return_func func)
{
	return(ORL_OKAY);
}

orl_table_index OmfCvtSecHdlToIdx(omf_sec_handle sh)
{
	return(sh->index);
}

omf_sec_handle OmfCvtIdxToSecHdl(omf_file_handle ofh, orl_table_index idx)
{
	return(NULL);
}

orl_return OmfRelocSecScan(omf_sec_handle sh, orl_reloc_return_func func)
{
	return(ORL_OKAY);
}

orl_return OmfSymbolSecScan(omf_sec_handle sh, orl_symbol_return_func func)
{
	return(ORL_OKAY);
}

orl_table_index OmfSecGetNumLines(omf_sec_handle sh)
{
	return(0);
}

orl_linnum* OmfSecGetLines(omf_sec_handle sh)
{
	return(NULL);
}

char* OmfSymbolGetName(omf_symbol_handle sym)
{
	return(sym->name);
}

orl_symbol_value OmfSymbolGetValue(omf_symbol_handle sym)
{
	return(sym->offset);
}

orl_symbol_binding OmfSymbolGetBinding(omf_symbol_handle sym)
{
	return(sym->binding);
}

orl_symbol_type OmfSymbolGetType(omf_symbol_handle sym)
{
	return(sym->typ);
}

unsigned char OmfSymbolGetRawInfo(omf_symbol_handle sym)
{
	return(0);
}

omf_sec_handle OmfSymbolGetSecHandle(omf_symbol_handle sym)
{
	return(sym->section);
}

orl_return OmfNoteSecScan(omf_sec_handle hnd, orl_note_callbacks* cb, void* cookie)
{
	return(ORL_OKAY);
}

orl_return OmfGroupsScan(omf_file_handle hnd, orl_group_return_func func)
{
	return(ORL_OKAY);
}

char* OmfGroupName(omf_grp_handle hnd)
{
	return(hnd->sym->name);
}

orl_table_index OmfGroupSize(omf_grp_handle hnd)
{
	return(hnd->size);
}

char* OmfGroupMember(omf_grp_handle hnd, orl_table_index idx)
{
	return(NULL);
}
