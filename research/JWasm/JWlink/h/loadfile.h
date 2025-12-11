#pragma once

enum {
    START_UNDEFED,
    START_IS_SYM,
    START_IS_SDATA
};

typedef struct {
    union {
        symbol* sym;
        segdata* sdata;
    } targ;
    offset              off;
    mod_entry* mod;
    targ_addr           addr;
    unsigned            type : 2;
    unsigned            user_specd : 1;
    unsigned            from_inc : 1;
} startinfo;

extern seg_leader* StackSegPtr;
extern startinfo        StartInfo;

void ResetLoadFile(void);
void FreeOutFiles(void);
void InitBuffFile(outfilelist* outfile, char* filename, bool executable);
void ResetLoadFile(void);
void CleanLoadFile(void);
void InitLoadFile(void);

