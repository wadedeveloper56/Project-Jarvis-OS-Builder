#pragma once

#include "types.h"
#include "File.h"
#include "syms.h"

typedef struct file_list        FILE_LIST;
typedef struct path_entry       PATH_ENTRY;
typedef struct mod_entry        MOD_ENTRY;
typedef struct ovl_area         OVL_AREA;
typedef struct section          SECTION;
typedef struct group_entry      GROUP_ENTRY;
typedef struct class_entry      CLASS_ENTRY;
typedef struct segnode          SEGNODE;
typedef struct seg_leader       SEG_LEADER;
typedef struct node             NODE;
typedef struct extnode          EXTNODE;
typedef struct grpnode          GRPNODE;
typedef struct list_of_names    LIST_OF_NAMES;
typedef struct lobject_data     LOBJECT_DATA;
typedef struct outfilelist      OUTFILELIST;
typedef struct infilelist       INFILELIST;
typedef struct member_list      MEMBER_LIST;
typedef struct segdata          SEGDATA;
typedef struct pubdeflist       PUBDEFLIST;
typedef struct trace_info       TRACE_INFO;
typedef struct ovl_area {
    OVL_AREA* next_area;
    SECTION* sections;
} ovl_area;
typedef struct order_class      ORDER_CLASS;
typedef struct order_segment    ORDER_SEGMENT;

#include "HashTable.h"

typedef struct section {
    SECTION* next_sect;
    FILE_LIST* files;
    HashTableDataPtr modFilesHashed;
    MOD_ENTRY* mods;
    CLASS_ENTRY* classlist;
    ORDER_CLASS* orderlist; // Link to data for ordering, if used
    targ_addr           sect_addr;
    unsigned_16         ovl_num;
    OVL_AREA* areas;
    SECTION* parent;
    unsigned_32         relocs;
    unsigned_32         size;
    void* reloclist;
    union {
        unsigned_32         file_loc;
        MOD_ENTRY* dist_mods;
    } u;
    void* dbg_info;
    OUTFILELIST* outfile;
} section;

typedef struct path_entry {
    PATH_ENTRY* next;
    char                name[1];
} path_entry;

typedef struct outfilelist {
    OUTFILELIST* next;
    char* fname;     // name of the file to be written to.
    FileHandle        handle;
    unsigned long   file_loc;
    char* buffer;
    unsigned long   bufpos;
    unsigned        ovlfnoff;   // offset of filename from _OVLTAB
    bool            is_exe;     // executable flag (for file permissions)
    unsigned long   origin;
} outfilelist;

enum infile_flags {
    INSTAT_USE_LIBPATH = 0x0001,       // use libpath for this file.
    INSTAT_LIBRARY = 0x0002,       // file is a library
    INSTAT_IOERR = 0x0004,       // problem reading this file
    INSTAT_IN_USE = 0x0008,       // file in use.
    INSTAT_OPEN_WARNING = 0x0010,       // only give a warning if can't open
    INSTAT_FULL_CACHE = 0x0020,       // read entire file.
    INSTAT_PAGE_CACHE = 0x0040,       // read in "paged"
    INSTAT_GOT_MODTIME = 0x0080,
    INSTAT_NO_WARNING = 0x0100
};

#define INSTAT_SET_CACHE (INSTAT_FULL_CACHE | INSTAT_PAGE_CACHE)

typedef struct infilelist {
    INFILELIST* next;
    PATH_ENTRY* path_list;
    char* prefix;
    void* cache;  // used when object file cached in mem
    unsigned long       len;     // length of the file.
    unsigned long       currpos; // current position of the file.
    FileHandle            handle;
    time_t              modtime;
    char* name;
    enum infile_flags   flags;
} infilelist;

enum file_status {
    DBI_LINE = 0x00000001,    /*  values for DBIFlag */
    DBI_TYPE = 0x00000002,
    DBI_LOCAL = 0x00000004,
    DBI_ONLY_EXPORTS = 0x00000008,
    DBI_STATICS = 0x00000010,
    DBI_ALL = (DBI_LINE | DBI_TYPE | DBI_LOCAL | DBI_STATICS),
    DBI_MASK = (DBI_ALL | DBI_ONLY_EXPORTS),
    STAT_HAS_CHANGED = 0x00000040,
    STAT_OMF_LIB = 0x00000080,
    STAT_AR_LIB = 0x00000100,
    STAT_IS_LIB = (STAT_AR_LIB | STAT_OMF_LIB),
    STAT_LAST_SEG = 0x00000200,    // set by newsegment option
    STAT_TRACE_SYMS = 0x00000400,
    STAT_LIB_FIXED = 0x00000800,
    STAT_OLD_LIB = 0x00001000,
    STAT_LIB_USED = 0x00002000,
    STAT_SEEN_LIB = 0x00004000,
    STAT_HAS_MEMBER = 0x00008000,
    STAT_USER_SPECD = 0x00010000
};

typedef enum lib_priorities {
    LIB_PRIORITY_MIN = 0,
    LIB_PRIORITY_MID = 128,
    LIB_PRIORITY_MAX = 255
} lib_priority;

typedef struct file_list {
    FILE_LIST* next_file;
    infilelist* file;
    union {
        union dict_entry* dict;
        MEMBER_LIST* member;
    } u;
    char* strtab; /* for AR format */
    enum file_status    status;
    lib_priority        priority;       /* for libraries */
    unsigned            ovlref : 16;  /* for fixed libraries */
    unsigned : 0;
} file_list;

typedef struct trace_info {
    TRACE_INFO* next;
    union {
        char* name;
        file_list* lib;
    } u;
    char* member;
    bool                found;
} trace_info;

typedef enum {
    // DBI_xxxx symbols are also stored here.
    // FMT_xxxx symbols (for deciding .obj format) are also stored here
    MOD_DBI_SEEN = 0x00000800, // true if dbi segment seen in this mod.
    MOD_FIXED = 0x00001000, // true if mod must stay in spec'd section
    MOD_VISITED = 0x00002000, // true if visited in call graph analysis.
    MOD_NEED_PASS_2 = 0x00004000, // true if pass 2 needed for this module.
    MOD_LAST_SEG = 0x00008000, // true if this module should end a group
    MOD_GOT_NAME = 0x00010000, // true if already got a source file name
    MOD_IMPORT_LIB = 0x00020000, // ORL: true if this is an import lib.
    MOD_KILL = 0x00040000, // module should be removed from list
    MOD_FLATTEN_DBI = 0x00080000, // flatten DBI found in this mod.
    MOD_DONE_PASS_1 = 0x00100000, // module been through pass 1 already.
    MOD_IS_FREE = 0x80000000, // used for marking carve free blocks
    MOD_CLEAR_ON_INC = 0x00100000  // flags to clear when inc. linking.
} module_flags;

typedef struct member_list {
    MEMBER_LIST* next;
    module_flags        flags;      //dbi & newseg flags to be xferred to mod entry
    char                name[1];
} member_list;

#define NO_ARCS_YET 0xFFFF

/*
   NOTE: this is an entry for the kludge of the year award, 1993.
   Since I need to keep symbol *'s and module handles in the same pointer,
   I tell the difference by checking test to see if it is less than 8K
   (the max. # of distributed modules).
*/

typedef union {
    symbol* sym;
    unsigned_16         mod;
    unsigned_32         test;
} dist_arc;

// fields used only in distributing libs are marked dist:
// remember to change DIST_ONLY_SIZE if you remove or add a "dist" field!

typedef struct arcdata {
    unsigned_16         ovlref;     // dist: # of the module
    unsigned_16         numarcs;    // dist: of arcs in the list
    dist_arc            arcs[1];    // dist: the actual arcs.
} arcdata;

#define DIST_ONLY_SIZE (2*sizeof(unsigned_16)+sizeof(dist_arc))

typedef struct name_list {
    struct name_list* next;
    unsigned            len;
    unsigned_32         num;
    char* name;          // NYI: make this vbl length again.
} name_list;

typedef struct odbimodinfo      ODBIMODINFO;    // defd in dbg information hdrs
typedef struct dwarfmodinfo     DWARFMODINFO;
typedef struct cvmodinfo        CVMODINFO;

// OMF debug information formats
typedef enum {
    OMF_DBG_UNKNOWN,
    OMF_DBG_CODEVIEW,
    OMF_DBG_HLL
} omf_dbg_type;

typedef struct mod_entry {
    union {
        MOD_ENTRY* next_mod;  // regular next pointer
        section* sect;      // when distributing - section of current mod.
    } n;
    union {
        FILE_LIST* source;
        char* fname;
    } f;
    char* name;
    unsigned_32         location;
    symbol* publist;
    SEGDATA* segs;
    time_t              modtime;
    unsigned            relocs;
    unsigned            sizerelocs;
    module_flags        modinfo;
    void* lines;
    omf_dbg_type        omfdbg;
    union {
        arcdata* arclist;   // segment definition data.
        MOD_ENTRY* next;      // for keeping track of modules when distrib
    } x;
    union {
        ODBIMODINFO* o;
        DWARFMODINFO* d;
        CVMODINFO* cv;
    } d;                        // union used for debugging information
} mod_entry;

typedef enum _ClassStatus{
    CLASS_32BIT = 0x00000001,
    CLASS_TRANSFER = 0x00000002,     /* used for PE import transfer code */
    CLASS_MS_TYPE = 0x00000004,
    CLASS_MS_LOCAL = 0x00000008,
    CLASS_DWARF = 0x0000000C,
    CLASS_DEBUG_INFO = (CLASS_MS_TYPE | CLASS_MS_LOCAL | CLASS_DWARF),
    CLASS_CODE = 0x00000010,
    CLASS_LXDATA_SEEN = 0x00000020,
    CLASS_READ_ONLY = 0x00000040,
    CLASS_STACK = 0x00000080,
    CLASS_IDATA = 0x00000100,
    CLASS_FIXED = 0x00001000,   // Class should load at specified address
    CLASS_COPY = 0x00002000,   // Class should use data from DupClass
    CLASS_NOEMIT = 0x00004000,   // Class should not generate output
    CLASS_IS_FREE = 0x80000000,   // not used, but guarantees 4 byte enum
} ClassStatus;

typedef struct class_entry {
    CLASS_ENTRY* next_class;
    SEG_LEADER* segs;
    char* name;
    ClassStatus        flags;
    section* section;
    targ_addr           BaseAddr;   // Fixed location to of this class for loadfile
    CLASS_ENTRY* DupClass;  // Class to get data from for output
} class_entry;

typedef struct group_entry {
    GROUP_ENTRY* next_group;
    SEG_LEADER* leaders;
    symbol* sym;
    section* section;
    targ_addr           grp_addr;
    unsigned_16         segflags;       /* see values in watcom\h\exeos2.h */
    unsigned_16         alignment;      /* max alignment of all segments in grp */
    offset              size;
    offset              totalsize;
    offset              linear;         // preferred base address
    union {
        void* grp_relocs;    // OS2/ELF only.
        class_entry* class1;         // CV (during addr calc )
    } g;
    union {
        unsigned        qnxflags;       // QNX
        unsigned        miscflags;      // OS/2
        segment         dos_segment;    // DOS/16M: DOS segment value
    } u;
    unsigned            num;
    unsigned            isfree : 1;
    unsigned            isautogrp : 1;
    unsigned            isdup : 1;
} group_entry;

// this is a bit in the segflags field. This is also defined in exeos2.h

#define SEG_DATA            1
#define SEG_READ_ONLY    0x80

// the default value to initialize group flags to. This is the same as
// SEG_LEVEL_3 in exeos2.h.

#define DEFAULT_GRP_FLAGS (0xC00 | SEG_READ_ONLY)

// flags used under OS/2 to indicate special information about a segment

#define SEG_16_ALIAS    1

typedef struct seg_leader {
    SEG_LEADER* next_seg;
    SEG_LEADER* grp_next;
    char* segname;
    SEGDATA* pieces;
    group_entry* group;
    class_entry* class1;
    offset          size;               // total size of segment
    SEG_LEADER* DupSeg;            // Segment to get data from for output
    unsigned_16     info;
    unsigned_16     align : 5;        // alignment of seg (power of 2)
    unsigned_16     dbgtype : 3;        // debugging type of seg
    unsigned_16     combine : 2;        // combine val. of seg
    unsigned_32     num;                // # of addrinfos to output (video)
    targ_addr       seg_addr;           // address of segment.
    unsigned_16     segflags;           // format specific segment flags
} seg_leader;

/***********************************************************************
 *
 *        The info field is used as follows:
 *
 *  n = bit used in segnode only        b = used in both segnode and leader
 *  l = bit used in leader only
 *
 *  b            l b b        b b              n b
 *  x x x x      x x x x      x x x x      x x x x
 *  | | | |      | | |        | |              | |
 *  | | | |      | | |        | |              | +---> seg. is absolute
 *  | | | |      | | |        | |              +-----> seg. is comdat (ORL)
 *  | | | |      | | |        | +--------------------> seg. in ovl. class
 *  | | | |      | | |        +--(leader)------------> generate an addr_info.
 *  | | | |      | | |        +--(node)--------------> segdef dead (terminated)
 *  | | | |      | | +-------------------------------> seg. is code.
 *  | | | |      | +---------------------------------> 32-bit segment.
 *  | | | |      +-(leader)--------------------------> last segment in group
 *  | | | +-(leader)---------------------------------> Segment should load at specified address
 *  | | +---(leader)---------------------------------> Segment should use data copied from DupSeg
 *  | +-----(leader)---------------------------------> Segment should not generate output
 *  +------------------------------------------------> LxDATA seen for this seg.
 ***********************************************************************/

 /*
  * bits in "info" field of "seg_entry" struct && the "seg_leader" struct.
  * Note that there are bits in this which are only used in the seg_entry->info
  * field, so the two words have overlapping bits.
  */

enum {
    SEG_ABSOLUTE = 0x0001,
    SEG_COMDAT = 0x0002,   /* seg is a comdat */
    SEG_OVERLAYED = 0x0040,   /* segment belongs to an overlay class */
    MAKE_ADDR_INFO = 0x0080,   /* set if making an addr info next time*/
    SEG_DEAD = 0x0080,   /* mark a segdef as being "dead"(pass 2)*/
    SEG_CODE = 0x0200,   /* segment is a code segment.         */
    USE_32 = 0x0400,   /* segment uses 32 bit addresses      */
    LAST_SEGMENT = 0x0800,   /* force last segment in a code group */
    SEG_LXDATA_SEEN = 0x8000,   /* LxDATA rec. seen for this segment */
    SEG_FIXED = 0x1000,   // Segment should start at seg_addr, not next addr
    SEG_NOEMIT = 0x2000,   // Segment should not generate output
    SEG_BOTH_MASK = 0x8641    /* flags common to both structures */
};

enum {
    NOT_DEBUGGING_INFO = 0x0000,
    MS_TYPE = 0x0001,   /* microsoft type information         */
    MS_LOCAL = 0x0002,   /* microsoft local symbol information */
    DWARF_DEBUG_INFO = 0x0003,   /* various types of dwarf debug segments */
    DWARF_DEBUG_ABBREV = 0x0004,
    DWARF_DEBUG_LINE = 0x0005,
    DWARF_DEBUG_ARANGE = 0x0006,
    DWARF_DEBUG_OTHER = 0x0007
};

enum {
    COMBINE_INVALID = 0,
    COMBINE_ADD = 1,
    COMBINE_COMMON = 2,
    COMBINE_STACK = 3, /* jwlink: new */
};

#define IS_DBG_DWARF( x ) ((x)->dbgtype >= DWARF_DEBUG_INFO)
#define IS_DBG_INFO( x ) ((x)->dbgtype != NOT_DEBUGGING_INFO)

/*
 * these are used to keep track of each individual contribution to a segment.
 * Any field that is solely used for dead code elimination is marked "dce"
 * any field that is solely used for comdat processing is marked "comdat"
*/

typedef struct segdata {
    SEGDATA* next;
    SEGDATA* mod_next;      // next segdata in module list.
    offset          length;         // length of segment in current module.
    virt_mem        data;           // data for this segment
    union {
        char* name;          // name of the segment (when is this member used???)
        seg_leader* leader;        // leader for the segment.
        SEGDATA* sdata;         // for explicit comdats
    } u;
    union {
        void* refs;          // P1dce: list of other seg's this references
        signed_32   delta;          // P2: for calc'ing segment & symbol addrs
    } a;
    union {
        mod_entry* mod;           // P2CV&DW: pointer to defining module.
        char* clname;        // INC: class name for segment
    } o;
    unsigned_32     addrinfo;       // P2VIDEO: offset into addrinfo of seg.
    unsigned_16     frame;          // the frame of an absolute segment.
    unsigned        align : 5;
    unsigned        select : 3; // comdat: selection type

    unsigned        combine : 2; // how to combine segment with others
    unsigned        alloc : 2; // comdat: where to allocate segment.
    unsigned        is32bit : 1; // true if segment is 32 bits
    unsigned        iscode : 1; // true if a code segment.
    unsigned        isabs : 1; // true if this is an absolute segment.
    unsigned        iscdat : 1; // true if this is a comdat

    unsigned        isuninit : 1; // true if seg is uninitialized
    unsigned        isidata : 1; // true if segment is .idata (ORL only)
    unsigned        ispdata : 1; // true if segment is .pdata
    unsigned        isreldata : 1; // true if segment is .reldata
    unsigned        visited : 1; // dce: true if visited in graph search.
    unsigned        isrefd : 1; // dce: true if this module is referenced.
    unsigned        isdead : 1; // dce: true if segdata or segdef killed.
    unsigned        isdefd : 1; // segdata has been defined

    unsigned        isfree : 1; // segdata is free (used in carver stuff)
    unsigned        isprepd : 1; // has been prepped for inc linking
    unsigned        canfarcall : 1; // OK to do far call optimization here
    unsigned        hascdatsym : 1; // true if comdat and has a symbol defd
    unsigned        isreadonly : 1; // true if readonly data. jwlink
} segdata;

typedef struct node {
    void* next;
    void* entry;
} node;

typedef struct dll_sym_info {
    union {
        name_list* modnum;        /* # of DLL in imported names table */
        char* modname;
    } m;
    union {
        name_list* entry;         /* # of entry in DLL */
        char* entname;
        unsigned        ordinal;
    } u;
    unsigned            isordinal : 1;
    unsigned            isfree : 1;
    symbol* iatsym;        // NT: symbol for address in iat
} dll_sym_info;

typedef enum {
    SEGFLAG_SEGMENT,
    SEGFLAG_CLASS,
    SEGFLAG_CODE,
    SEGFLAG_DATA
} segflag_type;

// this structure used for processing segment flags for various executable types
typedef struct seg_flags {
    struct seg_flags* next;
    unsigned_16         flags;  // as above.
    char* name;
    segflag_type        type;
} seg_flags;

typedef struct _ExtNode  {
    symbol* entry;
    void* handle;    // ORL: handle for the symbol
    unsigned            ovlref : 12;
    unsigned            isweak : 1;
    unsigned            isdefd : 1; // used in ORL
} ExtNode,* ExtNodePtr,**ExtNodePtrPtr;

typedef struct _GroupNode {
    GROUP_ENTRY* entry;
} GroupNode,* GroupNodePtr,** GroupNodePtrPtr;

typedef struct _SegmentNode {
    SEGDATA* entry;
    void* handle;    // ORL: handle for the segment.
    unsigned_8* contents;  // ORL: pointer to contents of segment.
    unsigned            info;
} SegmentNode,* SegmentNodePtr,** SegmentNodePtrPtr;

typedef struct _ListOfNames {
    LIST_OF_NAMES* next_name;
    char                name[1];
} ListOfNames,* ListOfNamesPtr,** ListOfNamesPtrPtr;

typedef struct lobject_data {
    segdata* seg;
    offset              obj_offset; // pass 1: delta for fixup offsets
    targ_addr           addr;
    unsigned_8* data;
} lobject_data;

typedef struct {
    size_t              len;
    char* name;
} length_name;

typedef struct order_class {
    ORDER_CLASS* NextClass;
    class_entry* Ring;  // Used for sorting
    char* Name;
    char* SrcName;
    targ_addr           Base;
    ORDER_SEGMENT* SegList;
    unsigned            FixedAddr : 1;
    unsigned            NoEmit : 1;
    unsigned            Copy : 1;
} order_class;

typedef struct order_segment {
    ORDER_SEGMENT* NextSeg;
    char* Name;
    targ_addr           Base;
    unsigned            FixedAddr : 1;
    unsigned            NoEmit : 1;
} order_segment;

typedef enum {
    MIDST,
    ENDOFLINE,
    ENDOFFILE,
    ENDOFCMD
}                       place;

typedef enum {
    NONBUFFERED,
    COMMANDLINE,
    INTERACTIVE,
    BUFFERED,
    ENVIRONMENT,
    SYSTEM
}                       method;

typedef enum {
    SEP_NO,
    SEP_COMMA,
    SEP_EQUALS,
    SEP_PERIOD,
    SEP_END,
    SEP_QUOTE,
    SEP_PAREN,
    SEP_SPACE,
    SEP_PERCENT,
    SEP_DOT_EXT,
    SEP_LCURLY,
    SEP_RCURLY
}                       sep_type;

typedef enum {
    OK,
    REJECT
}                       status;

typedef enum {
    ST_IS_ORDINAL,
    ST_NOT_ORDINAL,
    ST_INVALID_ORDINAL
} ord_state;

typedef struct tok {
    char* buff;
    unsigned    len;
    char* next;
    char* this1;
    unsigned_16 line;
    char        quoted;     /* if token parsed as a quoted string*/
    unsigned_8  where : 2;
    unsigned_8  how : 3;
    unsigned_8  thumb : 1;
    unsigned_8  locked : 1;
    unsigned_8  skipToNext : 1;   /* set true if we need to skip to next token without a separator */
} tok;

typedef enum commandflag {
    CF_TO_STDOUT = 0x00000001,
    CF_SET_SECTION = 0x00000002,   // used for LIB/FIXEDLIB directives
    CF_NO_DEF_LIBS = 0x00000004,
    CF_FILES_BEFORE_DBI = 0x00000008,
    CF_UNNAMED = 0x00000010,
    CF_AUTO_SEG_FLAG = 0x00000020,   // used in CMDOS2
    CF_MEMBER_ADDED = 0x00000040,
    CF_SEPARATE_SYM = 0x00000080,
    CF_AUTOSECTION = 0x00000100,
    CF_SECTION_THERE = 0x00000200,
    CF_HAVE_FILES = 0x00000400,
    CF_HAVE_REALBREAK = 0x00000800,
    CF_LANGUAGE_MASK = 0x00003000,
    CF_LANGUAGE_ENGLISH = 0x00000000,
    CF_LANGUAGE_JAPANESE = 0x00001000,
    CF_LANGUAGE_CHINESE = 0x00002000,
    CF_LANGUAGE_KOREAN = 0x00003000,
    CF_ANON_EXPORT = 0x00004000,
    CF_AFTER_INC = 0x00008000,  // option must be specd. after op inc
    CF_DOING_OPTLIB = 0x00010000,
    CF_NO_EXTENSION = 0x00020000    // don't put an extension on exe name
} commandflag;

typedef struct cmdfilelist {
    struct cmdfilelist* prev;
    struct cmdfilelist* next;
    FileHandle            file;
    char* symprefix;
    char* name;
    tok                 token;
} cmdfilelist;

typedef struct parse_entry {
    char* keyword;
    bool                (*rtn)(void);
    enum exe_format     format;
    commandflag         flags;
} parse_entry;

typedef struct sysblock {
    struct sysblock* next;
    char* name;
    char                commands[1];
} sysblock;

typedef enum {
    TOK_INCLUDE_DOT = 0x01,
    TOK_IS_FILENAME = 0x02
} tokcontrol;

typedef struct vecnode {
    struct vecnode* next;
    symbol* entry;
} vecnode;

typedef struct entry_export {
    struct entry_export* next;
    char* name;
    unsigned_32             ordinal;
    unsigned_16             iopl_words;
    unsigned_16             isresident : 1;
    unsigned_16             isexported : 1;
    unsigned_16             ismovable : 1;
    unsigned_16             isanonymous : 1;
    unsigned_16             isfree : 1;
    unsigned_16             isprivate : 1;
    symbol* sym;
    char* impname;
    targ_addr               addr;
} entry_export;

typedef struct cdat_piece {
    struct cdat_piece* next;
    unsigned_8* data;
    offset              length;
    unsigned            free_data : 1;
} comdat_piece;

typedef struct cdat_info {
    struct cdat_info* next;
    segdata* sdata;
    symbol* sym;
    comdat_piece* pieces;
    sym_info            flags;
} comdat_info;

typedef enum obj_format {
    FMT_EASY_OMF = 0x0001,
    FMT_MS_386 = 0x0002,
    FMT_UNUSED_3 = 0x0004,
    FMT_IS_LIDATA = 0x0008,   // true if last data was lidata
    FMT_TOLD_XXBIT = 0x0010,   // already said object was xx-bit
    FMT_IGNORE_FIXUPP = 0x0020,   // don't process a fixup record
    FMT_UNSAFE_FIXUPP = 0x0040,   // don't optimize calls in current fixupp
    FMT_UNUSED_1 = 0x0080,
    FMT_PE_XFER = 0x0000,   // .obj is PE xfer code segment(see note)
    FMT_OMF = 0x0100,   // .obj is an OMF object file (see note)
    FMT_COFF = 0x0200,   // .obj is a COFF object file (see note)
    FMT_ELF = 0x0300,   // .obj is an ELF object file (see note)
    FMT_INCREMENTAL = 0x0400,   // .obj is saved inc. linking info
    FMT_OBJ_FMT_MASK = 0x0700,
    FMT_UNUSED_2 = 0x0800,
    FMT_DEBUG_COMENT = 0x1000,   // saw an object debug coment.
} obj_format;

typedef struct omf_dict_entry {
    void** cache;          /* for extra memory store of dictionary */
    unsigned_32 start;          /* recno of start of dictionary         */
    unsigned_16 pages;          /* number of pages in dictionary        */
    unsigned_16 rec_length;     /* record alignment of obj recs         */
    byte* buffer;
} omf_dict_entry;

typedef struct ar_dict_entry {
    unsigned_32* filepostab;
    unsigned_16* offsettab;
    char** fnametab;
    unsigned_32         num_entries;
} ar_dict_entry;

typedef union dict_entry {
    omf_dict_entry      o;
    ar_dict_entry       a;
} dict_entry;

#define PAGES_IN_CACHE      0x40U

typedef enum exe_format {       // there is a corresp. table in MSG.C
    MK_OS2_NE = 0x00000001,
    MK_OS2_LE = 0x00000002,
    MK_OS2_LX = 0x00000004,
    MK_WIN_NE = 0x00000008,      /* Win16 (was: MK_WINDOWS) */
    MK_PE = 0x00000010,
    MK_DOS_EXE = 0x00000020,
    MK_COM = 0x00000040,
    MK_OVERLAYS = 0x00000080,
    MK_NOVELL = 0x00000100,
    MK_QNX_16 = 0x00000200,     // POSIX QNX, not ICON QNX
    MK_PHAR_SIMPLE = 0x00000400,
    MK_PHAR_FLAT = 0x00000800,
    MK_PHAR_REX = 0x00001000,
    MK_PHAR_MULTISEG = 0x00002000,
    MK_QNX_FLAT = 0x00004000,
    MK_ELF = 0x00008000,
    MK_WIN_VXD = 0x00010000,
    MK_DOS16M = 0x00020000,
    MK_RAW = 0x00080000
} exe_format;

#define MK_DOS       (MK_OVERLAYS | MK_DOS_EXE | MK_COM)
#define MK_ONLY_OS2_16  MK_OS2_NE
#define MK_OS2_FLAT  (MK_OS2_LE | MK_OS2_LX | MK_WIN_VXD)
#define MK_ONLY_OS2  (MK_ONLY_OS2_16 | MK_OS2_LE | MK_OS2_LX)
#define MK_OS2_16BIT (MK_ONLY_OS2_16 | MK_WIN_NE)
/* MK_WIN_VXD is not included into MK_OS2 */
#define MK_OS2       (MK_OS2_16BIT | MK_OS2_LE | MK_OS2_LX)
#define MK_PHAR_LAP  (MK_PHAR_SIMPLE|MK_PHAR_FLAT|MK_PHAR_REX|MK_PHAR_MULTISEG)
#define MK_QNX       (MK_QNX_16 | MK_QNX_FLAT)
#define MK_386       (MK_PHAR_LAP | MK_NOVELL | MK_QNX|MK_OS2_LE|MK_OS2_LX|MK_PE|MK_ELF|MK_WIN_VXD|MK_RAW)
#define MK_286       (MK_DOS | MK_OS2_16BIT | MK_DOS16M)
/* MK_OS2_LE, MK_OS2_LX, MK_WIN_VXD and MK_PE are not treated as FLAT internally */
#define MK_FLAT      (MK_PHAR_SIMPLE | MK_PHAR_FLAT | MK_PHAR_REX | MK_RAW )
#define MK_ALLOW_64  (MK_PE | MK_ELF | MK_RAW) /* jwlink */
#define MK_ALLOW_32  (MK_PHAR_LAP|MK_OS2_LE|MK_OS2_LX|MK_NOVELL|MK_QNX|MK_PE|MK_ELF|MK_WIN_VXD|MK_RAW)
#define MK_ALLOW_16  (MK_286 | MK_PHAR_FLAT | MK_OS2 | MK_QNX | MK_PE | MK_WIN_VXD | MK_RAW)
#define MK_ID_SPLIT  (MK_NOVELL)
#define MK_REAL_MODE (MK_DOS)
#define MK_PROT_MODE (~MK_REAL_MODE)
#define MK_SEGMENTED (MK_286 | MK_OS2 | MK_PHAR_MULTISEG)
#define MK_IMPORTS   (MK_NOVELL | MK_OS2 | MK_PE | MK_ELF)
/* MK_SPLIT_DATA allows to split the uninitialized data part from
 * the rest of DGROUP, but it also prohibits BSS to share pages
 * with preceding initialized data segments!
 * To be improved!
 */
#define MK_SPLIT_DATA (MK_ELF | MK_PE)
#define MK_LINEARIZE (MK_ELF | MK_PE)
#define MK_END_PAD   (MK_DOS)
#define MK_ALL       (0x000FFFFF)

#define IS_PPC_PE   ( LinkState & HAVE_PPC_CODE && FmtData.type & MK_PE )
#define IS_PPC_OS2   0//( LinkState & HAVE_PPC_CODE && FmtData.type & MK_OS2 )

 // linker specific phar lap data

struct fmt_dos_data {
    unsigned    distribute : 1;
    unsigned    noindirect : 1;
    unsigned    dynamic : 1;
    unsigned    ovl_short : 1;
    unsigned    pad_sections : 1;
    unsigned    knoweas : 1; /* JWlink */
};

struct fmt_phar_data {
    unsigned_32     mindata;
    unsigned_32     maxdata;
    char* breaksym;       // name of realbreak symbol
    struct rtpblock* params;         // run-time parameter block.
    char* stub;       // name of stub file.
    //    bool            pack;    needed if/when .exp packing implemented
};

// linker specific OS/2 data

struct fmt_os2_data {
    struct entry_export* exports;
    name_list* mod_ref_list;
    name_list* imp_tab_list;
    char* stub_file_name;
    char* res_module_name;
    char* old_lib_name;
    struct os2_seg_flags* os2_seg_flags;
    char* description;
    unsigned_32         heapsize;
    int                 segment_shift;
    unsigned            flags;            // in LOADOS2.H
    unsigned            chk_seg_relocs : 1;
    unsigned            toggle_relocs : 1;
    unsigned            gen_int_relocs : 1;
    unsigned            gen_rel_relocs : 1;
    unsigned            is_private_dll : 1;
    unsigned            no_stub : 1;
    unsigned            mixed1632 : 1;
    unsigned            dpmi16 : 1; /* for Windows 16-bit NE */
};

// linker specific PE data

struct fmt_pe_data {
    struct fmt_os2_data os2;    /* must be first field */
    list_of_names* resources;
    unsigned_32         heapcommit;
    unsigned_32         stackcommit;
    unsigned            subsystem;
    unsigned_16         submajor;
    unsigned_16         subminor;
    unsigned_16         osmajor;    /*  OS major version    */
    unsigned_16         osminor;    /*  OS minor version    */
    unsigned_8          linkmajor;  /*  link major version  */
    unsigned_8          linkminor;  /*  link minor version  */
    unsigned            tnt : 1;
    unsigned            sub_specd : 1;
    unsigned            no_stdcall : 1;
    unsigned            osv_specd : 1;      /* OS version specified? */
    unsigned            lnk_specd : 1;      /* Link version specified */
    unsigned            checksumfile : 1;   /* Create checksum for file? */
    unsigned            win64 : 1;               /* JWlink */
    unsigned            largeaddressaware : 1;   /* JWlink */
    unsigned            nolargeaddressaware : 1; /* JWlink */
    unsigned            hx : 1;                  /* JWlink */
    unsigned            nxcompat : 1;            /* JWlink, NXCOMPAT option */
    unsigned            fuzzy_export : 1;        /* JWlink, FUZZYEXPORT option */
};

// structures used in processing DOS/16M load files.

struct fmt_d16m_data {
    unsigned_16     options;
    unsigned_8      flags;              // in load16m.h
    unsigned_8      strategy;
    unsigned_16     buffer;
    unsigned_16     gdtsize;
    unsigned_16     selstart;
    unsigned_16     extended;
    unsigned_16     datasize;
    char* stub;              // name of stub file.
};

// stuff common to some file formats which have the concept of an export

struct exp_common {
    name_list* export1;
    name_list* module;
};

// linker specific Novell NLM data

struct fmt_nov_data {
    struct exp_common   exp;            // must be at the start
    char* screenname;     // actually a length byte then a string
    char* description;    // ditto.
    char* checkfn;        // check function name;
    char* exitfn;         // exit function name;
    char* customdata;     // custom data file name;
    char* threadname;
    char* copyright;
    char* messages;
    char* help;
    char* rpcdata;
    char* sharednlm;
    unsigned            moduletype;
    unsigned            flags;
    unsigned_32         exeflags;
};

// so we don't have to allocate any memory for imports which are not
// referenced, make them initially point to some other aribtrary non-zero place

#define DUMMY_IMPORT_PTR    (void *)&FmtData.u.nov

// linker specific QNX 4.0 data

struct fmt_qnx_data {
    struct qnx_seg_flags* seg_flags;
    unsigned_32             heapsize;
    unsigned                flags;
    unsigned                priv_level;
    unsigned                gen_seg_relocs : 1;
    unsigned                gen_linear_relocs : 1;
    unsigned                seen_mismatch : 1;
};

// linker specific ELF data

struct fmt_elf_data {
    struct exp_common   exp;            // must be at the start
    //unsigned long       alignment;    /* not used by Wlink! */
    int                 segment_shift;  /* for JWlink! */
    unsigned_32         extrasects;
    unsigned_8          abitype;        // EI_OSABI contents
    unsigned_8          abiversion;     // EI_ABIVERSION contents
    unsigned            exportallsyms : 1;
    unsigned            elf64 : 1;               /* JWlink */
};

#define NO_BASE_SPEC    ((offset)-1UL)

struct fmt_data {
    union   fmt_spec_data {
        struct  fmt_dos_data    dos;
        struct  fmt_os2_data    os2;
        struct  fmt_pe_data     pe;
        struct  fmt_d16m_data   d16m;
        struct  fmt_phar_data   phar;
        struct  fmt_nov_data    nov;
        struct  fmt_qnx_data    qnx;
        struct  fmt_elf_data    elf;
    }               u;
    seg_leader* dgroupsplitseg;
    offset          bsspad;
    offset          base;
    offset          objalign;
    char* implibname; /* IMPLIB filename */
    char* osname;
    char* resource;
    int             cpu_type;       /* '0' => 86, '1' => 186, etc */
    exe_format      type;
    unsigned        major;
    unsigned        minor;
    unsigned        def_seg_flags;
    unsigned        revision;
    unsigned        Hshift;     // Corresponds to huge shift variable used by libr
    unsigned        SegShift;   // 16 - HShift, used to convert a segment to an address
    unsigned_32     SegMask;    // used to extract remainder for segment normalization
    unsigned        HexSegShift;// shift to convert Intel Hex record segments to address
    unsigned_32     output_offset;
    char            FillChar;
    unsigned        dll : 1;
    unsigned        ver_specified : 1;
    unsigned        make_implib : 1;
    unsigned        make_impfile : 1;
    unsigned        res_name_only : 1;
    unsigned        toc_initialized : 1;
    unsigned        output_raw : 1;
    unsigned        output_hex : 1;
    unsigned        output_hshift : 1; // Hexout uses HexSegShift (else uses SegShift)
    unsigned        output_start : 1; // If Hexout should provide a start record
    unsigned        raw_hex_output : 1;
};

typedef enum file_defext {
#undef pick1
#define pick1(enum,text) enum,
#include "ldefext.h"
} file_defext;
