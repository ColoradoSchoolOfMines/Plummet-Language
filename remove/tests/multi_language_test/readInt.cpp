#include <iostream>

extern "C" int readInt() asm("readInt");
int readInt() {
	int a;
	std::cout << "> ";
	std::cin >> a;
	return a;
}
