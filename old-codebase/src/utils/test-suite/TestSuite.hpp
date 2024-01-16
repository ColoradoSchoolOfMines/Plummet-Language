#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include <functional>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

#include "ColorFormat.hpp"

class TestSuite {
	private:
		std::vector<std::pair<std::string, std::function<bool()>>> tests;
		std::function<bool()> setup, before;
		std::string suiteName;
		ColorFormat cf;

	public:
		TestSuite( std::string suiteName) : suiteName(suiteName) {
			setup = []() { return true; };
			before = []() { return true; };
		}

		void beforeAll(std::function<bool()> setupFunction) {
			this->setup = setupFunction;
		}

		void beforeEach(std::function<bool()> beforeFunction) {
			this->before = beforeFunction;
		}

		void addTest(std::string testName, std::function<bool()> test) {
			tests.push_back(std::make_pair(testName, test));
		}

		void runTests() {
			cf.setFormat(Style::BOLD);
			cf.setFormat(Style::UNDERLINE);
			cf.addText("Test Suite: " + suiteName);
			std::cout << cf << "\n";

			if (!setup()) {
				cf.setFormat(Style::BOLD, Color::RED);
				cf.addText("Before All Failed");
				cf.setFormat(Style::NORMAL);
				cf.addText(" - ");
				cf.setFormat(Style::ITALIC);
				cf.setFormat(Style::UNDERLINE, Color::YELLOW);
				cf.addText("ALL TESTS SKIPPED");
				std::cout << cf << "\n\n\n";
				return;
			}

			size_t numPassed = 0;
			for (auto test : tests) {
				if (!before()) {
					cf.setFormat(Style::BOLD, Color::RED);
					cf.addText("Before Each Failed");
					std::cout << cf << " - Test: " << test.first << " ... ";
					cf.setFormat(Style::ITALIC);
					cf.setFormat(Style::UNDERLINE, Color::YELLOW);
					cf.addText("SKIPPED");
					std::cout << cf << "\n";
					continue;
				}

				if (test.second()) {
					cf.setFormat(Style::ITALIC);
					cf.setFormat(Style::UNDERLINE, Color::GREEN);
					cf.addText("PASSED");
					std::cout << "Test: " << test.first << " ... " << cf << "\n";
					numPassed++;
				} else {
					cf.setFormat(Style::ITALIC);
					cf.setFormat(Style::UNDERLINE, Color::RED);
					cf.addText("FAILED");
					std::cout << "Test: " << test.first << " ... " << cf << "\n";
				}
			}

			std::cout << numPassed << "/" << tests.size() << " passed\n\n\n";
		}
};

#endif // TESTSUITE_HPP
