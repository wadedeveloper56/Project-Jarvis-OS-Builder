#include "pch.h"
#include "orl.h"
#include "orllevel.h"
#include "orlentry.h"
#include "orlflhnd.h"
#include "elfentr.h"
#include "elfload.h"
#include "elfflhn.h"
#include "elflwlv.h"
#include "coffentr.h"
#include "coffflhn.h"
#include "cofflwlv.h"
#include "coffload.h"
#include "omfentr.h"
#include "omfload.h"
#include "omfmunge.h"
#include "omfflhn.h"

#define _HashAlloc( a, b ) a->funcs->memory->AllocateMemory( b )
#define _HashFree( a, b ) a->funcs->memory->FreeMemory( b )
#define _HashCompare( a, b, c ) a->compare( b, c )

void ORLHashTableFree(orl_hash_table hash_table)
{
    int                         loop;
    orl_hash_struct* hash_ptr;
    orl_hash_struct* last_hash_ptr;
    orl_hash_data_struct* data_ptr;
    orl_hash_data_struct* last_data_ptr;

    for (loop = 0; loop < hash_table->size; loop++)
    {
        hash_ptr = hash_table->table[loop];
        while (hash_ptr != NULL) {
            data_ptr = hash_ptr->data_struct;
            while (data_ptr != NULL) {
                last_data_ptr = data_ptr;
                data_ptr = data_ptr->next;
                _HashFree(hash_table, last_data_ptr);
            }
            last_hash_ptr = hash_ptr;
            hash_ptr = hash_ptr->next;
            _HashFree(hash_table, last_hash_ptr);
        }
    }
    _HashFree(hash_table, hash_table->table);
    _HashFree(hash_table, hash_table);
}

orl_return freeFileHandle(omf_file_handle ofh)
{
    omf_sec_handle      sh;
    uint_32             x;
    omf_tmp_fixup       tf;

    sh = ofh->first_sec;
    while (sh) {
        switch (sh->type) {
            case ORL_SEC_TYPE_NOTE:
                if (sh->assoc.comment.comments) {
                    for (x = 0; x < sh->assoc.comment.num; x++) {
                        _ClientFree(ofh, sh->assoc.comment.comments[x]);
                    }
                    _ClientFree(ofh, sh->assoc.comment.comments);
                    sh->assoc.comment.comments = NULL;
                    sh->assoc.comment.num = 0;
                }
                break;
            case ORL_SEC_TYPE_RELOCS:
                if (sh->assoc.reloc.relocs) {
                    for (x = 0; x < sh->assoc.reloc.num; x++) {
                        _ClientFree(ofh, sh->assoc.reloc.relocs[x]);
                    }
                    _ClientFree(ofh, sh->assoc.reloc.relocs);
                    sh->assoc.reloc.relocs = NULL;
                    sh->assoc.reloc.num = 0;
                }
                break;
            case ORL_SEC_TYPE_SYM_TABLE:
                if (sh->assoc.sym.syms) {
                    for (x = 0; x < sh->assoc.sym.num; x++) {
                        _ClientFree(ofh, sh->assoc.sym.syms[x]);
                    }
                    _ClientFree(ofh, sh->assoc.sym.syms);
                    sh->assoc.sym.syms = NULL;
                    sh->assoc.sym.num = 0;
                }
                if (sh->assoc.sym.hash_tab) {
                    ORLHashTableFree(sh->assoc.sym.hash_tab);
                }
                break;
            case(ORL_SEC_TYPE_STR_TABLE):
                if (sh->assoc.string.strings) {
                    for (x = 0; x < sh->assoc.string.num; x++) {
                        _ClientFree(ofh, sh->assoc.string.strings[x]);
                    }
                    _ClientFree(ofh, sh->assoc.string.strings);
                    sh->assoc.string.strings = NULL;
                    sh->assoc.string.num = 0;
                }
                break;
            case(ORL_SEC_TYPE_NO_BITS):
            case(ORL_SEC_TYPE_PROG_BITS):
                if (sh->contents) {
                    _ClientFree(ofh, sh->contents);
                    sh->contents = NULL;
                }
                if (sh->assoc.seg.lines && (sh->assoc.seg.num_lines > 0)) {
                    _ClientFree(ofh, sh->assoc.seg.lines);
                    sh->assoc.seg.lines = NULL;
                    sh->assoc.seg.num_lines = 0;
                }
                break;
            default:
                assert(0);
        }
        ofh->first_sec = sh->next;
        _ClientFree(ofh, sh);
        sh = ofh->first_sec;
    }

    if (ofh->segs) {
        _ClientFree(ofh, ofh->segs);
        ofh->segs = NULL;
        ofh->num_segs = 0;
    }

    if (ofh->comdats) {
        _ClientFree(ofh, ofh->comdats);
        ofh->comdats = NULL;
        ofh->num_comdats = 0;
    }

    if (ofh->groups) {
        for (x = 0; x < ofh->num_groups; x++) {
            assert(ofh->groups[x]);
            _ClientFree(ofh, ofh->groups[x]->segs);
            _ClientFree(ofh, ofh->groups[x]);
        }
        _ClientFree(ofh, ofh->groups);
        ofh->groups = NULL;
        ofh->num_groups = 0;
    }

    if (ofh->lidata) {
        while (ofh->lidata->first_fixup) {
            tf = ofh->lidata->first_fixup;
            ofh->lidata->first_fixup = tf->next;
            _ClientFree(ofh, tf);
        }
        _ClientFree(ofh, ofh->lidata);
        ofh->lidata = NULL;
    }

    _ClientFree(ofh, ofh);

    return(ORL_OKAY);
}

orl_return OmfRemoveFileLinks(omf_file_handle ofh)
{
    omf_handle                          oh;
    omf_file_handle                     curr;

    assert(ofh);
    oh = ofh->omf_hnd;
    assert(oh);

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

void free_coff_file_hnd(coff_file_handle coff_file_hnd)
{
    int                 loop;
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
        ORLHashTableFree(coff_file_hnd->sec_name_hash_table);
    }
    if (coff_file_hnd->implib_data != NULL) {
        coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd->implib_data);
    }
    coff_file_hnd->coff_hnd->funcs->memory->FreeMemory(coff_file_hnd);
}

orl_return CoffRemoveFileLinks(coff_file_handle coff_file_hnd)
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

void free_elf_file_hnd(elf_file_handle elf_file_hnd)
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
        ORLHashTableFree(elf_file_hnd->sec_name_hash_table);
    }
    elf_file_hnd->elf_hnd->funcs->memory->FreeMemory(elf_file_hnd);
}

orl_return ElfRemoveFileLinks(elf_file_handle elf_file_hnd)
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

void free_orl_file_hnd(orl_file_handle orl_file_hnd)
{
    orl_file_hnd->orl_hnd->funcs->memory->FreeMemory(orl_file_hnd);
}

orl_return ORLRemoveFileLinks(orl_file_handle orl_file_hnd)
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

omf_handle OmfInit(orl_funcs* funcs)
{
    omf_handle oh = (omf_handle)funcs->memory->AllocateMemory(sizeof(omf_handle_struct));
    if (!oh) return(NULL);
    oh->funcs = funcs;
    oh->first_file_hnd = NULL;
    return(oh);
}

orl_return OmfFini(omf_handle oh)
{
    orl_return err;

    while (oh->first_file_hnd != NULL) {
        err = OmfRemoveFileLinks(oh->first_file_hnd);
        if (err != ORL_OKAY) return(err);
    }
    oh->funcs->memory->FreeMemory(oh);
    return(ORL_OKAY);
}

coff_handle CoffInit(orl_funcs* funcs)
{
    coff_handle coff_hnd = (coff_handle)funcs->memory->AllocateMemory(sizeof(coff_handle_struct));
    if (!coff_hnd) return(NULL);
    coff_hnd->funcs = funcs;
    coff_hnd->first_file_hnd = NULL;
    return(coff_hnd);
}

orl_return CoffFini(coff_handle coff_hnd)
{
    orl_return                                  error;

    while (coff_hnd->first_file_hnd != NULL) {
        error = CoffRemoveFileLinks(coff_hnd->first_file_hnd);
        if (error != ORL_OKAY) return(error);
    }
    coff_hnd->funcs->memory->FreeMemory(coff_hnd);
    return(ORL_OKAY);
}

elf_handle ElfInit(orl_funcs* funcs)
{
    elf_handle elf_hnd = (elf_handle)funcs->memory->AllocateMemory(sizeof(elf_handle_struct));
    if (!elf_hnd) return(NULL);
    elf_hnd->funcs = funcs;
    elf_hnd->first_file_hnd = NULL;
    return(elf_hnd);
}

orl_return ElfFini(elf_handle elf_hnd)
{
    orl_return                                  error;

    while (elf_hnd->first_file_hnd != NULL) {
        error = ElfRemoveFileLinks(elf_hnd->first_file_hnd);
        if (error != ORL_OKAY) return(error);
    }
    elf_hnd->funcs->memory->FreeMemory(elf_hnd);
    return(ORL_OKAY);
}

orl_handle ORLInit(orl_funcs* funcs)
{
    orl_handle orl_hnd = (orl_handle)funcs->memory->AllocateMemory(sizeof(orl_handle_struct));
    if (!orl_hnd) return(NULL);
    orl_hnd->error = ORL_OKAY;
    orl_hnd->funcs = funcs;
    orl_hnd->elf_hnd = ElfInit(funcs);
    if (!(orl_hnd->elf_hnd)) {
        funcs->memory->FreeMemory(orl_hnd);
        return(NULL);
    }
    orl_hnd->coff_hnd = CoffInit(funcs);
    if (!(orl_hnd->coff_hnd)) {
        funcs->memory->FreeMemory(orl_hnd);
        return(NULL);
    }
    orl_hnd->omf_hnd = OmfInit(funcs);
    if (!(orl_hnd->omf_hnd)) {
        funcs->memory->FreeMemory(orl_hnd);
        return(NULL);
    }
    orl_hnd->first_file_hnd = NULL;
    return(orl_hnd);
}

orl_return ORLFini(orl_handle orl_hnd)
{
    orl_return                  error;

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
