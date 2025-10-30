#include "pch.h"
#include "wlnkmsg.h"

static const char* const msgtexts[] = {
    "",
    "",
#undef pick
#define pick( code, string )  string,
#include "lnkerror.msg"
#include "wlink.msg"
//#include "..\sdk-rc\h\rc.msg"
#undef pick

}; 
bool  BannerPrinted;

int InitMsg(void)
{
    BannerPrinted = false;
    return(EXIT_SUCCESS);
}

int FiniMsg(void)
{
    return(EXIT_SUCCESS);
}