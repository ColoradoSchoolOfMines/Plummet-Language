#include <iostream>

#include "ColorFormat.hpp"

int main() {
	ColorFormat cf;
	cf.setFormat(Style::BOLD, Color::GREEN);
	cf.addText("Hello, ");
	cf.setFormat(Style::ITALIC, Color::RED);
	cf.addText("World!");
	std::cout << cf << std::endl;
}
