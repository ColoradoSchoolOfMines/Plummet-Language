llvm-config = `llvm-config --cxxflags --ldflags --system-libs --libs core`

executable = plummet
flags = -I./compiler/ -I./driver/ -I./package_manager/ -o $(executable)
release = -O3 -Wall -Wextra -Werror
debug = -O0 -g

package-manager-src = ./package_manager/*.cpp
compiler-src = ./compiler/*.cpp
driver-src = ./driver/*.cpp

#
# Phony Targets
#

.PHONY: compile-release compile-debug compile-compiler compile-package-manager clean

#
# Full Program Compile
#

compile-full-release:
	clang++ $(llvm-config) $(release) $(package-manager-src) \
		$(compiler-src) $(driver-src) $(flags)-release

compile-full-debug:
	clang++ $(llvm-config) $(debug) $(package-manager-src) \
		$(compiler-src) $(driver-src) $(flags)-debug

#
# Compile Compiler Only (use test.cpp as driver code)
#

compile-compiler-debug:
	clang++ $(llvm-config) $(debug) $(compiler-src) $(flags)-compiler

#
# Compile Package Manager Only (use test.cpp as driver code)
#

compile-package-manager-debug:
	clang++ $(debug) $(package-manager-src) $(flags)-package_manager

#
# Helper Commands
#

clean:
	[ -f $(executable)-package_manager ] && rm $(executable)-package_manager -i || true
	[ -f $(executable)-compiler ] && rm $(executable)-compiler -i || true
	[ -f $(executable)-release ] && rm $(executable)-release -i || true
	[ -f $(executable)-debug ] && rm $(executable)-debug -i || true
