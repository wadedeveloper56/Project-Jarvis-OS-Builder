#pragma once

#include <stdint.h>
#include "File.h"
#include "hash.h"

typedef enum file_defext
{
#undef pick1
#define pick1(enum,text) enum,
#include "ldefext.h"
} file_defext; 

#define MAKE_RELOCS             0x00000001
#define SEARCHING_LIBRARIES     0x00000002
#define LIBRARIES_ADDED         0x00000004
#define LINK_ERROR              0x00000008
#define FMT_SPECIFIED           0x00000010
#define FMT_DECIDED             0x00000020
#define FMT_SEEN_32_BIT         0x00000040
#define FMT_SEEN_IMPORT_CMT     0x00000080
#define PROC_LIBS_ADDED         0x00000100
#define FMT_INITIALIZED         0x00000200
#define UNDEFED_SYM_ERROR       0x00000400
#define GENERATE_LIB_LIST       0x00000800
#define HAVE_16BIT_CODE         0x00001000      // TRUE if we have 16 bit code.
#define HAVE_ALPHA_CODE         0x00002000
#define HAVE_PPC_CODE           0x00004000
#define HAVE_I86_CODE           0x00008000
#define HAVE_MIPS_CODE          0x00010000
#define CAN_REMOVE_SEGMENTS     0x00020000
#define STOP_WORKING            0x00040000      // IDE wants us to stop now
#define INTERNAL_DEBUG          0x00080000
#define GOT_PREV_STRUCTS        0x00100000
#define DOSSEG_FLAG             0x00200000
#define SPEC_ORDER_FLAG         0x00400000
#define FMT_SEEN_64_BIT         0x00800000

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
typedef struct ovl_area
{
	OVL_AREA* next_area;
	SECTION* sections;
} ovl_area;
typedef struct order_class      ORDER_CLASS;
typedef struct order_segment    ORDER_SEGMENT;
typedef struct odbimodinfo      ODBIMODINFO;    // defd in dbg information hdrs
typedef struct dwarfmodinfo     DWARFMODINFO;
typedef struct cvmodinfo        CVMODINFO;

typedef struct outfilelist
{
	OUTFILELIST* next;
	char* fname;     // name of the file to be written to.
	f_handle        handle;
	unsigned long   file_loc;
	char* buffer;
	unsigned long   bufpos;
	unsigned        ovlfnoff;   // offset of filename from _OVLTAB
	bool            is_exe;     // executable flag (for file permissions)
	unsigned long   origin;
} outfilelist;

typedef uint32_t offset;
typedef uint16_t segment;
typedef unsigned long stateflag;
typedef unsigned char   byte;
typedef unsigned long   virt_mem;
typedef unsigned long linkflag;

#define DWARF_DBI_FLAG  0x00000001UL    // set if making DWARF debug info
#define STK_SIZE_FLAG   0x00000002UL
#define GOT_CHGD_FILES  0x00000004UL
#define TRACE_FLAG      0x00000008UL
#define __UNUSED_FLAG_0 0x00000010UL
#define CV_DBI_FLAG     0x00000020UL
#define UNDEFS_ARE_OK   0x00000040UL
#define REDEFS_OK       0x00000080UL
#define QUIET_FLAG      0x00000100UL
#define PACKCODE_FLAG   0x00000200UL    // set if packcode specified
#define VF_REMOVAL      0x00000400UL
#define NOVELL_DBI_FLAG 0x00000800UL    // set if generating novell debug info
#define PACKDATA_FLAG   0x00001000UL
#define CASE_FLAG       0x00002000UL    // set for case sensitive operation
#define OLD_DBI_FLAG    0x00004000UL    // set if making WATCOM debug info
#define SHOW_DEAD       0x00008000UL
#define STRIP_CODE      0x00010000UL    // strip dead code.
#define CVPACK_FLAG     0x00020000UL
#define MAX_ERRORS_FLAG 0x00040000UL    // there is a max. number of errors.
#define DONT_UNMANGLE   0x00080000UL    // don't unmangle the names
#define INC_LINK_FLAG   0x00100000UL
#define NOCACHE_FLAG    0x00200000UL
#define CACHE_FLAG      0x00400000UL
#define FAR_CALLS_FLAG  0x00800000UL    // optimize far calls
#define __UNUSED_FLAG_8 0x01000000UL
#define __UNUSED_FLAG_7 0x02000000UL
#define __UNUSED_FLAG_6 0x04000000UL
#define __UNUSED_FLAG_5 0x08000000UL
#define __UNUSED_FLAG_4 0x10000000UL
#define __UNUSED_FLAG_3 0x20000000UL
#define __UNUSED_FLAG_2 0x40000000UL
#define __UNUSED_FLAG_1 0x80000000UL

/*  Generic constants */
enum GenericConstants
{
	MAX_REC = 1024,
	UNDEFINED = 0xffff,   /* undefined segment */
};

typedef enum mapflag
{
	MAP_FLAG = 0x0001,
	MAP_STATICS = 0x0002,       // put statics in the map file
	MAP_ARTIFICIAL = 0x0004,       // put artificial syms in the map file
	MAP_SORT = 0x0008,       // sort symbols in the map file
	MAP_ALPHA = 0x0010,       // sort symbols in alphabetical order
	MAP_GLOBAL = 0x0020,       // sort symbols globally.
	MAP_VERBOSE = 0x0040
} mapflag;

typedef enum
{

	// These constants define the meaning of the bits in the symbol "info" field
	// The values 0-15 are used for the type of the symbol
	// SYM_OLDHAT is only used in pass 1, and sym_checked is only used in pass 1.
	// SYM_MAP_GLOBAL is also used inbetween pass 1 and pass 2 to keep track of
	// symbols which are going in the map file (for sort global command)
	// SYM_KILL & SYM_RELOC_REFD only used before pass 1

	// Here is what is put in the first four bits of the info field.

	SYM_COMMUNAL_16 = 0,    // symbol is a 16-bit communal symbol
	SYM_COMMUNAL_32 = 1,    // symbol is a 32-bit communal symbol
	SYM_COMDAT = 2,    // symbol is an initialized communal.
	SYM_REGULAR = 3,    // a good, old-fashioned linker symbol
	SYM_ALIAS = 4,    // this is an alias for another symbol.
	SYM_IMPORTED = 5,    // symbol is imported (OS/2 & Novell).
	SYM_GROUP = 6,    // symbol is attached to a group
	SYM_LAZY_REF = 7,    // symbol is a "lazy" reference.
	SYM_WEAK_REF = 8,    // symbol is a "weak" reference.
	SYM_LINK_WEAK_REF = 9,    // symbol is a linker-generated weak reference
	SYM_VF_REF = 10,   // symbol is a virtual function table reference
	SYM_PURE_REF = 11,   // symbol is a pure virt. func. table reference

	// Here is all other values except the first four bits of the info field.

	SYM_DEAD = 0x00000010, // symbol has been eliminated.
	SYM_FREE_ALIAS = 0x00000010, // used for aliases only.
	SYM_OLDHAT = 0x00000020, // symbol referenced in a previous obj
	SYM_REFERENCED = 0x00000040, // used to mark unref'd symbols in map
	SYM_CHECKED = 0x00000080, // symbol has been checked by FindUndefined
	SYM_MAP_GLOBAL = 0x00000080, // put sym in global map symbol list
	SYM_STATIC = 0x00000100, // non-global symbol
	SYM_LOCAL_REF = 0x00000200, // symbol referenced locally.
	SYM_TRACE = 0x00000400, // keep track of references to this symbol
	SYM_IN_CURRENT = 0x00000800, // symbol seen in current module
	SYM_WAS_LAZY = 0x00000800, // used for aliases only
	SYM_DEFINED = 0x00001000, // symbol defined.
	SYM_ABSOLUTE = 0x00002000, // symbol is absolute
	SYM_EXPORTED = 0x00008000, // symbol has been exported
	SYM_CDAT_SEL_NODUP = 0x00000000, // do not allow duplicates
	SYM_CDAT_SEL_ANY = 0x00010000,
	SYM_CDAT_SEL_SIZE = 0x00020000,
	SYM_CDAT_SEL_EXACT = 0x00030000,
	SYM_CDAT_SEL_MASK = 0x00030000,
	SYM_CDAT_SEL_SHIFT = 16,
	SYM_RELOC_REFD = 0x00040000, // symbol referenced by a stored reloc
	SYM_KILL = 0x00080000, // remove symbol
	SYM_IS_ALTDEF = 0x00100000, // symbol is an altdef symbol.
	SYM_FAR_COMMUNAL = 0x00200000, // is a far communal symbol
	SYM_LINK_GEN = 0x00400000, // is a linker generated symbol
	SYM_HAS_DATA = 0x00800000, // only used for altdefs
	SYM_NAME_XLATED = 0x01000000, // only used during permdata writing
	SYM_IS_FREE = 0x10000000, // only used during permdata writing.

	SYM_CLEAR_ON_P2 = 0xE00000A0, // bits to clear before pass 2 starts.
	SYM_CLEAR_ON_INC = 0x010404F0,
	SYM_CLEAR_ON_ALT = 0x00980010,

	// the top three bits are used for the floating point fixup type during pass 2
	// SYM_DCE_REF, SYM_VF_REFS_DONE and SYM_VF_MARKED are only needed during
	// pass 1 and before the floating point syms are checked for.
	// SYM_VF_MARKED can be used at the same time as SYM_DISTRIB since
	// SYM_DISTRIB is only set when SYM_DEFINED is on, and SYM_VF_MARKED is only
	// needed when the symbol is not defined.

	SYM_DISTRIB = 0x20000000, // DOS ONLY: symbol is in a distrib. lib.
	SYM_VF_MARKED = 0x20000000, // vf reference record seen for this sym.
	SYM_DCE_REF = 0x40000000, // referenced for the purposes of dead code
	SYM_VF_REFS_DONE = 0x80000000  // ALL: vf refs added to call graph
} sym_info;

typedef enum obj_format
{
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

typedef enum exe_format
{       // there is a corresp. table in MSG.C
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

typedef enum
{
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
} class_status;

typedef enum
{
	// DBI_xxxx symbols are also stored here.
	// FMT_xxxx symbols (for deciding .obj format) are also stored here
	MOD_DBI_SEEN = 0x00000800, // TRUE if dbi segment seen in this mod.
	MOD_FIXED = 0x00001000, // TRUE if mod must stay in spec'd section
	MOD_VISITED = 0x00002000, // TRUE if visited in call graph analysis.
	MOD_NEED_PASS_2 = 0x00004000, // TRUE if pass 2 needed for this module.
	MOD_LAST_SEG = 0x00008000, // TRUE if this module should end a group
	MOD_GOT_NAME = 0x00010000, // TRUE if already got a source file name
	MOD_IMPORT_LIB = 0x00020000, // ORL: TRUE if this is an import lib.
	MOD_KILL = 0x00040000, // module should be removed from list
	MOD_FLATTEN_DBI = 0x00080000, // flatten DBI found in this mod.
	MOD_DONE_PASS_1 = 0x00100000, // module been through pass 1 already.
	MOD_IS_FREE = 0x80000000, // used for marking carve free blocks
	MOD_CLEAR_ON_INC = 0x00100000  // flags to clear when inc. linking.
} module_flags;

typedef enum
{
	OMF_DBG_UNKNOWN,
	OMF_DBG_CODEVIEW,
	OMF_DBG_HLL
} omf_dbg_type;

typedef enum
{
	FIX_CHANGE_SEG = 0x00000001,   // has to be 1.  used in pointers!
	FIX_ADDEND_ZERO = 0x00000002,
	FIX_UNSAFE = 0x00000004,
	FIX_ABS = 0x00000008,

	FIX_BASE = 0x00000010,
	FIX_HIGH = 0x00000020,
	FIX_REL = 0x00000040,
	FIX_SHIFT = 0x00000080,

	FIX_TARGET_SHIFT = 8,            // contains frame_type
	FIX_TARGET_MASK = 0x00000700,

	FIX_NOADJ = 0x00000800,   // flags no adjustment for FIX_REL

	FIX_NO_BASE = 0x00001000,
	FIX_SIGNED = 0x00002000,
	FIX_LOADER_RES = 0x00004000,
	FIX_SEC_REL = 0x00008000,

	FIX_NO_OFFSET = 0,
	FIX_OFFSET_8 = 0x00010000,   // If a new FIX_OFFSET constant is
	FIX_OFFSET_16 = 0x00020000,   // added, the OffsetSizes array in
	FIX_OFFSET_21 = 0x00030000,   // obj2supp.c also has to be updated!
	FIX_OFFSET_32 = 0x00040000,
	FIX_OFFSET_24 = 0x00050000,
	FIX_OFFSET_26 = 0x00060000,
	FIX_OFFSET_64 = 0x00080000,   // jwlink
	FIX_OFFSET_SHIFT = 16,
	FIX_OFFSET_MASK = 0x000F0000,   // jwlink

	FIX_TOC = 0x00100000,   // PPC PE
	FIX_TOCV = 0x00200000,   // PPC PE
	FIX_IFGLUE = 0x00300000,   // PPC PE
	FIX_SPECIAL_MASK = 0x00300000,

	FIX_FRAME_SHIFT = 24,           // contains frame_type
	FIX_FRAME_MASK = 0x07000000,


	// now for some handy constants which use these

	FIX_BASE_OFFSET_16 = (FIX_BASE | FIX_OFFSET_16),
	FIX_BASE_OFFSET_32 = (FIX_BASE | FIX_OFFSET_32),
	FIX_HIGH_OFFSET_8 = (FIX_HIGH | FIX_OFFSET_8),
	FIX_HIGH_OFFSET_16 = (FIX_HIGH | FIX_OFFSET_16),
} fix_type;

typedef struct targ_addr
{
	offset              off;
	segment             seg;
} targ_addr;

typedef struct
{
	uint16_t modnum;         // DOS: idx of module which defines this sym
	uint16_t ovlref : 12;  // DOS: overlay vector #
	uint16_t ovlstate : 4;  // DOS: overlay vector state
} dos_sym_data;

typedef struct symbol
{
	struct symbol* hash;
	struct symbol* publink;
	struct symbol* link;
	targ_addr           addr;
	uint16_t         namelen_cmp;
	sym_info            info;       // flags & floating point fixup type.
	struct mod_entry* mod;
	union
	{
		void* edges;     // for dead code elim. when sym undefd
		struct segdata* seg;       // seg symbol is in.
		char* alias;     // for aliased syms.
		void* import;    // NOVELL & OS/2 only: imported symbol data.
		offset          cdefsize;   // altdef comdefs: size of comdef
	} p;
	union
	{
		dos_sym_data    d;
		struct symbol* altdefs;   // for keeping track of comdat & comdef defs
		struct symbol* datasym;   // altdef comdats: sym which has data def
		unsigned        aliaslen;   // for aliases - length of name.
	} u;
	union
	{
		struct symbol* mainsym;   // altdefs: main symbol definition
		struct symbol* def;       // for lazy externs
		struct symbol** vfdata;   // for virtual function lazy externs.
		void* export1;    // OS/2 & PE only: exported sym info.
	} e;
	char* name;
	char* prefix;    // primarily for netware, though could be
	// subverted for other use. gives symbol
	// namespace qualification
} symbol;

typedef struct vecnode
{
	struct vecnode* next;
	symbol* entry;
} vecnode;

struct fmt_dos_data
{
	unsigned    distribute : 1;
	unsigned    noindirect : 1;
	unsigned    dynamic : 1;
	unsigned    ovl_short : 1;
	unsigned    pad_sections : 1;
	unsigned    knoweas : 1; /* JWlink */
};

struct fmt_phar_data
{
	uint32_t     mindata;
	uint32_t     maxdata;
	char* breaksym;       // name of realbreak symbol
	struct rtpblock* params;         // run-time parameter block.
	char* stub;       // name of stub file.
	//    bool            pack;    needed if/when .exp packing implemented
};

typedef struct name_list
{
	struct name_list* next;
	unsigned            len;
	uint32_t         num;
	char* name;          // NYI: make this vbl length again.
} name_list;

// linker specific OS/2 data

struct fmt_os2_data
{
	struct entry_export* exports;
	name_list* mod_ref_list;
	name_list* imp_tab_list;
	char* stub_file_name;
	char* res_module_name;
	char* old_lib_name;
	struct os2_seg_flags* os2_seg_flags;
	char* description;
	uint32_t         heapsize;
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

struct fmt_pe_data
{
	struct fmt_os2_data os2;    /* must be first field */
	list_of_names* resources;
	uint32_t         heapcommit;
	uint32_t         stackcommit;
	unsigned            subsystem;
	uint16_t         submajor;
	uint16_t         subminor;
	uint16_t         osmajor;    /*  OS major version    */
	uint16_t         osminor;    /*  OS minor version    */
	uint8_t          linkmajor;  /*  link major version  */
	uint8_t          linkminor;  /*  link minor version  */
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

struct fmt_d16m_data
{
	uint16_t     options;
	uint8_t      flags;              // in load16m.h
	uint8_t      strategy;
	uint16_t     buffer;
	uint16_t     gdtsize;
	uint16_t     selstart;
	uint16_t     extended;
	uint16_t     datasize;
	char* stub;              // name of stub file.
};

// stuff common to some file formats which have the concept of an export

struct exp_common
{
	name_list* export1;
	name_list* module;
};

// linker specific Novell NLM data

struct fmt_nov_data
{
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
	uint32_t         exeflags;
};

// so we don't have to allocate any memory for imports which are not
// referenced, make them initially point to some other aribtrary non-zero place

#define DUMMY_IMPORT_PTR    (void *)&FmtData.u.nov

// linker specific QNX 4.0 data

struct fmt_qnx_data
{
	struct qnx_seg_flags* seg_flags;
	uint32_t             heapsize;
	unsigned                flags;
	unsigned                priv_level;
	unsigned                gen_seg_relocs : 1;
	unsigned                gen_linear_relocs : 1;
	unsigned                seen_mismatch : 1;
};

// linker specific ELF data

struct fmt_elf_data
{
	struct exp_common   exp;            // must be at the start
	//unsigned long       alignment;    /* not used by Wlink! */
	int                 segment_shift;  /* for JWlink! */
	uint32_t         extrasects;
	uint8_t          abitype;        // EI_OSABI contents
	uint8_t          abiversion;     // EI_ABIVERSION contents
	unsigned            exportallsyms : 1;
	unsigned            elf64 : 1;               /* JWlink */
};

#define NO_BASE_SPEC    ((offset)-1UL)

struct fmt_data
{
	union   fmt_spec_data
	{
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
	uint32_t     SegMask;    // used to extract remainder for segment normalization
	unsigned        HexSegShift;// shift to convert Intel Hex record segments to address
	uint32_t     output_offset;
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

typedef struct group_entry
{
	GROUP_ENTRY* next_group;
	SEG_LEADER* leaders;
	symbol* sym;
	section* section;
	targ_addr           grp_addr;
	uint16_t         segflags;       /* see values in watcom\h\exeos2.h */
	uint16_t         alignment;      /* max alignment of all segments in grp */
	offset              size;
	offset              totalsize;
	offset              linear;         // preferred base address
	union
	{
		void* grp_relocs;    // OS2/ELF only.
		class_entry* class1;         // CV (during addr calc )
	} g;
	union
	{
		unsigned        qnxflags;       // QNX
		unsigned        miscflags;      // OS/2
		segment         dos_segment;    // DOS/16M: DOS segment value
	} u;
	unsigned            num;
	unsigned            isfree : 1;
	unsigned            isautogrp : 1;
	unsigned            isdup : 1;
} group_entry;

typedef struct grpnode
{
	GROUP_ENTRY* entry;
} grpnode;

typedef struct segdata
{
	SEGDATA* next;
	SEGDATA* mod_next;      // next segdata in module list.
	offset          length;         // length of segment in current module.
	virt_mem        data;           // data for this segment
	union
	{
		char* name;          // name of the segment (when is this member used???)
		seg_leader* leader;        // leader for the segment.
		SEGDATA* sdata;         // for explicit comdats
	} u;
	union
	{
		void* refs;          // P1dce: list of other seg's this references
		int32_t   delta;          // P2: for calc'ing segment & symbol addrs
	} a;
	union
	{
		mod_entry* mod;           // P2CV&DW: pointer to defining module.
		char* clname;        // INC: class name for segment
	} o;
	uint32_t     addrinfo;       // P2VIDEO: offset into addrinfo of seg.
	uint16_t     frame;          // the frame of an absolute segment.
	unsigned        align : 5;
	unsigned        select : 3; // comdat: selection type

	unsigned        combine : 2; // how to combine segment with others
	unsigned        alloc : 2; // comdat: where to allocate segment.
	unsigned        is32bit : 1; // TRUE if segment is 32 bits
	unsigned        iscode : 1; // TRUE if a code segment.
	unsigned        isabs : 1; // TRUE if this is an absolute segment.
	unsigned        iscdat : 1; // TRUE if this is a comdat

	unsigned        isuninit : 1; // TRUE if seg is uninitialized
	unsigned        isidata : 1; // TRUE if segment is .idata (ORL only)
	unsigned        ispdata : 1; // TRUE if segment is .pdata
	unsigned        isreldata : 1; // TRUE if segment is .reldata
	unsigned        visited : 1; // dce: TRUE if visited in graph search.
	unsigned        isrefd : 1; // dce: TRUE if this module is referenced.
	unsigned        isdead : 1; // dce: TRUE if segdata or segdef killed.
	unsigned        isdefd : 1; // segdata has been defined

	unsigned        isfree : 1; // segdata is free (used in carver stuff)
	unsigned        isprepd : 1; // has been prepped for inc linking
	unsigned        canfarcall : 1; // OK to do far call optimization here
	unsigned        hascdatsym : 1; // TRUE if comdat and has a symbol defd
	unsigned        isreadonly : 1; // TRUE if readonly data. jwlink
} segdata;

typedef struct segnode
{
	SEGDATA* entry;
	void* handle;    // ORL: handle for the segment.
	uint8_t* contents;  // ORL: pointer to contents of segment.
	unsigned            info;
} segnode;

typedef struct extnode
{
	symbol* entry;
	void* handle;    // ORL: handle for the symbol
	unsigned            ovlref : 12;
	unsigned            isweak : 1;
	unsigned            isdefd : 1; // used in ORL
} extnode;

typedef struct stringblock STRINGBLOCK;

#define STR_BLOCK_SIZE   (4*1024)

typedef struct stringblock
{
	STRINGBLOCK* next;
	unsigned    size;
	char        data[STR_BLOCK_SIZE];
} stringblock;

typedef struct
{
	STRINGBLOCK* data;
	unsigned    currbase;
} stringtable;

typedef struct blk blk_t;
typedef struct free_t free_t;

typedef struct
{
	free_t* free_list;
	free_t* insert;
	blk_t* blk_list;
	blk_t** blk_map;
	size_t      elm_size;
	size_t      elm_count;
	size_t      blk_top;
	size_t      blk_count;
	size_t      blk_size;
	unsigned    size_chg : 1;
} cv_t, * carve_t;

typedef struct groupdef
{
	struct groupdef* next;
	unsigned            numsegs;
	char* grpname;
	char* names[1];
} incgroupdef;

typedef struct liblist
{
	struct liblist* next;
	unsigned            namelen;
	char                name[1];
} libnamelist;

typedef struct class_entry
{
	CLASS_ENTRY* next_class;
	SEG_LEADER* segs;
	char* name;
	class_status        flags;
	section* section;
	targ_addr           BaseAddr;   // Fixed location to of this class for loadfile
	CLASS_ENTRY* DupClass;  // Class to get data from for output
} class_entry;

typedef struct entry_export
{
	struct entry_export* next;
	char* name;
	uint32_t             ordinal;
	uint16_t             iopl_words;
	uint16_t             isresident : 1;
	uint16_t             isexported : 1;
	uint16_t             ismovable : 1;
	uint16_t             isanonymous : 1;
	uint16_t             isfree : 1;
	uint16_t             isprivate : 1;
	symbol* sym;
	char* impname;
	targ_addr               addr;
} entry_export;

typedef struct dll_sym_info
{
	union
	{
		name_list* modnum;        /* # of DLL in imported names table */
		char* modname;
	} m;
	union
	{
		name_list* entry;         /* # of entry in DLL */
		char* entname;
		unsigned        ordinal;
	} u;
	unsigned            isordinal : 1;
	unsigned            isfree : 1;
	symbol* iatsym;        // NT: symbol for address in iat
} dll_sym_info;

typedef struct seg_leader
{
	SEG_LEADER* next_seg;
	SEG_LEADER* grp_next;
	char* segname;
	SEGDATA* pieces;
	group_entry* group;
	class_entry* class1;
	offset          size;               // total size of segment
	SEG_LEADER* DupSeg;            // Segment to get data from for output
	uint16_t     info;
	uint16_t     align : 5;        // alignment of seg (power of 2)
	uint16_t     dbgtype : 3;        // debugging type of seg
	uint16_t     combine : 2;        // combine val. of seg
	uint32_t     num;                // # of addrinfos to output (video)
	targ_addr       seg_addr;           // address of segment.
	uint16_t     segflags;           // format specific segment flags
} seg_leader;

typedef union
{
	symbol* sym;
	uint16_t         mod;
	uint32_t         test;
} dist_arc;

// fields used only in distributing libs are marked dist:
// remember to change DIST_ONLY_SIZE if you remove or add a "dist" field!

typedef struct arcdata
{
	uint16_t         ovlref;     // dist: # of the module
	uint16_t         numarcs;    // dist: of arcs in the list
	dist_arc            arcs[1];    // dist: the actual arcs.
} arcdata;

typedef struct mod_entry
{
	union
	{
		MOD_ENTRY* next_mod;  // regular next pointer
		section* sect;      // when distributing - section of current mod.
	} n;
	union
	{
		FILE_LIST* source;
		char* fname;
	} f;
	char* name;
	unsigned long       location;
	symbol* publist;
	SEGDATA* segs;
	time_t              modtime;
	unsigned            relocs;
	unsigned            sizerelocs;
	module_flags        modinfo;
	void* lines;
	omf_dbg_type        omfdbg;
	union
	{
		arcdata* arclist;   // segment definition data.
		MOD_ENTRY* next;      // for keeping track of modules when distrib
	} x;
	union
	{
		ODBIMODINFO* o;
		DWARFMODINFO* d;
		CVMODINFO* cv;
	} d;                        // union used for debugging information
} mod_entry;

typedef struct
{
	uint32_t offset;
	uint16_t num;
	uint16_t size;
} demanddata;

typedef struct odbimodinfo
{
	uint32_t linelinksize;
	demanddata  types;
	demanddata  locals;
	demanddata  lines;
	uint32_t modnum;
	unsigned    dbisourceoffset;
} odbimodinfo;

typedef struct
{
	virt_mem    addr;
	uint32_t size;
} dwarfsect;

typedef struct dwarfmodinfo
{
	dwarfsect   pubsym;
	dwarfsect   dasi;
	dwarfsect   arange;
} dwarfmodinfo;

typedef struct cvmodinfo
{
	uint32_t pubsize;
	virt_mem    segloc;
	uint16_t numlines;
	uint16_t modidx;
	uint16_t numsegs;
} cvmodinfo;

typedef union msg_arg
{
	symbol* symb;
	char* string;
	char            c;
	uint16_t     int_16;
	uint32_t     int_32;
	targ_addr* address;
} MSG_ARG;

typedef struct msg_arg_list
{
	int             index;
	MSG_ARG         arg[5];
} MSG_ARG_LIST;

#define SYM_BLOCK_SIZE      (16*1024)
#define SYM_BLOCK_MIN       32

typedef struct sym_block
{
	struct sym_block* next;       /* NOTE: this *must* be the first field */
	unsigned            size;
	char                block[1];
} sym_block;

#define ALLOC_SIZE  (sizeof( sym_block )-1)

typedef struct block_data
{
	sym_block* list;
	unsigned        currbrk;
} block_data;

typedef struct section
{
	SECTION* next_sect;
	FILE_LIST* files;
	pHTable             modFilesHashed;
	MOD_ENTRY* mods;
	CLASS_ENTRY* classlist;
	ORDER_CLASS* orderlist; // Link to data for ordering, if used
	targ_addr           sect_addr;
	uint16_t         ovl_num;
	OVL_AREA* areas;
	SECTION* parent;
	uint32_t         relocs;
	uint32_t         size;
	void* reloclist;
	union
	{
		uint32_t         file_loc;
		MOD_ENTRY* dist_mods;
	} u;
	void* dbg_info;
	OUTFILELIST* outfile;
} section;

typedef struct symrecinfo
{
	struct symrecinfo* next;
	symbol* sym;
	mod_entry* mod;
} symrecinfo;

typedef struct cdat_piece
{
	struct cdat_piece* next;
	uint8_t* data;
	offset              length;
	unsigned            free_data : 1;
} comdat_piece;

typedef struct cdat_info
{
	struct cdat_info* next;
	segdata* sdata;
	symbol* sym;
	comdat_piece* pieces;
	sym_info            flags;
} comdat_info;

struct import_name
{
	struct import_name* next;
	dll_sym_info* dll;
	name_list* imp;
};

typedef struct module_import
{
	struct module_import* next;
	struct name_list* mod;
	struct import_name* imports;
	unsigned                    num_entries;
} module_import;

typedef struct fix_data
{
	::byte* data;
	uint32_t value;              /* value at location being patched */
	uint32_t hvalue;             /* jwlink: in case value is 64-bit */
	targ_addr   loc_addr;
	targ_addr   tgt_addr;
	fix_type    type;
	unsigned    ffix : 3;
	unsigned    additive : 1;
	unsigned    done : 1;
	unsigned    imported : 1;
	unsigned    os2_selfrel : 1;
} fix_data;

typedef struct
{
	void* buffer;
	unsigned long       pos;
	infilelist* currfile;
} bufferedfile;

typedef struct edgelist
{
	struct edgelist* next;
	union
	{
		segdata* seg;
		symbol* sym;
	} u;
	unsigned            issym : 1;      // true if contains a symbol
	unsigned            reverse_dir : 1;// true if edge points in the opposite
	// direction
} edgelist;

typedef struct bakpatlist
{
	struct bakpatlist* next;
	virt_mem            addr;
	uint16_t         len;
	::byte                loctype;
	bool                is32bit;
	char                data[1];
} bakpat_list;

typedef enum
{
	FIX_FRAME_SEG,      /* segdata */
	FIX_FRAME_GRP,      /* group_entry */
	FIX_FRAME_EXT,      /* symbol */
	FIX_FRAME_ABS,      /* absolute value */
	FIX_FRAME_LOC,      /* frame containing location */
	FIX_FRAME_TARG,     /* frame same as target */
	FIX_FRAME_FLAT      /* frame is flat group */
} frame_type;

#define FRAME_HAS_DATA( fix ) ((fix) < FIX_FRAME_LOC)

typedef struct
{
	union
	{
		segdata* sdata;
		group_entry* group;
		symbol* sym;
		segment         abs;
		void* ptr;
		unsigned        val;
	} u;
	frame_type  type;
} frame_spec;

typedef union
{
	unsigned long   spill;
	void* addr;
} spilladdr;

typedef struct reloc_info
{
	struct reloc_info* next;
	unsigned            sizeleft;
	spilladdr           loc;
} reloc_info;

typedef struct os2_reloc_header
{
	reloc_info* externals; /* external and segment style fixups */
	reloc_info* internals; /* internal, non-segment fixups */
} os2_reloc_header;

typedef struct
{
	f_handle    handle;
	char* fname;
	char* buffer;
	unsigned    bufsize;
	//    char        *dllname;
	//    size_t      dlllen;
	char* module_name;
	size_t      module_name_len;
	unsigned    didone : 1;
} implibinfo;

typedef struct
{
	uint32_t grp_start;
	uint32_t seg_start;
	group_entry* lastgrp;  // used only for copy classes
	bool        repos;
} grpwriteinfo;

typedef struct
{
	union
	{
		symbol* sym;
		segdata* sdata;
	} targ;
	offset              off;
	mod_entry* mod;
	targ_addr           addr;
	unsigned            type : 2;
	unsigned            user_specd : 1;
	unsigned            from_inc : 1;
} startinfo;

typedef struct
{
	segdata* sdata;    // If sdata == NULL, use sym to get address
	// else use off and sdata->addr get address
	union
	{
		offset off;  // relative to sdata->addr
		symbol* sym;
	} u;
} TocEntryId;

typedef struct
{
	TocEntryId e;
	int pos;
} TocEntry;

typedef struct tok
{
	char* buff;
	unsigned    len;
	char* next;
	char* this1;
	uint16_t line;
	char        quoted;     /* if token parsed as a quoted string*/
	uint8_t  where : 2;
	uint8_t  how : 3;
	uint8_t  thumb : 1;
	uint8_t  locked : 1;
	uint8_t  skipToNext : 1;   /* set true if we need to skip to next token without a separator */
} tok;

typedef enum commandflag
{
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

typedef struct sysblock
{
	struct sysblock* next;
	char* name;
	char                commands[1];
} sysblock;

typedef struct node
{
	void* next;
	void* entry;
} node;

typedef struct trace_info
{
	TRACE_INFO* next;
	union
	{
		char* name;
		file_list* lib;
	} u;
	char* member;
	bool                found;
} trace_info;
