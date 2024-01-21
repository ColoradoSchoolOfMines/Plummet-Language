# TODO: add test target
# TODO: make sure this works on windows eventually or make a separate makefile for windows
# TODO: symlink /opt/plummet to /usr/local/bin/plummet instead of copying the file
# TODO: figure out if each subprogram should be seperately compiled or not

help:
	@echo "Usage:"
	@echo "  make build_dev  - Build the development version"
	@echo "  make build      - Build the production version"
	@echo "  make clean      - Clean the build"
	@echo "  make install    - Install the application [root required]"
	@echo "  make uninstall  - Uninstall the application [root required]"
	@echo "  make help       - Show this help message"

build_dev:
	clang++ src/main.cpp -Isrc/headers -DPLUMMET_ROOT=\"$$PWD\" -o plummet_dev

build:
	clang++ src/main.cpp -Isrc/headers -o plummet

clean:
	@if [ -f plummet ]; then \
		rm plummet; \
	else \
		echo "plummet does not exist"; \
	fi

	@if [ -f plummet_dev ]; then \
		rm plummet_dev; \
	else \
		echo "plummet_dev does not exist"; \
	fi

check_root:
	@if [ `id -u` -ne 0 ]; then \
		echo "Please run this target as root"; \
		exit 1; \
	fi

install: check_root build
	cp plummet /usr/local/bin/plummet

uninstall: check_root
	@if [ ! -f /usr/local/bin/plummet ]; then \
		echo "plummet is not installed"; \
		exit 1; \
	fi

	rm /usr/local/bin/plummet
