#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef>
#include <string>
#include <map>

enum tokenType
{
	integerLiteral,
	stringLiteral,
	identifier,
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
		size_t getLineNumber();
		std::string getValue();
		tokenType getType();
};

#endif // TOKEN_HPP
