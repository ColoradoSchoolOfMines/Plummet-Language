#ifndef LEXER_HPP
#define LEXER_HPP

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include "token.hpp"

class lexer {
	private:
		size_t lineNumber, columnNumber;
		std::vector<token> tokens;
		std::string fileName;
		std::ifstream* file;
		char lastChar;

		bool optimizeTokensHelper();

	public:
		lexer(const std::string&);

		std::vector<token> getTokens();
		void optimizeTokens();
		void lexFile();
};

#endif // LEXER_HPP
