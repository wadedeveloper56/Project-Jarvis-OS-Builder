#include "pch.h"
#include "globals.h"
#include "trmem.h"
#include "errmsg.h"

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
	if (signo != SIGBREAK) EmitError(GENERAL_FAILURE);
	close_files();
	exit(EXIT_FAILURE);
}

int main(int argc, char* argv[])
{
	tm_Init();
	char* pEnv = getenv("JWASM");
	if (pEnv == NULL)
		pEnv = (char*)"";
	argv[0] = pEnv;
	signal(SIGBREAK, genfailure);
	tm_Fini();
	return 0;
}

