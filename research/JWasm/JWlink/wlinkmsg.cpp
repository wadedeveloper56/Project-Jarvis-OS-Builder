#include "pch.h"
#include "wlnkmsg.h"
#include "msg.h"
#include "debug.h"

static const char* const msgtexts[] = {
    "",
    "",
#undef pick
#define pick( code, string )  string,
#include "lnkerror.msg"
#include "wlink.msg"
#include "rc.msg"
#undef pick

};

int InitMsg(void)
{
    BannerPrinted = false;
    return(EXIT_SUCCESS);
}

int FiniMsg(void)
{
    return(EXIT_SUCCESS);
}

int Msg_Get(int resourceid, char* buffer)
{
    strcpy(buffer, msgtexts[resourceid]);
    DEBUG((DBG_OLD, (char *)"Msg_Get( %h ) = %s", resourceid, buffer ))
    return(0);
}