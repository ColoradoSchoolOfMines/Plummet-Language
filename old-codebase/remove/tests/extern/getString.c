#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString() {
	char* str;
	size_t size = 0;

	printf("Enter a string: ");

	getline(&str, &size, stdin);

	if (str[strlen(str) - 1] == '\n') {
		str[strlen(str) - 1] = '\0';
	}

	return str;
}
