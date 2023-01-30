#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef>
#include <string>
#include <map>

enum tokenType
{
	// Literals
	characterLiteral,
	booleanLiteral,
	integerLiteral,
	doubleLiteral,
	stringLiteral,

	identifier,

	// Symbols
	openParenthesis,  // (
	closeParenthesis, // )
	openBracket,      // [
	closeBracket,     // ]
	openBrace,        // {
	closeBrace,       // }
	
	// Math operators
	plusSign,
	minusSign,
	multiplySign,
	divideSign,
	moduloSign,

	// Special Optimization Token
	optimizationToken,
	emptyToken,
};

class token
{
	size_t lineNumber, columnNumber;
	tokenType type;
	std::string value;
	std::map<tokenType, std::string> tokenTypeMap;

	public:
		token(tokenType, const std::string&, size_t, size_t);
		void prettyPrint();

		size_t getColumnNumber();
		void setType(tokenType);
		size_t getLineNumber();
		std::string getValue();
		tokenType getType();
};

#endif // TOKEN_HPP
