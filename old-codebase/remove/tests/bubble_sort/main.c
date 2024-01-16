#define ARRAY_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_functions.h"

extern void bubble_sort(int *arr, int len);

int main() {
	srand(time(NULL));

	// Set up array
	int* arr = newArray(ARRAY_SIZE);
	fillArray(arr, ARRAY_SIZE, 0, 100);

	// Show array
	printf("Before: ");
	printArray(arr, ARRAY_SIZE);

	// Sort array
	bubble_sort(arr, ARRAY_SIZE);

	// Show array
	printf("After: ");
	printArray(arr, ARRAY_SIZE);
}
