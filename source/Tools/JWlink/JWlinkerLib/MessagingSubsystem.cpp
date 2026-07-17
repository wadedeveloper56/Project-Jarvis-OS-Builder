#include "pch.h"
#include "MessagingSubsystem.h"
#include "debug.h"
#include "banner.h"
#include "Structs.h"

const char* const msgtexts[] = {
	"",
	"",
#undef pick
#define pick( code, string )  string,
#include "lnkerror.msg"
#include "wlink.msg"
#include "rc.msg"
#undef pick
};

#undef pick
char* MsgStrings[] = {
#define pick( num, string ) string
pick(PRODUCT, banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT, banner2("1985")),
pick(TRADEMARK, banner3),
};

MessagingSubsystem::MessagingSubsystem()
{
	DEBUG((DBG_OLD, "MessagingSubsystem constructor\n"));
}

MessagingSubsystem::~MessagingSubsystem()
{
	DEBUG((DBG_OLD, "MessagingSubsystem destructor\n"));
}
