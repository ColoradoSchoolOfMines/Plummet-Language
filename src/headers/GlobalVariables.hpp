#ifndef GLOBALVARIABLES_HPP
#define GLOBALVARIABLES_HPP

// NOTE: Define PLUMMET_ROOT for the project; if it is defined manually, it will
//       not be defined using this procedure

// TODO: Find a better way to do this

/* NOTE TO SELF
 * you MUST define all static variables in the .cpp file, otherwise you will get
 * a linker error.
*/

#ifndef PLUMMET_ROOT
    #ifdef __linux__
        // NOTE: symlink to /usr/local/bin/plummet at install time
        #define PLUMMET_ROOT "/opt/plummet"
    #elif defined(_WIN32) || defined(WIN32)
        #define PLUMMET_ROOT "C:\\Program Files\\Plummet"
    #else // Not linux or windows
        #error "Unsupported platform"
    #endif // __linux__
#endif // PLUMMET_ROOT

#include <unordered_map>
#include <utility>
#include <string>
#include <vector>

struct GlobalVariables {
    static const std::vector<std::string> PLUMMET_BUILTIN_SUBCOMMAND_NAMES;
    static const std::vector<std::string> PLUMMET_BUILTIN_SUBCOMMAND_HELP;

    static const std::vector<std::string> PLUMMET_SUBCOMMAND_NAMES;
    static const std::vector<std::string> PLUMMET_SUBCOMMAND_HELP;
    static const std::vector<std::string> PLUMMET_SUBCOMMAND_COMMANDS;

    static const std::string PLUMMET_VERSION_MAJOR;
    static const std::string PLUMMET_VERSION_MINOR;
    static const std::string PLUMMET_VERSION_PATCH;

    static std::unordered_map<std::string, std::string> PLUMMET_SUBCOMMANDS;
    static std::string PLUMMET_EXECUTABLE_NAME;
    static bool PLUMMET_AUTO_COMPLETE;

    static void init(const std::string& executableName, bool autoComplete);

};

#endif // GLOBALVARIABLES_HPP
