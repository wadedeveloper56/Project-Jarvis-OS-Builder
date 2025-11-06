#include "pch.h"
#include "linkstd.h"
#include "strtab.h"
#include "alloc.h"
#include "ring.h"
#include "msg.h"
#include "wlnkmsg.h"
#include <string.h>

#define STR_BLOCK_SIZE   (4*1024)
typedef struct stringblock {
    STRINGBLOCK* next;
    unsigned    size;
    char        data[STR_BLOCK_SIZE];
} stringblock;

static stringblock* AllocNewBlock(stringtable* strtab)
{
    stringblock* blk;

    _ChkAlloc(stringblock * , blk, sizeof(stringblock));
    blk->next = NULL;
    RingAppend(&strtab->data, blk);
    blk->size = 0;
    return blk;
}

void InitStringTable(stringtable* strtab, bool dontsplit)
{
    strtab->data = NULL;
    if (dontsplit) {
        strtab->currbase = 1;
    }
    else {
        strtab->currbase = 0;
    }
    AllocNewBlock(strtab);
}
