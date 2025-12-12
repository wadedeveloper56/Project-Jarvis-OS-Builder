#pragma once

typedef struct blk blk_t;
typedef struct free_t free_t;

typedef struct {
    free_t* free_list;
    free_t* insert;
    blk_t* blk_list;
    blk_t** blk_map;
    size_t      elm_size;
    size_t      elm_count;
    size_t      blk_top;
    size_t      blk_count;
    size_t      blk_size;
    unsigned    size_chg : 1;
} cv_t, * carve_t;

struct blk {
    blk_t* next;
    unsigned    index;
    unsigned    modified : 1;
    unsigned : 15;
    char        data[1];
};

struct free_t {
    free_t* next_free;
};

// assumes '->free_list' is non-nullptr
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

void CarveVerifyAllGone(carve_t cv, char* node_name);
void CarveDestroy(carve_t cv);
void CarveFree(carve_t cv, void* elm);
void* CarveAlloc(carve_t cv);
carve_t CarveCreate(size_t elm_size, size_t blk_size);
