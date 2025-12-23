#include "pch.h"
#include "globals.h"
#include "ring.h"

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
    if( i == h ) { \
        RING* _T = i=nullptr; \
        do { \
            i = i->next;

#define RingIterEnd( i ) \
        } while( i != _T ); \
    }

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
		}
	} RingIterEnd(curr)
}
#else
#define verifyNotInRing( h, r )
#endif

Ring::Ring(MemorySubsystem* memory, Carve* carve)
{
	this->memory = memory;
	this->carve = carve;
}

Ring::~Ring()
{
}

void Ring::RINGNAME(Append) (void* hdr, void* element)
{
	RING** rhdr;                   
	RING* relement;                
	RING* lelement;                   

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

void* Ring::RINGNAME(Promote)(void* hdr,void* elt,void* prv)
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
		return element;
	}
	if (last != element) {
		prev->next = element->next;
		element->next = last->next;
		last->next = element;
	}
	else {
		last = prev;
	}
	*(RING**)hdr = last;
	return element;
}


void Ring::RINGNAME(Insert) (             
	void* hdr,                       
	void* element,                   
	void* insert)                     
{
	RING** rhdr;                   
	RING* relement;                   
	RING* ielement;                  
	RING* lelement;                   

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	verifyNotInRing(*rhdr, relement);
	ielement = (RING*)insert;
	lelement = *rhdr;
	if ((lelement == nullptr) || (lelement == ielement)) {
		RINGNAME(Append)(hdr, element);
	}
	else if (ielement == nullptr) {       
		relement->next = lelement->next;
		lelement->next = relement;
	}
	else {
		relement->next = ielement->next;
		ielement->next = relement;
	}
}


void Ring::RINGNAME(Walk) (void* hdr,void (*rtn)(void* curr))               
{
	RING* relement = nullptr;                
	RingIterBegSafe(hdr, relement) {
		(*rtn)(relement);
	} RingIterEndSafe(relement)
}


void* Ring::RINGNAME(Pred)(                
	void* hdr,                     
	void* element)               
{
	RING* rhdr;                    
	RING* pred;                    
	RING* next;                    

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

void* Ring::RINGNAME(PruneWithPrev) (         
	void* hdr,                       
	void* element,                   
	void* prv)                      
{
	RING** rhdr;                     
	RING* relement;                  
	RING* prev;                    

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


void* Ring::RINGNAME(Prune) (              
	void* hdr,                       
	void* element)                  
{
	RING** rhdr;                     
	RING* relement;                  
	RING* prev;                    

	rhdr = (RING**)hdr;
	relement = (RING*)element;
	prev = (RING*)RINGNAME(Pred)(*rhdr, relement);
	return(RINGNAME(PruneWithPrev)(hdr, element, prev));
}


void* Ring::RINGNAME(Push) (                
	void* hdr,                       
	void* element)                  
{
	RING** rhdr;                     
	RING* last;                    
	RING* relement;                  

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

void* Ring::RINGNAME(Last) (               
	void* hdr)                    
{
	return hdr;
}

void* Ring::RINGNAME(First) (              
	void* hdr)                    
{
	return ((RING*)hdr)->next;
}

void* Ring::RINGNAME(Pop) (                
	void* hdr)                      
{
	RING** rhdr;                     
	RING* last;                    
	RING* first;                   

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


void* Ring::RINGNAME(Lookup) (           
	void* hdr,                     
	bool (*compare_rtn)            
	(void* element,           
		void* comparand),       
	void* comparand)         
{
	RING* rhdr;                    
	RING* curr;                    

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


int Ring::RINGNAME(Count) (                
	void* hdr)                    
{
	int count;                     
	RING* curr = nullptr;                    

	count = 0;
	RingIterBeg(hdr, curr) {
		++count;
	} RingIterEnd(curr)
		return count;
}

void* Ring::RINGNAME(Alloc) (void* hdr, size_t size)
{
	void* new_element = (void*)memory->AllocateMemory(size);             
	RINGNAME(Append)(hdr, new_element);
	return(new_element);
}

void Ring::RINGNAME(Dealloc)(void* hdr, void* element)
{
	RINGNAME(Prune)(hdr, element);
	_LnkFree(element);
}


void Ring::RINGNAME(Free)(void* hdr)
{
	void* elt;

	for (;;) {
		elt = RINGNAME(Pop)(hdr);
		if (elt == nullptr) break;
		_LnkFree(elt);
	}
}

void* Ring::RINGNAME(CarveAlloc) (carve_t carver, void* hdr)
{
	void* elt;

	elt = carve->CarveAlloc(carver);
	RINGNAME(Append)(hdr, elt);
	return elt;
}


void Ring::RINGNAME(CarveFree) (carve_t carver, void* hdr)
{
	void* elt;

	for (;;) {
		elt = RINGNAME(Pop)(hdr);
		if (elt == nullptr) break;
		carve->CarveFree(carver, elt);
	}
}


void* Ring::RINGNAME(Step) (            
	void* hdr,             
	void* elt)               
{
	RING* rhdr;            
	RING* relt;            

	rhdr = (RING*)hdr;
	if (elt == nullptr) {
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
