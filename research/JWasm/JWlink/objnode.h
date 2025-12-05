#pragma once

#define NODE_ARRAY_SIZE 256
#define MAX_NUM_NODES   128
#define NEED_NEW_ARRAY( x ) (!((x) & 0xFF))
#define ARRAY_NUM( x )      ((x) >> 8 )
#define ELEMENT_NUM( x )    ((x) & 0xFF)

typedef struct nodearray {
    unsigned    num;            // number of nodes inserted
    unsigned    elsize;         // size of individual element in array.
    unsigned    arraymax;       // the number of node arrays allocated - 1
    char* array[MAX_NUM_NODES];   // the array.
} nodearray;

void InitNodes(void);
void BurnNodes(void);
