#include "std_plummet.h"

int main() {
	char* test = "Hello, World!";

	print("What is your name? ");
	char* name = input();

	char** words = split(name, ' ');
	char* s = join(words, ' ');

	print(s);
	print("\n");
}
