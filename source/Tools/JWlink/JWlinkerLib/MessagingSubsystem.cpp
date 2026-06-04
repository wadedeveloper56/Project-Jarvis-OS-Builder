#include "pch.h"
#include "MessagingSubsystem.h"

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

MessagingSubsystem::MessagingSubsystem()
{
}

MessagingSubsystem::~MessagingSubsystem()
{
}


int MessagingSubsystem::Msg_Get(int resourceid, char* buffer)
{
	if (resourceid < 0 || resourceid >= sizeof(msgtexts) / sizeof(msgtexts[0]))
		return 1;
	strcpy(buffer, msgtexts[resourceid]);
	return 0;
}
