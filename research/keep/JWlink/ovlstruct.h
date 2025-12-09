#pragma once

typedef struct vecnode {
    struct vecnode* next;
    symbol* entry;
} vecnode;
