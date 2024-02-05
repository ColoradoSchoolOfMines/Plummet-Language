#ifndef PLUMMET_BOX_H
#define PLUMMET_BOX_H

#include "plummet_map.h"
#include "plummet_list.h"

// Forward declaration
struct PLUMMET_MAP;
struct PLUMMET_LIST;

typedef union PLUMMET_BOX {
	int i;
	double dbl;
	char *str;
	struct PLUMMET_MAP *map;
	struct PLUMMET_LIST *list;
} PLUMMET_BOX;

#endif // PLUMMET_BOX_H