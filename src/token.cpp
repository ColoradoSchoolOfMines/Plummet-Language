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
		{ tokenType::characterLiteral, "characterLiteral" },
		{ tokenType::booleanLiteral, "booleanLiteral" },
		{ tokenType::integerLiteral, "integerLiteral" },
		{ tokenType::doubleLiteral, "doubleLiteral" },
		{ tokenType::stringLiteral, "stringLiteral" },

		{ tokenType::identifier, "identifier" },

		{ tokenType::openParenthesis, "openParenthesis" },
		{ tokenType::closeParenthesis, "closeParenthesis" },
		{ tokenType::openBracket, "openBracket" },
		{ tokenType::closeBracket, "closeBracket" },
		{ tokenType::openBrace, "openBrace" },
		{ tokenType::closeBrace, "closeBrace" },

		{ tokenType::plusSign, "plusSign" },
		{ tokenType::minusSign, "minusSign" },
		{ tokenType::multiplySign, "multiplySign" },
		{ tokenType::divideSign, "divideSign" },
		{ tokenType::moduloSign, "moduloSign" },
	};
}

void token::prettyPrint()
{
	std::cout << "token: [type: " << tokenTypeMap[type]
		<< ", value: " << value
		<< ", line: " << lineNumber
		<< ", column: " << columnNumber << "]" << std::endl;
}

void token::setType(tokenType type)
{
	this->type = type;
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
