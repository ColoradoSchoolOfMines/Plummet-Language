#include "TestSuite.hpp"

int main() {

	// test for no setup or before functions

	TestSuite ts0("Testing TestSuite - No Setup");

	ts0.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts0.addTest("Add New Test (Fail)", []() {
		return false;
	});

	ts0.runTests();

	// test normal operation

	TestSuite ts1("Testing TestSuite - Normal Operation");

	ts1.beforeAll([]() {
			std::cout << "Before All" << std::endl;
			return true;
	});

	ts1.beforeEach([]() {
			std::cout << "Before Each" << std::endl;
			return true;
	});

	ts1.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts1.addTest("Add New Test (Fail)", []() {
		return false;
	});

	ts1.runTests();

	// test for a broken beforeEach

	TestSuite ts2("Testing TestSuite - Broken beforeEach");

	ts2.beforeEach([]() {
			std::cout << "Before Each" << std::endl;

			// trigger a failure on the first call
			static int errorCountDown = 1;
			if (errorCountDown-- > 0) {
				return false;
			}

			return true;
	});

	ts2.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts2.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts2.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts2.runTests();

	// test for a broken beforeAll

	TestSuite ts3("Testing TestSuite - Broken beforeAll");

	ts3.beforeAll([]() {
			std::cout << "Before All" << std::endl;
			return false;
	});

	ts3.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts3.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts3.addTest("Add New Test (Pass)", []() {
		return true;
	});

	ts3.runTests();

	std::cout << "If you got to this point, all tests have passed\n";

	return 0;
}
