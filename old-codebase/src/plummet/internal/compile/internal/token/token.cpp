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
		{ tokenType::booleanLiteral, "booleanLiteral" },
		{ tokenType::integerLiteral, "integerLiteral" },
		{ tokenType::doubleLiteral, "doubleLiteral" },
		{ tokenType::stringLiteral, "stringLiteral" },

		{ tokenType::identifier, "identifier" },
		{ tokenType::modifier, "modifier" },

		{ tokenType::openParenthesis, "openParenthesis" },
		{ tokenType::closeParenthesis, "closeParenthesis" },
		{ tokenType::openBracket, "openBracket" },
		{ tokenType::closeBracket, "closeBracket" },
		{ tokenType::openBrace, "openBrace" },
		{ tokenType::closeBrace, "closeBrace" },
		{ tokenType::vbar, "verticalBar" },

		{ tokenType::plusSign, "plusSign" },
		{ tokenType::minusSign, "minusSign" },
		{ tokenType::multiplySign, "multiplySign" },
		{ tokenType::divideSign, "divideSign" },
		{ tokenType::moduloSign, "moduloSign" },

		{ tokenType::plusPlusSign, "plusPlusSign" },
		{ tokenType::minusMinusSign, "minusMinusSign" },
		{ tokenType::plusEqualSign, "plusEqualSign" },
		{ tokenType::minusEqualSign, "minusEqualSign" },
		{ tokenType::multiplyEqualSign, "multiplyEqualSign" },
		{ tokenType::divideEqualSign, "divideEqualSign" },
		{ tokenType::moduloEqualSign, "moduloEqualSign" },

		{ tokenType::equalSign, "equalSign" },

		{ tokenType::equalEqualSign, "equalEqualSign" },
		{ tokenType::notEqualSign, "notEqualSign" },
		{ tokenType::greaterThanSign, "greaterThanSign" },
		{ tokenType::greaterEqualSign, "greaterEqualSign" },
		{ tokenType::lessThanSign, "lessThanSign" },
		{ tokenType::lessEqualSign, "lessEqualSign" },

		{ tokenType::andSign, "andSign" },
		{ tokenType::orSign, "orSign" },
		{ tokenType::notSign, "notSign" },

		{ tokenType::questionMark, "questionMark" },
		{ tokenType::semicolon, "semicolon" },
		{ tokenType::colon, "colon" },
		{ tokenType::comma, "comma" },
		{ tokenType::dot, "dot" },

		{ tokenType::derefSign, "derefSign" },
		{ tokenType::refSign, "refSign" },

		{ tokenType::optimizationToken, "optimizationToken" },
		{ tokenType::emptyToken, "emptyToken" },
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
