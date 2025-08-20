#ifndef ARGUMENTTABLE
#define ARGUMENTTABLE

#ifdef __cplusplus
extern "C" {
#endif

#define ARG_REX_ICASE 1
#define ARG_CMD_NAME_LEN 100
#define ARG_CMD_DESCRIPTION_LEN 256
#define START_VSNBUFF 16
#define ARG_DSTR_SIZE 200
#define ARG_DSTR_STATIC ((ArgDstrFreeFunctionPtr)0)
#define ARG_DSTR_VOLATILE ((ArgDstrFreeFunctionPtr)1)
#define ARG_DSTR_DYNAMIC ((ArgDstrFreeFunctionPtr)3)
#define ALT_E 0x01
#define ALT_O 0x02
#define LEGAL_ALT(x)           \
    {                          \
        if (alt_format & ~(x)) \
            return (0);        \
    }
#define TM_YEAR_BASE (1900)
#define TRexChar char
#define MAX_CHAR 0xFF
#define _TREXC(c) (c)
#define trex_strlen strlen
#define trex_printf printf

#define TRex_True 1
#define TRex_False 0

#define TREX_ICASE ARG_REX_ICASE
#define OP_GREEDY (MAX_CHAR + 1)        
#define OP_OR (MAX_CHAR + 2)
#define OP_EXPR (MAX_CHAR + 3)          
#define OP_NOCAPEXPR (MAX_CHAR + 4)     
#define OP_DOT (MAX_CHAR + 5)
#define OP_CLASS (MAX_CHAR + 6)
#define OP_CCLASS (MAX_CHAR + 7)
#define OP_NCLASS (MAX_CHAR + 8)       
#define OP_RANGE (MAX_CHAR + 9)
#define OP_CHAR (MAX_CHAR + 10)
#define OP_EOL (MAX_CHAR + 11)
#define OP_BOL (MAX_CHAR + 12)
#define OP_WB (MAX_CHAR + 13)

#define TREX_SYMBOL_ANY_CHAR ('.')
#define TREX_SYMBOL_GREEDY_ONE_OR_MORE ('+')
#define TREX_SYMBOL_GREEDY_ZERO_OR_MORE ('*')
#define TREX_SYMBOL_GREEDY_ZERO_OR_ONE ('?')
#define TREX_SYMBOL_BRANCH ('|')
#define TREX_SYMBOL_END_OF_STRING ('$')
#define TREX_SYMBOL_BEGINNING_OF_STRING ('^')
#define TREX_SYMBOL_ESCAPE_CHAR ('\\')
#define no_argument        0
#define required_argument  1
#define optional_argument  2

	enum { ARG_ERR_MINCOUNT = 1, ARG_ERR_MAXCOUNT, ARG_ERR_BADINT, ARG_ERR_OVERFLOW, ARG_ERR_BADDOUBLE, ARG_ERR_BADDATE, ARG_ERR_REGNOMATCH };

	enum {
		ARG_ELIMIT = 1,
		ARG_EMALLOC,
		ARG_ENOMATCH,
		ARG_ELONGOPT,
		ARG_EMISSARG
	};

	enum arg_hdr_flag {
		ARG_TERMINATOR = 0x1,
		ARG_HASVALUE = 0x2,
		ARG_HASOPTVALUE = 0x4
	};

	struct _ArgDstr;

	typedef void(*ArgResetFunctionPtr)(void* parent);
	typedef int(*ArgScanFunctionPtr)(void* parent, const char* argval);
	typedef int(*ArgCheckInFunctionPtr)(void* parent);
	typedef void(*ArgErrorFunctionPtr)(void* parent, struct _ArgDstr* ds, int error, const char* argval, const char* progname);
	typedef void(*ArgDstrFreeFunctionPtr)(char* buf);
	typedef int(*ArgCmdFunctionPtr)(int argc, char* argv[], struct _ArgDstr* res, void* ctx);
	typedef int(*ArgCompareFunctionPtr)(const void* k1, const void* k2);

	typedef struct _Option {
		const char* name;
		int has_arg;
		int* flag;
		int val;
	}Option, * OptionPtr, ** OptionPtrPtr;

	typedef struct _LongOptions {
		int getoptval;
		int noptions;
		OptionPtr options;
	}LongOptions, * LongOptionsPtr, ** LongOptionsPtrPtr;

	typedef struct _PrivHdr {
		const char* pattern;
		int flags;
	}PrivHdr, * PrivHdrPtr, ** PrivHdrPtrPtr;

	typedef struct _ArgHdr {
		char flag;
		const char* shortopts;
		const char* longopts;
		const char* datatype;
		const char* glossary;
		int mincount;
		int maxcount;
		void* parent;
		ArgResetFunctionPtr resetfn;
		ArgScanFunctionPtr scanfn;
		ArgCheckInFunctionPtr checkfn;
		ArgErrorFunctionPtr errorfn;
		void* priv;
	} ArgHdr, * ArgHdrPtr, ** ArgHdrPtrPtr;

	typedef struct _ArgRem {
		ArgHdr hdr;
	} ArgRem, * ArgRemPtr;

	typedef struct _ArgLit {
		ArgHdr hdr;
		int count;
	} ArgLit, * ArgLitPtr, ** ArgLitPtrPtr;

	typedef struct _ArgInt {
		ArgHdr hdr;
		int count;
		int* ival;
	} ArgInt, * ArgIntPtr, ** ArgIntPtrPtr;

	typedef struct _ArgDbl {
		ArgHdr hdr;
		int count;
		double* dval;
	} ArgDbl, * ArgDblPtr, ** ArgDblPtrPtr;

	typedef struct _ArgStr {
		ArgHdr hdr;
		int count;
		const char** sval;
	} ArgStr, * ArgStrPtr, ** ArgStrPtrPtr;

	typedef struct _ArgRex {
		ArgHdr hdr;
		int count;
		const char** sval;
	} ArgRex, * ArgRexPtr, ** ArgRexPtrPtr;

	typedef struct _ArgFile {
		ArgHdr hdr;
		int count;
		const char** filename;
		const char** basename;
		const char** extension;
	} ArgFile, * ArgFilePtr, ** ArgFilePtrPtr;

	typedef struct _ArgDate {
		ArgHdr hdr;
		const char* format;
		int count;
		struct tm* tmval;
	}ArgDate, * ArgDatePtr, ** ArgDatePtrPtr;

	typedef struct _ArgEnd {
		ArgHdr hdr;
		int count;
		int* error;
		void** parent;
		const char** argval;
	} ArgEnd, * ArgEndPtr, ** ArgEndPtrPtr;

	typedef struct _ArgCmdInfo {
		char name[ARG_CMD_NAME_LEN];
		char description[ARG_CMD_DESCRIPTION_LEN];
		ArgCmdFunctionPtr proc;
		void* ctx;
	} ArgCmdInfo, * ArgCmdInfoPtr, ** ArgCmdInfoPtrPtr;

	typedef struct _ArgDstr {
		char* data;
		ArgDstrFreeFunctionPtr free_proc;
		char sbuf[ARG_DSTR_SIZE + 1];
		char* append_data;
		int append_data_size;
		int append_used;
	} ArgDstr, * ArgDstrPtr, ** ArgDstrPtrPtr;

	typedef void* arg_cmd_itr_t;

	typedef int TRexNodeType;
	typedef unsigned int TRexBool;
	extern char* optarg;
	extern int optind, opterr, optopt;

	typedef struct _TRexMatch {
		const TRexChar* begin;
		int len;
	} TRexMatch, * TRexMatchPtr, ** TRexMatchPtrPtr;

	typedef struct _TRexNode {
		TRexNodeType type;
		int left;
		int right;
		int next;
	} TRexNode, * TRexNodePtr, ** TRexNodePtrPtr;

	typedef struct _TRex {
		const TRexChar* _eol;
		const TRexChar* _bol;
		const TRexChar* _p;
		int _first;
		int _op;
		TRexNode* _nodes;
		int _nallocated;
		int _nsize;
		int _nsubexpr;
		TRexMatchPtr _matches;
		int _currsubexp;
		void* _jmpbuf;
		const TRexChar** _error;
		int _flags;
	}TRex, * TRexPtr, ** TRexPtrPtr;

	// ArgGetOpt.cpp
	void warnx(const char* fmt, ...);
	void permuteArgs(int panonopt_start, int panonopt_end, int opt_end, char* const* nargv);
	int parseLongOptions(char* const* nargv, const char* options, const OptionPtr long_options, int* idx, int short_too, int flags);
	int getOptInternal(int nargc, char* const* nargv, const char* options, const OptionPtr long_options, int* idx, int flags);
	int getOpt(int nargc, char* const* nargv, const char* options);
	int getOptLong(int nargc, char* const* nargv, const char* options, const OptionPtr long_options, int* idx);
	int getOptLongOnly(int nargc, char* const* nargv, const char* options, const OptionPtr long_options, int* idx);
	void argCat(char** pdest, const char* src, size_t* pndest);
	void argCatOptionV(char* dest, size_t ndest, const char* shortopts, const char* longopts, const char* datatype, int optvalue, const char* separator);
	void argPrintOptionDs(ArgDstrPtr ds, const char* shortopts, const char* longopts, const char* datatype, const char* suffix);
	
	//ArdDate.cpp
	void argDateResetFn(void* parent_);
	int argDateScanFn(void* parent_, const char* argval);
	int argDateCheckFn(void* parent_);
	void argDateErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgDatePtr argDate0(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary);
	ArgDatePtr argDate1(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary);
	ArgDatePtr argDateN(const char* shortopts, const char* longopts, const char* format, const char* datatype, int mincount, int maxcount, const char* glossary);;
	int argStrCaseCmp(const char* s1, const char* s2);
	int argStrNCaseCmp(const char* s1, const char* s2, size_t n);
	char* argStrPTime(const char* buf, const char* fmt, struct tm* tm);
	int convNum(const char** buf, int* dest, int llim, int ulim);

	//ArgDbl.cpp
	void argDblResetFn(void* parent_);
	int argDblScanFn(void* parent_, const char* argval);
	int argDblCheckFn(void* parent_);
	void argDblErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgDblPtr argDbl0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgDblPtr argDbl1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgDblPtr argDblN(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);

	//ArgDstr.cpp
	char* argDstrCStr(ArgDstrPtr ds);
	void argDstrReset(ArgDstrPtr ds);
	ArgDstrPtr argDstrCreate(void);
	void argDstrDestroy(ArgDstrPtr ds);
	void argDstrFree(ArgDstrPtr ds);
	void setupAppendBuf(ArgDstrPtr ds, int new_space);
	void argDstrCat(ArgDstrPtr ds, const char* str);
	void argDstrCatF(ArgDstrPtr ds, const char* fmt, ...);

	//ArgEnd.cpp
	void argEndResetFn(void* parent_);
	void argEndErrorFn(void* parent, ArgDstrPtr ds, int error, const char* argval, const char* progname);
	ArgEndPtr argEnd(int maxcount);
	void argPrintErrorsDs(ArgDstrPtr ds, ArgEndPtr end, const char* progname);
	void argPrintErrors(FILE* fp, ArgEndPtr end, const char* progname);

	//ArgFile.cpp
	void argFileResetFn(void* parent_);
	const char* argBasename(const char* filename);
	const char* argExtension(const char* basename);
	int argFileScanFn(void* parent_, const char* argval);
	int argFileCheckFn(void* parent_);
	void argFileErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgFilePtr argFile0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgFilePtr argFile1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgFilePtr argFileN(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);

	//ArgInt.cpp
	void argIntResetFn(void* parent_);
	long int strtol0X(const char* str, const char** endptr, char X, int base);
	int detectsuffix(const char* str, const char* suffix);
	int argIntScanFn(void* parent_, const char* argval);
	int argIntCheckFn(void* parent_);
	void argIntErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgIntPtr argIntN(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	ArgIntPtr argInt0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgIntPtr argInt1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);

	//ArgLit.cpp
	void argLitResetFn(void* parent_);
	int argLitScanFn(void* parent_, const char* argval);
	int argLitCheckFn(void* parent_);
	void argLitErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgLitPtr argLitN(const char* shortopts, const char* longopts, int mincount, int maxcount, const char* glossary);
	ArgLitPtr argLit0(const char* shortopts, const char* longopts, const char* glossary);
	ArgLitPtr argLit1(const char* shortopts, const char* longopts, const char* glossary);

	//ArgRex.cpp
	void argRexResetFn(void* parent_);
	int argRexScanFn(void* parent_, const char* argval);
	int argRexCheckFn(void* parent_);
	void argRexErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgRexPtr argRex0(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary);
	ArgRexPtr argRex1(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary);
	ArgRexPtr argRexN(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int mincount, int maxcount, int flags, const char* glossary);
	int trex_newnode(TRex* exp, TRexNodeType type);
	void trex_error(TRex* exp, const TRexChar* error);
	void trex_expect(TRex* exp, int n);
	TRexChar trex_escapechar(TRex* exp);
	int trex_charclass(TRex* exp, int classid);
	int trex_charnode(TRex* exp, TRexBool isclass);
	int trex_class(TRex* exp);
	int trex_parsenumber(TRex* exp);
	int trex_element(TRex* exp);
	int trex_list(TRex* exp);
	TRexBool trex_matchcclass(int cclass, TRexChar c);
	TRexBool trex_matchclass(TRex* exp, TRexNode* node, TRexChar c);
	const TRexChar* trex_matchnode(TRex* exp, TRexNode* node, const TRexChar* str, TRexNode* next);
	TRex* trex_compile(const TRexChar* pattern, const TRexChar** error, int flags);
	void trex_free(TRex* exp);
	TRexBool trex_match(TRex* exp, const TRexChar* text);
	TRexBool trex_searchrange(TRex* exp, const TRexChar* text_begin, const TRexChar* text_end, const TRexChar** out_begin, const TRexChar** out_end);
	TRexBool trex_search(TRex* exp, const TRexChar* text, const TRexChar** out_begin, const TRexChar** out_end);
	int trex_getsubexpcount(TRex* exp);
	TRexBool trex_getsubexp(TRex* exp, int n, TRexMatch* subexp);

	void argStrResetFn(void* parent_);
	int argStrScanFn(void* parent_, const char* argval);
	int argStrCheckFn(void* parent_);
	void argStrErrorFn(void* parent_, ArgDstrPtr ds, int errorcode, const char* argval, const char* progname);
	ArgStrPtr argStr0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgStrPtr argStr1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	ArgStrPtr argStrN(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);

	void arg_freetable(void** argtable, size_t n);
	ArgRemPtr arg_rem(const char* datatype, const char* glossary);
	int argNullCheck(void** argtable);
	void arg_reset(void** argtable);
	int arg_endindex(ArgHdrPtrPtr table);
	void arg_register_error(ArgEndPtr end, void* parent, int error, const char* argval);
	void arg_parse_check(ArgHdrPtrPtr table, ArgEndPtr endtable);
	LongOptionsPtr alloc_longoptions(ArgHdrPtrPtr table);
	char* alloc_shortoptions(ArgHdrPtrPtr table);
	int find_shortoption(ArgHdrPtrPtr table, char shortopt);
	void arg_parse_untagged(int argc, char** argv, ArgHdrPtrPtr table, ArgEndPtr endtable);
	void arg_parse_tagged(int argc, char** argv, ArgHdrPtrPtr table, ArgEndPtr endtable);
	int argParse(int argc, char** argv, void** argtable);
	void arg_print_gnuswitch_ds(ArgDstrPtr ds, ArgHdrPtrPtr table);
	void arg_cat_option(char* dest, size_t ndest, const char* shortopts, const char* longopts, const char* datatype, int optvalue);
	void arg_print_syntax_ds(ArgDstrPtr ds, void** argtable, const char* suffix);
	void argPrintSyntax(FILE* fp, void** argtable, const char* suffix);
	void arg_print_glossary_ds(ArgDstrPtr ds, void** argtable, const char* format);
	void argPrintGlossary(FILE* fp, void** argtable, const char* format);

#ifdef __cplusplus
}
#endif
#endif
