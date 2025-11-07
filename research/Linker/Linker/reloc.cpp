#include "pch.h"
#include "linkstd.h"
#include "alloc.h"
#include "reloc.h"
#include "fileio.h"
#include "spillio.h"
#include "loadfile.h"
#include "overlays.h"

typedef union {
    unsigned long   spill;
    void* addr;
} spilladdr;

/* note: if either of these two structures get any bigger, the magic constants
 * in the RLIDX_* macros will have to change to ensure that no allocation > 64k
 * occurs. */

typedef struct reloc_info {
    struct reloc_info* next;
    unsigned            sizeleft;
    spilladdr           loc;
} reloc_info;

typedef struct os2_reloc_header {
    reloc_info* externals; /* external and segment style fixups */
    reloc_info* internals; /* internal, non-segment fixups */
} os2_reloc_header;

#define RELOC_PAGE_SIZE 512
#define RELOC_SPILLED   0x8000
#define SIZELEFT_MASK   0x7FFF

unsigned        FmtRelocSize;
reloc_info* FloatFixups;

void ResetReloc(void)
{
    FloatFixups = NULL;
}

bool SwapOutRelocs(void)
{
	return false;
}

