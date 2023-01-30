#include <iostream>
#include <cstddef>
#include <string>

#include "token.hpp"

/*
 * Token Class Member Functions
 */

token::token(tokenType type, const std::string& value, size_t lineNumber, size_t columnNumber)
	: type(type), value(value), lineNumber(lineNumber), columnNumber(columnNumber)
{
	tokenTypeMap = {
		{ tokenType::integerLiteral, "integerLiteral" },
		{ tokenType::stringLiteral, "stringLiteral" },
		{ tokenType::identifier, "identifier" },
	};
}

void token::prettyPrint()
{
	std::cout << "token: [type: " << tokenTypeMap[type]
		<< ", value: " << value
		<< ", line: " << lineNumber
		<< ", column: " << columnNumber << "]" << std::endl;
}

size_t token::getColumnNumber()
{
	return columnNumber;
}

size_t token::getLineNumber()
{
	return lineNumber;
}

std::string token::getValue()
{
	return value;
}

tokenType token::getType()
{
	return type;
}
