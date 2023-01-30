#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

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

bool lexer::optimizeTokensHelper()
{
	// TODO: Implement optimization routines
	bool optimiationMade = false;
	std::queue<token> tokenQueue;
	for (int i = 0; i < tokens.size(); i++)
	{
		// Check for back to back minus signs
		if (tokens[i].getType() == tokenType::minusSign && tokens[i + 1].getType() == tokenType::minusSign)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::plusSign, "+", tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for back to back plus signs
		if (tokens[i].getType() == tokenType::plusSign && tokens[i + 1].getType() == tokenType::plusSign)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::plusSign, "+", tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for minus followed by a plus
		if (tokens[i].getType() == tokenType::minusSign && tokens[i + 1].getType() == tokenType::plusSign)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::minusSign, "-", tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for plus followed by a minus
		if (tokens[i].getType() == tokenType::plusSign && tokens[i + 1].getType() == tokenType::minusSign)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::minusSign, "-", tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for a minus before a integer literal but not after a integer literal
		if (tokens[i].getType() == tokenType::minusSign &&
				tokens[i + 1].getType() == tokenType::integerLiteral &&
				tokens[i - 1].getType() != tokenType::integerLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::integerLiteral,
					std::to_string(0 - std::stoi(tokens[i + 1].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for integer literal arithmetic operations
		if (tokens[i].getType() == tokenType::integerLiteral &&
				tokens[i + 1].getType() == tokenType::plusSign &&
				tokens[i + 2].getType() == tokenType::integerLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::integerLiteral,
					std::to_string(std::stoi(tokens[i].getValue()) + std::stoi(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		if (tokens[i].getType() == tokenType::integerLiteral &&
				tokens[i + 1].getType() == tokenType::minusSign &&
				tokens[i + 2].getType() == tokenType::integerLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::integerLiteral,
					std::to_string(std::stoi(tokens[i].getValue()) - std::stoi(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for a minus before a double literal but not after a double literal
		if (tokens[i].getType() == tokenType::minusSign &&
				tokens[i + 1].getType() == tokenType::doubleLiteral &&
				tokens[i - 1].getType() != tokenType::doubleLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(0 - std::stod(tokens[i + 1].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for double literal arithmetic operations
		if (tokens[i].getType() == tokenType::doubleLiteral &&
				tokens[i + 1].getType() == tokenType::plusSign &&
				tokens[i + 2].getType() == tokenType::doubleLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) + std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		if (tokens[i].getType() == tokenType::doubleLiteral &&
				tokens[i + 1].getType() == tokenType::minusSign &&
				tokens[i + 2].getType() == tokenType::doubleLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) - std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for double literal to integer literal arithmetic operations
		if (tokens[i].getType() == tokenType::doubleLiteral &&
				tokens[i + 1].getType() == tokenType::plusSign &&
				tokens[i + 2].getType() == tokenType::integerLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) + std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		if (tokens[i].getType() == tokenType::doubleLiteral &&
				tokens[i + 1].getType() == tokenType::minusSign &&
				tokens[i + 2].getType() == tokenType::integerLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) - std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for integer literal to double literal arithmetic operations
		if (tokens[i].getType() == tokenType::integerLiteral &&
				tokens[i + 1].getType() == tokenType::plusSign &&
				tokens[i + 2].getType() == tokenType::doubleLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) + std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		if (tokens[i].getType() == tokenType::integerLiteral &&
				tokens[i + 1].getType() == tokenType::minusSign &&
				tokens[i + 2].getType() == tokenType::doubleLiteral)
		{
			tokens[i].setType(tokenType::optimizationToken);
			tokens[i + 1].setType(tokenType::optimizationToken);
			tokens[i + 2].setType(tokenType::optimizationToken);
			tokenQueue.push(token(tokenType::doubleLiteral,
					std::to_string(std::stod(tokens[i].getValue()) - std::stod(tokens[i + 2].getValue())),
					tokens[i].getLineNumber(), tokens[i].getColumnNumber()));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			tokenQueue.push(token(tokenType::emptyToken, "", 0, 0));
			break;
		}

		// Check for literal comparisons

		// Check for unnecessary parentheses
	}

	std::vector<token> optimizedTokens;
	for (token t: tokens)
	{
		if (t.getType() != tokenType::optimizationToken)
		{
			optimizedTokens.push_back(t);
		} else if (tokenQueue.front().getType() != tokenType::emptyToken) {
			optimizedTokens.push_back(tokenQueue.front());
			tokenQueue.pop();
			optimiationMade = true;
		} else {
			tokenQueue.pop();
		}
	}

	tokens = optimizedTokens;
	return optimiationMade;
}

void lexer::optimizeTokens()
{
	// Optimize tokens until no more optimizations can be made
	while (optimizeTokensHelper()) {}
}

void lexer::lexFile()
{
	// Extract tokens from file

	// TODO: file->get(lastChar) will be problematic as it will consume
	//       extra characters. For example, if a number is followed by a
	//       string, the opening quote will be consumed by the while loop.
	//       This will cause the string to be parsed incorrectly.
	while(file->get(lastChar))
	{
		jump:

		std::cout << lastChar << std::endl;

		columnNumber++;

		// Check for string literal
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

		// Check for character literal
		if (lastChar == '\'')
		{
			// Parse string from text
			std::string tempString;
			bool escape = false;
			int tokenLength = 0;
			while (file->get(lastChar) && lastChar != '\'')
			{
				// TODO: Handle escape sequences and produce error if invalid escape sequence or invalid character literal
				tempString += lastChar;
				tokenLength++;
			}
			tokenLength++;

			tokens.push_back(token(tokenType::characterLiteral, tempString, lineNumber, columnNumber));
			columnNumber += tokenLength;
		}

		// Check for number literals
		if (isdigit(lastChar) || lastChar == '.')
		{
			std::string numberString = "";
			numberString += lastChar;
			int tokenLength = 0;

			bool decimal = (lastChar == '.');
			bool validNumber = false;

			// Parse number from text
			while (file->get(lastChar) && (isdigit(lastChar) || lastChar == '.'))
			{
				if (lastChar == '.')
				{
					if (decimal)
					{
						// TODO: Throw error
					}
					decimal = true;
				}

				if (isdigit(lastChar))
				{
					validNumber = true;
				}

				numberString += lastChar;
				tokenLength++;
			}
			tokenLength++;

			if (decimal)
			{
				tokens.push_back(token(tokenType::doubleLiteral, numberString, lineNumber, columnNumber));
			} else {
				tokens.push_back(token(tokenType::integerLiteral, numberString, lineNumber, columnNumber));
			}

			columnNumber += tokenLength;
			goto jump;
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

			// Check for boolean literals
			if (identifierString == "true" || identifierString == "false")
			{
				tokens.push_back(token(tokenType::booleanLiteral, identifierString, lineNumber, columnNumber));
			} else {
				tokens.push_back(token(tokenType::identifier, identifierString, lineNumber, columnNumber));
			}

			columnNumber += tokenLength;
			goto jump;
		}

		// Check for comment
		if (lastChar == '#')
		{
			while (file->get(lastChar) && lastChar != '\n') {}
			goto jump;
		}

		// Check for newline
		if (lastChar == '\n')
		{
			columnNumber = 0;
			lineNumber++;
			continue;
		}

		// Check for semicolon
		if (lastChar == ';')
		{
			tokens.push_back(token(tokenType::semicolon, ";", lineNumber, columnNumber));
			continue;
		}

		// Check for single character tokens
		switch (lastChar)
		{
			case '(':
				tokens.push_back(token(tokenType::openParenthesis, "(", lineNumber, columnNumber));
				break;
			case ')':
				tokens.push_back(token(tokenType::closeParenthesis, ")", lineNumber, columnNumber));
				break;
			case '[':
				tokens.push_back(token(tokenType::openBracket, "[", lineNumber, columnNumber));
				break;
			case ']':
				tokens.push_back(token(tokenType::closeBracket, "]", lineNumber, columnNumber));
				break;
			case '{':
				tokens.push_back(token(tokenType::openBrace, "{", lineNumber, columnNumber));
				break;
			case '}':
				tokens.push_back(token(tokenType::closeBrace, "}", lineNumber, columnNumber));
				break;
			case '+':
				tokens.push_back(token(tokenType::plusSign, "+", lineNumber, columnNumber));
				break;
			case '-':
				tokens.push_back(token(tokenType::minusSign, "-", lineNumber, columnNumber));
				break;
			case '*':
				tokens.push_back(token(tokenType::multiplySign, "*", lineNumber, columnNumber));
				break;
			case '/':
				tokens.push_back(token(tokenType::divideSign, "/", lineNumber, columnNumber));
				break;
			case '%':
				tokens.push_back(token(tokenType::moduloSign, "%", lineNumber, columnNumber));
				break;
		}
	}
}
