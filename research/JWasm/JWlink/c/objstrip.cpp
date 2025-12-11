#include "pch.h"
#include "globals.h"
#include "objstrip.h"

/* data structure used to keep track of all the edges in the call graph */

typedef struct edgelist {
    struct edgelist* next;
    union {
        segdata* seg;
        symbol* sym;
    } u;
    unsigned            issym : 1;      // true if contains a symbol
    unsigned            reverse_dir : 1;// true if edge points in the opposite
    // direction
} edgelist;

static edgelist* FreedEdges;

/* some handy routines for dealing with edges. */

void ResetObjStrip(void)
{
    FreedEdges = NULL;
}
