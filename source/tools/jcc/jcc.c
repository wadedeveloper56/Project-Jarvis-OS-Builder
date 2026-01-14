#include <stdio.h>
#include "cansi.tab.h"
#include "wic.h"

extern FILE* yyin; 

static void initJccBasics(int argc, char* argv[]) {
    g_commentList = createSLList();
    g_dirList = createSLList();
    g_logList = createSLList();
    g_currPos = NULL;
    //getCmdLineOptions(argc, argv);
}

void jccExit(int exitCode) {
    if (exitCode == 0) {
        zapSLList(g_logList, NULL);
        zapSLList(g_dirList, NULL);
        zapSLList(g_commentList, NULL);
    }
    else {
        printf("WIC: Terminating with error...\n");
        _fcloseall();
    }
    exit(exitCode);
}

void main(int argc, char* argv[])
{
    initJccBasics(argc, argv);
	jccExit(0);
}
