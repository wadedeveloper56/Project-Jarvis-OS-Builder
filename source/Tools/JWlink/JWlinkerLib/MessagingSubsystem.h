#pragma once
class MessagingSubsystem
{
public:
	MessagingSubsystem();
	~MessagingSubsystem();
	int Msg_Get(int resourceid, char* buffer);
};

