#include "pch.h"
#include "walloca.h"
#include "linkstd.h"
#include "newmem.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
//#include "ostype.h"
#include "spillio.h"
#include "loadfile.h"
#include "fileio.h"
#include "virtmem.h"
/* flags used in the virtual memory structure */
typedef enum {
    VIRT_INMEM = 0x01,      // virtual memory block is in RAM
    VIRT_HUGE = 0x02       // virtual memory block is a huge block
} virt_flags;

typedef union {
    unsigned long   spill;
    void* addr;
} spilladdr;

/* this is for allocating very large memory requests (i.e. > 1 megabyte).
   virtual memory locations 0x80000000 and above are split into 1 megabyte
   pages.

   offset into subpage         subpage #  page #       big-page indicator
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   15 bits                   | 5 bits  | 11 bits             |1|
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
low-order                           high-order

each page pointer in the huge_table structure points to an array of 32
spill addresses, each of which points to a 32K-byte subpage of virtual memory.
*/

typedef struct huge_table {
    struct huge_table* next;       // next entry to swap.
    virt_flags          flags;
    unsigned_8          numthere;
    unsigned_8          numswapped;
    unsigned_16         sizelast;
    spilladdr* page;
} huge_table;

#define HUGE_OFFSET_SHIFT   20
#define MAX_BIGNODE_SIZE    (1UL << HUGE_OFFSET_SHIFT)
#define HUGE_OFFSET_MASK    (MAX_BIGNODE_SIZE - 1)
#define HUGE_BIT_MASK       0x7FFFFFFFUL
#define HUGE_PAGE           0x80000000UL
#define HUGE_INITIAL_ALLOC  2
#define HUGE_LIMIT          2048       /* max number of huge pages */
#define HUGE_SUBPAGE_SHIFT  15
#define HUGE_SUBPAGE_SIZE   (1 << HUGE_SUBPAGE_SHIFT)
#define HUGE_SUBPAGE_MASK   (HUGE_SUBPAGE_SIZE - 1)
#define HUGE_NUM_SUBPAGES   32

#define BIGNODE( stg )  (&HugeTab[(stg & HUGE_BIT_MASK) >> HUGE_OFFSET_SHIFT])
#define SUBPAGENUM(stg)     ((stg & HUGE_OFFSET_MASK) >> HUGE_SUBPAGE_SHIFT)

#define BIGNODE_OFF( stg )  (stg & HUGE_SUBPAGE_MASK)

/* the following structures are for "normal" virtual memory allocation */

typedef struct seg_table {
    struct seg_table* next;       // next entry to swap out.
    virt_flags              flags;
    unsigned_16             size;
    spilladdr               loc;
} seg_table;

/* the seg tables are referenced by an array of pointers, something like
SegTab --> 0 1 2 3 4 5 6 ...        <-- array elements are pointers
           | | | | | | |
           v v v v v v v
           1 1 1 1 1 1 1    <-  array elements are seg_tables
           2 2 2 2 2 2 2   these arrays are referred to as "branches",
           3 3 3 3 3 3 3   and the individual elements are called "leaves".

in other words, it is effectively a dynamically allocated 2 dimensional array.
All virtual memory locations from 0 - 0x7FFFFFFF are split into 4K pages.

a virtual memory address is split into three parts:
offset                   leaf id   branch id
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   12 bits             | 4 bits|  15 bits                    |0|
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 low order word                 high order word.
the leaf id chooses which element of the branch is the correct seg_table.
 0 means that the bit is always zero.
*/

// this structure is used for picking the high order word off a long
typedef struct wordpick {
    unsigned_16 low;
    unsigned_16 high;
} wordpick;

// this is used instead of the virt_mem type inside this module, since it is
// desirable to be able to get the high order word without having to do a
// 16-bit shift. MAKE SURE THAT VIRT_MEM IS THE SAME SIZE AS THIS STRUCTURE!
typedef union {
    unsigned_32     l;
    wordpick        w;
} virt_struct;

#define OFFSET_SHIFT      12
#define MAX_NODE_SIZE     (1U << OFFSET_SHIFT)
#define MAX_LEAFS         16            // maximum # of leafs per branch
#define SEG_LIMIT         32767     // maximum # of branches (leafs * 16)

/* find the node for MEM_ADDR or FILE_ADDR */
#define NODE( stg )         (&SegTab[ stg.w.high ][ stg.w.low >> OFFSET_SHIFT ])

#define NODE_OFF( stg )     ( stg.w.low & (MAX_NODE_SIZE-1) )

#define TINY_BLOCK_CUTOFF 256

static huge_table* HugeTab;
static unsigned         NumHuge;
static unsigned         NextHuge;
static seg_table** SegTab;
static unsigned         NumBranches;
// start with branch # 1 so an address of zero can be illegal.
static unsigned         CurrBranch;
static unsigned         NextLeaf;       // next leaf # to be allocated.
static seg_table* NextSwap;       // next entry to swap out.
static unsigned         TinyLeft;
static virt_mem         TinyAddr;

bool SwapOutVirt(void)
{
    spilladdr* spillmem;
    void* mem;
    seg_table* seg_entry;
    huge_table* huge_entry;
    unsigned        size;

    while (NextSwap != NULL) {
        seg_entry = NextSwap;
        NextSwap = NextSwap->next;
        if (seg_entry->flags & VIRT_INMEM) {
            if (seg_entry->flags & VIRT_HUGE) {
                huge_entry = (huge_table*)seg_entry;
                spillmem = &huge_entry->page[huge_entry->numswapped];
                mem = (*spillmem).addr;
                huge_entry->numswapped++;
                if (huge_entry->numthere == huge_entry->numswapped) {
                    seg_entry->flags = (virt_flags)(seg_entry->flags & ~VIRT_INMEM);
                    size = huge_entry->sizelast;
                }
                else {
                    size = HUGE_SUBPAGE_SIZE;
                }
                (*spillmem).spill = SpillAlloc(size);
                SpillWrite((*spillmem).spill, 0, mem, size);
                _LnkFree(mem);
            }
            else {
                seg_entry->flags = (virt_flags)(seg_entry->flags & ~VIRT_INMEM);
                mem = seg_entry->loc.addr;
                seg_entry->loc.spill = SpillAlloc(seg_entry->size);
                SpillWrite(seg_entry->loc.spill, 0, mem, seg_entry->size);
                _LnkFree(mem);
            }
            DEBUG((DBG_VIRTMEM, "swapping out %h to %h", mem,
                seg_entry->loc.spill));
            return(TRUE);
        }
    }
    return(FALSE);
}

void VirtMemInit(void)
{
    NumHuge = HUGE_INITIAL_ALLOC;
    NextHuge = 0;
    NumBranches = 127;
    CurrBranch = 1;
    NextLeaf = 0;
    NextSwap = NULL;
    TinyLeft = 0;
    _ChkAlloc(seg_table **, SegTab, NumBranches * sizeof(seg_table*));
    memset(SegTab, 0, NumBranches * sizeof(seg_table*));
    SegTab[1] = (seg_table *)PermAlloc(sizeof(seg_table) * MAX_LEAFS);
    memset(SegTab[1], 0, sizeof(seg_table) * MAX_LEAFS);
    _ChkAlloc(huge_table *, HugeTab, NumHuge * sizeof(huge_table));
    memset(HugeTab, 0, NumHuge * sizeof(huge_table));
}

