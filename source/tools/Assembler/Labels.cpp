#include "Assembler.h"

void init_block(union label* blk)
{
    for (int j = 0; j < LABEL_BLOCK - 1; j++)
        blk[j].admin.movingon = END_LIST;
    blk[LABEL_BLOCK - 1].admin.movingon = END_BLOCK;
    blk[LABEL_BLOCK - 1].admin.next = NULL;
}

int init_labels(void)
{
    ldata = lfree = (label *)nasm_malloc(LBLK_SIZE);
    init_block(lfree);
    perm_head = perm_tail = (struct permts*)nasm_malloc(sizeof(struct permts));
    perm_head->next = NULL;
    perm_head->size = PERMTS_SIZE;
    perm_head->usage = 0;
    prevlabel = "";
    initialized = true;
    return 0;
}
