#ifndef PLUMMET_LIST_H
#define PLUMMET_LIST_H

#include "plummet_variable.h"

// Forward declaration
struct PLUMMET_VARIABLE;

typedef struct PLUMMET_LIST_NODE {
    struct PLUMMET_VARIABLE *value;
    struct PLUMMET_LIST_NODE *next;
} PLUMMET_LIST_NODE;

typedef struct PLUMMET_LIST {
    PLUMMET_LIST_NODE *head;
    PLUMMET_LIST_NODE *tail;
    int size;
} PLUMMET_LIST;

#endif // PLUMMET_LIST_H