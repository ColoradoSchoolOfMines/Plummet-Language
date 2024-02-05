#include "plummet_bool.h"

bool plummet_variable_equals(PLUMMET_VARIABLE a, PLUMMET_VARIABLE b) {
    if (a.type != b.type) {
        return false;
    }
    switch (a.type) {
        case PLUMMET_TYPE_INT:
            return a.value.i == b.value.i;
        case PLUMMET_TYPE_DOUBLE:
            return a.value.dbl == b.value.dbl;
        case PLUMMET_TYPE_STRING:
            return strcmp(a.value.str, b.value.str) == 0;
        case PLUMMET_TYPE_MAP:
            perror("plummet_variable_equals() not implemented for PLUMMET_MAP");
            exit(1);
        case PLUMMET_TYPE_LIST:
            perror("plummet_variable_equals() not implemented for PLUMMET_LIST");
            exit(1);
    }

    return false;
}

bool plummet_variable_not_equals(PLUMMET_VARIABLE a, PLUMMET_VARIABLE b) {
    return !plummet_variable_equals(a, b);
}