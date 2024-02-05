#ifndef PLUMMET_LIST_FUNCTIONS_H
#define PLUMMET_LIST_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "plummet_bool.h"
#include "plummet_variable.h"
#include "plummet_list.h"
#include "plummet_init_functions.h"

PLUMMET_VARIABLE plummet_make_list();

void plummet_list_push(
    PLUMMET_VARIABLE *list,
    PLUMMET_VARIABLE *value
);

PLUMMET_VARIABLE *plummet_list_at(
    PLUMMET_VARIABLE *list,
    int index
);

bool plummet_list_remove(
    PLUMMET_VARIABLE *list,
    int index
);

#endif // PLUMMET_LIST_FUNCTIONS_H