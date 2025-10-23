#include "pch.h"
#include "globals.h"
#include "trmem.h"
#include "errmsg.h"
#include "cmdline.h"
#include "input.h"
#include "msgtext.h"

void tm_Init(void);
void tm_Fini(void);

void close_files(void)
{
	if (CurrFile[ASM] != NULL) {
		if (fclose(CurrFile[ASM]) != 0)
			EmitErr(CANNOT_CLOSE_FILE, CurrFName[ASM], errno);
		CurrFile[ASM] = NULL;
	}

	if (CurrFile[OBJ] != NULL) {
		if (fclose(CurrFile[OBJ]) != 0)
			EmitErr(CANNOT_CLOSE_FILE, CurrFName[OBJ], errno);
		CurrFile[OBJ] = NULL;
	}
	if (Options.syntax_check_only == FALSE &&
		ModuleInfo.g.error_count > 0) {
		remove(CurrFName[OBJ]);
	}

	if (CurrFile[LST] != NULL) {
		fclose(CurrFile[LST]);
		CurrFile[LST] = NULL;
	}

	if (CurrFile[ERR] != NULL) {
		fclose(CurrFile[ERR]);
		CurrFile[ERR] = NULL;
	}
	else if (CurrFName[ERR])
		remove(CurrFName[ERR]);
	return;
}

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
	intptr_t fh;
	const char* pfn;
	size_t dirsize;
	struct _finddata_t finfo;
	char fname[FILENAME_MAX];
#endif

#ifdef TRMEM
	tm_Init();
#endif
	const char* pEnv = (const char*)getenv("JWASM");
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
	while (ParseCmdline((const char**)&argv[1], &numArgs)) {
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
	};
	CmdlineFini();
	if (numArgs == 0) {
		write_logo();
		printf("%s", MsgGetEx(MSG_USAGE));
	}
	else if (numFiles == 0)
		EmitError(NO_FILENAME_SPECIFIED);

#ifdef TRMEM
	tm_Fini();
#endif

	DebugMsg(("main: exit, return code=%u\n", 1 - rc));
	return(1 - rc);
}

