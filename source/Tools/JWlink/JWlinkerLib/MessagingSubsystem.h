#pragma once

#include <stdint.h>
#include "Structs.h"
#define MSG_MAX_ERR_MSG_NUM 180
#define MSG_TARGET_DISP_IGNORED 180
#define MSG_ARRAY_SIZE ((MSG_MAX_ERR_MSG_NUM / 8) + 1)

class MessagingSubsystem
{
	char* LocFile;
	char* LocMem;
	int             LocRec;
	MSG_ARG_LIST    MsgArgInfo;
	char* CurrSymName;
	uint32_t         MaxErrors;
	bool            BannerPrinted;
	::byte MsgFlags[MSG_ARRAY_SIZE];
public:
	MessagingSubsystem();
	~MessagingSubsystem();
	int Msg_Get(int resourceid, char* buffer);
	void reset();
	void Locator(char* filename, char* mem, unsigned rec);
};

