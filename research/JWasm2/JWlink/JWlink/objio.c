#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include "linkstd.h"
#include "pcobj.h"
#include "msg.h"
#include "alloc.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "strtab.h"
#include "carve.h"
#include "permdata.h"
#include "objio.h"

void InitTokBuff(void)

{
    TokSize = MAX_HEADROOM;
    _ChkAlloc(char *, TokBuff, MAX_HEADROOM);
}

void FreeTokBuffs(void)
{
    if (TokBuff != NULL) {
        _LnkFree(TokBuff);
        TokBuff = NULL;
    }
}