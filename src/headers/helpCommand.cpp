#include "helpCommand.hpp"

// TODO: Refactor this to not need parameters to be passed in
void helpCommand::print() {
    std::cout
    << "Usage: "
    << GlobalVariables::PLUMMET_EXECUTABLE_NAME
    << " <built in | subcommand> [flags]"
    << std::endl;

    std::cout << "Built in subcommands:" << std::endl;

    for (int i = 0; i < GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES.size(); i++) {
        std::cout
        << "    "
        << GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES[i]
        << " - "
        << GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_HELP[i]
        << std::endl;
    }

    std::cout << "Subcommands:" << std::endl;
    
    for (int i = 0; i < GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size(); i++) {
        std::cout
        << "    "
        << GlobalVariables::PLUMMET_SUBCOMMAND_NAMES[i]
        << " - "
        << GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS[i]
        << std::endl;
    }
}
