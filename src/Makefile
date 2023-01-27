flags = -g -std=c++17

.Phony: compile clean

compile:
	clang++ $(flags) `llvm-config --cxxflags --ldflags --system-libs --libs all` main.cpp -o plummetc

clean:
	[ -f plummetc ] && rm plummetc || true
