flags = -g -std=c++17
llvm-config = `llvm-config --cxxflags --ldflags --system-libs --libs all`

.Phony: compile clean

compile_program:
	clang++ $(flags) $(llvm-config) plummet.cpp -o plummetc
	./plummetc main > main.ll
	rm plummetc
	clang ./addNums.c -c -o addNums.o
	clang++ ./readInt.cpp -c -o readInt.o
	rustc ./printInt.rs --emit=obj -o printInt.o
	clang++ main.ll addNums.o readInt.o printInt.o -o program

ir_program:
	clang++ $(flags) $(llvm-config) plummet.cpp -o plummetc
	./plummetc main > main.ll
	rm plummetc
	clang ./addNums.c -S -emit-llvm -o addNums.ll
	clang++ ./readInt.cpp -S -emit-llvm -o readInt.ll
	rustc ./printInt.rs --emit=llvm-ir -o printInt.ll
