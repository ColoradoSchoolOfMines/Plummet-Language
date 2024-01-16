make_main:
	clang++ `llvm-config --cxxflags --ldflags --system-libs --libs core` main.cpp
	./a.out > main.ll

all:
	clang++ `llvm-config --cxxflags --ldflags --system-libs --libs core` main.cpp
	./a.out > main.ll
	clang ./getString.c -S -emit-llvm -o getString.ll
	clang ./printString.c -S -emit-llvm -o printString.ll
	clang main.ll getString.ll printString.ll
	test -f main.ll && rm main.ll
	test -f getString.ll && rm getString.ll
	test -f printString.ll && rm printString.ll
