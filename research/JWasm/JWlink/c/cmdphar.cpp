#include "pch.h"
#include "formats.h"
#include "globals.h"
#include "cmdphar.h"
#include "cmdline.h"
#include "mem.h"
#include "exephar.h"
#include "cmdos2.h"

void SetPharFmt(void)
/****************************/
{
    Extension = E_PROTECT;
    LinkState &= ~MAKE_RELOCS;     // do not generate relocations.
    _ChkAlloc(rtpblock*,FmtData.u.phar.params, sizeof(*FmtData.u.phar.params));
    FmtData.u.phar.mindata = 0;
    FmtData.u.phar.maxdata = 0xFFFFFFFF;
    FmtData.u.phar.breaksym = NULL;
    FmtData.u.phar.stub = NULL;
    //  FmtData.u.phar.pack = FALSE;
    FmtData.u.phar.params->minreal = 0;
    FmtData.u.phar.params->maxreal = 0;
    FmtData.u.phar.params->callbufs = 0;
    FmtData.u.phar.params->realbreak = 0;
    FmtData.u.phar.params->minibuf = 1;
    FmtData.u.phar.params->maxibuf = 4;
    FmtData.u.phar.params->nistack = 4;
    FmtData.u.phar.params->istksize = 1;
    FmtData.u.phar.params->extender_flags = 0;
    FmtData.u.phar.params->unpriv = 0;
    ChkBase(4 * 1024);
}

void FreePharFmt(void)
/*****************************/
{
    _LnkFree(FmtData.u.phar.breaksym);
    _LnkFree(FmtData.u.phar.params);
    _LnkFree(FmtData.u.phar.stub);
}
