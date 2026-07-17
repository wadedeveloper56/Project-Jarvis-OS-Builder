#pragma once

#include <stdint.h>
#include "Structs.h"
//#define MSG_MAX_ERR_MSG_NUM 180
//#define MSG_TARGET_DISP_IGNORED 180
#define MSG_ARRAY_SIZE ((MSG_MAX_ERR_MSG_NUM / 8) + 1)

#define BAN_VER_STR "2.0"

#define _I86WCGL_VERSION_       BAN_VER_STR
#define _386WCGL_VERSION_       BAN_VER_STR
#define _WCC_VERSION_           BAN_VER_STR
#define _WPP_VERSION_           BAN_VER_STR
#define _WCL_VERSION_           BAN_VER_STR
#define _WFC_VERSION_           BAN_VER_STR
#define _WFL_VERSION_           BAN_VER_STR
#define _WLINK_VERSION_         BAN_VER_STR
#define _BPATCH_VERSION_        BAN_VER_STR
#define _MOUSEFIX_VERSION_      BAN_VER_STR
#define _XXXSERV_VERSION_       BAN_VER_STR
#define _RFX_VERSION_           BAN_VER_STR
#define _WVIDEO_VERSION_        BAN_VER_STR
#define _WD_VERSION_            BAN_VER_STR
#define _WBED_VERSION_          BAN_VER_STR
#define _WCEXP_VERSION_         BAN_VER_STR
#define _WATFOR77_VERSION_      BAN_VER_STR
#define _WHELP_VERSION_         BAN_VER_STR
#define _WDISASM_VERSION_       BAN_VER_STR
#define _FCENABLE_VERSION_      BAN_VER_STR
#define _MS2WLINK_VERSION_      BAN_VER_STR
#define _EXE2BIN_VERSION_       BAN_VER_STR
#define _WLIB_VERSION_          BAN_VER_STR
#define _WMAKE_VERSION_         BAN_VER_STR
#define _WOMP_VERSION_          BAN_VER_STR
#define _WPROF_VERSION_         BAN_VER_STR
#define _WSAMP_VERSION_         BAN_VER_STR
#define _WSTRIP_VERSION_        BAN_VER_STR
#define _WTOUCH_VERSION_        BAN_VER_STR
#define _WBIND_VERSION_         BAN_VER_STR
#define _PERES_VERSION_         BAN_VER_STR
#define _EDBIND_VERSION_        BAN_VER_STR
#define _WASM_VERSION_          BAN_VER_STR
#define _WBRW_VERSION_          BAN_VER_STR
#define _WBRG_VERSION_          BAN_VER_STR
#define _VIPER_VERSION_         BAN_VER_STR
#define _RESEDIT_VERSION_       BAN_VER_STR
#define _WRC_VERSION_           BAN_VER_STR
#define _SPY_VERSION_           BAN_VER_STR
#define _HEAPWALKER_VERSION_    BAN_VER_STR
#define _DDESPY_VERSION_        BAN_VER_STR
#define _DRWATCOM_VERSION_      BAN_VER_STR
#define _DRNT_VERSION_          BAN_VER_STR
#define _ZOOM_VERSION_          BAN_VER_STR
#define _VI_VERSION_            BAN_VER_STR
#define _ASAXP_CLONE_VERSION_   BAN_VER_STR
#define _CL_CLONE_VERSION_      BAN_VER_STR
#define _CVTRES_CLONE_VERSION_  BAN_VER_STR
#define _LIB_CLONE_VERSION_     BAN_VER_STR
#define _LINK_CLONE_VERSION_    BAN_VER_STR
#define _NMAKE_CLONE_VERSION_   BAN_VER_STR
#define _RC_CLONE_VERSION_      BAN_VER_STR
#define _WIC_VERSION_           BAN_VER_STR
#define _WGML_VERSION_          BAN_VER_STR

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
	FTL = 0x00050000 + OUT_TERM + OUT_MAP,
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

pick(PRODUCT, banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT, banner2("1985")),
pick(TRADEMARK, banner3),
};

#define MSG_LANG_SPACING        1000
#define RESOURCE_MAX_SIZE       128
#define MAX_MSG_SIZE 512

#if 0
#define IDV     "** EXPERIMENTAL ** "
#elif _DEVELOPMENT == _ON
#define IDV   " **INTERNAL DEVELOPMENT** "
#else
#define IDV
#endif

enum message_texts
{
	MSG_PRODUCT,
	MSG_COPYRIGHT,

#undef pick
#define pick( code, string )  code,
#include   "lnkerror.msg"
#include   "wlink.msg"
#include   "rc.msg"
#undef pick

};
#define IS_VOWEL(c) (((c)=='a')||((c)=='e')||((c)=='i')||((c)=='o')||((c)=='u'))

class MessagingSubsystem
{
public:
	MessagingSubsystem();
	~MessagingSubsystem();
};
