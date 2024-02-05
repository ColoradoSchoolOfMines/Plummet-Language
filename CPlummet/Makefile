generate_std_lib:
	@for file in *.h; do \
		echo \#include \"$$file\"; \
	done

build:
	clang *.c -O0 -g
