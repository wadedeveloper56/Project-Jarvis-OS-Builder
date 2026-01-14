/* WIC.H: Master include file. */

#include "bool.h"
#include "gentypes.h" /* Generic types */
#include "forward.h"
#include "cmdline.h"
#include "wicmsg.h"
#include "wicgener.h"
//#include "symtab.h" /* Generic symbol table */
#include "token.h"
#include "tables.h"  /* A symbol table and a generic hash table */
#include "ctree.h"
#include "exptok.h"
#include "parse.h"
#include "trandecl.h"
#include "globals.h"
#include "hash.h"
#include "wicstr.h"
#include "print.h"
#include "Memory.h"

int isEmptySLList(pSLList pList);
void rewindCurrSLListPos(pSLList pList);
pSLList createSLList(void);
void zapSLList(pSLList pList, void (zapElem)(void*));

