#include "pch.h"
#include "linkstd.h"
#include "virtmem.h"
#include "pcobj.h"
#include "alloc.h"
#include "specials.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "objnode.h"
#include "objcalc.h"
#include "objpass1.h"
#include "objomf.h"
#include "overlays.h"
#include "objio.h"
#include "dbgall.h"
#include "objstrip.h"
#include "objcache.h"
#include "omfreloc.h"
#include "ring.h"
#include "wcomdef.h"

/* these are handy constants used when processing comdat records */
#define CDAT_ALLOC_MASK         0xF
#define CDAT_CONTINUATION       0x1
#define CDAT_ITERATED           0x2
#define CDAT_STATIC             0x4
#define CDAT_SELECT_MASK        0xF0
#define CDAT_SELECT_SHIFT       12

#if 0
static char* CDatClassNames[] = {
        CodeClassName,
        FarDataClassName,
        CodeClassName,
        DataClassName
};

static seg_leader* CDatSegments[4];
static unsigned         CDatSegNum;     /* for making the comdat seg. name */

/* keep a base-36 number after the COMDAT_SEG to differentiate the segments*/
/* 32-bit unsigned int gives a maximum of 7 digits in base 36. */
#define CDAT_SEG_NAME "COMDAT_SEG\0\0\0\0\0\0\0\0"
static char     CDatSegName[] = CDAT_SEG_NAME;

#define CDAT_SEG_NAME_LEN sizeof(CDatSegName)
#define CDAT_SEG_NUM_OFF  10
#endif

#if BORLAND_EXT==0
#define FindSegNode FindNode
#else
void* FindSegNode(NODEARRAY* list, unsigned index);
#endif

static comdat_info* CDatList;
static comdat_info* FreedInfos;
static comdat_piece* FreedPieces;

void ResetComdef(void)
{
#if 0
    memcpy(CDatSegName, CDAT_SEG_NAME, CDAT_SEG_NAME_LEN);
    CDatSegments[0] = NULL;
    CDatSegments[1] = NULL;
    CDatSegments[2] = NULL;
    CDatSegments[3] = NULL;
    CDatSegNum = 0;
#endif
    CDatList = NULL;
    FreedInfos = NULL;
    FreedPieces = NULL;
}
