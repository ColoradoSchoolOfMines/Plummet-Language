#ifndef LEXER_HPP
#define LEXER_HPP

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include "token.hpp"

class lexer
{
	size_t lineNumber, columnNumber;
	std::vector<token> tokens;
	std::ifstream* file;
	char lastChar;

	void optimizeTokensHelper();

	public:
		lexer(const std::string&);

		std::vector<token> getTokens();
		void optimizeTokens(const int = -1);
		void lexFile();
};

#endif // LEXER_HPP
