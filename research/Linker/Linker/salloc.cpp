#include  "pch.h"
#include "linkstd.h"
#include "pcobj.h"
#include "msg.h"
#include "wlnkmsg.h"
#include "loadpe.h"
#include "ring.h"
#include "objcalc.h"
#include "salloc.h"

static targ_addr    DataLoc;
static targ_addr    CodeLoc;

void ResetAddr(void)
{
    CurrLoc.seg = 0;
    CurrLoc.off = 0;
    CurrentSeg = NULL;
}
