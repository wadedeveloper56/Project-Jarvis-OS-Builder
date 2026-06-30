#include "pch.h"
#include "MessagingSubsystem.h"
#include "debug.h"

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
#define pick( num, string ) string
char* MsgStrings[] = {
#if !defined(pick)
enum msg_class
{
OUT_TERM = 0x00100000,
OUT_MAP = 0x00200000,
INF = 0x00000000 + OUT_TERM,
MAP = 0x00000000 + OUT_MAP,
YELL = 0x00010000 + OUT_TERM,
WRN = 0x00020000 + OUT_TERM + OUT_MAP,
MILD_ERR = 0x00030000 + OUT_TERM + OUT_MAP,
ERR = 0x00040000 + OUT_TERM + OUT_MAP,
FTL = 0x00050000 + OUT_TERM + OUT_MAP,  /* fatal */
BANNER = 0x00060000,
LINE = 0x00080000,
LOC = 0x00400000,
LOC_REC = 0x00800000 + LOC,
CLASS_MSK = 0x00070000,
OUT_MSK = 0x00300000,
NUM_MSK = 0x0000ffff,
NUM_SHIFT = 16
};
#define pick( name, string ) name
enum msg_num
 {
#else
#include <banner.h>
#endif

#define IDV

pick(PRODUCT,                  banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT,                banner2("1985")),
pick(TRADEMARK,                banner3),
//pick( TRADEMARK2,               banner3a ),
};

MessagingSubsystem::MessagingSubsystem()
{}

MessagingSubsystem::~MessagingSubsystem()
{
	DEBUG((DBG_OLD, "MessagingSubsystem destructor\n"));
}

int MessagingSubsystem::Msg_Get(int resourceid, char* buffer)
{
	if (resourceid < 0 || resourceid >= sizeof(msgtexts) / sizeof(msgtexts[0]))
		return 1;
	strcpy(buffer, msgtexts[resourceid]);
	return 0;
}

void MessagingSubsystem::reset()
{
	LocFile = NULL;
	LocMem = NULL;
	LocRec = 0;
	MsgArgInfo.index = -1;
	memset(MsgFlags, 0xFF, MSG_ARRAY_SIZE);
}
