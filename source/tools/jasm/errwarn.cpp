#include "jasm.h"

using namespace std;

unsigned long warn_class_enabled; 
yasm_error_class yasm_eclass;
static char* yasm_estr;
static unsigned long yasm_exrefline;
static char* yasm_exrefstr;
static STAILQ_HEAD(warn_head, warn) yasm_warns;

void yasm_errwarn_initialize(void)
{
    /* Default enabled warnings.  See errwarn.h for a list. */
    warn_class_enabled =
        (1UL << YASM_WARN_GENERAL) | (1UL << YASM_WARN_UNREC_CHAR) |
        (1UL << YASM_WARN_PREPROC) | (0UL << YASM_WARN_ORPHAN_LABEL) |
        (1UL << YASM_WARN_UNINIT_CONTENTS) | (0UL << YASM_WARN_SIZE_OVERRIDE) |
        (1UL << YASM_WARN_IMPLICIT_SIZE_OVERRIDE);

    yasm_eclass = YASM_ERROR_NONE;
    yasm_estr = NULL;
    yasm_exrefline = 0;
    yasm_exrefstr = NULL;

    STAILQ_INIT(&yasm_warns);
}

void yasm__fatal(const char* message, ...)
{
    va_list va;
    va_start(va, message);
    yasm_fatal(message, va);
    va_end(va);
}