#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int len) {
	printf("[");
	for (int i = 0; i < len - 1; i++) printf("%d, ", arr[i]);
	printf("%d]\n", arr[len - 1]);
}

void fillArray(int *arr, int len, int min, int max) {
	for (int i = 0; i < len; i++) arr[i] = rand() % (max - min + 1) + min;
}

int* newArray(int len) {
	return (int*)malloc(sizeof(int) * len);
}

#endif // ARRAY_FUNCTIONS_H
