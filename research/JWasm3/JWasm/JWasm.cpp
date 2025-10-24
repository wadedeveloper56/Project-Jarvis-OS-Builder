#include "pch.h"
#include "errmsg.h"
#include "assemble.h"
#include "trmem.h"
#include "cmdline.h"
#include"input.h"

static void genfailure(int signo)
{
#if CATCHBREAK
	if (signo != SIGBREAK)
#else
	if (signo != SIGTERM)
#endif
	EmitError(GENERAL_FAILURE);
	close_files();
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	int numArgs = 0;
	int numFiles = 0;
	int rc = 0;
#if WILDCARDS
	long    fh;
	const char* pfn;
	int     dirsize;
	struct  _finddata_t finfo;
	char    fname[FILENAME_MAX];
#endif
#ifdef TRMEM
	tm_Init();
#endif
	const char* pEnv = getenv("JWASM");
	if (pEnv == NULL) pEnv = "";
	argv[0] = (char*)pEnv;
#ifndef DEBUG_OUT
	signal(SIGSEGV, genfailure);
#endif
#if CATCHBREAK
	signal(SIGBREAK, genfailure);
#else
	signal(SIGTERM, genfailure);
#endif
	while (ParseCmdline((const char**)&argv[1], &numArgs))
	{
		numFiles++;
		write_logo();
#if WILDCARDS
		if ((fh = _findfirst(Options.names[ASM], &finfo)) == -1) {
			DebugMsg(("main: _findfirst(%s) failed\n", Options.names[ASM]));
			EmitErr(CANNOT_OPEN_FILE, Options.names[ASM], ErrnoStr());
			break;
		}
		pfn = GetFNamePart(Options.names[ASM]);
		dirsize = pfn - Options.names[ASM];
		memcpy(fname, Options.names[ASM], dirsize);
		do {
			strcpy(&fname[dirsize], finfo.name);
			DebugMsg(("main: fname=%s\n", fname));
			rc = AssembleModule(fname);
		} while ((_findnext(fh, &finfo) != -1));
		_findclose(fh);
#else
		rc = AssembleModule(Options.names[ASM]);
#endif
	}
	CmdlineFini();
#ifdef TRMEM
	tm_Fini();
#endif
	DebugMsg(("main: exit, return code=%u\n", 1 - rc));
	return(1 - rc);
}

