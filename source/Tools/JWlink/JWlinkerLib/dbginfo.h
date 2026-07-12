#pragma once

#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

#define EXE_MAJOR_VERSION   3
#define EXE_MINOR_VERSION   0

#define ADDR_INFO_LIMIT ( 63 * 1024U / sizeof( addrinfo ) )
#define DEMAND_INFO_SPLIT ( 16 * 1024 )

#define NON_SECT_INFO 0x8000


typedef struct snamelist
{
    struct snamelist* next;
    ::byte                len;
    char                name[1];
} snamelist;

typedef struct dbgheader
{
    uint16_t         signature;
    uint8_t          exe_major_ver;
    uint8_t          exe_minor_ver;
    uint8_t          obj_major_ver;
    uint8_t          obj_minor_ver;
    uint16_t         lang_size;
    uint16_t         seg_size;
    uint32_t         debug_size;
} dbgheader;

extern uint32_t  DBISize;
extern dbgheader    Master;
extern snamelist* DBISourceLang;

#ifdef _INT_DEBUG
struct
{
    offset   sizeadded;
    offset   sizegenned;
} TraceInfo;
#endif

#define DBG_SIGNATURE   0x8386
#define FOX1_SIGNATURE  0x8300
#define FOX2_SIGNATURE  0x8301
#define RES_SIGNATURE   0x8302

void ODBISectCleanup(MemorySubsystem* memorySubsystem, section* sect);
snamelist* LangAlloc(MemorySubsystem* memorySubsystem, ::byte len, char* buff);
void ODBIInit(MemorySubsystem* memorySubsystem, section* sect);
