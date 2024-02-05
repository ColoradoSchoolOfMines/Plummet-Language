#ifndef PLUMMET_CONVERSIONS_H
#define PLUMMET_CONVERSIONS_H

#include <stdlib.h>
#include <stdio.h>

#include "plummet_language_constants.h"
#include "plummet_variable.h"
#include "plummet_init_functions.h"

// Variable to String

PLUMMET_VARIABLE int_to_string(int);
PLUMMET_VARIABLE double_to_string(double);
PLUMMET_VARIABLE string_to_string(char *);
PLUMMET_VARIABLE to_string(PLUMMET_VARIABLE);

// Variable to Int

PLUMMET_VARIABLE string_to_int(char *);
PLUMMET_VARIABLE double_to_int(double);
PLUMMET_VARIABLE int_to_int(int);
PLUMMET_VARIABLE to_int(PLUMMET_VARIABLE);

// Variable to Double

PLUMMET_VARIABLE string_to_double(char *);
PLUMMET_VARIABLE int_to_double(int);
PLUMMET_VARIABLE double_to_double(double);
PLUMMET_VARIABLE to_double(PLUMMET_VARIABLE);

#endif // PLUMMET_CONVERSIONS_H