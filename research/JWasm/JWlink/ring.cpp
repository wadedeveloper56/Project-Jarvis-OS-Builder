#include "pch.h"
#include "ring.h"
#include "alloc.h"

typedef struct ring RING;
struct ring                     // model of a ring
{
#ifdef PARAM2
    void* filler;
#endif
    RING* next;                 // - points to next
};

void* RINGNAME(Pop) (          // PRUNE FIRST ELEMENT IN THE RING
    void* hdr)                 // - addr( ring header )
{
    RING** rhdr;                // - addr( ring header )
    RING* last;                 // - last element
    RING* first;                // - first element

    rhdr = (RING**)hdr;
    first = NULL;
    last = *rhdr;
    if (last != NULL) {
        first = last->next;
        if (first == last) {
            *rhdr = NULL;
        }
        else {
            last->next = first->next;
        }
    }
    return(first);
}


void RINGNAME(Free) (           // FREE ALL ELEMENTS IN A RING
    void* hdr)                 // - addr( ring header )
{
    void* elt;

    for (;;) {
        /* modify ring in an atomic manner */
        elt = RINGNAME(Pop)(hdr);
        if (elt == NULL) break;
        _LnkFree(elt);
    }
}
