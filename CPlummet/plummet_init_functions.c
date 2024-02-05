#include "plummet_init_functions.h"

PLUMMET_VARIABLE make_plummet_variable_int(int x) {
	PLUMMET_VARIABLE var;
	var.type = PLUMMET_TYPE_INT;
	var.value.i = x; 	
	return var;
}

PLUMMET_VARIABLE make_plummet_variable_double(double x) {
	PLUMMET_VARIABLE var;
	var.type = PLUMMET_TYPE_DOUBLE;
	var.value.dbl = x;
	return var;
}

PLUMMET_VARIABLE make_plummet_variable_string(char *x) {
	PLUMMET_VARIABLE var;
	var.type = PLUMMET_TYPE_STRING;
	var.value.str = x;
	// // TODO: evaluate is strdup is mem safe vs strcpy
	// var.value.str = strdup(x);
	// // strcpy(var.value.str, x);
	return var;
}

PLUMMET_VARIABLE make_plummet_variable_map(PLUMMET_MAP *x) {
	PLUMMET_VARIABLE var;
	var.type = PLUMMET_TYPE_MAP;
	var.value.map = x;
	return var;
}

PLUMMET_VARIABLE make_plummet_variable_list(PLUMMET_LIST *x) {
	PLUMMET_VARIABLE var;
	var.type = PLUMMET_TYPE_LIST;
	var.value.list = x;
	return var;
}