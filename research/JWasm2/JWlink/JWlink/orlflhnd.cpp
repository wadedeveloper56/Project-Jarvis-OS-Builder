#include "pch.h"
#include "orllevel.h"
#include "orlflhnd.h"

void free_orl_file_hnd(orl_file_handle orl_file_hnd)
{
    orl_file_hnd->orl_hnd->funcs->free(orl_file_hnd);
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
