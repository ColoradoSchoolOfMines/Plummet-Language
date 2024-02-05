#include "plummet_io.h"

void print(PLUMMET_VARIABLE var) {
	switch (var.type) {
		case PLUMMET_TYPE_INT:
			printf("%d\n", var.value.i);
			break;
		case PLUMMET_TYPE_DOUBLE:
			printf("%f\n", var.value.dbl);
			break;
		case PLUMMET_TYPE_STRING:
			printf("\"%s\"\n", var.value.str);
			break;
		case PLUMMET_TYPE_MAP:
			perror("NOT IMPLEMENTED: _print() for PLUMMET_TYPE_MAP\n");
			exit(1);
		case PLUMMET_TYPE_LIST:
			perror("NOT IMPLEMENTED: _print() for PLUMMET_TYPE_LIST\n");
			exit(1);
	}
}