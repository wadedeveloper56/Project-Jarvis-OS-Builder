#ifndef ARGUMENTTABLE
#define ARGUMENTTABLE

#include <stdio.h>   
#include <time.h>     

#ifdef __cplusplus
extern "C" {
#endif

#define ARG_CMD_NAME_LEN 100
#define ARG_CMD_DESCRIPTION_LEN 256
#define START_VSNBUFF 16
#define ARG_DSTR_SIZE 200
#define ARG_DSTR_STATIC ((arg_dstr_freefn*)0)
#define ARG_DSTR_VOLATILE ((arg_dstr_freefn*)1)
#define ARG_DSTR_DYNAMIC ((arg_dstr_freefn*)3)

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

	typedef struct _internal_arg_dstr* arg_dstr_t;
	typedef void* arg_cmd_itr_t;

	typedef void(arg_resetfn)(void* parent);
	typedef int(arg_scanfn)(void* parent, const char* argval);
	typedef int(arg_checkfn)(void* parent);
	typedef void(arg_errorfn)(void* parent, arg_dstr_t ds, int error, const char* argval, const char* progname);
	typedef void(arg_dstr_freefn)(char* buf);
	typedef int(arg_cmdfn)(int argc, char* argv[], arg_dstr_t res, void* ctx);
	typedef int(arg_comparefn)(const void* k1, const void* k2);

	typedef struct arg_hdr {
		char flag;
		const char* shortopts;
		const char* longopts;
		const char* datatype;
		const char* glossary;
		int mincount;
		int maxcount;
		void* parent;
		arg_resetfn* resetfn;
		arg_scanfn* scanfn;
		arg_checkfn* checkfn;
		arg_errorfn* errorfn;
		void* priv;
	} arg_hdr_t;

	typedef struct _ArgRem {
		struct arg_hdr hdr;
	} ArgRem, * ArgRemPtr;

	typedef struct _ArgLit {
		struct arg_hdr hdr;
		int count;
	} ArgLit, * ArgLitPtr;

	typedef struct arg_int {
		struct arg_hdr hdr;
		int count;
		int* ival;
	} arg_int_t;

	typedef struct arg_dbl {
		struct arg_hdr hdr;
		int count;
		double* dval;
	} arg_dbl_t;

	typedef struct arg_str {
		struct arg_hdr hdr;
		int count;
		const char** sval;
	} arg_str_t;

	typedef struct arg_rex {
		struct arg_hdr hdr;
		int count;
		const char** sval;
	} arg_rex_t;

	typedef struct arg_file {
		struct arg_hdr hdr;
		int count;
		const char** filename;
		const char** basename;
		const char** extension;
	} arg_file_t;

	typedef struct arg_date {
		struct arg_hdr hdr;
		const char* format;
		int count;
		struct tm* tmval;
	} arg_date_t;

	typedef struct arg_end {
		struct arg_hdr hdr;
		int count;
		int* error;
		void** parent;
		const char** argval;
	} arg_end_t;

	typedef struct arg_cmd_info {
		char name[ARG_CMD_NAME_LEN];
		char description[ARG_CMD_DESCRIPTION_LEN];
		arg_cmdfn* proc;
		void* ctx;
	} arg_cmd_info_t;

	typedef struct _internal_arg_dstr {
		char* data;
		arg_dstr_freefn* free_proc;
		char sbuf[ARG_DSTR_SIZE + 1];
		char* append_data;
		int append_data_size;
		int append_used;
	} _internal_arg_dstr_t;

	ArgRemPtr arg_rem(const char* datatype, const char* glossary);
	ArgLitPtr arg_litn(const char* shortopts, const char* longopts, int mincount, int maxcount, const char* glossary);
	ArgLitPtr arg_lit0(const char* shortopts, const char* longopts, const char* glossary);
	ArgLitPtr arg_lit1(const char* shortopts, const char* longopts, const char* glossary);
	arg_int_t* arg_intn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_int_t* arg_int0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_int_t* arg_int1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_dbl_t* arg_dbln(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_dbl_t* arg_dbl0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_dbl_t* arg_dbl1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_str_t* arg_strn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_str_t* arg_str0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_str_t* arg_str1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_rex_t* arg_rexn(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int mincount, int maxcount, int flags, const char* glossary);
	arg_rex_t* arg_rex0(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary);
	arg_rex_t* arg_rex1(const char* shortopts, const char* longopts, const char* pattern, const char* datatype, int flags, const char* glossary);
	arg_file_t* arg_filen(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_file_t* arg_file0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_file_t* arg_file1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_date_t* arg_daten(const char* shortopts, const char* longopts, const char* format, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_date_t* arg_date0(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary);
	arg_date_t* arg_date1(const char* shortopts, const char* longopts, const char* format, const char* datatype, const char* glossary);
	arg_end_t* arg_end(int maxcount);
	int arg_nullcheck(void** argtable);
	int argParse(int argc, char** argv, void** argtable);
	void arg_print_syntax(FILE* fp, void** argtable, const char* suffix);
	void arg_print_glossary(FILE* fp, void** argtable, const char* format);
	void arg_print_errors(FILE* fp, arg_end_t* end, const char* progname);
	void arg_freetable(void** argtable, size_t n);
	void arg_print_option_ds(arg_dstr_t ds, const char* shortopts, const char* longopts, const char* datatype, const char* suffix);
	void arg_cat_optionv(char* dest, size_t ndest, const char* shortopts, const char* longopts, const char* datatype, int optvalue, const char* separator);
	void arg_dstr_catf(arg_dstr_t ds, const char* fmt, ...);
	void arg_dstr_cat(arg_dstr_t ds, const char* str);
	void arg_cat(char** pdest, const char* src, size_t* pndest);
	void setup_append_buf(arg_dstr_t ds, int new_space);
	void arg_dstr_free(arg_dstr_t ds);
#ifdef __cplusplus
}
#endif
#endif
