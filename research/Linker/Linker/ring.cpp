#include "pch.h"
#include "linkstd.h"
#include "ring.h"
#include "alloc.h"

#ifdef PARAM2
#define RINGNAME( name ) Ring2##name
#else
#define RINGNAME( name ) Ring##name
#endif

typedef struct ring RING;
struct ring                     // model of a ring
{
#ifdef PARAM2
    void* filler;
#endif
    RING* next;                 // - points to next
};

// following assume that ring will not be modified

#define RingIterBeg( h, i ) \
    if( i = h ) { \
        RING* _T = i; \
        do { \
            i = i->next;

#define RingIterEnd( i ) \
        } while( i != _T ); \
    }

// following allow ring to be modified

#define RingIterBegSafe( h, i ) \
    if( i = h ) { \
        RING* _T = i; \
        RING* _N = _T->next; \
        do { \
            i = _N; \
            _N = i->next;

#define RingIterEndSafe( i ) \
        } while( i != _T ); \
    }

#ifndef NDEBUG
static void verifyNotInRing(RING* ring, RING* elt)
{
    RING* curr;

    RingIterBeg(ring, curr) {
        if (curr == elt) {
            //FIX ME LnkFatal("trying to insert element twice into a ring");
        }
    } RingIterEnd(curr)
}
#else
#define verifyNotInRing( h, r )
#endif


void RINGNAME(Append) (         // APPEND ELEMENT TO RING
    void* hdr,                  // - addr( ring header )
    void* element)             // - element to be appended
{
    RING** rhdr;                // - ring header
    RING* relement;             // - ring element
    RING* lelement;             // - last ring element, before appending

    rhdr = (RING**)hdr;
    relement = (RING*)element;
    verifyNotInRing(*rhdr, relement);
    lelement = *rhdr;
    if (lelement == NULL) {
        relement->next = relement;
    }
    else {
        relement->next = lelement->next;
        lelement->next = relement;
    }
    *rhdr = relement;
}
