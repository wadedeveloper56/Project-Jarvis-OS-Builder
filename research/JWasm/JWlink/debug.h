#pragma once

#define _ON             1
#define _OFF            0

#define DBG_ALWAYS      0x00
#define DBG_BASE        0x01
#define DBG_OLD         0x02
#define DBG_NEW         0x04
#define DBG_LOADDOS     0x08
#define DBG_VIRTMEM     0x10
#define DBG_DEADCODE    0x20
#define DBG_DBGINFO     0x40
#define DBG_NOCRLF      0x8000
#define DBG_INFO_MASK   0x7FFF

#ifndef _DEVELOPMENT
#define _DEVELOPMENT    _OFF
#endif

#ifdef _DEBUG
#define PRINTLOC   printf("%s(line:%d) - ", __FILE__, __LINE__);
#define DEBUG( x )   PRINTLOC printf x ;
#else
#define PRINTLOC
#define DEBUG( x )
#endif
