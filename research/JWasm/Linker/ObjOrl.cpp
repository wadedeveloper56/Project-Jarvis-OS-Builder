#include "ObjOrl.h"
#include "MemorySubsystem.h"
#include "orllevel.h"
#include "FileSubsystem.h"
#include "TokenBuffer.h"
#include "orlglobl.h"
#include "orl.h"

ObjOrl::ObjOrl(MemorySubsystem* memory, FileSubsystem* file, TokenBuffer* tokenBuffer)
{
	this->memory = memory;
	this->file = file;
	this->tokenBuffer = tokenBuffer;
	mixcache = new MixCache(memory, file, tokenBuffer);
	ORLFuncs = { this, memory };
	ORLHandle = ORLInit(&ORLFuncs);
	ORLFilePos = 0;
	ImpExternalName = nullptr;
	ImpModName = nullptr;
	FirstCodeSymName = nullptr;
	FirstDataSymName = nullptr;
	ImpOrdinal = 0;
	ReadCacheList = nullptr;
}

ObjOrl::~ObjOrl()
{
	ORLFini(ORLHandle);
	delete mixcache;
}

orl_return ObjOrl::ORLFini(orl_handle orl_hnd) 
{
	orl_return error;

	if ((error = ElfFini(orl_hnd->elf_hnd)) != ORL_OKAY) return(error);
	if ((error = CoffFini(orl_hnd->coff_hnd)) != ORL_OKAY) return(error);
	if ((error = OmfFini(orl_hnd->omf_hnd)) != ORL_OKAY) return(error);
	while (orl_hnd->first_file_hnd) {
		error = ORLRemoveFileLinks(orl_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	orl_hnd->funcs->memory->FreeMemory(orl_hnd);
	return(ORL_OKAY);
}

void ObjOrl::free_coff_file_hnd(coff_file_handle coff_file_hnd)
{
	unsigned int                 loop;
	coff_sec_handle     coff_sec_hnd;

	if (coff_file_hnd->coff_sec_hnd) {
		for (loop = 0; loop < coff_file_hnd->num_sections; loop++) {
			coff_sec_hnd = coff_file_hnd->coff_sec_hnd[loop];
			if (coff_sec_hnd->type == ORL_SEC_TYPE_RELOCS) {
				if (coff_sec_hnd->assoc.reloc.relocs) {
					coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_sec_hnd->assoc.reloc.relocs);
				}
			}
			if (coff_sec_hnd->name_alloced) {
				coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_sec_hnd->name);
			}
			coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->coff_sec_hnd[loop]);
		}
		coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->coff_sec_hnd);
	}
	coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->orig_sec_hnd);
	if (coff_file_hnd->symbol_handles) {
		for (loop = 0; loop < coff_file_hnd->num_symbols; loop++) {
			if (coff_file_hnd->symbol_handles[loop].name_alloced) {
				coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->symbol_handles[loop].name);
			}
			loop += coff_file_hnd->symbol_handles[loop].symbol->num_aux;
		}
		coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->symbol_handles);
	}
	if (coff_file_hnd->sec_name_hash_table) {
		//FIX ME ORLHashTableFree(coff_file_hnd->sec_name_hash_table);
	}
	if (coff_file_hnd->implib_data != NULL) {
		coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->implib_data);
	}
	coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd);
}

orl_return ObjOrl::CoffRemoveFileLinks(coff_file_handle coff_file_hnd)
{
	coff_handle                         coff_hnd;
	coff_file_handle                    current;

	coff_hnd = coff_file_hnd->coff_hnd;

	if (coff_hnd->first_file_hnd == coff_file_hnd) {
		coff_hnd->first_file_hnd = coff_file_hnd->next;
		free_coff_file_hnd(coff_file_hnd);
		return(ORL_OKAY);
	}
	else {
		current = coff_hnd->first_file_hnd;
		while (current->next != NULL) {
			if (current->next == coff_file_hnd) {
				current->next = coff_file_hnd->next;
				free_coff_file_hnd(coff_file_hnd);
				return(ORL_OKAY);
			}
			else {
				current = current->next;
			}
		}
	}
	return(ORL_ERROR);
}

orl_return ObjOrl::CoffFini(coff_handle coff_hnd)
{
	orl_return                                  error;

	while (coff_hnd->first_file_hnd != NULL) {
		error = CoffRemoveFileLinks(coff_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	coff_hnd->funcs->memory->FreeMemory(coff_hnd);
	return(ORL_OKAY);
}

orl_return ObjOrl::freeFileHandle(omf_file_handle ofh)
{
	omf_sec_handle      sh;
	int_32             x;
	omf_tmp_fixup       tf;

	sh = ofh->first_sec;
	while (sh) {
		switch (sh->type) {
			case ORL_SEC_TYPE_NOTE:
				if (sh->assoc.comment.comments) {
					for (x = 0; x < sh->assoc.comment.num; x++) {
						ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.comment.comments[x]);
					}
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.comment.comments);
					sh->assoc.comment.comments = NULL;
					sh->assoc.comment.num = 0;
				}
				break;
			case ORL_SEC_TYPE_RELOCS:
				if (sh->assoc.reloc.relocs) {
					for (x = 0; x < sh->assoc.reloc.num; x++) {
						ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.reloc.relocs[x]);
					}
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.reloc.relocs);
					sh->assoc.reloc.relocs = NULL;
					sh->assoc.reloc.num = 0;
				}
				break;
			case ORL_SEC_TYPE_SYM_TABLE:
				if (sh->assoc.sym.syms) {
					for (x = 0; x < sh->assoc.sym.num; x++) {
						ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.sym.syms[x]);
					}
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.sym.syms);
					sh->assoc.sym.syms = NULL;
					sh->assoc.sym.num = 0;
				}
				if (sh->assoc.sym.hash_tab) {
					//FIX ME ORLHashTableFree(sh->assoc.sym.hash_tab);
				}
				break;
			case(ORL_SEC_TYPE_STR_TABLE):
				if (sh->assoc.string.strings) {
					for (x = 0; x < sh->assoc.string.num; x++) {
						ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.string.strings[x]);
					}
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.string.strings);
					sh->assoc.string.strings = NULL;
					sh->assoc.string.num = 0;
				}
				break;
			case(ORL_SEC_TYPE_NO_BITS):
			case(ORL_SEC_TYPE_PROG_BITS):
				if (sh->contents) {
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->contents);
					sh->contents = NULL;
				}
				if (sh->assoc.seg.lines && (sh->assoc.seg.num_lines > 0)) {
					ofh->omf_hnd->funcs->memory->FreeMemory(sh->assoc.seg.lines);
					sh->assoc.seg.lines = NULL;
					sh->assoc.seg.num_lines = 0;
				}
				break;
			default:
				//assert(0);
				break;
		}
		ofh->first_sec = sh->next;
		ofh->omf_hnd->funcs->memory->FreeMemory(sh);
		sh = ofh->first_sec;
	}

	if (ofh->segs) {
		ofh->omf_hnd->funcs->memory->FreeMemory(ofh->segs);
		ofh->segs = NULL;
		ofh->num_segs = 0;
	}

	if (ofh->comdats) {
		ofh->omf_hnd->funcs->memory->FreeMemory(ofh->comdats);
		ofh->comdats = NULL;
		ofh->num_comdats = 0;
	}

	if (ofh->groups) {
		for (x = 0; x < ofh->num_groups; x++) {
			//assert(ofh->groups[x]);
			ofh->omf_hnd->funcs->memory->FreeMemory(ofh->groups[x]->segs);
			ofh->omf_hnd->funcs->memory->FreeMemory(ofh->groups[x]);
		}
		ofh->omf_hnd->funcs->memory->FreeMemory(ofh->groups);
		ofh->groups = NULL;
		ofh->num_groups = 0;
	}

	if (ofh->lidata) {
		while (ofh->lidata->first_fixup) {
			tf = ofh->lidata->first_fixup;
			ofh->lidata->first_fixup = tf->next;
			ofh->omf_hnd->funcs->memory->FreeMemory(tf);
		}
		ofh->omf_hnd->funcs->memory->FreeMemory(ofh->lidata);
		ofh->lidata = NULL;
	}

	ofh->omf_hnd->funcs->memory->FreeMemory(ofh);

	return(ORL_OKAY);
}

orl_return ObjOrl::OmfRemoveFileLinks(omf_file_handle ofh)
{
	omf_handle                          oh;
	omf_file_handle                     curr;

	oh = ofh->omf_hnd;
	if (oh->first_file_hnd == ofh) {
		oh->first_file_hnd = ofh->next;
	}
	else {
		curr = oh->first_file_hnd;
		while (curr->next != NULL) {
			if (curr->next == ofh) {
				curr->next = ofh->next;
				break;
			}
			curr = curr->next;
		}
	}
	return(freeFileHandle(ofh));
}

orl_return ObjOrl::OmfFini(omf_handle oh)
{
	orl_return err;
	while (oh->first_file_hnd != NULL) {
		err = OmfRemoveFileLinks(oh->first_file_hnd);
		if (err != ORL_OKAY) return(err);
	}
	oh->funcs->memory->FreeMemory(oh);
	return(ORL_OKAY);
}

void ObjOrl::free_elf_file_hnd(elf_file_handle elf_file_hnd)
{
	int                         loop;
	elf_sec_handle              elf_sec_hnd;

	if (elf_file_hnd->elf_sec_hnd) {
		for (loop = 0; loop < elf_file_hnd->num_sections; loop++) {
			elf_sec_hnd = elf_file_hnd->elf_sec_hnd[loop];
			switch (elf_sec_hnd->type) {
				case ORL_SEC_TYPE_RELOCS:
				case ORL_SEC_TYPE_RELOCS_EXPADD:
					if (elf_sec_hnd->assoc.reloc.relocs) {
						elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_sec_hnd->assoc.reloc.relocs);
					}
					break;
				case ORL_SEC_TYPE_SYM_TABLE:
				case ORL_SEC_TYPE_DYN_SYM_TABLE:
					if (elf_sec_hnd->assoc.sym.symbols) {
						elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_sec_hnd->assoc.sym.symbols);
					}
					break;
				default:
					break;
			}
			elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_sec_hnd);
		}
		elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_file_hnd->elf_sec_hnd);
	}
	elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_file_hnd->orig_sec_hnd);
	if (elf_file_hnd->sec_name_hash_table) {
		//FIX ME ORLHashTableFree(elf_file_hnd->sec_name_hash_table);
	}
	elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_file_hnd);
}

orl_return ObjOrl::ElfRemoveFileLinks(elf_file_handle elf_file_hnd)
{
	elf_handle                          elf_hnd;
	elf_file_handle                     current;

	elf_hnd = elf_file_hnd->elf_hnd;

	if (elf_hnd->first_file_hnd == elf_file_hnd) {
		elf_hnd->first_file_hnd = elf_file_hnd->next;
		free_elf_file_hnd(elf_file_hnd);
		return(ORL_OKAY);
	}
	else {
		current = elf_hnd->first_file_hnd;
		while (current->next != NULL) {
			if (current->next == elf_file_hnd) {
				current->next = elf_file_hnd->next;
				free_elf_file_hnd(elf_file_hnd);
				return(ORL_OKAY);
			}
			else {
				current = current->next;
			}
		}
	}
	return(ORL_ERROR);
}

orl_return ObjOrl::ElfFini(elf_handle elf_hnd)
{
	orl_return error;

	while (elf_hnd->first_file_hnd != NULL) {
		error = ElfRemoveFileLinks(elf_hnd->first_file_hnd);
		if (error != ORL_OKAY) return(error);
	}
	elf_hnd->funcs->memory->FreeMemory(elf_hnd);
	return(ORL_OKAY);
}

void ObjOrl::free_orl_file_hnd(orl_file_handle orl_file_hnd)
{
	orl_file_hnd->orl_hnd->funcs->memory->FreeMemory(orl_file_hnd);
}

orl_return ObjOrl::ORLRemoveFileLinks(orl_file_handle orl_file_hnd)
{
	orl_handle                          orl_hnd;
	orl_file_handle                     current;

	orl_hnd = orl_file_hnd->orl_hnd;

	if (orl_hnd->first_file_hnd == orl_file_hnd) {
		orl_hnd->first_file_hnd = orl_file_hnd->next;
		free_orl_file_hnd(orl_file_hnd);
		return(ORL_OKAY);
	}
	else {
		current = orl_hnd->first_file_hnd;
		while (current->next != NULL) {
			if (current->next == orl_file_hnd) {
				current->next = orl_file_hnd->next;
				free_orl_file_hnd(orl_file_hnd);
				return(ORL_OKAY);
			}
			else {
				current = current->next;
			}
		}
	}
	return(ORL_ERROR);
}

orl_handle ObjOrl::ORLInit(orl_funcs* funcs)
{
	orl_handle orl_hnd = (orl_handle)funcs->memory->AllocateMemory(sizeof(orl_handle_struct));
	if (!orl_hnd) return(nullptr);
	orl_hnd->error = ORL_OKAY;
	orl_hnd->funcs = funcs;
	orl_hnd->elf_hnd = ElfInit(funcs);
	if (!(orl_hnd->elf_hnd)) {
		funcs->memory->FreeMemory(orl_hnd);
		return(nullptr);
	}
	orl_hnd->coff_hnd = CoffInit(funcs);
	if (!(orl_hnd->coff_hnd)) {
		funcs->memory->FreeMemory(orl_hnd);
		return(nullptr);
	}
	orl_hnd->omf_hnd = OmfInit(funcs);
	if (!(orl_hnd->omf_hnd)) {
		funcs->memory->FreeMemory(orl_hnd);
		return(nullptr);
	}
	orl_hnd->first_file_hnd = nullptr;
	return orl_hnd;
}

elf_handle ObjOrl::ElfInit(orl_funcs* funcs)
{
	elf_handle elf_hnd = (elf_handle)funcs->memory->AllocateMemory(sizeof(elf_handle_struct));
	if (!elf_hnd) return(nullptr);
	elf_hnd->funcs = funcs;
	elf_hnd->first_file_hnd = nullptr;
	return(elf_hnd);
}

coff_handle ObjOrl::CoffInit(orl_funcs* funcs)
{
	coff_handle coff_hnd = (coff_handle)funcs->memory->AllocateMemory(sizeof(coff_handle_struct));
	if (!coff_hnd) return(nullptr);
	coff_hnd->funcs = funcs;
	coff_hnd->first_file_hnd = nullptr;
	return(coff_hnd);
}

omf_handle ObjOrl::OmfInit(orl_funcs* funcs)
{
	omf_handle oh = (omf_handle)funcs->memory->AllocateMemory(sizeof(omf_handle_struct));
	if (!oh) return(nullptr);
	oh->funcs = funcs;
	oh->first_file_hnd = nullptr;
	return(oh);
}

long ObjOrl::seek(void* _list, long pos, int where)
{
	file_list* list = (file_list*)_list;

	if (where == SEEK_SET) {
		ORLFilePos = pos;
	}
	else if (where == SEEK_CUR) {
		ORLFilePos += pos;
	}
	else {
		ORLFilePos = list->file->len - pos;
	}
	return(ORLFilePos);
}

void* ObjOrl::read(void* _list, size_t len)
{
	file_list* list = (file_list*)_list;
	void* result;
	static readcache* cache;

	result = mixcache->CachePermRead(list, ORLFilePos, len);
	ORLFilePos += (long)len;
	cache = (readcache*)memory->AllocateMemory(sizeof(readcache));
	cache->next = ReadCacheList;
	ReadCacheList = cache;
	cache->data = result;
	return(result);
}
