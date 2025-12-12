#pragma once

#define MSG_LANG_SPACING        1000

enum message_texts {
	MSG_PRODUCT,
	MSG_COPYRIGHT,

#undef pick
#define pick( code, string )  code,
#include   "lnkerror.msg"
#include   "wlink.msg"
#include   "rc.msg"
#undef pick

};