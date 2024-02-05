#include "plummet_utility.h"

PLUMMET_VARIABLE plummet_get_type(PLUMMET_VARIABLE var) {
    PLUMMET_VARIABLE *temp;

    switch (var.type) {
        case PLUMMET_TYPE_INT:
            *temp = make_plummet_var("PLUMMET_TYPE_INT");
            break;
        case PLUMMET_TYPE_DOUBLE:
            *temp = make_plummet_var("PLUMMET_TYPE_DOUBLE");
            break;
        case PLUMMET_TYPE_STRING:
            *temp = make_plummet_var("PLUMMET_TYPE_STRING");
            break;
        case PLUMMET_TYPE_MAP:
            *temp = make_plummet_var("PLUMMET_TYPE_MAP");
            break;
        case PLUMMET_TYPE_LIST:
            *temp = make_plummet_var("PLUMMET_TYPE_LIST");
            break;
    }

    return *temp;
}