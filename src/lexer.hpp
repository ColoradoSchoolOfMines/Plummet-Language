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

	public:
		lexer(const std::string&);

		std::vector<token> getTokens();
		void lexFile();
};

#endif // LEXER_HPP
