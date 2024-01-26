#include "GlobalVariables.hpp"

const std::vector<std::string> GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES = {
    "help",
    "version",
};

const std::vector<std::string> GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_HELP = {
    "Print this help message",
    "Print the version of Plummet",
};

const std::vector<std::string> GlobalVariables::PLUMMET_SUBCOMMAND_NAMES = {
    "compile",
    "explain",
    "new",
    "package",
};

const std::vector<std::string> GlobalVariables::PLUMMET_SUBCOMMAND_HELP = {
    "Compile a file",
    "Explain an error",
    "Create a new project",
    "Manage packages",
};

const std::vector<std::string> GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS = {
    "cat " PLUMMET_ROOT "/src/compile/compile.temp",
    "python3 " PLUMMET_ROOT "/src/explain/explain.py",
    "python3 " PLUMMET_ROOT "/src/new/new.py",
    "python3 " PLUMMET_ROOT "/src/package/package.py",
};

const std::string GlobalVariables::PLUMMET_VERSION_MAJOR = "0";
const std::string GlobalVariables::PLUMMET_VERSION_MINOR = "0";
const std::string GlobalVariables::PLUMMET_VERSION_PATCH = "0";

std::unordered_map<std::string, std::string> GlobalVariables::PLUMMET_SUBCOMMANDS;
std::string GlobalVariables::PLUMMET_EXECUTABLE_NAME;
bool GlobalVariables::PLUMMET_AUTO_COMPLETE;

void GlobalVariables::init(const std::string& executableName, bool autoComplete) {
    // Initialize subcommands map
    for (int i = 0; i < GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size(); i++) {
        GlobalVariables::PLUMMET_SUBCOMMANDS.insert(std::make_pair(
            GlobalVariables::PLUMMET_SUBCOMMAND_NAMES[i],
            GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS[i]
        ));
    }

    // Initialize executable name
    GlobalVariables::PLUMMET_EXECUTABLE_NAME = executableName;

    // Initialize auto complete
    GlobalVariables::PLUMMET_AUTO_COMPLETE = autoComplete;
}
