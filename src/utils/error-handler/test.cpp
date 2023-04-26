#include "ErrorHandler.hpp"

int main() {
	ErrorHandler eh;
	eh.fileError("test.cpp", 5, 37, "test file error");
	eh.lineError("notReal.plmt", "Not the actual file contents", 20, 5, "test line error");
	eh.displayErrorCount();
}
