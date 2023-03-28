#ifndef COLORS_HPP
#define COLORS_HPP

#include <sstream>
#include <string>

enum Style {
	NORMAL = 0,
	BOLD = 1,
	LIGHT = 2,
	ITALIC = 3,
	UNDERLINE = 4
};

enum Color {
	NONE = 0,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	PURPLE = 35,
	CYAN = 36,
	WHITE = 37
};

class ColorFormat {
	private:
		std::stringstream ss;
	
	public:
		ColorFormat() {
#ifdef linux
			ss << "\033[0m";
#endif
		}

		// Colors are only supported on linux
		void setFormat(Style style, Color color = Color::NONE) {
#ifdef linux
			if (color == Color::NONE) {
				ss << "\033[" << style << "m";
			} else {
				ss << "\033[" << style << ";" << color << "m";
			}
#endif
		}

		void addText(std::string text) {
			ss << text;
#ifdef linux
			ss << "\033[0m";
#endif
		}

		std::string getFormattedText() {
			std::string temp = ss.str();
			ss.str(std::string());
#ifdef linux
			ss << "\033[0m";
#endif
			return temp;
		}
};

std::ostream &operator<<(std::ostream &os, ColorFormat &cf) {
	os << cf.getFormattedText();
	return os;
}

#endif // COLORS_HPP
