#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "std_plummet.h"

// Plummet IO functions

void print(const char* str) {
	for (int i = 0; i < strlen(str); i++) {
		putchar(str[i]);
	}
}

char* input() {
	size_t buffer_size = 0;
	char* buffer = NULL;

	getline(&buffer, &buffer_size, stdin);

	buffer[strlen(buffer) - 1] = '\0';

	return buffer;
}

// Plummet string functions

char** split(char* str, char delim) {

	// Count the number of delimiters and allocate memory for the array

	int delim_count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == delim) {
			delim_count++;
		}
	}
	delim_count++; // Account for the last substring
	char** substrings = (char**)malloc(delim_count * sizeof(char*));

	// Split input string into substrings

	int substring_index = 0;
	char* copy = strdup(str);           // copy of input string
	char* token = strtok(copy, &delim); // traverse copy for delimiters
					    // and replace them with NULL

	while (token != NULL) {
		substrings[substring_index] = strdup(token);
		substring_index++;
		token = strtok(NULL, &delim);
	}

	return substrings;
}

char* join(char** list, char delim) {

	// Find length of string and allocate memory for the string
	
	int str_length = 0;
	for (int i = 0; list[i] != NULL; i++) {
		str_length += strlen(list[i]) + 2;
	}
	char* str = (char*)malloc(str_length);

	// Join substrings into final string and add null terminator

	int str_index = 0;
	for (int i = 0; list[i] != NULL; i++) {
		// Add substring
		for (int j = 0; j < strlen(list[i]); j++) {
			str[str_index] = list[i][j];
			str_index++;
		}

		// Add delimiter
		if (list[i + 1] != NULL) {
			str[str_index] = delim;
			str_index++;
		}
	}
	str[str_index] = '\0';

	return str;
}
