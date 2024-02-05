#include "plummet_conversions.h"

// Variable to String

PLUMMET_VARIABLE int_to_string(int x) {
	char *str = malloc(PLUMMET_MAX_STRING_LENGTH);

	if (str == NULL) {
		perror("malloc failed: int_to_string()\n");
		exit(1);
	}

	snprintf(str, PLUMMET_MAX_STRING_LENGTH, "%d", x);
	return make_plummet_variable_string(str);
}

PLUMMET_VARIABLE double_to_string(double x) {
	char *str = malloc(PLUMMET_MAX_STRING_LENGTH);

	if (str == NULL) {
		perror("malloc failed: double_to_string()\n");
		exit(1);
	}

	snprintf(str, PLUMMET_MAX_STRING_LENGTH, "%f", x);
	return make_plummet_variable_string(str);
}

PLUMMET_VARIABLE string_to_string(char *x) {
	char *str = malloc(PLUMMET_MAX_STRING_LENGTH);

	if (str == NULL) {
		perror("malloc failed: string_to_string()\n");
		exit(1);
	}

	snprintf(str, PLUMMET_MAX_STRING_LENGTH, "%s", x);
	return make_plummet_variable_string(str);
}

PLUMMET_VARIABLE to_string(PLUMMET_VARIABLE var) {
	switch (var.type) {
		case PLUMMET_TYPE_INT:
			return int_to_string(var.value.i);
		case PLUMMET_TYPE_DOUBLE:
			return double_to_string(var.value.dbl);
		case PLUMMET_TYPE_STRING:
			return string_to_string(var.value.str);
		case PLUMMET_TYPE_MAP:
			perror("NOT IMPLEMENTED: _to_string() for PLUMMET_TYPE_MAP\n");
			exit(1);
		case PLUMMET_TYPE_LIST:
			perror("NOT IMPLEMENTED: _to_string() for PLUMMET_TYPE_LIST\n");
			exit(1);
	}
}

// Variable to Int

PLUMMET_VARIABLE string_to_int(char *x) {
	return make_plummet_variable_int(atoi(x));
}

PLUMMET_VARIABLE double_to_int(double x) {
	return make_plummet_variable_int((int)x);
}

PLUMMET_VARIABLE int_to_int(int x) {
	return make_plummet_variable_int(x);
}

PLUMMET_VARIABLE to_int(PLUMMET_VARIABLE var) {
	switch (var.type) {
		case PLUMMET_TYPE_INT:
			return int_to_int(var.value.i);
		case PLUMMET_TYPE_DOUBLE:
			return double_to_int(var.value.dbl);
		case PLUMMET_TYPE_STRING:
			return string_to_int(var.value.str);
		case PLUMMET_TYPE_MAP:
			perror("NOT IMPLEMENTED: _to_int() for PLUMMET_TYPE_MAP\n");
			exit(1);
		case PLUMMET_TYPE_LIST:
			perror("NOT IMPLEMENTED: _to_int() for PLUMMET_TYPE_LIST\n");
			exit(1);
	}
}

// Variable to Double

PLUMMET_VARIABLE string_to_double(char *x) {
	return make_plummet_variable_double(atof(x));
}

PLUMMET_VARIABLE int_to_double(int x) {
	return make_plummet_variable_double((double)x);
}

PLUMMET_VARIABLE double_to_double(double x) {
	return make_plummet_variable_double(x);
}

PLUMMET_VARIABLE to_double(PLUMMET_VARIABLE var) {
	switch (var.type) {
		case PLUMMET_TYPE_INT:
			return int_to_double(var.value.i);
		case PLUMMET_TYPE_DOUBLE:
			return double_to_double(var.value.dbl);
		case PLUMMET_TYPE_STRING:
			return string_to_double(var.value.str);
		case PLUMMET_TYPE_MAP:
			perror("NOT IMPLEMENTED: _to_double() for PLUMMET_TYPE_MAP\n");
			exit(1);
		case PLUMMET_TYPE_LIST:
			perror("NOT IMPLEMENTED: _to_double() for PLUMMET_TYPE_LIST\n");
			exit(1);
	}
}