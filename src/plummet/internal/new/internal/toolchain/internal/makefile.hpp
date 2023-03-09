#ifndef MAKEFILE_HPP
#define MAKEFILE_HPP

#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>

// using valueMap = std::unordered_map<std::string, std::vector<std::string>>;
#include "value-map.hpp"
#include "template.hpp"

class Makefile : public toolchainTemplate {
	private:
		std::string createFinalString(valueMap parameters) {
			std::stringstream result;
			result << "all: " << std::endl;
			result << "\t" << parameters["compiler"][0] << " ";
			for (std::string s: parameters["include"]) {
				result << parameters["src"][0] << s << " ";
			}
			return result.str();
		}
};

#endif // MAKEFILE_HPP
