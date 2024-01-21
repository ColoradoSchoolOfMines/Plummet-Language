#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "jaro.hpp"
#include "Result.hpp"
#include "helpCommand.hpp"
#include "GlobalVariables.hpp"

void versionCommand() {
    std::cout
    << "Plummet version: "
    << GlobalVariables::PLUMMET_VERSION_MAJOR
    << "."
    << GlobalVariables::PLUMMET_VERSION_MINOR
    << "."
    << GlobalVariables::PLUMMET_VERSION_PATCH
    << std::endl;
}

// NOTE: if return code is 4, the program recieved incorrect flags
Result<int> executeSubcommand(std::string subcommand, std::string args) {
    int returnCode = system((subcommand + " " + args).c_str());

    // NOTE: get top 8 bits of return code to convert into int this usually is
    //       done with sys/wait.h -- WEXITSTATUS
    returnCode = returnCode >> 8;

    return Result<int>{returnCode, returnCode == 0};
}

// TODO: Make this check for multiple subcommands if there exists two sub
//       commands equadistant from the unrecognized subcommand
Result<std::string> findClosestSubcommand(
    std::vector<std::string> subcommandNames,
    const std::string& unrecognizedSubcommand
) {
    // Add builtin commands to the possible subcommand names

    subcommandNames.push_back("help");
    subcommandNames.push_back("version");

    // Find the closest subcommand(s) to the unrecognized subcommand

    std::string closestSubcommand;
    double closestDistance = 0.0;
    for (const std::string& subcommandName : subcommandNames) {
        double distance = jaro::distance(unrecognizedSubcommand, subcommandName);
        if (distance > closestDistance) {
            closestSubcommand = subcommandName;
            closestDistance = distance;
        }
    }

    // If there is a direct match, return match and true

    if (closestDistance == 1.0) {
        return Result<std::string>{closestSubcommand, true};
    }

    // See if the user meant to type the closest subcommand

    std::cout << "Did you mean " << closestSubcommand << "? [y/N] ";
    std::string mistake;
    std::getline(std::cin, mistake);

    return Result<std::string>{
        closestSubcommand,
        mistake == "y" || mistake == "Y"
    };
}

int main(int argc, char** argv) {

    // Initialize global variables

    GlobalVariables::init(argv[0]);

    // Ensure subcommands vectors are the same size

    if (GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size() != GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS.size()) {
        std::cout
        << "subcommandNames.size(): "
        << GlobalVariables::PLUMMET_SUBCOMMAND_NAMES.size()
        << "\n"
        << "subcommandCommands.size(): "
        << GlobalVariables::PLUMMET_SUBCOMMAND_COMMANDS.size()
        << std::endl;
        
        throw std::runtime_error(
            "subcommandNames and subcommandCommands must be the same size"
        );
    }

    // Parse command line arguments

    std::vector<std::string> args(argv, argv + argc);

    if (args.size() < 2) {
        std::cout << "Error: No subcommand provided" << std::endl;
        helpCommand::print();
        return 1;
    }

    // TODO: check if flags format is correct

    std::string subcommand = args[1];

    Result<std::string> subcommandResult = findClosestSubcommand(
        GlobalVariables::PLUMMET_SUBCOMMAND_NAMES,
        subcommand
    );

    if (!subcommandResult.success) {
        helpCommand::print();
        return 1;
    }

    subcommand = subcommandResult.unwrap("Unknown subcommand: " + subcommand);

    // Handle built in subcommands

    // TODO: make builtin commands easier to scale as the project gets bigger
    //       to do this use a map and pass it around
    if (subcommand == "help") {
        helpCommand::print();
        return 0;
    }

    if (subcommand == "version") {
        versionCommand();
        return 0;
    }

    // Construct subcommand arguments into an easy to parse string

    std::stringstream ss;
    for (std::string s: std::vector<std::string>(args.begin() + 2, args.end())) {
        ss << s << " ";
    }

    Result<int> result = executeSubcommand(
        GlobalVariables::PLUMMET_SUBCOMMANDS[subcommand],
        ss.str()
    );

    if (result.value == 4) {
        std::cout << "Subcommand failed due to: Incorrect Flags" << std::endl;
        return 1;
    }

    if (result.value == 5) {
        std::cout << "Subcommand failed due to: Undefined Behavior" << std::endl;
        return 1;
    }

    result.unwrap("Subcommand failed with exit code: " + std::to_string(result.value));

    return 0;
}
