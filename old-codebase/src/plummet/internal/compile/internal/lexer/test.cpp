#include <iostream>
#include "token.hpp"
#include "lexer.hpp"
#include "error.hpp"
using namespace std;

int main(int argc, char **argv)
{
	lexer l(argv[1]);
	l.lexFile();
	l.optimizeTokens();
	for (token t: l.getTokens()) {
		t.prettyPrint();
	}
	return 0;
}
