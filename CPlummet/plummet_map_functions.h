#ifndef PLUMMET_MAP_FUNCTIONS_H
#define PLUMMET_MAP_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "plummet_bool.h"
#include "plummet_variable.h"
#include "plummet_map.h"
#include "plummet_init_functions.h"

PLUMMET_VARIABLE plummet_make_map();

void plummet_map_insert(
    PLUMMET_VARIABLE *map,
    PLUMMET_VARIABLE *key,
    PLUMMET_VARIABLE *value
);

// TODO: make this return a PLUMMET_TYPE_RESULT
PLUMMET_VARIABLE *plummet_map_get(
    PLUMMET_VARIABLE *map,
    PLUMMET_VARIABLE *key
);

// TODO: make this return a PLUMMET_TYPE_RESULT
bool plummet_map_remove(
    PLUMMET_VARIABLE *map,
    PLUMMET_VARIABLE *key
);

#endif // PLUMMET_MAP_FUNCTIONS_H