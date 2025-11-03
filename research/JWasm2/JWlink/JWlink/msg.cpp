#include "pch.h"
#include "linkstd.h"
#include "command.h"
#include "wlnkmsg.h"
#include "fileio.h"
#include "mapio.h"
#include "loadfile.h"
#include "demangle.h"
#include "banner.h"
#include "msg.h"

#undef pick
#define pick( num, string ) string
bool            BannerPrinted;
static const char* MsgStrings[] = {
pick(PRODUCT,                  banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT,                banner2("1985")),
pick(TRADEMARK,                banner3),
};

static  char* LocFile;
static  char* LocMem;
static  int             LocRec;
static  MSG_ARG_LIST    MsgArgInfo;
static  char* CurrSymName;

void LnkMsg(unsigned num,char* types,...)
{
}

