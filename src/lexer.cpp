#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include "lexer.hpp"
#include "token.hpp"

/*
 * Lexer class member functions
 */

lexer::lexer(const std::string& fileName)
	: file(new std::ifstream(fileName)), lastChar()
{
	columnNumber = 0;
	lineNumber = 1;
}

std::vector<token> lexer::getTokens()
{
	return tokens;
}

void lexer::lexFile()
{
	// Extract tokens from file
	while (file->get(lastChar))
	{
		columnNumber++;

		// Check for newline
		if (lastChar == '\n')
		{
			columnNumber = 0;
			lineNumber++;
			continue;
		}

		// Check for string
		if (lastChar == '"')
		{
			// Parse string from text
			std::string tempString;
			int tokenLength = 0;
			while (file->get(lastChar) && lastChar != '"')
			{
				tempString += lastChar;
				tokenLength++;
			}
			tokenLength++;

			tokens.push_back(token(tokenType::stringLiteral, tempString, lineNumber, columnNumber));
			columnNumber += tokenLength;
		}

		// Check for identifiers
		if (isalpha(lastChar) || lastChar == '_')
		{
			std::string identifierString = "";
			identifierString += lastChar;
			
			// Parse identifier from text
			int tokenLength = 0;
			while (file->get(lastChar) && (isalnum(lastChar) || lastChar == '_'))
			{
				identifierString += lastChar;
				tokenLength++;
			}
			tokenLength++;

			tokens.push_back(token(tokenType::identifier, identifierString, lineNumber, columnNumber));
			columnNumber += tokenLength;
		}
	}
}
