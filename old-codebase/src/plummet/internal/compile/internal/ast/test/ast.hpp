#ifndef AST_HPP
#define AST_HPP

#include <string>
#include <vector>
#include <memory>

struct Node {};

enum ExpressionType
{
	/*
	ExpressionType_Unknown,
	ExpressionType_Literal,
	ExpressionType_StringLiteral,
	ExpressionType_IntegerLiteral,
	ExpressionType_BinaryOperation,
	ExpressionType_FunctionCall,
	ExpressionType_Variable,
	*/
};

// Results in a value:
// - Functions
// - Literals
// - Variables
// - Binary operations
struct Expression : public Node
{
	ExpressionType type;
	Expression(ExpressionType type) : type(type) {}
};

struct LiteralExpression : public Expression
{
	LiteralExpression(ExpressionType type) : Expression(type) {}
};

struct StringLiteralExpression : public Expression
{
};

struct IntegerLiteralExpression : public Expression
{
};

// Results in an action:
// - Assignment
// - If
// - While
// - For
struct Statement : public Node
{
};

// TODO: decide if a block can be in another block
struct Block
{
	std::vector<std::unique_ptr<Node>> nodes;
};

struct Function
{
	std::string name;
	std::vector<std::string> parameters;
	Block body;
};

#endif // AST_HPP
