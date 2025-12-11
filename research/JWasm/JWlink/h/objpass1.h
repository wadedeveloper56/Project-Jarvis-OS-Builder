#pragma once

#include "globals.h"

struct objbuff;

typedef struct {
    void* (*getstart)(struct objbuff*);
    void    (*setstart)(struct objbuff*, void*);
    bool    (*isend)(struct objbuff*);
    char* (*getname)(struct objbuff*);
    struct objbuff* ob;
} vflistrtns;

typedef struct cdat_piece {
    struct cdat_piece* next;
    unsigned_8* data;
    offset              length;
    unsigned            free_data : 1;
} comdat_piece;

typedef struct cdat_info {
    struct cdat_info* next;
    segdata* sdata;
    symbol* sym;
    comdat_piece* pieces;
    sym_info            flags;
} comdat_info;

void ResetObjPass1(void);
void FreeLeader(void* seg);
