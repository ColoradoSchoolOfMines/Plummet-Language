#define PLUMMET_MAIN

#include <vector>
#include <string>

class argumentParser {
	private:
		typedef enum {
			_compile, // compile all mentioned files
			_explain, // explain the provided error code
			_get,     // download a library using provided url
			_help,    // display help (optional: pass a subcommand)
			_new,     // create a new project using cli setup menu
				  // or given project config.toml file
			_version  // display version information
		} plummetSubCommand;

	public:
		static std::vector<std::string> parseArguments(int argc, char **argv) {
			return std::vector<std::string>();
		}
};
