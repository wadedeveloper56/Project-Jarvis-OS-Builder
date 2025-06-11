#ifndef ARGUMENTTABLE
#define ARGUMENTTABLE

#include <stdio.h> /* FILE */
#include <time.h>  /* struct tm */

#ifdef __cplusplus
extern "C" {
#endif

#define ARG_CMD_NAME_LEN 100
#define ARG_CMD_DESCRIPTION_LEN 256

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

	typedef struct arg_rem {
		struct arg_hdr hdr;
	} arg_rem_t;

	typedef struct arg_lit {
		struct arg_hdr hdr;
		int count;
	} arg_lit_t;

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

	arg_int_t* arg_intn(const char* shortopts, const char* longopts, const char* datatype, int mincount, int maxcount, const char* glossary);
	arg_int_t* arg_int0(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);
	arg_int_t* arg_int1(const char* shortopts, const char* longopts, const char* datatype, const char* glossary);

#ifdef __cplusplus
}
#endif
#endif
