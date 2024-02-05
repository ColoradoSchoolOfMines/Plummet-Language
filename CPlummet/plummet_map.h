#ifndef PLUMMET_MAP_H
#define PLUMMET_MAP_H

#include "plummet_variable.h"
#include "plummet_type.h"

// Forward declaration
struct PLUMMET_VARIABLE;

typedef struct PLUMMET_MAP_NODE {
    struct PLUMMET_VARIABLE *key;
    struct PLUMMET_VARIABLE *value;
    struct PLUMMET_MAP_NODE *next;
} PLUMMET_MAP_NODE;

typedef struct PLUMMET_MAP {
    PLUMMET_MAP_NODE *head;
    PLUMMET_MAP_NODE *tail;
    int size;
} PLUMMET_MAP;

#endif // PLUMMET_MAP_H