#include "pch.h"
#include "coffflhn.h"
#include "orlhash.h"

void free_coff_file_hnd(coff_file_handle coff_file_hnd)
{
    int                 loop;
    coff_sec_handle     coff_sec_hnd;

    if (coff_file_hnd->coff_sec_hnd) {
        for (loop = 0; loop < (int)coff_file_hnd->num_sections; loop++) {
            coff_sec_hnd = coff_file_hnd->coff_sec_hnd[loop];
            if (coff_sec_hnd->type == ORL_SEC_TYPE_RELOCS) {
                if (coff_sec_hnd->assoc.reloc.relocs) {
                    _ClientFree(coff_file_hnd, coff_sec_hnd->assoc.reloc.relocs);
                }
            }
            if (coff_sec_hnd->name_alloced) {
                _ClientFree(coff_file_hnd, coff_sec_hnd->name);
            }
            _ClientFree(coff_file_hnd, coff_file_hnd->coff_sec_hnd[loop]);
        }
        _ClientFree(coff_file_hnd, coff_file_hnd->coff_sec_hnd);
    }
    _ClientFree(coff_file_hnd, coff_file_hnd->orig_sec_hnd);
    if (coff_file_hnd->symbol_handles) {
        for (loop = 0; loop < (int)coff_file_hnd->num_symbols; loop++) {
            if (coff_file_hnd->symbol_handles[loop].name_alloced) {
                _ClientFree(coff_file_hnd, coff_file_hnd->symbol_handles[loop].name);
            }
            loop += coff_file_hnd->symbol_handles[loop].symbol->num_aux;
        }
        _ClientFree(coff_file_hnd, coff_file_hnd->symbol_handles);
    }
    if (coff_file_hnd->sec_name_hash_table) {
        ORLHashTableFree(coff_file_hnd->sec_name_hash_table);
    }
    if (coff_file_hnd->implib_data != NULL) {
        _ClientFree(coff_file_hnd, coff_file_hnd->implib_data);
    }
    _ClientFree(coff_file_hnd, coff_file_hnd);
}

void CoffAddFileLinks(coff_handle coff_hnd, coff_file_handle coff_file_hnd)
{
    coff_file_hnd->next = coff_hnd->first_file_hnd;
    coff_file_hnd->coff_hnd = coff_hnd;
    coff_hnd->first_file_hnd = coff_file_hnd;
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
