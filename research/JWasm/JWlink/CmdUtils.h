#pragma once

#include "globals.h"

#define PATH_SEP '\\'
#define IS_PATH_SEP( a ) ((a)=='\\' || (a)=='/' || (a)==':')
#define CASE_PATH_SEP   case '\\': case '/': case ':'
#define PATH_LIST_SEP ';'

typedef enum file_defext {
#undef pick1
#define pick1(enum,text) enum,
#include "ldefext.h"
} file_defext;

char* FileName(char* buff, unsigned len, file_defext etype, bool force);
