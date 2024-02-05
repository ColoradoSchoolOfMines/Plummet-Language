#include "helpCommand.hpp"

// TODO: Refactor this to not need parameters to be passed in
void helpCommand::print() {
    std::cout
    << "Usage: "
    << GlobalVariables::PLUMMET_EXECUTABLE_NAME
    << " <built in | subcommand> [flags]"
    << std::endl;

    // get longest subcommand name

    size_t longestSubcommandName = 8;

    // for (size_t i = 0; i < GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES.size(); i++) {
    //     if (GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES[i].size() > longestSubcommandName) {
    //         longestSubcommandName = GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES[i].size();
    //     }
    // }

    // for (size_t i = 0; i < GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size(); i++) {
    //     if (GlobalVariables::PLUMMET_SUBCOMMAND_NAMES[i].size() > longestSubcommandName) {
    //         longestSubcommandName = GlobalVariables::PLUMMET_SUBCOMMAND_NAMES[i].size();
    //     }
    // }

    std::cout << "Built in subcommands:" << std::endl;

    for (size_t i = 0; i < GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES.size(); i++) {
        std::cout
        << "    "
        << std::left
        << std::setw(longestSubcommandName)
        << std::setfill(' ')
        // << "    "
        << GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_NAMES[i]
        << " - "
        << GlobalVariables::PLUMMET_BUILTIN_SUBCOMMAND_HELP[i]
        << std::endl;
    }

    std::cout << "Subcommands:" << std::endl;
    
    for (size_t i = 0; i < GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size(); i++) {
        std::cout
        << "    "
        << std::left
        << std::setw(longestSubcommandName)
        << std::setfill(' ')
        << GlobalVariables::PLUMMET_SUBCOMMAND_NAMES[i]
        << " - "
        << GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS[i]
        << std::endl;
    }
}
