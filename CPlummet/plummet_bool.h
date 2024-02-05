#ifndef PLUMMET_BOOL_H
#define PLUMMET_BOOL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plummet_variable.h"

bool plummet_variable_equals(PLUMMET_VARIABLE, PLUMMET_VARIABLE); 
bool plummet_variable_not_equals(PLUMMET_VARIABLE, PLUMMET_VARIABLE);

#endif // PLUMMET_BOOL_H