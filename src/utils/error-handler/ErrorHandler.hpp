#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "ColorFormat.hpp"

class ErrorHandler {
	private:
		int errorCount;
		ColorFormat cf;

	public:
		ErrorHandler() : errorCount(0) {}
		void lineError(const std::string&, const std::string&, int, int, const std::string&);
		void fileError(const std::string&, int, int, const std::string&);
		void displayErrorCount();
};

void ErrorHandler::lineError(const std::string& fileName, const std::string& lineContents, int lineNumber, int columnNumber, const std::string& message)
{

	cf.addText(fileName + " line: " + std::to_string(lineNumber) + " col: " + std::to_string(columnNumber));
	cf.setFormat(Style::NORMAL, Color::RED);
	cf.addText(" error: ");
	cf.addText(message + "\n" + lineContents + "\n");
	cf.setFormat(Style::NORMAL, Color::GREEN);
	cf.addText(std::string(columnNumber - 1, '~') + "^\n");
	std::cout << cf << std::endl;
	errorCount++;
}

void ErrorHandler::fileError(const std::string& fileName, int lineNumber, int columnNumber, const std::string& message)
{
	std::ifstream file(fileName);

	std::string lineContents;
	for (int i = 0; i < lineNumber; i++)
	{
		std::getline(file, lineContents);
	}
	file.close();

	lineError(fileName, lineContents, lineNumber, columnNumber, message);
}

void ErrorHandler::displayErrorCount()
{
	if (ErrorHandler::errorCount > 0)
	{
		std::cout << ErrorHandler::errorCount << " error" << (ErrorHandler::errorCount > 1 ? "s" : "") << " generated." << std::endl;
	}
}

#endif // ERRORHANDLER_HPP
