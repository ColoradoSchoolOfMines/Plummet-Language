#ifndef AST_HPP
#define AST_HPP

#include <string>

class ast
{
	public:
		virtual ~ast() {}
		virtual void prettyPrint() = 0;
};

class intAst : public ast
{
	int data;

	public:
		intAst(int);
		void prettyPrint();
};

class variableAst : public ast
{
	std::string id;

	public:
		variableAst(const std::string&);
		void prettyPrint();
};

#endif // AST_HPP
