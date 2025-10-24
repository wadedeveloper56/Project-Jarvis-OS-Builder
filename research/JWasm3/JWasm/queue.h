#pragma once

struct qnode {
    void* next;
    union {
        const void* elmt;
        struct asym* sym;
    };
};

struct qdesc {
    void* head;
    void* tail;
};
