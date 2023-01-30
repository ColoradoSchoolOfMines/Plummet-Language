#include <iostream>

int readInt() asm("readInt");
int readInt() {
	int a;
	std::cin >> a;
	return a;
}
