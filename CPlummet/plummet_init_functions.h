#ifndef PLUMMET_INIT_FUNCTIONS_H
#define PLUMMET_INIT_FUNCTIONS_H

#include "plummet_variable.h"
#include "plummet_type.h"
#include "plummet_map.h"
#include "plummet_list.h"

#define make_plummet_var(x) _Generic((x), \
	int: make_plummet_variable_int, \
	double: make_plummet_variable_double, \
	char *: make_plummet_variable_string, \
	PLUMMET_MAP *: make_plummet_variable_map, \
	PLUMMET_LIST *: make_plummet_variable_list \
)(x);

PLUMMET_VARIABLE make_plummet_variable_int(int);
PLUMMET_VARIABLE make_plummet_variable_double(double);
PLUMMET_VARIABLE make_plummet_variable_string(char *);
PLUMMET_VARIABLE make_plummet_variable_map(PLUMMET_MAP *);
PLUMMET_VARIABLE make_plummet_variable_list(PLUMMET_LIST *);

#endif // PLUMMET_INIT_FUNCTIONS_H