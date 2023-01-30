llvm-config = `llvm-config --cxxflags --ldflags --system-libs --libs core`

executable = plummet
flags = -std=c++17 -I ./compiler -I ./driver -I ./package_manager -o $(executable)
release =  -O3 -Wall -Wextra -Werror
debug =  -g -O0

driver-src = ./driver/*.cpp
package-manager-src = ./package_manager/*.cpp
compiler-src = ./compiler/*.cpp

.PHONY: compile-release compile-debug clean

compile-release:
	clang++ $(llvm-config) $(release) $(package-manager-src) $(compiler-src) $(driver-src) $(flags)-release

compile-debug:
	clang++ $(llvm-config) $(debug) $(package-manager-src) $(compiler-src) $(driver-src) $(flags)-debug

clean:
	[ -f $(executable)-release ] && rm $(executable)-release -i || true
	[ -f $(executable)-debug ] && rm $(executable)-debug -i || true
