#ifndef PLUMMET_MAIN

#include <iostream>

#include "bash.hpp"
#include "makefile.hpp"

using namespace std;

int main() {
	cout << "Bash template:" << endl;
	Bash bashTemplate;
	cout << bashTemplate.getTemplate() << endl;

	cout << endl;

	cout << "Makefile template:" << endl;
	Makefile makefileTemplate;
	cout << makefileTemplate.getTemplate() << endl;

	return 0;
}

#endif // PLUMMET_MAIN
