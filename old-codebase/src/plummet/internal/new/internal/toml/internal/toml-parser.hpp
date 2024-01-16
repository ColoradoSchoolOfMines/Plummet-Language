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

		static struct {
			std::unordered_map<std::string, std::vector<tomlVariable>> tables = {
				{ "project",
					std::vector<tomlVariable>() = {
						tomlVariable("name", tomlLiteral(std::vector<std::string>() = { "test" }, _STRING)),
					} },
			};
		} tomlFile;

	public:
		/*
		std::vector<token> parseTomlFile(const std::string& filePath) {
			lexer lex(filePath);
			lex.lexFile();
			return lex.getTokens();
		}
		*/

		void prettyPrint() {
			for (auto& table : tomlFile.tables) {
				std::cout << "[" << table.first << "]" << std::endl;
				for (auto& variable : table.second) {
					std::cout << variable.name << " = ";
					for (auto& value : variable.value.values) {
						std::cout << value << " ";
					}
					std::cout << std::endl;
				}
			}
		}
};

#endif // TOML_HPP
