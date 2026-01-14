#pragma once

extern pSLList g_commentList;   /* Store comments */
extern pSLList g_dirList;       /* Store preprocessor directives */
extern pSLList g_currLineCode;  /* All tokens collected from beginning of current line */
extern int g_currLineNum;       /* Current line number */
extern int g_currColNum;        /* Current column number */
extern char* g_currFileName;    /* Current file name */
extern pTokPos g_currPos;       // Current position
extern long unsigned g_memUsed; /* Amount of memory used */
extern long unsigned g_numSymbols;  // Number of symbols in symbol table
extern long unsigned g_debugCount;  // Debug counter
extern long unsigned g_dribbleCounter;  // Advanced every time when dribble is called
extern pLogList g_logList;  // List of errors (and other messages?) that is output along with the rest of code
extern struct Opt g_opt;   // Options
extern char *g_usage[];
extern long unsigned g_totalNumLines;
extern long unsigned g_numErrNotDisp;
extern pHTable g_fileTable;  // Keep track of files included
