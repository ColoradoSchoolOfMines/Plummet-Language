# TODO: make sure this works on windows eventually or make a separate makefile for windows

COMPILER = clang++
HEADERS = $(wildcard src/headers/*.cpp)
OUTPUT = plummet
DEV_FLAGS = -DPLUMMET_ROOT=\"$$PWD\"
FLAGS = -Isrc/headers

PYTHON = python3
TEST_NUMBER =

help:
	@echo "Usage: make [target]"
	@echo "  make help       - Show this help message"
	@echo "  make clean_diff - Clean the test diffs"
	@echo "  make clean      - Clean the build"
	@echo "  make build_dev  - Build the development version"
	@echo "  make build      - Build the production version"
	@echo "  make test       - Run the prod test suite   - Optional: TEST_NUMBER=<number>"
	@echo "  make install    - Install the application   - Required: RUN WITH ROOT"
	@echo "  make uninstall  - Uninstall the application - Required: RUN WITH ROOT"

clean_diff:
	@if [ -f tests/diffs/*.txt ]; then \
		echo "Removing tests/diffs/*.txt"; \
		rm tests/diffs/*.txt; \
	else \
		echo "tests/diffs/*.txt does not exist"; \
	fi

clean: clean_diff
	@if [ -f $(OUTPUT) ]; then \
		echo "Removing $(OUTPUT)"; \
		rm $(OUTPUT); \
	else \
		echo "$(OUTPUT) does not exist"; \
	fi

	@if [ -f $(OUTPUT)_dev ]; then \
		echo "Removing $(OUTPUT)_dev"; \
		rm $(OUTPUT)_dev; \
	else \
		echo "$(OUTPUT)_dev does not exist"; \
	fi

build_dev: clean
	$(COMPILER) src/main.cpp $(HEADERS) $(FLAGS) $(DEV_FLAGS) -o $(OUTPUT)_dev

build: clean
	$(COMPILER) src/main.cpp $(HEADERS) $(FLAGS) -o $(OUTPUT)

test: build_dev
	@$(PYTHON) tests/run_tests.py $(TEST_NUMBER)

check_root:
	@echo "Checking if root..."
	@if [ `id -u` -ne 0 ]; then \
		echo "Please run this target as root"; \
		exit 1; \
	fi
	@echo "Root check passed!"

install: check_root build
	@if [ ! -d /opt/plummet/ ]; then \
		mkdir /opt/plummet/; \
	else \
		echo "/opt/plummet/ already exists. Please follow update instructions in the README.md"; \
		exit 1; \
	fi
	@cp -r . /opt/plummet/
	@cd /opt/plummet/ && make build
	@ln -s /opt/plummet/$(OUTPUT) /usr/local/bin/
	@echo "Install Complete!"

uninstall: check_root
	@if [ ! -d /opt/plummet/ ]; then \
		echo "/opt/plummet/ does not exist. Please check /opt/ to further diagnose"; \
		exit 1; \
	fi
	@rm -r /opt/plummet/
	@if [ ! -f /usr/local/bin/$(OUTPUT) ]; then \
		echo "/usr/local/bin/$(OUTPUT) does not exist. Please check /usr/local/bin/plummet to further diagnose"; \
		exit 1; \
	fi
	@rm /usr/local/bin/$(OUTPUT)
	@echo "Uninstall Complete!"