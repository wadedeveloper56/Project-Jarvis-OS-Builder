#pragma once

//#define RINGHNAME( name ) Ring##name

#include "MemorySubsystem.h"

class Ring
{
    MemorySubsystem* memory;
public:
    Ring(MemorySubsystem* memory);
    ~Ring();
    //void* RINGHNAME(Alloc) (void* hdr, size_t size);
    //void* RINGHNAME(CarveAlloc) (carve_t carver, void* hdr);
    //void RINGHNAME(CarveFree) (carve_t carver, void* hdr);
    //void RINGHNAME(Append) (void* hdr, void* element);
    //int RINGHNAME(Count) (void* hdr);
    //void RINGHNAME(Dealloc) (void* hdr, void* element);
    //void RINGHNAME(Free) (void* hdr);
    //void* RINGHNAME(Promote) (void* hdr,void* elt,void* prv);
    //void RINGHNAME(Insert) (void* hdr,void* element,void* insert);
    //void* RINGHNAME(Lookup) (       // LOOKUP IN A RING (also used for walks)
    //    void* hdr,                  // - ring hdr
    //    bool (*compare_rtn)         // - comparison routine
    //    (void* element,        // - - element
    //        void* comparand),    // - - comparand
    //    void* comparand)           // - comparand
    //    ;
    //void* RINGHNAME(Pop) (          // PRUNE FIRST ELEMENT IN THE RING
    //    void* hdr)                 // - addr( ring header )
    //    ;
    //void* RINGHNAME(Last) (         // RETURN LAST ELEMENT IN THE RING
    //    void* hdr)
    //    ;
    //void* RINGHNAME(First) (        // RETURN FIRST ELEMENT IN THE RING
    //    void* hdr)
    //    ;
    //void* RINGHNAME(Pred) (         // FIND PREDECESSOR ELEMENT IN A RING
    //    void* hdr,                  // - ring header
    //    void* element)             // - element
    //    ;
    //void* RINGHNAME(Prune) (        // PRUNE ELEMENT FROM A RING
    //    void* hdr,                  // - addr( ring header )
    //    void* element)             // - element to be pruned
    //    ;
    //void* RINGHNAME(PruneWithPrev) ( // PRUNE ELEMENT FROM A RING (PREV ELT AVAILABLE)
    //    void* hdr,                  // - addr( ring header )
    //    void* element,              // - element to be pruned
    //    void* prv)                 // - element just before element
    //    ;
    //void* RINGHNAME(Push) (         // INSERT ELEMENT AT START OF RING
    //    void* hdr,                  // - addr( ring header )
    //    void* element)             // - element to be pushed
    //    ;
    //void RINGHNAME(Walk) (          // TRAVERSE RING
    //    void* hdr,                  // - ring header
    //    void (*rtn)                 // - traversal routine
    //    (void* curr))         // - - passed current element
    //    ;
    //void* RINGHNAME(Step) (         // STEP ALONG ELEMENTS (nullptr -> e1 -> e2 -> nullptr)
    //    void* hdr,                  // - ring header
    //    void* elt)                 // - curr element (nullptr to start)
    //    ;
};



