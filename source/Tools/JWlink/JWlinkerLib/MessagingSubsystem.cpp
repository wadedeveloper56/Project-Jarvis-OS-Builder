#include "pch.h"
#include "MessagingSubsystem.h"
#include "debug.h"
#include "banner.h"
#include "globals.h"
#include "cmdutils.h"
#include "linkutil.h"
#include "cmdline.h"
#include "Structs.h"
#include "mapio.h"

#undef pick
#define pick( code, string )  string,

const char* const msgtexts[] = {
	"",
	"",
pick(MSG_INTERNAL,            "** internal ** - %s")
pick(MSG_LOADING_OBJECT,      "loading object files")
pick(MSG_SEARCHING_LIBS,      "searching libraries")
pick(MSG_CREATE_MAP,          "creating map file")
pick(MSG_CREATE_EXE,          "creating %f")
pick(MSG_USING_SPILL,         "using spill file")
pick(MSG_CANT_OPEN,           "cannot open %1 : %2")
pick(MSG_NO_DYN_MEM,          "dynamic memory exhausted")
pick(MSG_IO_PROBLEM,          "I/O error processing %1 : %2")
pick(MSG_OBJ_FILE_ATTR,       "invalid object file attribute")
pick(MSG_LIB_FILE_ATTR,       "invalid library file attribute")
pick(MSG_BREAK_HIT,           "break key detected")
pick(MSG_STACK_NOT_FOUND,     "stack segment not found")
pick(MSG_BAD_RELOC_TYPE,      "bad relocation type specified")
pick(MSG_BAD_ABS_FIXUP,       "%a: absolute target invalid for self-relative relocation")
pick(MSG_BAD_REL_FIXUP,       "bad location specified for self-relative relocation at %a")
pick(MSG_FIXUP_OFF_RANGE,     "relocation offset at %a is out of range")
pick(MSG_SEG_RELOC_OUT,       "segment relocation at %a")
pick(MSG_GROUP_TOO_BIG,       "size of group %s exceeds 64k by %l bytes")
pick(MSG_SEG_TOO_BIG,         "size of segment %s exceeds 64k by %l bytes")
pick(MSG_CANT_HAVE_START,     "cannot have a starting address with an imported symbol")
pick(MSG_NO_START_ADDR,       "no starting address found, using %a")
pick(MSG_NO_OVERLAY_LOADER,   "missing overlay loader")
pick(MSG_VECT_RANGE,          "%s vector %d is out of range")
pick(MSG_RESERVED_SYM_DEFINED,"redefinition of reserved symbol %s")
pick(MSG_MULT_DEF,            "redefinition of %S ignored")
pick(MSG_UNDEF_REF,           "%S is an undefined reference")
pick(MSG_EARLY_EOF,           "premature end of file encountered")
pick(MSG_MULT_START_ADDRS,    "multiple starting addresses found")
pick(MSG_SEG_IN_TWO_GROUPS,   "segment %1 is in group %2 and group %3")
pick(MSG_REC_NOT_DONE,        "record (type 0x%x) not processed")
pick(MSG_DIRECTIVE_ERR,       "directive error near '%s'")
pick(MSG_NO_OFFSET_WITH_DLL,  "%a: cannot have an offset with an imported symbol")
pick(MSG_EXE_NAME,            "Executable Image: %s")
pick(MSG_CREATED_ON,          "Created on:       %1 %2")
pick(MSG_UNDEF_SYM,           "file %1(%2): undefined symbol %S")
pick(MSG_DEBUG_AFTER_FILES,   "DEBUG directive appears after object files")
pick(MSG_ALIGN_TOO_SMALL,     "ALIGNMENT value too small")
pick(MSG_IMPORT_ORD_INVALID,  "ordinal in IMPORT directive not valid")
pick(MSG_EXPORT_ORD_INVALID,  "ordinal in EXPORT directive not valid")
pick(MSG_TOO_MANY_IOPL_WORDS, "too many IOPL words in EXPORT directive")
pick(MSG_DUP_EXP_ORDINAL,     "duplicate exported ordinal")
pick(MSG_EXP_SYM_NOT_FOUND,   "exported symbol %s not found")
pick(MSG_SEG_FLAG_MULT_DEFD,  "segment attribute defined more than once")
pick(MSG_SEG_NAME_NOT_FOUND,  "segment name %s not found")
pick(MSG_CLASS_NAME_NOT_FOUND,"class name %s not found")
pick(MSG_AUTO_SEG_MULT_DEFD,  "inconsistent attributes for automatic data segment")
pick(MSG_INV_STUB_FILE,       "invalid STUB file")
pick(MSG_INV_OLD_DLL,         "invalid DLL specified in OLDLIBRARY option")
pick(MSG_STUB_SAME_AS_LOAD,   "STUB file name same as executable file name")
pick(MSG_REL_NOT_SAME_SEG,    "relocation at %a not in the same segment")
pick(MSG_DLL_IN_REL_RELOC,    "%a: cannot reach a DLL with a relative relocation")
pick(MSG_CANT_USE_LOCALS,     "debugging information incompatible: using line numbers only")
pick(MSG_FRAME_EQ_TARGET,     "%a: frame must be the same as the target in protect mode")
pick(MSG_CANT_FIND_MEMBER,    "cannot find library member %1(%2)")
pick(MSG_MULTIPLE_MODES_FOUND,"executable format has been established")
pick(MSG_FORMAT_BAD_OPTION,   "option %s not valid for %f")
pick(MSG_VALUE_TOO_LARGE,     "value for %s too large")
pick(MSG_VALUE_INCORRECT,     "value for %s incorrect")
pick(MSG_MULT_REALBREAKS,     "multiple values specified for REALBREAK")
pick(MSG_DLL_WITH_386,        "export and import records not valid for %f")
pick(MSG_INVALID_FLAT_RELOC,    "invalid relocation for flat memory model at %a")
pick(MSG_CANT_COMBINE_32_AND_16,"cannot combine 32-bit segments (%1) with 16-bit segments (%2)")
pick(MSG_BREAKSYM_NOT_FOUND,    "REALBREAK symbol %s not found")
pick(MSG_BAD_IMP_REL_RELOC,     "invalid relative relocation type for an import at %a")
pick(MSG_NOV_NO_CODE_DATA_RELOC,"%a: cannot relocate between code and data in Novell formats")
pick(MSG_ABS_SEG_FIXUP_BAD,     "absolute segment fixup not valid in protect mode")
pick(MSG_CHECK_NOT_FOUND,       "unload CHECK procedure not found")
pick(MSG_START_PROC_NOT_FOUND,  "START procedure not found")
pick(MSG_EXIT_PROC_NOT_FOUND,   "EXIT procedure not found")
pick(MSG_NO_SECTION_IN_ROOT,    "SECTION directive not allowed in root")
pick(MSG_BAD_NOV_FILE_TYPE,     "bad Novell file format specified")
pick(MSG_CIRCULAR_ALIAS_FOUND,  "circular alias found for %s")
pick(MSG_EXPECTING_END,         "expecting an END directive")
pick(MSG_OPTION_MULTIPLY_DEFD,  "%s option multiply specified")
pick(MSG_NOT_MULTIPLE_OF_8,     "%s is not a multiple of 8")
pick(MSG_BOTH_RELOC_OPTIONS,    "both relocation options specified")
pick(MSG_TRANS_RELOCS_NEEDED,   "relocations needed for transparent data")
pick(MSG_FOUND_XXBIT_OBJ,       "file %s is a %d-bit object file")
pick(MSG_TOO_MANY_SELECTORS,    "too many selectors needed")
pick(MSG_BAD_REC_TYPE,          "invalid record type 0x%x")
pick(MSG_FRAME_INVALID,         "cannot reference address %A from frame %x")
pick(MSG_BAD_TARG_OFF,          "target offset exceeds 64K at %a")
#ifdef __UNIX__
pick(MSG_PRESS_CTRL_Z,          "Press CTRL/D to finish")
#else
pick(MSG_PRESS_CTRL_Z,          "Press CTRL/Z and then RETURN to finish")
#endif
pick(MSG_INV_COM_START_ADDR,       "invalid starting address for .COM file")
pick(MSG_STACK_SEG_IGNORED,        "stack segment ignored in .COM file")
pick(MSG_NO_VIRT_MEM,              "virtual memory exhausted")
pick(MSG_COM_TOO_LARGE,            "program too large for a .COM file")
pick(MSG_MULT_DEF_BY,              "redefinition of %1 by %2 ignored")
pick(MSG_OVL_GROUP_SPLIT,          "group %s is in more than one overlay")
pick(MSG_NEWSEG_BEFORE_OBJ,        "NEWSEGMENT directive appears before object files")
pick(MSG_CANT_OPEN_NO_REASON,      "cannot open %s")
pick(MSG_IO_PROBLEM_NO_REASON,     "I/O error processing %s")
pick(MSG_DEBUG_TOO_LARGE,          "%s debugging information too large")
pick(MSG_INCOMPATIBLE_DBI_FOUND,   "incompatible types of debugging information found")
pick(MSG_TOO_MANY_LIB_MODS,        "too many library modules")
pick(MSG_OFFSET_MUST_BE_ALIGNED,   "Offset option must be a multiple of %l")
pick(MSG_SYMBOL_NAME_TOO_LONG,     "symbol name too long: %s")
pick(MSG_MOD_TRACE,                "%S referenced by module %s")
pick(MSG_INV_INC_FILE,             "invalid incremental information file")
pick(MSG_TRACE_OBJ_NOT_FOUND,      "object file %s not found for tracing")
pick(MSG_TRACE_LIB_NOT_FOUND,      "library module %1(%2) not found for tracing")
pick(MSG_MOD_IND_TRACE,            "%S referenced indirectly by module %s")
pick(MSG_CANT_RESERVE_SPACE,       "cannot reserve %l bytes of extra overlay space")
pick(MSG_VIRDEF_UNSUPPORTED,       "Borland VIRDEF records not supported")
pick(MSG_SYSTEM_UNDEFINED,         "undefined system name: %s")
pick(MSG_SYSTEM_ALREADY_DEFINED,   "system %s defined more than once")
pick(MSG_QNX_BASE_LT_STACK,        "OFFSET option is less than the stack size")
pick(MSG_NO_MEMB_IN_LIBFILE,       "library members not allowed in libfile")
pick(MSG_ERROR_IN_SYSTEM_BLOCK,    "error in default system block")
pick(MSG_NO_PREVIOUS_INPUT,        "no previous input source")
pick(MSG_NO_INPUT_LEFT,            "no more input found for ^ command")
pick(MSG_ENV_NAME_INCORRECT,       "environment name specified incorrectly")
pick(MSG_ENV_NOT_FOUND,            "environment name %s not found")
pick(MSG_AREA_TOO_SMALL,           "overlay area must be at least %l bytes")
pick(MSG_BAD_MOVABLE_SEG_NUM,      "segment number too high for a movable entry point")
pick(MSG_HEAP_TOO_BIG,             "heap size too large")
pick(MSG_BAD_WLIB_IMPORT,          "wlib import statement incorrect")
pick(MSG_APP_TOO_BIG_FOR_DOS,      "application too large to run under DOS")
pick(MSG_DUP_EXP_NAME,             "'%s' has already been exported")
pick(MSG_NO_FILES_FOUND,           "no FILE directives found")
pick(MSG_OVERLAYS_NOT_SUPPORTED,   "overlays are not supported in this version of JWlink")
pick(MSG_LAZY_EXTDEF_MISMATCH,     "lazy reference for %S has different default resolutions")
pick(MSG_MULTIPLE_ALIASES,         "multiple aliases found for %S")
pick(MSG_EXE_DATE_CHANGED,         "%s has been modified: doing full relink")
pick(MSG_CANT_EXPORT_ABSOLUTE,     "cannot export symbol %S")
pick(MSG_DIRECTIVE_ERR_BEGINNING,  "directive error near beginning of input")
pick(MSG_ADDR_INFO_TOO_LARGE,      "address information too large")
pick(MSG_INV_SHARED_NLM_FILE,      "%s is an invalid shared NLM file")
pick(MSG_CANT_OPEN_SPILL,          "cannot open temporary file: file already exists")
pick(MSG_BAD_CURLY_LIST,           "curly brace delimited list incorrect")
pick(MSG_NO_REALBREAK_WITH_16BIT,  "no realbreak specified for 16-bit code")
pick(MSG_INV_MESSAGE_FILE,         "%s is an invalid message file")
pick(MSG_INCORRECT_NUM_AREAS,      "need exactly 1 overlay area with dynamic overlay manager")
pick(MSG_RELOC_TO_RWDATA_SEG,      "segment relocation to a read/write data segment found at %a(%S)")
pick(MSG_TOO_MANY_ERRORS,          "too many errors encountered")
pick(MSG_INV_FILENAME,             "invalid filename '%s'")
pick(MSG_CANNOT_HAVE_16_AND_32,    "cannot have both 16-bit and 32-bit object files")
pick(MSG_INVALID_MSG_NUM,          "invalid message number")
pick(MSG_VF_TABLE_MISMATCH,        "virtual function table record for %S mismatched")
pick(MSG_SECTIONALIGN_GT_OBJALIGN, "section %s alignment (%d) greater than OBJALIGN value")
pick(MSG_CANT_SORT_SYMBOLS,        "not enough memory to sort map file symbols")
pick(MSG_SYMBOL_DEAD,              "symbol %S removed")
pick(MSG_VF_PURE_MISMATCH,         "%S is both pure virtual and non-pure virtual")
pick(MSG_BAD_OBJECT,               "%s is an invalid object file")
pick(MSG_AMBIG_FORMAT,             "ambiguous format specified")
pick(MSG_INVALID_TYPE_DESC,        "invalid segment type specified")
pick(MSG_MULT_DBI_FORMATS,         "only one debugging format can be specified")
pick(MSG_MACHTYPE_DIFFERENT,       "file %s has code for a different processor")
pick(MSG_NO_BIG_ENDIAN,            "big endian code not supported")
pick(MSG_NO_DICT_FOUND,            "no dictionary found")
pick(MSG_INVALID_INDEX_IN_RELOC,   "invalid segment/group/external index (%d) in relocation")
pick(MSG_CANT_EXECUTE,             "cannot execute %1 : %2")
pick(MSG_REL_NOT_ALIGNED,          "relocation at %a to an improperly aligned target")
pick(MSG_INC_NEAR_START,           "OPTION INCREMENTAL must be one of the first commands specified ")
pick(MSG_NO_CODE_OR_DATA,          "no code or data present")
pick(MSG_PROBLEM_IN_RESOURCE,      "problem adding resource information")
pick(MSG_INC_ONLY_SUPPORTS_DWARF,  "incremental linking only supports DWARF debugging information")
pick(MSG_INC_AND_DCE_NOT_ALLOWED,  "incremental linking does not support dead code elimination")
pick(MSG_TOC_TOO_BIG,              "Table of Contents too big to fit into 64K")
pick(MSG_free_3,                   "relocations on iterated data not supported")
pick(MSG_NOT_COMPILED_VF_ELIM,     "module has not been compiled with -zv")
pick(MSG_INC_AND_VFR_NOT_ALLOWED,  "incremental linking does not support virtual function removal")
pick(MSG_RESOURCE_TOO_BIG,         "resource file %s too big")
pick(MSG_MULT_START_ADDRS_BY,      "both %1 and %2 marked as starting symbols")
pick(MSG_INTERNAL_MOD_NAME_DIFF_FROM_FILE,  "The NLM internal name (%s) has been truncated as it exceeds the maximum size")
pick(MSG_VXD_INCORRECT_EXPORT,     "One export must exist for the VxD format")
pick(MSG_FIXED_LOC_BEFORE_CUR_LOC, "Location counter is already beyond fixed Segment Address %a")
pick(MSG_DUP_DIRECTIVE,            "Directive %s can only occur once")
pick(MSG_IMPORT_LOCAL,             "Locally defined symbol %s is imported")
pick(MSG_NEED_NOLARGEADDRESSAWARE, "32-bit relocation to '%s' requires option NOLARGEaddressaware")
pick(MSG_UNKNOWN_DIRECTIVE_IGNORED,"unknown directive '-%s' ignored")
pick(MSG_TARGET_DISP_IGNORED,      "target displacement %x ignored for segment fixup")

pick(MSG_FILE_REC_NAME_0, "file %s: ")
pick(MSG_FILE_REC_NAME_1, "(%s): ")
pick(MSG_FILE_REC_NAME_2, "file %1(%2): ")
pick(MSG_FILE_REC_NAME_3, "record %d: ")
pick(MSG_FILE_REC_NAME_4, "file %s, record %d: ")
pick(MSG_FILE_REC_NAME_5, "(%s), record %d: ")
pick(MSG_FILE_REC_NAME_6, "file %1(%2), record %d: ")
pick(MSG_ERROR, "Error! E%d: ")
pick(MSG_WARNING, "Warning! W%d: ")
pick(MSG_SYS_BLK, "system block %s: ")
pick(MSG_ENVIRON, "environment %s: ")
pick(MSG_LINE, "line(%d): ")
pick(MSG_FORMAT_NOT_DECIDED, "format not decided")
pick(MSG_NO_LEADER_ON_PASS_2, "no leader found on pass 2")
pick(MSG_IOERRLIST_0, "")
pick(MSG_IOERRLIST_1, "")
pick(MSG_IOERRLIST_2, "file not found")
pick(MSG_IOERRLIST_3, "path not found")
pick(MSG_IOERRLIST_4, "too many open files")
pick(MSG_IOERRLIST_5, "access denied")
pick(MSG_IOERRLIST_6, "invalid handle")
pick(MSG_IOERRLIST_7, "disk full")
pick(MSG_PRESS_KEY, "press any key to continue")
pick(MSG_FILE_TYPES_0, "OS/2")
pick(MSG_FILE_TYPES_1, "OS/2 linear")
pick(MSG_FILE_TYPES_2, "OS/2 linear extended")
pick(MSG_FILE_TYPES_3, "Windows")
pick(MSG_FILE_TYPES_4, "PE")
pick(MSG_FILE_TYPES_5, "DOS")
pick(MSG_FILE_TYPES_6, "DOS .COM")
pick(MSG_FILE_TYPES_7, "DOS overlayed")
pick(MSG_FILE_TYPES_8, "Novell Netware")
pick(MSG_FILE_TYPES_9, "QNX")
pick(MSG_FILE_TYPES_10, "Phar Lap simple")
pick(MSG_FILE_TYPES_11, "Phar Lap extended")
pick(MSG_FILE_TYPES_12, "Phar Lap relocatable")
pick(MSG_FILE_TYPES_13, "Phar Lap segmented")
pick(MSG_FILE_TYPES_14, "QNX 386")
pick(MSG_FILE_TYPES_15, "ELF")
pick(MSG_FILE_TYPES_16, "Windows VxD")
pick(MSG_FILE_TYPES_17, "DOS/16M")
pick(MSG_FILE_PE64, "64-bit PE")
pick(MSG_FILE_ELF64, "64-bit ELF")
pick(MSG_CREATE_TYPE_DLL, "dynamic link library")
pick(MSG_CREATE_TYPE_EXE, "executable")
pick(MSG_IS_A_EXE, "This is %f")

pick(MSG_MAP_BOX_GROUP, "|   Groups   |")
pick(MSG_MAP_TITLE_GROUP_0, "Group                           Address              Size")
pick(MSG_MAP_TITLE_GROUP_1, "=====                           =======              ====")
pick(MSG_MAP_BOX_ABS_SEG, "|   Absolute Segments   |")
pick(MSG_MAP_TITLE_ABS_SEG_0, "Segment                 Class           Address              Size")
pick(MSG_MAP_TITLE_ABS_SEG_1, "=======                 =====           =======              ====")
pick(MSG_MAP_BOX_SEGMENTS, "|   Segments   |")
pick(MSG_MAP_TITLE_SEGMENTS_0, "Segment                Class          Group          Address         Size")
pick(MSG_MAP_TITLE_SEGMENTS_1, "=======                =====          =====          =======         ====")
pick(MSG_MAP_BOX_MEMORY_MAP, "|   Memory Map   |")
pick(MSG_MAP_UNREF_SYM, "* = unreferenced symbol")
pick(MSG_MAP_REF_LOCAL_SYM, "+ = symbol only referenced locally")
pick(MSG_MAP_TITLE_MEMORY_MAP_0, "Address        Symbol")
pick(MSG_MAP_TITLE_MEMORY_MAP_1, "=======        ======")
pick(MSG_MAP_BOX_OVERLAY_VECTOR, "|   Overlay Vectors   |")
pick(MSG_MAP_BOX_COMMUNAL, "|   Communal Symbols   |")
pick(MSG_MAP_TITLE_COMMUNAL_0, "Address        Symbol")
pick(MSG_MAP_TITLE_COMMUNAL_1, "=======        ======")
pick(MSG_MAP_BOX_MOD_SEG, "|   Module Segments   |")
pick(MSG_MAP_ABS_ADDR, "* = absolute address")
pick(MSG_MAP_32BIT_SEG, "! = 32-bit segment")
pick(MSG_MAP_TITLE_MOD_SEG_0, "Module          Segment               Class           Address         Size")
pick(MSG_MAP_TITLE_MOD_SEG_1, "======          =======               =====           =======         ====")
pick(MSG_MAP_BOX_TRACE_SYM, "|   Traced Symbols   |")
pick(MSG_MAP_BOX_IMP_SYM, "|   Imported Symbols   |")
pick(MSG_MAP_TITLE_IMP_SYM_0, "Symbol")
pick(MSG_MAP_TITLE_IMP_SYM_1, "======")
pick(MSG_MAP_TITLE_IMP_SYM_2, "Symbol                              Module")
pick(MSG_MAP_TITLE_IMP_SYM_3, "======                              ======")
pick(MSG_MAP_BOX_UNRES_REF, "|   Unresolved References   |")
pick(MSG_MAP_TITLE_UNRES_REF_0, "Undefined Symbol                Referenced by")
pick(MSG_MAP_TITLE_UNRES_REF_1, "================                =============")
pick(MSG_MAP_BOX_LIB_USED, "|   Libraries Used   |")
pick(MSG_MAP_BOX_LINKER_STAT, "|   Linker Statistics   |")
pick(MSG_MAP_STACK_SIZE, "Stack size:")
pick(MSG_MAP_MEM_SIZE, "Memory size:")
pick(MSG_MAP_OVL_SIZE, "Overlay area size:")
pick(MSG_MAP_ENTRY_PT_ADDR, "Entry point address: %a")
pick(MSG_MAP_LINK_TIME, "Link time: %s")
pick(MSG_MAP_COMDAT, "c = initialized communal data")
pick(MSG_MAP_SYM_STATIC, "s = symbol is static")
pick(MSG_MAP_DEFINING_MODULE, "Module: %s(%s)")

	pick(MSG_GENERAL_HELP_0, "usage: jwlink {directive} ('jwlink -?' for detailed help)")
	pick(MSG_GENERAL_HELP_1, "\ncommands valid for all executable formats:\n")
	pick(MSG_GENERAL_HELP_2, "directive  ::= \"File\"        obj_spec{\",\"obj_spec}")
	pick(MSG_GENERAL_HELP_3, "            | \"Name\"         exe_file")
	pick(MSG_GENERAL_HELP_4, "            | \"OPtion\"       option{\",\"option}")
	pick(MSG_GENERAL_HELP_5, "            | \"Library\"      library_file{\",\"library_file}")
	pick(MSG_GENERAL_HELP_6, "            | \"OPTLIB\"       library_file{\",\"library_file}")
	pick(MSG_GENERAL_HELP_7, "            | \"Path\"         path_name{\";\"path_name}")
	pick(MSG_GENERAL_HELP_8, "            | \"LIBPath\"      path_name{\";\"path_name}")
	pick(MSG_GENERAL_HELP_9, "            | \"LIBFile\"      obj_file{\",\"obj_file}")
	pick(MSG_GENERAL_HELP_10, "            | \"Debug\"        dbtype [dblist] | dblist")
	pick(MSG_GENERAL_HELP_11, "            | \"MODTrace\"     module_name{\",\"module_name}")
	pick(MSG_GENERAL_HELP_12, "            | \"SYMTrace\"     symbol_name{\",\"symbol_name}")
	pick(MSG_GENERAL_HELP_13, "            | \"SYStem\"       system_name")
	pick(MSG_GENERAL_HELP_14, "            | \"SYStem Begin\" system_name directive {directive} \"End\"")
	pick(MSG_GENERAL_HELP_15, "            | \"FORMat\"       form")
	pick(MSG_GENERAL_HELP_16, "            | \"REFerence\"    symbol_name{\",\"symbol_name}")
	pick(MSG_GENERAL_HELP_17, "            | \"@\"            directive_file")
	pick(MSG_GENERAL_HELP_18, "            | \"#\"            comment")

	pick(MSG_GENERAL_HELP_19, "")

	pick(MSG_GENERAL_HELP_20, "\ncommands valid for all executable formats (continued):\n")
	pick(MSG_GENERAL_HELP_21, "            | \"Alias\"        alias\"=\"symbol_name{\",\"alias\"=\"symbol_name}")
	pick(MSG_GENERAL_HELP_22, "            | \"DISAble\"      msg_num{\",\"msg_num}")
	pick(MSG_GENERAL_HELP_23, "            | \"SOrt\"         [\"GLobal\"] [\"ALPhabetical\"]")
	pick(MSG_GENERAL_HELP_24, "            | \"LANGuage\"     (\"JApanese\" | \"CHinese\" | \"KOrean\")")
	pick(MSG_GENERAL_HELP_25, "            | \"STARTLINK\"")
	pick(MSG_GENERAL_HELP_26, "            | \"ENDLINK\"")
	pick(MSG_GENERAL_HELP_27, "            | \"MODFile\"      obj_file{\",\"obj_file}")
	pick(MSG_GENERAL_HELP_28, "obj_spec  ::= obj_file[\"(\"obj_member\")\"] | library_file[\"(\"lib_member\")\"]")
	pick(MSG_GENERAL_HELP_29, "dbtype    ::= \"Watcom\" | \"Dwarf\" | \"Codeview\"")
	pick(MSG_GENERAL_HELP_30, "dblist    ::= dboption{\",\"dboption}")
	pick(MSG_GENERAL_HELP_31, "dboption  ::= \"LInes\" | \"Types\" | \"LOcals\" | \"All\"")
	pick(MSG_GENERAL_HELP_32, "option    ::= \"ARTificial\" | \"[NO]CAChe\" | \"[NO]CASEexact\" | \"CVPack\"")
	pick(MSG_GENERAL_HELP_33, "            | \"Dosseg\" | \"ELiminate\" | \"[NO]FARcalls\"")
	pick(MSG_GENERAL_HELP_34, "            | \"INCremental[=file_name]\" | \"MANGlednames\"")
	pick(MSG_GENERAL_HELP_35, "            | \"Map\"[\"=\"map_file] | \"MAXErrors=\"n | \"NAMELen=\"n")
	pick(MSG_GENERAL_HELP_36, "            | \"NODefaultlibs\" | \"NOEXTension\" | \"OSName=\"string | \"Quiet\"")
	pick(MSG_GENERAL_HELP_37, "            | \"[NO]REDefsok\" | \"STack\"=n | \"START=\"symbol_name | \"STATics\"")
	pick(MSG_GENERAL_HELP_38, "            | \"SYMFile\"[\"=\"symbol_file], | \"[NO]Undefsok\" | \"Verbose\"")
	pick(MSG_GENERAL_HELP_39, "            | \"VFRemoval\"")

#define  MSG_GENERAL_HELP_LAST MSG_GENERAL_HELP_39

	pick(MSG_DOS_HELP_0, "\ncommands valid for the MS-DOS executable format only:\n")
	pick(MSG_DOS_HELP_1, "form      ::= \"Dos\" [\"COM\"]")
	pick(MSG_DOS_HELP_2, "directive ::= \"NEWsegment\"")
	pick(MSG_DOS_HELP_3, "option    ::=  \"PACKCode=\"n | \"PACKData=\"n | KNOWEAS")

#define  MSG_DOS_HELP_LAST MSG_DOS_HELP_3

	pick(MSG_OS2_HELP_0, "\ncommands valid for the OS/2 executable formats (NE, LE, LX) only:\n")
	pick(MSG_OS2_HELP_1, "form      ::= \"OS2\" [\"FLat\"|\"LE\"|\"LX\"] [\"PHYSdevice\" | \"VIRTdevice\"")
	pick(MSG_OS2_HELP_2, "            | [\"DLl\"[\"INITGlobal\"|\"INITInstance\" [\"TERMInstance\"|\"TERMGlobal\"]]")
	pick(MSG_OS2_HELP_3, "            | \"PM\" | \"PMCompatible\" | \"FULLscreen\"] ")
	pick(MSG_OS2_HELP_4, "directive ::= \"NEWsegment\"")
	pick(MSG_OS2_HELP_5, "            | \"SEGment\"     segdesc{\",\"segdesc}")
	pick(MSG_OS2_HELP_6, "            | \"IMPort\"      import{\",\"import}")
	pick(MSG_OS2_HELP_7, "            | \"EXPort\"      export{\",\"export}")
	pick(MSG_OS2_HELP_8, "            | \"EXPort\"      \"=\"wlib_directive_file")
	pick(MSG_OS2_HELP_9, "segdesc   ::= segspec segmodel {segmodel}")
	pick(MSG_OS2_HELP_10, "segspec   ::= seg_name | \"Class\" class_name | \"TYpe\" (\"CODE\" | \"DATA\")")
	pick(MSG_OS2_HELP_11, "import    ::= entryname module[\".\"(extname | ordinal)]")
	pick(MSG_OS2_HELP_12, "option    ::= \"Alignment=\"n | \"DEscription\" description | \"Heapsize=\"n")
	pick(MSG_OS2_HELP_13, "            | \"IMPFile\"[=file_name] | \"IMPLib\"[=file_name]")
	pick(MSG_OS2_HELP_14, "            | (\"MANYautodata\" | \"NOautodata\" | \"ONEAutodata\")")
	pick(MSG_OS2_HELP_15, "            | \"MODName=\"module_name | \"MIXed1632\" | \"NEWFiles\" | \"OFFset=\"n")
	pick(MSG_OS2_HELP_16, "            | \"OLDlibrary=\"dll_name | \"PACKCode=\"n | \"PACKData=\"n | \"PROTmode\"")
	pick(MSG_OS2_HELP_17, "            | \"RESource=\"res_file_name | \"STUB=\"stub_name | \"NOSTUB\"")
	pick(MSG_OS2_HELP_18, "            | \"VERSion=\"major.[minor]")
	pick(MSG_OS2_HELP_19, "export    ::= entryname[\".\"ordinal][\"=\"internal][\"RESident\"][\"PRIVATE\"][iopl]")
	pick(MSG_OS2_HELP_20, "segmodel  ::= (\"PReload\" | \"LOadoncall\") | (\"SHared\" | \"NONShared\")")
	pick(MSG_OS2_HELP_21, "            | (\"EXECUTEOnly\" | \"EXECUTERead\" | \"READOnly\" | \"READWrite\")")
	pick(MSG_OS2_HELP_22, "            | (\"Iopl\" | \"NOIopl\") | (\"CONforming\" | \"NONConforming\")")
	pick(MSG_OS2_HELP_23, "            | (\"PERManent\" | \"NONPERManent\") | \"INValid\" | \"RESident\"")
	pick(MSG_OS2_HELP_24, "            | \"CONTiguous\" | \"DYNamic\"\n")

#define MSG_OS2_HELP_LAST MSG_OS2_HELP_24

	pick(MSG_WINDOWS_HELP_0, "\ncommands valid for the Microsoft Win16 executable formats (NE) only:\n")
	pick(MSG_WINDOWS_HELP_1, "form      ::= \"WIndows\" [\"DLl\"[\"INITGlobal\" | \"INITInstance\"]] [DPMI] [MEMory] [FOnt]")
	pick(MSG_WINDOWS_HELP_2, "directive ::= \"NEWsegment\"")
	pick(MSG_WINDOWS_HELP_3, "            | \"SEGment\"     segdesc{\",\"segdesc}")
	pick(MSG_WINDOWS_HELP_4, "            | \"IMPort\"      import{\",\"import}")
	pick(MSG_WINDOWS_HELP_5, "            | \"EXPort\"      export{\",\"export}")
	pick(MSG_WINDOWS_HELP_6, "            | \"EXPort\"      \"=\"wlib_directive_file")
	pick(MSG_WINDOWS_HELP_7, "segdesc   ::= segspec segmodel {segmodel}")
	pick(MSG_WINDOWS_HELP_8, "segspec   ::= seg_name | \"Class\" class_name | \"TYpe\" (\"CODE\" | \"DATA\")")
	pick(MSG_WINDOWS_HELP_9, "import    ::= entryname module[\".\"(extname | ordinal)]")
	pick(MSG_WINDOWS_HELP_10, "option    ::= \"Alignment=\"n | \"DEscription\" description | \"Heapsize=\"n")
	pick(MSG_WINDOWS_HELP_11, "            | \"IMPFile\"[=file_name] | \"IMPLib\"[=file_name]")
	pick(MSG_WINDOWS_HELP_12, "            | (\"MANYautodata\" | \"NOautodata\" | \"ONEAutodata\")")
	pick(MSG_WINDOWS_HELP_13, "            | \"MODName=\"module_name | \"OLDlibrary=\"dll_name | \"PACKCode=\"n")
	pick(MSG_WINDOWS_HELP_14, "            | \"PACKData=\"n | \"RESource=\"res_file_name | \"RWReloccheck\"")
	pick(MSG_WINDOWS_HELP_15, "            | \"STUB=\"stub_name | \"NOSTUB\" | \"VERSion=\"major.[minor]")
	pick(MSG_WINDOWS_HELP_16, "export    ::= entryname[\".\"ordinal][\"=\"internal][\"RESident\"][\"PRIVATE\"]")
	pick(MSG_WINDOWS_HELP_17, "segmodel  ::= (\"PReload\" | \"LOadoncall\") | (\"SHared\" | \"NONShared\")")
	pick(MSG_WINDOWS_HELP_18, "            | (\"EXECUTEOnly\" | \"EXECUTERead\" | \"READOnly\" | \"READWrite\")")
	pick(MSG_WINDOWS_HELP_19, "            | (\"MOVeable\" | \"FIXed\") | \"DIScardable\"\n")

#define MSG_WINDOWS_HELP_LAST MSG_WINDOWS_HELP_19

	pick(MSG_NT_HELP_0, "\ncommands valid for the PE executable formats only:\n")
	pick(MSG_NT_HELP_1, "form      ::= \"WIndows PE\" [\"TNT\"|\"HX\"]")
	pick(MSG_NT_HELP_2, "              [\"DLl\"[\"INITGlobal\"|\"INITInstance\" [\"TERMInstance\"|\"TERMGlobal\"]]")
	pick(MSG_NT_HELP_3, "directive ::= \"RUntime\"     runoption[\"=\"major[\".\"minor]]")
	pick(MSG_NT_HELP_4, "            | \"SEGment\"     segdesc{\",\"segdesc}")
	pick(MSG_NT_HELP_5, "            | \"IMPort\"      import{\",\"import}")
	pick(MSG_NT_HELP_6, "            | \"EXPort\"      export{\",\"export}")
	pick(MSG_NT_HELP_7, "            | \"EXPort\"      \"=\"wlib_directive_file")
	pick(MSG_NT_HELP_8, "            | \"COMmit\"       commitopt{\",\"commitopt}")
	pick(MSG_NT_HELP_9, "segdesc   ::= segspec segmodel {segmodel}")
	pick(MSG_NT_HELP_10, "segspec   ::= seg_name | \"Class\" class_name | \"TYpe\" (\"CODE\" | \"DATA\")")
	pick(MSG_NT_HELP_11, "import    ::= entryname module[\".\"(extname | ordinal)]")
	pick(MSG_NT_HELP_12, "option    ::= \"Alignment=\"n | \"DEscription\" description | \"Heapsize=\"n")
	pick(MSG_NT_HELP_13, "            | \"IMPFile\"[=file_name] | \"IMPLib\"[=file_name]")
	pick(MSG_NT_HELP_14, "            | \"MODName=\"module_name | \"NOSTDCall\" | \"OBJAlign=\"n | \"OFFset=\"n")
	pick(MSG_NT_HELP_15, "            | \"OLDlibrary=\"dll_name | \"RESource=\"res_file_name")
	pick(MSG_NT_HELP_16, "            | \"STUB=\"stub_name | \"NOSTUB\" | \"VERSion=\"major.[minor]")
	pick(MSG_NT_HELP_17, "            | \"[NO]LARGEaddressaware")
	pick(MSG_NT_HELP_18, "export    ::= entryname[\".\"ordinal][\"=\"internal][\"PRIVATE\"]")
	pick(MSG_NT_HELP_19, "segmodel  ::= (\"SHared\" | \"NONShared\") | (\"PAGEable\" | \"NONPageable\"")
	pick(MSG_NT_HELP_19_1, "            | \"EXECUTAble\" | \"WRITAble\"")
	pick(MSG_NT_HELP_20, "runoption ::= (\"NATive\" | \"WINdows\" | \"CONsole\" | \"POSix\" | \"OS2\" | \"DOSstyle\")")
	pick(MSG_NT_HELP_21, "commitopt ::= \"STack=\"n | \"Heap=\"n\n")

#define MSG_NT_HELP_LAST MSG_NT_HELP_21

	pick(MSG_PHAR_HELP_0, "\ncommands valid for the Phar Lap executable formats only:\n")
	pick(MSG_PHAR_HELP_3, "form      ::= \"PHARlap\" [\"EXTended\" | \"REX\" | \"SEGmented\"]")
	pick(MSG_PHAR_HELP_4, "directive ::= \"RUntime\"     runoption{\",\"runoption}")
	pick(MSG_PHAR_HELP_5, "option    ::= \"MAXData=\"n | \"MINData=\"n | \"OFFset=\"n | \"STUB=\"stub_name")
	pick(MSG_PHAR_HELP_6, "runoption ::= \"MINReal=\"n | \"MAXReal=\"n | \"CALLBufs=\"n | \"MINIBuf=\"n")
	pick(MSG_PHAR_HELP_7, "            | \"MAXIBuf=\"n | \"NISTack=\"n | \"ISTKsize=\"n | \"PRIVileged\"")
	pick(MSG_PHAR_HELP_8, "            | \"REALBreak=\"(n | symbol_name ) | \"UNPRIVileged\"")

#define MSG_PHAR_HELP_LAST MSG_PHAR_HELP_8

	pick(MSG_NOVELL_HELP_0, "\ncommands valid for the Novell Netware executable format only:\n")
	pick(MSG_NOVELL_HELP_3, "form      ::= \"NOVell\" [\"NLM\" | \"LAN\" | \"DSK\" | \"NAM\" | 'number'] 'description'")
	pick(MSG_NOVELL_HELP_4, "directive ::= \"MODUle\"      module_name{\",\"module_name}")
	pick(MSG_NOVELL_HELP_5, "            | \"IMPort\"      import{\",\"import}")
	pick(MSG_NOVELL_HELP_6, "            | \"EXPort\"      export{\",\"export}")
	pick(MSG_NOVELL_HELP_7, "            | \"Debug\"       \"Novell\" [\"ONLyexports\"] [\"REFerenced\"]")
	pick(MSG_NOVELL_HELP_8, "option    ::= \"CHeck=\"symbol_name | \"COPYRight\" [string] | \"CUSTom=\"file_name")
	pick(MSG_NOVELL_HELP_9, "            | \"EXit=\"symbol_name | \"HElp=\"file_name | \"IMPFile=\"file_name")
	pick(MSG_NOVELL_HELP_10, "            | \"IMPLib\"[=file_name] | \"MESsages\"[=file_name] | \"MULTILoad\"")
	pick(MSG_NOVELL_HELP_11, "            | \"NLMFlags=\"value | \"PSeudopreemption\" | \"REentrant\"")
	pick(MSG_NOVELL_HELP_12, "            | \"SCReenname\" description | \"SHArelib=\"file_name | \"SYnchronize\"")
	pick(MSG_NOVELL_HELP_13, "            | \"THReadname\" name | \"VERSion=\"major[.minor[.revision]]")
	pick(MSG_NOVELL_HELP_14, "            | \"XDCdata=\"file_name | \"AUTOUNload\"")
	pick(MSG_NOVELL_HELP_15, "import    ::= entryname")
	pick(MSG_NOVELL_HELP_16, "export    ::= entryname")

#define MSG_NOVELL_HELP_LAST MSG_NOVELL_HELP_16

#ifdef _DOS16M
	pick(MSG_DOS16_HELP_0, "\ncommands valid for the DOS/16M executable format only:\n")
	pick(MSG_DOS16_HELP_3, "form      ::= \"DOS16M\"")
	pick(MSG_DOS16_HELP_4, "directive ::= \"MEMory\"      strategy")
	pick(MSG_DOS16_HELP_5, "            | \"TRansparent\" seg_type")
	pick(MSG_DOS16_HELP_6, "            | \"RUntime\"     runoption{\",\"runoption}")
	pick(MSG_DOS16_HELP_7, "option    ::= \"BUFfer=\"n | \"GDTsize=\"n | (\"RELocs\" | \"NORelocs\") | \"SELstart=\"n")
	pick(MSG_DOS16_HELP_8, "            | \"DATASize=\"n | \"EXTended=\"n")
	pick(MSG_DOS16_HELP_9, "            | \"STUB=\"stub_name")
	pick(MSG_DOS16_HELP_10, "runoption ::= \"KEYboard\" | \"OVERload\" | \"INIT00\" | \"INITFF\" | \"ROTate\" | \"AUTO\"")
	pick(MSG_DOS16_HELP_11, "            | \"SELectors\" | \"INT10\"")
	pick(MSG_DOS16_HELP_12, "strategy  ::= \"TRYExtended\" | \"TRYLow\" | \"FORCEExtended\" | \"FORCELow\"")
	pick(MSG_DOS16_HELP_13, "seg_type  ::= \"STack\" | \"DAta\"")

#define MSG_DOS16_HELP_LAST MSG_DOS16_HELP_13
#endif

	pick(MSG_QNX_HELP_0, "\ncommands valid for the QNX executable format only:\n")
	pick(MSG_QNX_HELP_3, "form      ::= \"QNX\" [\"FLat\"]")
	pick(MSG_QNX_HELP_4, "directive ::= \"SEGment\"     segdesc{\",\"segdesc}")
	pick(MSG_QNX_HELP_5, "            | \"NEWsegment\"")
	pick(MSG_QNX_HELP_6, "option    ::= \"Heapsize=\"n | \"LInearrelocs\" | \"LOnglived\" | \"NORelocs\" ")
	pick(MSG_QNX_HELP_7, "            | \"OFFset=\"n | \"PACKCode=\"n | \"PACKData=\"n | \"PRIVilege\"=n")
	pick(MSG_QNX_HELP_8, "            | \"RESource\"(\"=\"res_file_name | string)")
	pick(MSG_QNX_HELP_9, "segdesc   ::= segspec segmodel {segmodel}")
	pick(MSG_QNX_HELP_10, "segspec   ::= seg_name | \"Class\" class_name | \"TYpe\" (\"CODE\" | \"DATA\")")
	pick(MSG_QNX_HELP_11, "segmodel  ::= \"EXECUTEOnly\" | \"EXECUTERead\" | \"READOnly\" | \"READWrite\"")

#define MSG_QNX_HELP_LAST MSG_QNX_HELP_11

	pick(MSG_ELF_HELP_0, "\ncommands valid for the ELF executable format only:\n")
	pick(MSG_ELF_HELP_3, "form      ::= \"ELF\" [\"DLl\"]")
	pick(MSG_ELF_HELP_4, "directive ::= \"MODUle\"      module_name{\",\"module_name}")
	pick(MSG_ELF_HELP_5, "            | \"IMPort\"      import{\",\"import}")
	pick(MSG_ELF_HELP_6, "            | \"EXPort\"      export{\",\"export}")
	pick(MSG_ELF_HELP_7, "            | \"RUntime\"     runoption{\",\"runoption}")
	pick(MSG_ELF_HELP_8, "option    ::= \"Alignment=\"n | \"EXPORTAll\" | \"EXTRASections=\"n | \"OBJAlign=\"n")
	pick(MSG_ELF_HELP_9, "            | \"OFFSet=\"n")
	pick(MSG_ELF_HELP_10, "import    ::= entryname")
	pick(MSG_ELF_HELP_11, "export    ::= entryname")
	pick(MSG_ELF_HELP_12, "runoption ::= (\"SVR4\" | \"LINux\" | \"FREebsd\" | \"NETbsd\" | \"SOLaris\" | \"ABIver\" )")


	pick(MSG_WIN_VXD_HELP_0, "\ncommands valid for the Microsoft Windows VxD formats only:\n")
	pick(MSG_WIN_VXD_HELP_1, "form      ::= \"WIndows VXD\" [\"DYNamic\"]")
	pick(MSG_RAW_HELP_0, "\ncommands valid for the RAW executable formats only:\n")
	pick(MSG_RAW_HELP_1, "form      ::= \"Raw\" (\"BIN\" | \"HEX\")")
	pick(MSG_RAW_HELP_2, "option    ::= \"OFFset=\"n")


		pick(ERR_INTERNAL, "Internal compiler error %d.")
		pick(ERR_WRITTING_FILE, "Error writing to \"%s\": %s.")
		pick(ERR_CANT_OPEN_FILE, "Unable to open file \"%s\": %s.")
		pick(ERR_READING_RES, "Error reading RES file \"%s\": %s.")
		pick(ERR_UNEXPECTED_EOF, "Error reading file \"%s\": Unexpected end of file.")
		pick(ERR_INVALID_RES, "\"%s\" is not a valid RES file.")
		pick(ERR_BAD_RES_VER, "Unable to read RES file \"%s\": wrong version.")
		pick(ERR_NONWIN_RES_TO_WIN_EXE, "Trying to add a Win32 or OS/2 RES file \"%s\" to a Win16 executable \"%s\".")
		pick(ERR_NONNT_RES_TO_NT_EXE, "Trying to add a Win16 or OS/2 RES file \"%s\" to a Win32 executable \"%s\".")
		pick(ERR_NONOS2_RES_TO_OS2_EXE, "Trying to add a Win16 or Win32 RES file \"%s\" to an OS/2 executable \"%s\".")
		pick(ERR_DUPLICATE_STR_TABLE_FILE, "Duplicate string table block containing strings %d to %d found in files '%s' and '%s'.")
		pick(ERR_DUPLICATE_STR_TABLE, "Duplicate string table block containing strings %d to %d found.")
		pick(ERR_DUPLICATE_RES_FILE, "Duplicate %s named '%s' found in files '%s' and '%s'.")
		pick(ERR_DUPLICATE_RES, "Duplicate %s named '%s' found.")
#if 0
		pick(STR_WARNING, "Warning!")
		pick(STR_ERROR, "Error!")
		pick(STR_FATAL_ERROR, "Fatal Error!")
		pick(STR_END_OF_FILE, "Unexpected end of file")
		pick(STR_APP_NAME, "Open Watcom Resource Compiler Version 1.0\n")
		pick(ERR_RENAMEING_TMP_FILE, "Error renaming temporary file \"%s\" to \"%s\": %s.")
		pick(ERR_NOT_ICON_FILE, "\"%s\" is not a valid icon file.")
		pick(ERR_NOT_CURSOR_FILE, "\"%s\" is not a valid cursor file.")
		pick(ERR_NOT_BITMAP_FILE, "\"%s\" is not a valid bitmap file.")
		pick(ERR_PE_HEADER_SIZE_CHANGE, "Object alignment increase required.  Relink with larger object alignment.")
		pick(ERR_OLD_RESOURCE_OBJECT, "EXE contains old resources that cannot be removed.")
		pick(ERR_READING_EXE, "Error reading EXE file \"%s\": %s.")
		pick(ERR_READING_ICON, "Error reading icon file \"%s\": %s.")
		pick(ERR_READING_CURSOR, "Error reading cursor file \"%s\": %s.")
		pick(ERR_READING_BITMAP, "Error reading bitmap file \"%s\": %s.")
		pick(ERR_READING_FONT, "Error reading font file \"%s\": %s.")
		pick(ERR_READING_DATA, "Error reading data file \"%s\": %s.")
		pick(ERR_READING_TMP, "Error reading temporary file \"%s\": %s.")
		pick(ERR_WRITTING_TMP, "Error writing to temporary file \"%s\": %s.")
		pick(ERR_OPENING_TMP, "Unable to open temporary file \"%s\": %s.")
		pick(ERR_READING_FILE, "Error reading from file \"%s\": %s.")
		pick(ERR_WRITTING_RES_FILE, "Error writing resources to temporary file \"%s\": %s.")
		pick(ERR_CLOSING_FILE, "Error while closing file \"%s\" or flushing buffers to it: %s.")
		pick(ERR_CLOSING_TMP, "Error while closing temporary file \"%s\" or flushing buffers to it: %s.")
		pick(ERR_NO_MSG, "")
		pick(ERR_NO_RCINCLUDES, "RCINCLUDE keyword not currently supported. Use #include.")
		pick(ERR_UNKNOWN_CHAR, "'%c' is not valid at this point")
		pick(ERR_RUNAWAY_STRING, "String may not cross newline boundary")
		pick(ERR_EXPECTING_CHAR, "Expecting '%s' but found '%c'")
		pick(ERR_TOO_MANY_ARGS, "Too many arguments: %s")
		pick(ERR_FILENAME_NEEDED, "Filename required on command line.")
		pick(ERR_UNKNOWN_OPTION, "Unknown option '%c'")
		pick(ERR_NO_OPT_SPECIFIED, "No options specified after options character.")
		pick(ERR_OUT_OF_MEMORY, "Out of memory")
		pick(ERR_ACCEL_NO_TYPE, "No type given for accelerator %ld")
		pick(ERR_ACCEL_KEYWORD_IGNORED, "Keyword %s ignored for type ASCII accelerator %ld")
		pick(ERR_DUPLICATE_RESOURCE, "Duplicate resource: %s")
		pick(ERR_PARSER_INTERNAL, "Internal parser error.")
		pick(ERR_SYNTAX_INT, "")
		pick(ERR_SYNTAX_STR, "Syntax error near \"%s\"")
		pick(ERR_DUPLICATE_STRING_CONST, "%d is a duplicate string identifier.")
		pick(ERR_RAW_DATA_TOO_BIG, "Raw data item %lu is too big. Max %u")
		pick(ERR_RAW_DATA_TOO_SMALL, "Raw data item %ld is too small. Min %d")
		pick(ERR_FONT_NAME, "Font name must be a number.")
		pick(ERR_RCINCLUDE_TOO_DEEP, "Can't #include more than %d levels.")
		pick(ERR_INVALID_CPP, "Unknown preprocessor directive")
		pick(ERR_INVALID_CPP_LINE, "Invalid #line directive")
		pick(ERR_UNKNOWN_MULT_OPTION, "Unknown option '%s'")
		pick(ERR_NOT_VALID_EXE, "\"%s\" is not a valid EXE file.")
		pick(ERR_NO_GANGLOAD, "Unable to produce fastload section.")
		pick(ERR_CANT_FIND_FILE, "Can't find file \"%s\".")
		pick(ERR_UNKNOWN_TARGET_OS, "Unknown target OS: '%s'.")
		pick(ERR_TEXT_FROM_CPP, "%s")
		pick(ERR_NT_KEYWORD, "Keyword \"%s\" is only valid for Win32")
		pick(ERR_UNSUPPORTED, "Keyword \"%s\" not currently supported")
		pick(ERR_RCSTR_NOT_FOUND, "")
		pick(ERR_CANT_FIND_CHAR_FILE, "Error can't find character translation file \"%s\".")
		pick(ERR_CANT_OPEN_CHAR_FILE, "Error opening character translation file \"%s\": %s.")
		pick(ERR_READING_CHAR_FILE, "Error reading character translation file \"%s\": %s.")
		pick(ERR_BAD_CHAR_FILE, "\"%s\" is not a valid character translation file.")
		pick(ERR_WRONG_CHAR_FILE_VER, "Unable to read character translation file \"%s\": wrong version.")
		pick(ERR_OPT_NOT_VALID_FOR_NT, "Option '%s' not valid for a Win32 .res file.")
		pick(ERR_LSTRING_IGNORED_FOR_WINDOWS, "L\"...\" construct is not valid for Windows.")
		pick(ERR_OPT_NOT_VALID_TOGETHER, "Options '%s' and '%s' may not be specified together.")
		pick(ERR_ENV_VAR_NOT_FOUND, "Environment variable '%s' is not set.")
		pick(ERR_OPT_NOT_VALID_FOR_WINDOWS, "Option '%s' not valid for a Windows .res file.")
		pick(ERR_MISSING_MENUITEM_ID, "MENUITEM must have ID value.")
		pick(ERR_MENUEX_POPUP_OPTIONS, "Id/Type/State/HelpId not allowed for MENU POPUP controls.")
		pick(ERR_MENU_POPUP_OPTIONS, "MENUITEM options are not allowed for MENUEX POPUP controls.")
		pick(ERR_MENUEX_NORMAL_OPTIONS, "Type/State not valid for MENU MENUITEM controls.")
		pick(ERR_MENU_NORMAL_OPTIONS, "MENUITEM options not valid for MENUEX MENUITEM controls.")
		pick(ERR_DIALOG_HELPID, "HELPID not valid for DIALOG.")
		pick(ERR_FONT_ITALIC, "Font Italic setting not allowed for DIALOG.")
		pick(ERR_FONT_WEIGHT, "Font Weight setting not allowed for DIALOG.")
		pick(ERR_DIALOG_CONTROL_HELPID, "HELPID not valid for DIALOG controls.")
		pick(ERR_DATA_ELEMENTS, "Data Elements not valid for DIALOG controls.")
		pick(ERR_BAD_RES_ID, "%ld is not a valid resource id.")
		pick(ERR_STOP_REQUESTED, "User interrupt detected.")
		pick(ERR_TYPE_GT_7FFF, "Resource type for resource \"%s\" is greater than 32767.")
		pick(ERR_NAME_GT_7FFF, "Resource ID \"%s\" is greater than 32767.")
		pick(ERR_UNMATCHED_QUOTE_ON_CMD_LINE, "Unmatched quotation mark on command line.")
		pick(ERR_DUPLICATE_RESOURCE_IN_FILE, "Duplicate resource \"%s\" found in files '%s' and '%s'.")
		pick(ERR_DUPLICATE_NUM_RESOURCE_IN_FILE, "Duplicate resource numbered %d found in files '%s' and '%s'.")
		pick(ERR_FR_NOT_VALID_FOR_WIN, "'-fr' option cannot be used with Windows executables or .res files.")
		pick(ERR_RES_OS_MISMATCH, "Included RES file '%s' is compiled for a different platform.")
		pick(ERR_RCVARIABLE_RECURSIVE, "Can't expand environment variable '%s' recursively.")
		pick(ERR_BAD_RES_TYPE, "%ld is not a valid type id.")
		pick(ERR_WIN16_TOO_MANY_CONTROLS, "Too many controls for Win16 resource '%d' > 255.")
		pick(ERR_SYMBOL_NOT_DEFINED, "Symbol '%s' is not defined.")
		pick(USAGE_MSG_FIRST, "Usage: %s {options} input-filename {options} [output-filename] {options}")
		pick(USAGE_MSG_1, "Options: (/option is also accepted)")
		pick(USAGE_MSG_2, "-?             - print this help message")
		pick(USAGE_MSG_3, "-q             - operate quietly")
		pick(USAGE_MSG_4, "-30            - stamp file as requiring Windows 3.0")
		pick(USAGE_MSG_5, "-31            - stamp file as requiring Windows 3.1 (default)")
		pick(USAGE_MSG_6, "-DNAME=value   - behave as if #define NAME value was at top of file")
		pick(USAGE_MSG_7, "-ad            - generate auto dependency information for use by wmake")
		pick(USAGE_MSG_8, "-bt=windows    - build a Win16 resource file")
		pick(USAGE_MSG_9, "-bt=nt         - build a Win32 resource file (default)")
		pick(USAGE_MSG_10, "-bt=os2        - build an OS/2 resource file")
		pick(USAGE_MSG_11, "-c=name        - set code page conversion file")
		pick(USAGE_MSG_12, "-e             - for a DLL, global memory above EMS line")
		pick(USAGE_MSG_13, "-fo=name       - set the output resource file to name")
		pick(USAGE_MSG_14, "-fe=name       - set the output executable file to name")
		pick(USAGE_MSG_15, "-i=path        - look in path for include files")
		pick(USAGE_MSG_16, "-k             - don't sort segments (same as -s0)")
		pick(USAGE_MSG_17, "-l             - program uses LIM 3.2 EMS directly")
		pick(USAGE_MSG_18, "-m             - each instance of program has its own EMS bank")
		pick(USAGE_MSG_19, "-o             - preprocess only")
		pick(USAGE_MSG_20, "-p             - private DLL")
		pick(USAGE_MSG_21, "-r             - only build the resource file")
		pick(USAGE_MSG_22, "-s{0,1,2}      - segment and resource sorting method:")
		pick(USAGE_MSG_23, "                 0: no sorting, leave segments in the linker order")
		pick(USAGE_MSG_24, "                 1: move preload segments to front and mark for fast load")
		pick(USAGE_MSG_25, "                    if possible")
		pick(USAGE_MSG_26, "                 2: (default) move preload, data, and non-discardable segments")
		pick(USAGE_MSG_27, "                    to front and mark for fast load if possible")
		pick(USAGE_MSG_28, "-t             - protected mode only")
#ifdef SCANDEBUG
		pick(USAGE_MSG_29, "-v             - verbose: print tokens as they are scanned")
#endif
#ifdef YYDEBUG
		pick(USAGE_MSG_30, "-v1            - verbose: print grammar rules as they are reduced")
#endif
#if defined(YYDEBUG) || defined(SCANDEBUG)
		pick(USAGE_MSG_31, "-v2            - verbose: print both tokens and grammar rules")
		pick(USAGE_MSG_32, "-v3            - verbose: print tokens as they are scanned")
#endif
		pick(USAGE_MSG_33, "-x             - ignore the INCLUDE environment variable")
		pick(USAGE_MSG_34, "-zk{0,1,2,3}   - double-byte char support:")
		pick(USAGE_MSG_35, "                 0: (default) Japanese (Kanji, CP 932)")
		pick(USAGE_MSG_36, "                 1: Chinese (Traditional, CP 950)")
		pick(USAGE_MSG_37, "                 2: Korean (Wansung, CP 949)")
		pick(USAGE_MSG_38, "                 3: Chinese (Simplified, CP 936)")
		pick(USAGE_MSG_39, "-zm            - output Microsoft/IBM format .res files")
		pick(USAGE_MSG_LAST, "-zn            - don't preprocess the file")
#endif


#define MSG_ELF_HELP_LAST MSG_ELF_HELP_12
#define MSG_WIN_VXD_HELP_LAST MSG_WIN_VXD_HELP_1
#define MSG_RAW_HELP_LAST MSG_RAW_HELP_2
#define MSG_MAX_ERR_MSG_NUM MSG_TARGET_DISP_IGNORED
};
#undef pick

#undef pick
char* MsgStrings[] = {
#define pick( num, string ) string
pick(PRODUCT, banner1(IDV "JWlink", _WLINK_VERSION_)),
pick(COPYRIGHT, banner2("1985")),
pick(TRADEMARK, banner3),
};

MessagingSubsystem::MessagingSubsystem()
{}

MessagingSubsystem::~MessagingSubsystem()
{
	DEBUG((DBG_OLD, "MessagingSubsystem destructor\n"));
}

int MessagingSubsystem::Msg_Get(int resourceid, char* buffer)
{
	if (resourceid < 0 || resourceid >= sizeof(msgtexts) / sizeof(msgtexts[0]))
		return 1;
	strcpy(buffer, msgtexts[resourceid]);
	return 0;
}

void MessagingSubsystem::reset()
{
	LocFile = NULL;
	LocMem = NULL;
	LocRec = 0;
	MsgArgInfo.index = -1;
	memset(MsgFlags, 0xFF, MSG_ARRAY_SIZE);
}

void MessagingSubsystem::Locator(char* filename, char* mem, unsigned rec)
{
	LocFile = filename;
	LocMem = mem;
	LocRec = rec;
}

bool TestBit(::byte* array, unsigned num)
{
	::byte        mask;

	mask = 1 << (num % 8);
	num /= 8;
	return(*(array + num) & mask);
}

void MessagingSubsystem::LocateFile(unsigned num)
{
	unsigned    rec;

	if (num & LOC)
	{
		if (num & (LOC_REC & ~LOC))
		{
			rec = RecNum;
		}
		else
		{
			rec = 0;
		}
		if (CurrMod == NULL)
		{
			if (CmdFile == NULL)
			{
				Locator(NULL, NULL, 0);
			}
			else
			{
				Locator(CmdFile->name, NULL, 0);
			}
		}
		else
		{
			Locator(CurrMod->f.source->file->name, CurrMod->name, rec);
		}
	}
}

unsigned CalcMsgNum(unsigned num)
{
	unsigned    class1;

	class1 = (num & CLASS_MSK) >> NUM_SHIFT;
	class1 = (class1 + 1) / 2;
	return class1 * 1000 + (num & NUM_MSK);
}

unsigned MessagingSubsystem::FmtStr(char* buff, unsigned len, char* fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	return(DoFmtStr(buff, len, fmt, &args));
}

unsigned MessagingSubsystem::MakeExeName(char* buff, unsigned max)
{
	char        rc_buff[RESOURCE_MAX_SIZE];
	exe_format  format;
	unsigned    len;
	char* str;
	unsigned    num;

	if (max <= 3) return(0);
	len = 1;
	*buff++ = 'a';
	if (FmtData.osname != NULL)
	{
		str = FmtData.osname;
	}
	else
	{
		format = FmtData.type;
		if ((FmtData.type & MK_PE) && FmtData.u.pe.win64)
		{
			Msg_Get(MSG_FILE_PE64, rc_buff);
		}
		else if ((FmtData.type & MK_ELF) && FmtData.u.elf.elf64)
		{
			Msg_Get(MSG_FILE_ELF64, rc_buff);
		}
		else
		{
			for (;; )
			{
				num = blog_32(format);
				DO_AND_EQUAL(exe_format, format, &=, ~(1 << num));
				if (format == 0)
					break;
			}
			Msg_Get(MSG_FILE_TYPES_0 + num, rc_buff);
		}
		str = rc_buff;
	}
	if (IS_VOWEL(tolower(*str)))
	{
		*buff++ = 'n';
		len++;
	}
	*buff++ = ' ';
	num = strlen(str);
	len += num + 2;
	if (len > max) return(len - (num + 2));
	memcpy(buff, str, num);
	buff += num;
	*buff++ = ' ';
	if (FmtData.dll)
	{
		Msg_Get(MSG_CREATE_TYPE_DLL, rc_buff);
		str = rc_buff;
	}
	else
	{
		Msg_Get(MSG_CREATE_TYPE_EXE, rc_buff);
		str = rc_buff;
	}
	num = strlen(str);
	len += num;
	if (len > max) return(len - num);
	memcpy(buff, str, num + 1);
	return(len);
}

int MessagingSubsystem::UseArgInfo(void)
{
	return(MsgArgInfo.index >= 0);
}

void MessagingSubsystem::IncremIndex(void)
{
	MsgArgInfo.index++;
}

char* utoa(unsigned int val, char* s, int radix)
{
	switch (radix)
	{
		case 10:  sprintf(s, "%u", val); break;
		case 16:  sprintf(s, "%x", val); break;
		default: printf("utoa: unsupported radix %u\n", radix);
	}
	return s;
}

unsigned MessagingSubsystem::DoFmtStr(char* buff, unsigned len, char* src, va_list* args)
{
	char            ch;
	char* dest;
	char* str;
	uint16_t     num;
	uint32_t     num2;
#ifdef LONG_IS_64BITS
	unsigned long   num3;
#else
	unsigned long long num3;
#endif
	unsigned        size;
	targ_addr* addr;
	unsigned int    i;
	static char     hexchar[] = "0123456789abcdef";
	int             temp;

	dest = buff;
	for (;;)
	{
		ch = *src++;
		if (ch == '\0' || len == 1) break;
		if (ch != '%')
		{
			*dest++ = ch;
			len--;
		}
		else
		{
			ch = *src++;
			switch (ch)
			{
				case 'S':
					if (UseArgInfo())
					{
						str = MsgArgInfo.arg[MsgArgInfo.index].symb->name;
						IncremIndex();
					}
					else
					{
						str = va_arg(*args, symbol*)->name;
					}
#if defined(__WATCOMC__)
					if (!(LinkFlags & DONT_UNMANGLE))
					{
						size = __demangle_l(str, 0, dest, len);
						if (size > (len - 1)) size = len - 1;
						CurrSymName = dest;
					}
					else
#endif
					{
						size = strlen(str);
						if (size > len) size = len;
						memcpy(dest, str, size);
						CurrSymName = str;
					}
					len -= size;
					dest += size;
					break;
				case 's':
					if (UseArgInfo())
					{
						str = MsgArgInfo.arg[MsgArgInfo.index].string;
						IncremIndex();
					}
					else
					{
						str = va_arg(*args, char*);
					}
					size = strlen(str);
					if (size > len) size = len;
					memcpy(dest, str, size);
					len -= size;
					dest += size;
					break;
				case 't':
					str = va_arg(*args, char*);
					num = *src++ - '0';
					num = num * 10 + *src++ - '0';
					if (num > len) num = len;
					while ((*str != '\0') && (num > 0))
					{
						*dest++ = *str++;
						num--;
					}
					while (num > 0)
					{
						*dest++ = ' ';
						num--;
					}
					len -= num;
					break;
				case 'c':
					*dest++ = va_arg(*args, int);
					len--;
					break;
				case 'x':
					if (UseArgInfo())
					{
						num = MsgArgInfo.arg[MsgArgInfo.index].int_16;
						IncremIndex();
					}
					else
					{
						num = va_arg(*args, unsigned int);
					}
					if (len < 4) return(dest - buff);
					dest += 4;
					len -= 4;
					str = dest;
					for (i = 4; i > 0; i--)
					{
						*--str = hexchar[num & 0x0f];
						num >>= 4;
					}
					break;
				case 'h':
					num2 = va_arg(*args, uint32_t);
					if (len < 8) return(dest - buff);
					dest += 8;
					len -= 8;
					str = dest;
					for (i = 8; i > 0; i--)
					{
						*--str = hexchar[num2 & 0x0f];
						num2 >>= 4;
					}
					break;
				case 'p':
					if (sizeof(void*) == 4)
						num2 = va_arg(*args, uint32_t);
					else
					{
						num3 = va_arg(*args, unsigned long);
						num2 = (uint32_t)(num3 >> 32);
						if (num2)
						{
							if (len < 8) return(dest - buff);
							dest += 8;
							len -= 8;
							str = dest;
							for (i = 8; i > 0; i--)
							{
								*--str = hexchar[num2 & 0x0f];
								num2 >>= 4;
							}
						}
						num2 = (uint32_t)num3;
					}
					if (len < 8) return(dest - buff);
					dest += 8;
					len -= 8;
					str = dest;
					for (i = 8; i > 0; i--)
					{
						*--str = hexchar[num2 & 0x0f];
						num2 >>= 4;
					}
					break;
				case 'd':
					if (len < 5) return(dest - buff);
					if (UseArgInfo())
					{
						num = MsgArgInfo.arg[MsgArgInfo.index].int_16;
						IncremIndex();
					}
					else
					{
						num = va_arg(*args, unsigned int);
					}
					utoa(num, dest, 10);
					size = strlen(dest);
					dest += size;
					len -= size;
					break;
				case 'l':
					if (len < 10) return(dest - buff);
					if (UseArgInfo())
					{
						num2 = MsgArgInfo.arg[MsgArgInfo.index].int_32;
						IncremIndex();
					}
					else
					{
						num2 = va_arg(*args, uint32_t);
					}
					_ultoa(num2, dest, 10);
					size = strlen(dest);
					dest += size;
					len -= size;
					break;
				case 'a':
				case 'A':
					if (UseArgInfo())
					{
						addr = MsgArgInfo.arg[MsgArgInfo.index].address;
						IncremIndex();
					}
					else
					{
						addr = va_arg(*args, targ_addr*);
					}
					temp = MsgArgInfo.index;
					MsgArgInfo.index = -1;
					if (FmtData.type & MK_FLAT)
					{
						size = FmtStr(dest, len, "%h", addr->off);
					}
					else if (FmtData.type & MK_QNX_FLAT)
					{
						size = FmtStr(dest, len, "%h", FindLinearAddr(addr));
					}
					else if (FmtData.type & (MK_ELF | MK_PE))
					{
						size = FmtStr(dest, len, "%h", FindLinearAddr2(addr));
					}
					else if (FmtData.type & MK_ID_SPLIT)
					{
						if (addr->seg == CODE_SEGMENT)
						{
							size = FmtStr(dest, len, "CODE:%h", addr->off);
						}
						else
						{
							size = FmtStr(dest, len, "DATA:%h", addr->off);
						}
					}
					else if ((FmtData.type & MK_386) || ch == 'A')
					{
						size = FmtStr(dest, len, "%x:%h", addr->seg, addr->off);
					}
					else
					{
						size = FmtStr(dest, len, "%x:%x", addr->seg,
							(unsigned short)addr->off);
					}
					dest += size;
					len -= size;
					MsgArgInfo.index = temp;
					break;
				case 'f':
					num = MakeExeName(dest, len);
					dest += num;
					len -= num;
					break;
			}
		}
	}
	MsgArgInfo.index = -1;
	*dest = '\0';
	return(dest - buff);
}

void MessagingSubsystem::LnkMsg(unsigned  num, char* types, ...)
{
	va_list     args;
	int         which_file = 0;
	unsigned    len;
	unsigned    prefixlen;
	unsigned    class1;
	bool        waserror;
	char        rc_buff[RESOURCE_MAX_SIZE];
	char        buff[MAX_MSG_SIZE];
	char        prefix[MAX_MSG_SIZE];

	if (!TestBit(MsgFlags, num & NUM_MSK))
		return;
	CurrSymName = NULL;
	LocateFile(num);
	len = 0;
	prefixlen = 0;
	waserror = FALSE;
	class1 = num & CLASS_MSK;
	if (class1 == (YELL & CLASS_MSK))
	{
		waserror = TRUE;
	}
	else if (class1 >= (MILD_ERR & CLASS_MSK))
	{
		waserror = TRUE;
		if (class1 >= (ERR & CLASS_MSK))
		{
			LinkState |= LINK_ERROR;
		}
	}
	if (class1 >= (WRN & CLASS_MSK))
	{
		if (class1 == (WRN & CLASS_MSK))
		{
			Msg_Get(MSG_WARNING, rc_buff);
		}
		else
		{
			Msg_Get(MSG_ERROR, rc_buff);
		}
#if !defined( _DLLHOST )
		len = FmtStr(buff, MAX_MSG_SIZE - len, rc_buff, CalcMsgNum(num));
#else
		prefixlen = FmtStr(prefix, MAX_MSG_SIZE, rc_buff, CalcMsgNum(num));
#endif
	}
	if (LocFile != NULL)
	{
		which_file += 1;
	}
	if (LocMem != NULL)
	{
		which_file += 2;
	}
	if (LocRec != 0)
	{
		which_file += 4;
	}
	if (which_file != 0)
	{
		if (Token.how == SYSTEM)
		{
			Msg_Get(MSG_SYS_BLK, rc_buff);
			which_file = 1;
		}
		else if (Token.how == ENVIRONMENT)
		{
			Msg_Get(MSG_ENVIRON, rc_buff);
			which_file = 1;
		}
		else
		{
			Msg_Get(MSG_FILE_REC_NAME_0 + which_file - 1, rc_buff);
		}
		FileOrder(rc_buff, which_file);
		len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
		if (num & LINE)
		{
			if (Token.how != SYSTEM && Token.how != ENVIRONMENT)
			{
				Msg_Get(MSG_LINE, rc_buff);
				Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "d", Token.line);
				len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
			}
		}
		LocFile = NULL;
		LocMem = NULL;
		LocRec = 0;
	}

	va_start(args, types);
	Msg_Get(num & NUM_MSK, rc_buff);
	Msg_Put_Args(rc_buff, &MsgArgInfo, types, &args);
	va_end(args);
	len += FmtStr(&buff[len], MAX_MSG_SIZE - len, rc_buff);
	MessageFini(num, buff, len, prefix, prefixlen, waserror);
}

void MessagingSubsystem::FileOrder(char rc_buff[], int which_file)
{
	switch (which_file)
	{
		case 1:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "s", LocFile);
			break;
		case 2:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "s", LocMem);
			break;
		case 3:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "12", LocFile, LocMem);
			break;
		case 4:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "d", LocRec);
			break;
		case 5:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "sd", LocFile, LocRec);
			break;
		case 6:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "sd", LocMem, LocRec);
			break;
		case 7:
			Msg_Do_Put_Args(rc_buff, &MsgArgInfo, "12d", LocFile, LocMem,LocRec);
			break;
	}
}

void MessagingSubsystem::Msg_Do_Put_Args(char rc_buff[], MSG_ARG_LIST* arg_info, char* types, ...)
{
	va_list     args;

	va_start(args, types);
	Msg_Put_Args(rc_buff, arg_info, types, &args);
	va_end(args);
}

void MessagingSubsystem::Msg_Put_Args(char message[], MSG_ARG_LIST* arg_info, char* types, va_list* args)
{
	int         argnum = 0;
	int         j;
	int         order[3];
	char* percent;
	char        types_buff[1 + 3];
	char        specifier;

	if (types != NULL)
	{
		strcpy(types_buff, types);
		percent = message - 2;
		while ((percent = strchr(percent + 2, '%')) != NULL)
		{
			specifier = percent[1];
			for (j = 0; types_buff[j] != '\0'; j++)
			{
				if (types_buff[j] == specifier)
				{
					order[j] = argnum;
					argnum++;
					if (isdigit(specifier))
						types_buff[j] = percent[1] = 's';
					break;
				}
			}
		}
		for (j = 0; j < argnum; j++)
		{
			Msg_Add_Arg(arg_info->arg + order[j], types_buff[j], args);
		}
	}
	arg_info->index = 0;
}

void MessagingSubsystem::Msg_Add_Arg(MSG_ARG* arginfo, char typech, va_list* args)
{
	switch (typech)
	{
		case 's':
			arginfo->string = va_arg(*args, char*);
			break;
		case 'x':
		case 'd':
			arginfo->int_16 = va_arg(*args, unsigned int);
			break;
		case 'l':
			arginfo->int_32 = va_arg(*args, unsigned long);
			break;
		case 'A':
		case 'a':
			arginfo->address = va_arg(*args, targ_addr*);
			break;
		case 'S':
			arginfo->symb = va_arg(*args, symbol*);
			break;
	}
}

void MessagingSubsystem::MessageFini(unsigned num, char* buff, unsigned len,char* prefix, unsigned prefixlen, bool waserror)
{
	if (num & OUT_TERM)
	{
		if (!(LinkFlags & QUIET_FLAG))
		{
			WLPrtBanner();
			WriteInfoStdOut(buff, num, CurrSymName);
		}
		else if ((num & CLASS_MSK) != (CLASS_MSK & INF))
		{
			WriteInfoStdOut(buff, num, CurrSymName);
		}
	}
	if ((num & OUT_MAP) && (MapFile != NIL_HANDLE))
	{
#if defined( _DLLHOST )
		BufWrite(prefix, prefixlen);
#endif
		BufWrite(buff, len);
		WriteMapNL(1);
	}
	//if ((num & CLASS_MSK) == (FTL & ~OUT_MSK)) Suicide();
	if (waserror && LinkFlags & MAX_ERRORS_FLAG)
	{
		MaxErrors--;
		if (MaxErrors == 0)
		{
			LnkMsg(FTL + MSG_TOO_MANY_ERRORS, NULL);
		}
	}
}

void MessagingSubsystem::WLPrtBanner()
{
	char* msg;

	if (!BannerPrinted)
	{
		msg = MsgStrings[PRODUCT];
		WriteInfoStdOut(msg, BANNER, NULL);
		msg = MsgStrings[COPYRIGHT];
		WriteInfoStdOut(msg, BANNER, NULL);
		msg = MsgStrings[TRADEMARK];
		WriteInfoStdOut(msg, BANNER, NULL);
		BannerPrinted = TRUE;
	}
}

void MessagingSubsystem::Msg_Write_Map(int resourceid, ...)
{
	char        msg_buff[RESOURCE_MAX_SIZE];
	va_list     arglist;

	Msg_Get(resourceid, msg_buff);
	va_start(arglist, resourceid);
	DoWriteMap(this, msg_buff, &arglist);
	va_end(arglist);
}
