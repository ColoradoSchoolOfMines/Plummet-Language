#include <iostream>
#include <string>

#include "ast.hpp"

/*
 * Integer Literal Abstract Syntax Tree
 */

intAst::intAst(int data)
	: data(data) {}

void intAst::prettyPrint()
{
	std::cout << "intAst: [data: " << data << "]" << std::endl;
}

/*
 * Variable Abstract Syntax Tree
 */

variableAst::variableAst(const std::string& id)
	: id(id) {}

void variableAst::prettyPrint()
{
	std::cout << "variableAst: [id: " << id << "]" << std::endl;
}
