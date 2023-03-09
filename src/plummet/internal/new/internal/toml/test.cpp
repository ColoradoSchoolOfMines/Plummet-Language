#ifndef PLUMMET_MAIN

#include <iostream>

#include "toml.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <toml-file>" << std::endl;
		return 1;
	}

	tomlParser parser;
	for (token tok: parser.parseTomlFile(argv[1])) {
		tok.prettyPrint();
	}
}

#endif // PLUMMET_MAIN
