#include "pch.h"
#include "globals.h"
#include "ring.h"

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
    if( i == h ) { \
        RING* _T = i=nullptr; \
        do { \
            i = i->next;

#define RingIterEnd( i ) \
        } while( i != _T ); \
    }

// following allow ring to be modified

#define RingIterBegSafe( h, i ) \
    if( i == h ) { \
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
	RING* curr = nullptr;
	if (ring == nullptr) return;
	RingIterBeg(ring, curr) {
		if (curr == elt) {
			//FIX ME LnkFatal("trying to insert element twice into a ring");
		}
	} RingIterEnd(curr)
}
#else
#define verifyNotInRing( h, r )
#endif


Ring::Ring(MemorySubsystem* memory)
{
	this->memory = memory;
}

Ring::~Ring()
{
}

void Ring::RINGNAME(Append) (void* hdr,void* element)
{
	RING** rhdr;                // - ring header
	RING* relement;             // - ring element
	RING* lelement;             // - last ring element, before appending

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	verifyNotInRing(*rhdr, relement);
	lelement = *rhdr;
	if (lelement == nullptr) {
		relement->next = relement;
	}
	else {
		relement->next = lelement->next;
		lelement->next = relement;
	}
	*rhdr = relement;
}


void* Ring::RINGNAME(Promote) (       // PROMOTE ELEMENT TO START OF RING
	void* hdr,                  // - addr( ring header )
	void* elt,                  // - element to be promoted
	void* prv)                 // - element just before element
{
	RING** rhdr;
	RING* last;
	RING* prev;
	RING* element;

	rhdr = (RING**)hdr;
	prev = (RING*)prv;
	element = (RING*)elt;
	last = *rhdr;
	if (prev == nullptr || last == prev) {
		/* already at front */
		return element;
	}
	if (last != element) {
		/* delete */
		prev->next = element->next;
		/* insert at front */
		element->next = last->next;
		last->next = element;
	}
	else {
		/* last element in ring; rotate */
		last = prev;
	}
	*(RING**)hdr = last;
	return element;
}


void Ring::RINGNAME(Insert) (         // INSERT ELEMENT INTO RING
	void* hdr,                  // - addr( ring header )
	void* element,              // - element to be inserted
	void* insert)              // - insertion point (or nullptr for start)
{
	RING** rhdr;                // - ring header
	RING* relement;             // - ring element, to be inserted
	RING* ielement;             // - ring element, insertion point
	RING* lelement;             // - last ring element, before appending

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	verifyNotInRing(*rhdr, relement);
	ielement = (RING*)insert;
	lelement = *rhdr;
	if ((lelement == nullptr) || (lelement == ielement)) {
		RINGNAME(Append)(hdr, element);
	}
	else if (ielement == nullptr) {  // insert at start of ring
		relement->next = lelement->next;
		lelement->next = relement;
	}
	else {
		relement->next = ielement->next;
		ielement->next = relement;
	}
}


void Ring::RINGNAME(Walk) (           // TRAVERSE RING
	void* hdr,                  // - ring header
	void (*rtn)                 // - traversal routine
	(void* curr))          // - - passed current element
{
#if 0
	RING* rhdr;                 // - ring header
	RING* relement;             // - ring element
	RING* nelement;             // - next ring element

	if (hdr != nullptr) {
		rhdr = hdr;
		nelement = rhdr->next;
		do {
			relement = nelement;
			nelement = nelement->next;
			(*rtn)(relement) );
		} while (relement != rhdr);
	}
#else
	RING* relement = nullptr;             // - ring element
	RingIterBegSafe(hdr, relement) {
		(*rtn)(relement);
	} RingIterEndSafe(relement)
#endif
}


void* Ring::RINGNAME(Pred)(          // FIND PREVIOUS ELEMENT IN A RING
	void* hdr,                  // - ring header
	void* element)             // - element
{
	RING* rhdr;                 // - ring header
	RING* pred;                 // - previous element
	RING* next;                 // - next element

	rhdr = (RING*)hdr;
	if (rhdr == nullptr) {
		pred = nullptr;
	}
	else {
		for (pred = rhdr; ; ) {
			next = pred->next;
			if (element == next) break;
			pred = next;
			if (pred == rhdr) {
				pred = nullptr;
				break;
			}
		}
	}
	return(pred);
}

void* Ring::RINGNAME(PruneWithPrev) ( // PRUNE ELEMENT FROM A RING (PREV ELT AVAILABLE)
	void* hdr,                  // - addr( ring header )
	void* element,              // - element to be pruned
	void* prv)                 // - element just before element
{
	RING** rhdr;                // - addr( ring header )
	RING* relement;             // - element to be pruned
	RING* prev;                 // - previous element

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	prev = (RING*)prv;
	if (prev == nullptr) {
		prev = *rhdr;
	}
	prev->next = relement->next;
	if (prev == relement) {
		*rhdr = nullptr;
	}
	else {
		if (*rhdr == relement) {
			*rhdr = prev;
		}
	}
	relement->next = nullptr;
	return(relement);
}


void* Ring::RINGNAME(Prune) (         // PRUNE ELEMENT FROM A RING
	void* hdr,                  // - addr( ring header )
	void* element)             // - element to be pruned
{
	RING** rhdr;                // - addr( ring header )
	RING* relement;             // - element to be pruned
	RING* prev;                 // - previous element

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	prev = (RING*)RINGNAME(Pred)(*rhdr, relement);
	return(RINGNAME(PruneWithPrev)(hdr, element, prev));
}


void* Ring::RINGNAME(Push) (          // INSERT ELEMENT AT START OF RING
	void* hdr,                  // - addr( ring header )
	void* element)             // - element to be pushed
{
	RING** rhdr;                // - addr( ring header )
	RING* last;                 // - last element
	RING* relement;             // - element to be pruned

	rhdr = (RING**)hdr;
	last = (RING*)*rhdr;
	relement = (RING*)element;
	verifyNotInRing(last, relement);
	if (last == nullptr) {
		relement->next = relement;
		*rhdr = relement;
	}
	else {
		relement->next = last->next;
		last->next = relement;
	}
	return relement;
}

void* Ring::RINGNAME(Last) (         // RETURN LAST ELEMENT IN THE RING
	void* hdr)                 // - ring header
{
	return hdr;
}

void* Ring::RINGNAME(First) (        // RETURN FIRST ELEMENT IN THE RING
	void* hdr)                 // - ring header
{
	return ((RING*)hdr)->next;
}

void* Ring::RINGNAME(Pop) (          // PRUNE FIRST ELEMENT IN THE RING
	void* hdr)                 // - addr( ring header )
{
	RING** rhdr;                // - addr( ring header )
	RING* last;                 // - last element
	RING* first;                // - first element

	rhdr = (RING**)hdr;
	first = nullptr;
	last = *rhdr;
	if (last != nullptr) {
		first = last->next;
		if (first == last) {
			*rhdr = nullptr;
		}
		else {
			last->next = first->next;
		}
	}
	return(first);
}


void* Ring::RINGNAME(Lookup) (       // LOOKUP IN A RING
	void* hdr,                  // - ring hdr
	bool (*compare_rtn)         // - comparison routine
	(void* element,        // - - element
		void* comparand),    // - - comparand
	void* comparand)       // - comparand
{
	RING* rhdr;                 // - ring hdr
	RING* curr;                 // - current element

	if (hdr == nullptr) {
		curr = nullptr;
	}
	else {
		rhdr = (RING*)hdr;
		curr = (RING*)rhdr;
		for (; ; ) {
			curr = curr->next;
			if ((*compare_rtn)(curr, comparand)) break;
			if (curr == rhdr) {
				curr = nullptr;
				break;
			}
		};
	}
	return(curr);
}


int Ring::RINGNAME(Count) (           // COUNT ELEMENTS IN A RING
	void* hdr)                 // - ring hdr
{
	int count;                  // - number elements
	RING* curr = nullptr;                 // - current element

	count = 0;
	RingIterBeg(hdr, curr) {
		++count;
	} RingIterEnd(curr)
		return count;
}

void* Ring::RINGNAME(Alloc) (void* hdr,size_t size)
{
    void* new_element = (void *)memory->AllocateMemory(size);          // - allocated element
	RINGNAME(Append)(hdr, new_element);
	return(new_element);
}

void Ring::RINGNAME(Dealloc) (        // DE-ALLOCATE A RING ELEMENT
	void* hdr,                  // - addr( ring header )
	void* element)             // - element to be de-allocated
{
	RINGNAME(Prune)(hdr, element);
	//FIX ME _LnkFree(element);
}


void Ring::RINGNAME(Free) (           // FREE ALL ELEMENTS IN A RING
	void* hdr)                 // - addr( ring header )
{
	void* elt;

	for (;;) {
		/* modify ring in an atomic manner */
		elt = RINGNAME(Pop)(hdr);
		if (elt == nullptr) break;
		//FIX ME _LnkFree(elt);
	}
}



//************************************************************************
// NOTE:: the following use carving technology
//***********************************************************************

//#include "carve.h"


void* Ring::RINGNAME(CarveAlloc) (    // CARVER ALLOC AND APPEND AN ENTRY
	carve_t carver,             // - carving control
	void* hdr)                 // - addr( ring header )
{
	void* elt;

	elt = nullptr; //FIX ME  CarveAlloc(carver);
	RINGNAME(Append)(hdr, elt);
	return elt;
}


void Ring::RINGNAME(CarveFree) (      // CARVER FREE ALL ELEMENTS IN A RING
	carve_t carver,             // - carving control
	void* hdr)                 // - addr( ring header )
{
	void* elt;

	for (;;) {
		elt = RINGNAME(Pop)(hdr);
		if (elt == nullptr) break;
		//FIX ME CarveFree(carver, elt);
	}
}


void* Ring::RINGNAME(Step) (  // STEP ALONG ELEMENTS (nullptr -> e1 -> e2 -> nullptr)
	void* hdr,          // - ring header
	void* elt)         // - curr element (nullptr to start)
{
	RING* rhdr;         // - ring hdr
	RING* relt;         // - ring element

	rhdr = (RING*)hdr;
	if (elt == nullptr) {
		/* start traversal */
		if (rhdr != nullptr) {
			elt = rhdr->next;
		}
	}
	else {
		relt = (RING*)elt;
		if (relt != rhdr) {
			elt = relt->next;
		}
		else {
			elt = nullptr;
		}
	}
	return(elt);
}
