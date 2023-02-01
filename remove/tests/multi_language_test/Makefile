flags = -g -std=c++17

.Phony: compile clean

compile:
	clang++ $(flags) `llvm-config --cxxflags --ldflags --system-libs --libs all` plummet.cpp -o plummetc

clean:
	[ -f plummetc ] && rm plummetc -i || true
	[ -f a.out ] && rm a.out -i || true
	[ -f *.ll ] && rm *.ll -i || true
	[ -f *.o ] && rm *.o -i || true
