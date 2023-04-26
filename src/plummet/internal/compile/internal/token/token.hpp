#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstddef>
#include <string>
#include <map>

/* Example Plummet Program

class calculator {
	@[public, static]
	int add := function(int[] args) {
		int sum := 0;
		for (int i := 0; i < args.length; i++) { sum += args[i]; }
		return sum;
	};

	@[public, static]
	int subtract := function(int[] args) {
		int quotient := args[0];
		for (int i := 1; i < args.length; i++) { quotient -= args[i]; }
		return quotient;
	};
};

void main := function(string[] args) {
	int[] numbers := [1, 2, 3, 4, 5];
	int sum := calculator.add(numbers);
	int quotient := calculator.subtract(numbers);
	print("Sum: " + sum);
	print("Quotient: " + quotient);
};

*/

enum tokenType
{
	// Literals
	booleanLiteral,
	integerLiteral,
	doubleLiteral,
	stringLiteral,

	// Other
	identifier, // variable name, function name, etc.
	modifier,   // @ (used to modify a function withing a class)

	// Symbols
	openParenthesis,  // ( (used to start a function parameter list)
	closeParenthesis, // ) (used to end a function parameter list)
	openBracket,      // [ (used to start an array or index an array)
	closeBracket,     // ] (used to end an array or index an array)
	openBrace,        // { (used to start a function, class, scope, etc.)
	closeBrace,       // } (used to end a function, class, scope, etc.)
	vbar,             // | (used to enclose a generic type)

	// Math operators
	plusSign,     // + (addition)
	minusSign,    // - (subtraction)
	multiplySign, // * (multiplication)
	divideSign,   // / (division)
	moduloSign,   // % (modulus)

	// Advanced math operators
	plusPlusSign,     // ++ (increment)
	minusMinusSign,   // -- (decrement)
	plusEqualSign,    // += (addition assignment)
	minusEqualSign,   // -= (subtraction assignment)
	multiplyEqualSign,// *= (multiplication assignment)
	divideEqualSign,  // /= (division assignment)
	moduloEqualSign,  // %= (modulus assignment)

	// Assignment operators
	equalSign, // := (used to assign a value to a variable)

	// Comparison operators
	equalEqualSign,   // == (equal to)
	notEqualSign,     // != (not equal to)
	greaterThanSign,  // >  (greater than)
	greaterEqualSign, // >= (greater than or equal to)
	lessThanSign,     // <  (less than)
	lessEqualSign,    // <= (less than or equal to)

	// Logical operators
	andSign, // && (and)
	orSign,  // || (or)
	notSign, // !  (not)

	// Other operators
	questionMark, // ? (used in ternary operator)
	semicolon,    // ; (used to end statements)
	colon,        // : (used in ternary operator)
	comma,        // , (used to separate arguments)
	dot,          // . (used to access public interface of a class)

	// Pointer operators ** (can only be used in unsafe mode) **
	derefSign, // ^ (dereference)
	refSign,   // & (reference)

	// Special Optimization Token (used later, DO NOT USE IN LEXER)
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
