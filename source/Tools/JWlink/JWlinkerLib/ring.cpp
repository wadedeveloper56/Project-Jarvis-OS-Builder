#include "pch.h"
#include "Ring.h"

#ifdef PARAM2
#define RINGNAME( name ) Ring2##name
#else
#define RINGNAME( name ) Ring##name
#endif

typedef struct ring RING;
struct ring
{
#ifdef PARAM2
	void* filler;
#endif
	RING* next;
};

#define RingIterBeg( h, i ) \
    if( i = h ) { \
        RING* _T = i; \
        do { \
            i = i->next;

#define RingIterEnd( i ) \
        } while( i != _T ); \
    }

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

#define verifyNotInRing( h, r )

void RINGNAME(Append) (void* hdr, void* element)
{
	RING** rhdr;                // - ring header
	RING* relement;             // - ring element
	RING* lelement;             // - last ring element, before appending

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	verifyNotInRing(*rhdr, relement);
	lelement = *rhdr;
	if (lelement == NULL)
	{
		relement->next = relement;
	}
	else
	{
		relement->next = lelement->next;
		lelement->next = relement;
	}
	*rhdr = relement;
}

