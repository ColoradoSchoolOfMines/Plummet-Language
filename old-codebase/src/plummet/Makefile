llvm-config = `llvm-config --cxxflags --ldflags --system-libs --libs core`

temp:
	clang++ `llvm-config --cxxflags --ldflags --system-libs --libs core` main.cpp error/error.cpp -I./error/ lexer/lexer.cpp -I./lexer/ token/token.cpp -I./token/
