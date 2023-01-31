#ifndef MAIN_HPP

#include <iostream>

#include "lexer.hpp"
#include "token.hpp"

int main()
{
	lexer lex("test.txt");
	lex.lexFile();

	std::cout << "Tokens: " << std::endl;
	for (token t: lex.getTokens())
	{
		t.prettyPrint();
	}

	std::cout << "Optimized Tokens: " << std::endl;
	lex.optimizeTokens();
	for (token t: lex.getTokens())
	{
		t.prettyPrint();
	}
	return 0;
}

#endif // MAIN_HPP
