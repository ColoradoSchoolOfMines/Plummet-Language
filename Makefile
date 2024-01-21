# TODO: add test target
# TODO: make sure this works on windows eventually or make a separate makefile for windows
# TODO: symlink /opt/plummet to /usr/local/bin/plummet instead of copying the file
# TODO: figure out if each subprogram should be seperately compiled or not

COMPILER = clang++
HEADERS = $(wildcard src/headers/*.cpp)
OUTPUT = plummet
DEV_FLAGS = -DPLUMMET_ROOT=\"$$PWD\"
FLAGS = -Isrc/headers

help:
	@echo "Usage:"
	@echo "  make build_dev  - Build the development version"
	@echo "  make build      - Build the production version"
	@echo "  make clean      - Clean the build"
	@echo "  make install    - Install the application [root required]"
	@echo "  make uninstall  - Uninstall the application [root required]"
	@echo "  make help       - Show this help message"

build_dev:
	$(COMPILER) src/main.cpp $(HEADERS) $(FLAGS) $(DEV_FLAGS) -o $(OUTPUT)_dev

build:
	$(COMPILER) src/main.cpp $(HEADERS) $(FLAGS) -o $(OUTPUT)

clean:
	@if [ -f $(OUTPUT) ]; then \
		rm $(OUTPUT); \
	else \
		echo "$(OUTPUT) does not exist"; \
	fi

	@if [ -f $(OUTPUT)_dev ]; then \
		rm $(OUTPUT)_dev; \
	else \
		echo "$(OUTPUT)_dev does not exist"; \
	fi

check_root:
	@echo "Checking if root..."
	@if [ `id -u` -ne 0 ]; then \
		echo "Please run this target as root"; \
		exit 1; \
	fi

install: check_root build
	cp $(OUTPUT) /usr/local/bin/$(OUTPUT)

uninstall: check_root
	@if [ ! -f /usr/local/bin/$(OUTPUT) ]; then \
		echo "$(OUTPUT) is not installed"; \
		exit 1; \
	fi

	rm /usr/local/bin/$(OUTPUT)
