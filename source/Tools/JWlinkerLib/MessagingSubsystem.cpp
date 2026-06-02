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
