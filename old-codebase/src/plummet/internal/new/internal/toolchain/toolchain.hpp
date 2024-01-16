#ifndef TOOLCHAIN_HPP
#define TOOLCHAIN_HPP

#include "template.hpp"
#include "makefile.hpp"
#include "bash.hpp"

class toolchainHandler {
	public:
		typedef enum {
			MAKEFILE,
			BASH,
		} toolchainType;

		static void createTooling(toolchainType) {
			
		}
};

#endif // TOOLCHAIN_HPP
