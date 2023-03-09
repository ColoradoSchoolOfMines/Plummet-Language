#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>

struct error {
	int errorCount = 0;
	void lineError(const std::string&, const std::string&, int, int, const std::string&);
	void fileError(const std::string&, int, int, const std::string&);
	void displayErrorCount();
};

#endif // ERROR_HPP
