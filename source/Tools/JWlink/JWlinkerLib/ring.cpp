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
    if( i = (RING*)h ) { \
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
	RING** rhdr;                   
	RING* relement;                
	RING* lelement;                   

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

void* RINGNAME(Pop) (void* hdr)                      
{
    RING** rhdr;                     
    RING* last;                    
    RING* first;                   

    rhdr = (RING**)hdr;
    first = NULL;
    last = *rhdr;
    if (last != NULL)
    {
        first = last->next;
        if (first == last)
        {
            *rhdr = NULL;
        }
        else
        {
            last->next = first->next;
        }
    }
    return(first);
}

void RINGNAME(Free) (shared_ptr<MemorySubsystem> memorySubsystem,void* hdr)
{
    void* elt;

    for (;;)
    {
        elt = RINGNAME(Pop)(hdr);
        if (elt == NULL) break;
        memorySubsystem->FreeMemory(elt);
    }
}

void RINGNAME(Walk) (void* hdr,void (*rtn)(void* curr))               
{
#if 0
    RING* rhdr;                    
    RING* relement;                
    RING* nelement;                 

    if (hdr != NULL)
    {
        rhdr = hdr;
        nelement = rhdr->next;
        do
        {
            relement = nelement;
            nelement = nelement->next;
            (*rtn)(relement) );
        } while (relement != rhdr);
    }
#else
    RING* relement;                
    RingIterBegSafe(hdr, relement) {
        (*rtn)(relement);
    } RingIterEndSafe(relement)
#endif
}

void* RINGNAME(Last) (               
    void* hdr)                    
{
    return hdr;
}

void* RINGNAME(First) (              
    void* hdr)                    
{
    return ((RING*)hdr)->next;
}
