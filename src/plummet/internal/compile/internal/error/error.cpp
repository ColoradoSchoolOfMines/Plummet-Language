#include <iostream>
#include <fstream>
#include <string>

#include "error.hpp"

void error::lineError(const std::string& fileName, const std::string& lineContents, int lineNumber, int columnNumber, const std::string& message)
{

#ifdef linux
	std::cout << fileName << " line: " << lineNumber << " col: " << columnNumber << " \033[0;31merror:\033[0;0m " << message << std::endl;
#else
	std::cout << fileName << " line: " << lineNumber << " col: " << columnNumber << " error: " << message << std::endl;
#endif

	std::cout << lineContents << std::endl;

#ifdef linux
	std::cout << "\033[0;32m" << std::string(columnNumber - 1, '~') << "^\033[0;0m" << std::endl;
#else
	std::cout << std::string(columnNumber - 1, '~') << "^" << std::endl;
#endif

	std::cout << std::endl;

	error::errorCount++;
}

void error::fileError(const std::string& fileName, int lineNumber, int columnNumber, const std::string& message)
{
	std::ifstream file(fileName);

	std::string lineContents;
	for (int i = 0; i < lineNumber; i++)
	{
		std::getline(file, lineContents);
	}
	file.close();

	error::lineError(fileName, lineContents, lineNumber, columnNumber, message);
}

void error::displayErrorCount()
{
	if (error::errorCount > 0)
	{
		std::cout << error::errorCount << " error" << (error::errorCount > 1 ? "s" : "") << " generated." << std::endl;
	}
}
