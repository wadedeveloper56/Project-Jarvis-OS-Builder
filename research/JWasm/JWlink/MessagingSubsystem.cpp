#include "pch.h"
#include "MessagingSubsystem.h"

static char* MsgStrings[] = {
"JWlink Version 1.9beta 13",
"Portions Copyright (c) 1985-2002 Sybase, Inc. All Rights Reserved.",
"Source code is available under the Sybase Open Watcom Public License."
};

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

MessagingSubsystem::MessagingSubsystem(FileSubsystem* file)
{
	this->file = file;
}

MessagingSubsystem::~MessagingSubsystem()
{
}
