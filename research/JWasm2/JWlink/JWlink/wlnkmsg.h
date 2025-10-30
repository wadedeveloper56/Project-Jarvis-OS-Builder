#pragma once

enum message_texts {
	MSG_PRODUCT,
	MSG_COPYRIGHT,

#undef pick
#define pick( code, string )  code,
#include   "lnkerror.msg"
#include   "wlink.msg"
//#include   "..\sdk-rc\h\rc.msg"
#undef pick

};
extern bool BannerPrinted;

int InitMsg(void);
int FiniMsg(void);
