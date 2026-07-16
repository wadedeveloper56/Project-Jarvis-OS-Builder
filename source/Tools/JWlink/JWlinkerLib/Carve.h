#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"

typedef struct blk blk_t;
typedef struct free_t free_t;

struct blk
{
    blk_t* next;
    unsigned    index;
    unsigned    modified : 1;
    unsigned : 15;
    char        data[1];
};

struct free_t
{
    free_t* next_free;
};

#define _REMOVE_FROM_FREE( pcv, p ) \
    { \
        free_t *head = pcv->free_list; \
        pcv->free_list = head->next_free; \
        p = head; \
    }

#define _ADD_TO_FREE( fl, p ) \
    { \
        free_t *node = (free_t *) (p); \
        node->next_free = (fl); \
        (fl) = node; \
    }

#define DbgZapAlloc( tgt, size )
#define DbgZapFreed( tgt, size )
#define CarveDebugFree( cv, elm )

class Carve
{
    MemorySubsystem* memorySubsystem;
    cv_t* cv;
public:
	Carve(MemorySubsystem* memorySubsystem);
	~Carve();
    void CarveCreate(size_t elm_size, size_t blk_size);
    void CarveDestroy();
    void* CarveAlloc();
    void CarveFree(void* elm);
};

