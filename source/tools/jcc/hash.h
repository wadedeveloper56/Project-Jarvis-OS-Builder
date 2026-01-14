#pragma once

typedef struct {
    char *name;            // Keyword name
    int code;
    char *tname[TLT_MAX];  // target langauge keyword name
} TokTab, *pTokTab;
