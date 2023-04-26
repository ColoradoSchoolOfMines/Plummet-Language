// This code will not compile, this is intended :)

#define BUBBLE_SORT_CPP
#ifndef BUBBLE_SORT_CPP

extern "C" void bubble_sort(int* arr, int len) asm("bubble_sort");

void bubble_sort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

#endif // BUBBLE_SORT_CPP
