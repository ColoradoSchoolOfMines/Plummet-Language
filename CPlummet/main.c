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

	// print(*plummet_list_at(&var, 0));
	// print(*plummet_list_at(&var, 1));
	// print(*plummet_list_at(&var, 2));
	// print(*plummet_list_at(&var, 3));

	for (int i = 0; i < var.value.list->size; i++) {
		PLUMMET_VARIABLE temp = *plummet_list_at(&var, i);
		print(temp);
		print(plummet_get_type(temp));
	}

	return 0;
}