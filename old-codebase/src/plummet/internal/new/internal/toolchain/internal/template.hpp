#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <unordered_map>
#include <string>
#include <vector>

// using valueMap = std::unordered_map<std::string, std::vector<std::string>;
#include "value-map.hpp"

// Abstract class for toolchain templates
class toolchainTemplate {
	private:
		valueMap defaultValues = {
			{ "name", { "myproject" } },
			{ "build", { "./" } },
			{ "src", { "./" } },
			{ "include", { "*.plmt" } },
			{ "compiler", { "/bin/clang++" } },
		};

		valueMap getFinalValues(valueMap customValues) {
			valueMap result = this->defaultValues;

			for (auto a: customValues) {
				result[a.first] = a.second;
			}

			return result;
		}

		virtual std::string createFinalString(valueMap) = 0;

	public:
		std::string getTemplate(valueMap parameters = {}) {
			return createFinalString(getFinalValues(parameters));
		}
};

#endif // TEMPLATE_HPP
