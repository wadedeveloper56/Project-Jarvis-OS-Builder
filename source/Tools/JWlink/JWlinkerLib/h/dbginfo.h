#include <memory>
#include "MemorySubsystem.h"
#include "Structs.h"

using namespace std;

#define DBG_SIGNATURE   0x8386
#define FOX1_SIGNATURE  0x8300
#define FOX2_SIGNATURE  0x8301
#define RES_SIGNATURE   0x8302

#pragma pack(1)

typedef struct sectheader {
    uint32_t         mod_offset;
    uint32_t         gbl_offset;
    uint32_t         addr_offset;
    uint32_t         section_size;
    uint16_t         section_id;
} sectheader;

typedef struct {
    virt_mem        init;
    virt_mem        curr;
    uint32_t     size;
    uint32_t     start;
} dbi_section;


typedef struct debug_info {
    dbi_section     locallinks;
    dbi_section     local;
    dbi_section     typelinks;
    dbi_section     type;
    dbi_section     linelinks;
    dbi_section     line;
    dbi_section     mod;
    dbi_section     global;
    dbi_section     addr;
    virt_mem        dump_addr;
    int16_t       modnum;
    class_entry     *LocalClass;
    class_entry     *TypeClass;
} debug_info;


typedef struct dbgheader {
    uint16_t         signature;
    uint8_t          exe_major_ver;
    uint8_t          exe_minor_ver;
    uint8_t          obj_major_ver;
    uint8_t          obj_minor_ver;
    uint16_t         lang_size;
    uint16_t         seg_size;
    uint32_t         debug_size;
} dbgheader;

typedef struct gblinfo {
    uint32_t         off;
    uint16_t         seg;
    uint16_t         mod_idx;
    uint8_t          flags;
    char                name[ 1 ];
} gblinfo;

#define DBG_GBL_STATIC  0x1
#define DBG_GBL_DATA    0x2
#define DBG_GBL_CODE    0x4

typedef struct demand_info {
    uint32_t         off;
    uint16_t         len;
} demand_info;

typedef struct modinfo {
    uint16_t         language;
    demand_info         locals;
    demand_info         types;
    demand_info         lines;
    char                name[ 1 ];
} modinfo;

typedef struct lineseg {
    uint32_t segment;
    uint16_t num;
} lineseg;

typedef struct segheader {
    uint32_t         off;
    uint16_t         seg;
    uint16_t         num;
} segheader;

typedef struct addrinfo {
    uint32_t         size;
    uint16_t         mod_idx;
} addrinfo;

typedef struct dbinode {
    struct dbinode      *next;
    uint16_t         segidx;
} dbinode;

#pragma pack()

void ODBISectCleanup(MemorySubsystem *memorySubsystem, section* sect);
void ODBIInit(MemorySubsystem* memorySubsystem, section* sect);
