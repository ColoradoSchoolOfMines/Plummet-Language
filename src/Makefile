flags = -g -Wall -Wextra -Werror -std=c++17
clang_flags =

.Phony: compile clean

compile:
	@clang++ $(flags) $(clang_flags) *.cpp -o plummetc

clean:
	@[ -f plummetc ] && rm plummetc || true
