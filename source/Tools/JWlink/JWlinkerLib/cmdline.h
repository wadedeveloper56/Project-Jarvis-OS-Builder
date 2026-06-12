#pragma once

typedef struct sysblock
{
    struct sysblock* next;
    char* name;
    char                commands[1];
} sysblock;

void InitCmdFile(void);
char* GetNextLink(void);
