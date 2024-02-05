#ifndef PLUMMET_VARIABLE_H
#define PLUMMET_VARIABLE_H

#include "plummet_type.h"
#include "plummet_box.h"

typedef struct PLUMMET_VARIABLE {
	PLUMMET_TYPE type;
	PLUMMET_BOX value;
} PLUMMET_VARIABLE;

#endif // PLUMMET_VARIABLE_H