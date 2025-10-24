#pragma once
#include "globals.h"

#define EXPQUAL
#define OPTQUAL
#if defined(__UNIX__) || defined(__CYGWIN__) || defined(__DJGPP__)
#define HANDLECTRLZ 0
#define SWITCHCHAR 0
#else
#define HANDLECTRLZ 1
#define SWITCHCHAR 1
#endif

#ifdef __I86__
#define OPTQUAL __near
#else
#define OPTQUAL
#endif

extern struct global_options Options;

static void SetCpuCmdline(enum cpu_info value, const char* parm);
static void queue_item(int i, const char* string);
static void get_fname(int type, const char* token);
static void set_option_n_name(int idx, const char* name);
#if BUILD_TARGET
static void OPTQUAL Set_bt(void);
#endif
static void OPTQUAL Set_c(void);
#ifdef DEBUG_OUT
static void OPTQUAL Set_ce(void);
#endif
static void OPTQUAL Set_Cp(void);
static void OPTQUAL Set_Cu(void);
static void OPTQUAL Set_Cx(void);
static void OPTQUAL Set_Zd(void);
static void OPTQUAL Set_Zi(void);
static void OPTQUAL Set_Zp(void);
static void OPTQUAL Set_D(void);
static void OPTQUAL Set_Fi(void);
static void OPTQUAL Set_I(void);
static void OPTQUAL Set_e(void);
static void OPTQUAL Set_nologo(void);
static void OPTQUAL Set_q(void);
static void OPTQUAL Set_EP(void);
#if DLLIMPORT
static void OPTQUAL Set_Fd(void);
#endif
static void OPTQUAL Set_Fw(void);
static void OPTQUAL Set_Fl(void);
static void OPTQUAL Set_Fo(void);
static void OPTQUAL Set_fp(void);
static void OPTQUAL Set_FPx(void);
static void OPTQUAL Set_G(void);
static void OPTQUAL Set_Sa(void);
static void OPTQUAL Set_True(void);
static void OPTQUAL Set_m(void);
static void OPTQUAL Set_n(void);
#ifdef DEBUG_OUT
static void OPTQUAL Set_pm(void);
#endif
static void OPTQUAL Set_WX(void);
static void OPTQUAL Set_w(void);
static void OPTQUAL Set_W(void);
static void OPTQUAL Set_ofmt(void);
static void OPTQUAL Set_zcm(void);
#if OWFC_SUPPORT
static void OPTQUAL Set_zf(void);
#endif
static void OPTQUAL Set_zt(void);
#ifndef __SW_BD
static void OPTQUAL Set_h(void);
#endif
#ifdef DEBUG_OUT
static void OPTQUAL Set_dm(void);
static void OPTQUAL Set_dt(void);
#if FASTPASS
static void OPTQUAL Set_nfp(void);
#endif
static void OPTQUAL Set_nbp(void);
#endif

struct  cmdloption {
    const char* name;
    unsigned    value;
    void OPTQUAL(*function)(void);
};

#define optofs( x ) offsetof( struct global_options, x )

static const char* GetNameToken(char* dst, const char* str, int max, char type);

static char* ReadParamFile(const char* name);

static const char* getnextcmdstring(const char** cmdline);

static const char* GetNumber(const char* p);

#if SWITCHCHAR
#define IsOptionDelimiter( x ) (x == ' ' || x == '-' || x == '/' || x == NULLC || x == '\t' )
#else
#define IsOptionDelimiter( x ) (x == ' ' || x == '-' || x == NULLC || x == '\t' )
#endif

static void ProcessOption(const char** cmdline, char* buffer);

#define MAX_OS_NAME_SIZE 7

static void set_default_build_target(void);
char* EXPQUAL ParseCmdline(const char** cmdline, int* pCntArgs);

void EXPQUAL CmdlineFini(void);
