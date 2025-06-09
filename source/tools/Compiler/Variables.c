#include "global.h"

Boolean bit16 = FALSE;
Boolean bit32 = FALSE;
Boolean bit64 = FALSE;
DeclarationListPtr symbolTable = NULL;
DeclarationListPtr functionTable = NULL;
char logFileName[_MAX_PATH];
char drive[_MAX_DRIVE];
char dir[_MAX_DIR];
char fname[_MAX_FNAME];
char ext[_MAX_EXT];

char* VariableSignName[] = {
	"TYPE_SIGNED",
	"TYPE_UNSIGNED"
};

char* VariableTypeName[] = {
	"TYPE_NULL",
	"TYPE_VOID",
	"TYPE_CHARACTER",
	"TYPE_SHORT",
	"TYPE_INTEGER",
	"TYPE_LONG",
	"TYPE_LONG64",
	"TYPE_FLOAT",
	"TYPE_DOUBLE",
	"TYPE_STRING",
	"TYPE_STRUCT",
	"TYPE_BOOLEAN",
	"TYPE_COMPLEX",
	"TYPE_IMAGINARY"
};