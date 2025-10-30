#include "pch.h"
#include "elfflhn.h"
#include "orlhash.h"

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
                        _ClientFree(elf_file_hnd, elf_sec_hnd->assoc.reloc.relocs);
                    }
                    break;
                case ORL_SEC_TYPE_SYM_TABLE:
                case ORL_SEC_TYPE_DYN_SYM_TABLE:
                    if (elf_sec_hnd->assoc.sym.symbols) {
                        _ClientFree(elf_file_hnd, elf_sec_hnd->assoc.sym.symbols);
                    }
                    break;
                default:
                    break;
            }
            _ClientFree(elf_file_hnd, elf_sec_hnd);
        }
        _ClientFree(elf_file_hnd, elf_file_hnd->elf_sec_hnd);
    }
    _ClientFree(elf_file_hnd, elf_file_hnd->orig_sec_hnd);
    if (elf_file_hnd->sec_name_hash_table) {
        ORLHashTableFree(elf_file_hnd->sec_name_hash_table);
    }
    _ClientFree(elf_file_hnd, elf_file_hnd);
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
