#include <stdio.h>
#include "cansi.tab.h"

extern FILE* yyin; 

int main()
{
	yyin = NULL;
	yyparse();
	return 0;
}
