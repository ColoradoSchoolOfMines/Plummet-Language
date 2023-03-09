#ifndef TOML_HPP
#define TOML_HPP

#include <vector>
#include <string>
#include <unordered_map>

#include "lexer.hpp"
#include "token.hpp"
#include "error.hpp"

class tomlParser {
	private:
		enum tomlTypes {
			_STRING,
			_BOOLEAN,
			_ARRAY, // always a string array
		};

		struct tomlLiteral {
			std::vector<std::string> values;
			tomlTypes type;
			tomlLiteral(std::vector<std::string> values, tomlTypes type) : values(values), type(type) {}
		};

		struct tomlVariable {
			std::string name;
			tomlLiteral value;
			tomlVariable(std::string name, tomlLiteral value) : name(name), value(value) {}
		};

		struct tomlFile {
			std::unordered_map<std::string, std::vector<tomlVariable>> tables = {
				{ "project",
					std::vector<tomlVariable>() = {
						tomlVariable("name", tomlLiteral(std::vector<std::string>() = { "test" }, _STRING)),
					} },
			};
		};

	public:
		/*
		std::vector<token> parseTomlFile(const std::string& filePath) {
			lexer lex(filePath);
			lex.lexFile();
			return lex.getTokens();
		}
		*/
};

#endif // TOML_HPP
