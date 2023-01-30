#include "lexer.hpp"
#include "token.hpp"

int main()
{
	lexer lex("test.txt");
	lex.lexFile();
	for (token t: lex.getTokens())
	{
		t.prettyPrint();
	}
	return 0;
}
