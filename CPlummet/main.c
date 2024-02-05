#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "plummet_standard_library.h"

int main() {
	PLUMMET_VARIABLE var = plummet_make_list();

	PLUMMET_VARIABLE el1 = make_plummet_var("hello world");
	PLUMMET_VARIABLE el2 = make_plummet_var(10);
	PLUMMET_VARIABLE el3 = make_plummet_var(3.14);

	plummet_list_push(&var, &el1);
	plummet_list_push(&var, &el2);
	plummet_list_push(&var, &el3);

	for (int i = 0; i < var.value.list->size; i++) {
		print(*plummet_list_at(&var, i)); // There is an error indexing past 0
		PLUMMET_VARIABLE temp = *plummet_list_at(&var, i);
		print(plummet_get_type(temp));
	}

	return 0;
}
