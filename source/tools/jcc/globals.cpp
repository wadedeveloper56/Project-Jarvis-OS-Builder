#include "wic.h"

 pSLList g_commentList;   /* Store comments */
 pSLList g_dirList;       /* Store preprocessor directives */
 pSLList g_currLineCode;  /* All tokens collected from beginning of current line */
 int g_currLineNum;       /* Current line number */
 int g_currColNum;        /* Current column number */
 char* g_currFileName;    /* Current file name */
 pTokPos g_currPos;       // Current position
 long unsigned g_memUsed; /* Amount of memory used */
 long unsigned g_numSymbols;  // Number of symbols in symbol table
 long unsigned g_debugCount;  // Debug counter
 long unsigned g_dribbleCounter;  // Advanced every time when dribble is called
 pLogList g_logList;  // List of errors (and other messages?) that is output along with the rest of code
 struct Opt g_opt;   // Options
 char* g_usage[];
 long unsigned g_totalNumLines;
 long unsigned g_numErrNotDisp;
 pHTable g_fileTable;  // Keep track of files included
