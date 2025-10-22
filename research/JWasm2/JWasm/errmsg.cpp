#include "pch.h"
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "input.h"
#include "tokenize.h"
#include "macro.h"
#include "msgtext.h"
#include "listing.h"
#include "segment.h"

extern void             print_source_nesting_structure(void);
extern jmp_buf          jmpenv;

char banner_printed = FALSE;

static const char usage[] = {
#include "usage.h"
};

int write_logo(void)
{
    if (banner_printed == FALSE) {
        banner_printed = TRUE;
        printf("%s, %s\n", MsgGetEx(MSG_JWASM), MsgGetEx(MSG_JWASM2));
        return(4);       
    }
    return(0);
}

static void PutMsg(FILE* fp, int severity, int msgnum, va_list args)
{
    int             i, j;
    const char* type;
    const char* pMsg;
    char            buffer[MAX_LINE_LEN + 128];

    if (fp != NULL) {

        if (severity && (j = GetCurrSrcPos(buffer))) {
            fwrite(buffer, 1, j, fp);
        }
        pMsg = MsgGetEx(msgnum);
        switch (severity) {
            case 1:  type = MsgGetEx(MSG_FATAL_PREFIX);   break;
            case 2:  type = MsgGetEx(MSG_ERROR_PREFIX);   break;
            case 4:  type = MsgGetEx(MSG_WARNING_PREFIX); break;
            default:  type = NULL; i = 0; break;
        }
        if (type)
            i = sprintf(buffer, "%s A%4u: ", type, severity * 1000 + msgnum);
        i += vsprintf(buffer + i, pMsg, args);
        fwrite(buffer, 1, i, fp);
        fwrite("\n", 1, 1, fp);

        if (CurrFile[LST] &&
            severity &&
            Parse_Pass == PASS_1 &&
            fp == CurrFile[ERR]) {
            LstWrite(LSTTYPE_DIRECTIVE, GetCurrOffset(), 0);
            LstPrintf("                           %s", buffer);
            LstNL();
        }
    }
}

static void PrtMsg(int severity, int msgnum, va_list args1, va_list args2)
{
#ifndef __SW_BD
    write_logo();
#endif
    if (CurrFile[ERR] == NULL && CurrFName[ERR] != NULL) {
        CurrFile[ERR] = fopen(CurrFName[ERR], "w");
        if (CurrFile[ERR] == NULL) {
            char* p = CurrFName[ERR];
            CurrFName[ERR] = NULL;       
            Options.no_error_disp = FALSE;    
            EmitErr(CANNOT_OPEN_FILE, p, ErrnoStr());
            LclFree(p);
        }
    }

    if (Options.no_error_disp == FALSE) {
        PutMsg(errout, severity, msgnum, args1);
        fflush(errout);                         
    }
    if (CurrFile[ERR]) {
        PutMsg(CurrFile[ERR], severity, msgnum, args2);
    }
}

int EmitErr(int msgnum, ...)
{
    va_list args1, args2;

#ifdef DEBUG_OUT
    printf("%s\n", ModuleInfo.tokenarray ? ModuleInfo.tokenarray[0].tokpos : "");
#endif
    va_start(args1, msgnum);
    va_start(args2, msgnum);
    PrtMsg(2, msgnum, args1, args2);
    va_end(args1);
    va_end(args2);
    ModuleInfo.g.error_count++;
    write_to_file = FALSE;
    print_source_nesting_structure();
    if (Options.error_limit != -1 && ModuleInfo.g.error_count == Options.error_limit + 1)
        Fatal(TOO_MANY_ERRORS);
    return(ERROR);
}

int EmitError(int msgnum)
{
    return(EmitErr(msgnum));
}

void EmitWarn(int level, int msgnum, ...)
{
    va_list args1, args2;

    if (level <= Options.warning_level) {
#ifdef DEBUG_OUT
        printf("%s\n", ModuleInfo.tokenarray ? ModuleInfo.tokenarray[0].tokpos : "");
#endif
        va_start(args1, msgnum);
        va_start(args2, msgnum);
        if (!Options.warning_error) {
            PrtMsg(4, msgnum, args1, args2);
            ModuleInfo.g.warning_count++;
        }
        else {
            PrtMsg(2, msgnum, args1, args2);
            ModuleInfo.g.error_count++;
        }
        va_end(args1);
        va_end(args2);
        print_source_nesting_structure();
    }
}

char* ErrnoStr(void)
{
    static char buffer[32];
    return((char *)((errno == ENOENT) ? "ENOENT" : myltoa(errno, buffer, 10, FALSE, FALSE)));
}

void Fatal(int msgnum, ...)
{
    va_list     args1, args2;

    va_start(args1, msgnum);
    va_start(args2, msgnum);
    PrtMsg(1, msgnum, args1, args2);
    va_end(args1);
    va_end(args2);

    ModuleInfo.g.error_count++;
    if (CurrFName[ASM])
        longjmp(jmpenv, 2);

    exit(1);
}
