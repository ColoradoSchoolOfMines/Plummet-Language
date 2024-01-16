#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "jaro.hpp"

#define PLUMMET_VERSION_MAJOR 0
#define PLUMMET_VERSION_MINOR 0
#define PLUMMET_VERSION_PATCH 0

void versionCommand() {
    std::cout
    << "Plummet version: "
    << PLUMMET_VERSION_MAJOR
    << "."
    << PLUMMET_VERSION_MINOR
    << "."
    << PLUMMET_VERSION_PATCH
    << std::endl;
}

// Refactor this to not need parameters to be passed in
void helpCommand(
    const std::string& programName,
    const std::vector<std::string>& subcommandNames,
    const std::vector<std::string>& subcommandHelp
) {
    std::cout
    << "Usage: "
    << programName
    << " <subcommand> [flags]"
    << std::endl;
    
    std::cout << "Subcommands:" << std::endl;
    
    for (int i = 0; i < subcommandNames.size(); i++) {
        std::cout
        << "    "
        << subcommandNames[i]
        << " - "
        << subcommandHelp[i]
        << std::endl;
    }
}

template <typename T> struct Result {
    T value;
    bool success;

    // TODO: use color lib to make the error message red for posix environments
    // TODO: modify color lib to use https://www.computerhope.com/color.htm for
    //       windows compatibility
    T unwrap(std::string errorMessage) {
        if (success) { return value; }
        throw std::runtime_error(errorMessage);
    }

    Result<T> onFailHelpCommand(
        const std::string& programName,
        const std::vector<std::string>& subcommandNames,
        const std::vector<std::string>& subcommandHelp
    ) {
        if (success) { return *this; }
        helpCommand(programName, subcommandNames, subcommandHelp);
        return *this;
    }
};

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

    // Construct subcommands vectors (names, commands, and help messages)

    const std::vector<std::string> subcommandNames = {
        "compile",
        "explain",
        "new",
        "pkg",
    };

    const std::vector<std::string> subcommandCommands = {
        "echo 'compile called'",
        "python3 ./explain.py",
        "python3 ./new.py",
        "echo 'pkg called'",
    };

    const std::vector<std::string> subcommandHelp = {
        "Compile a file",
        "Explain an error",
        "Display help",
        "Create a new project",
        "Display version",
        "Manage packages",
    };

    // Ensure subcommands vectors are the same size

    if (subcommandNames.size() != subcommandCommands.size()) {
        std::cout
        << "subcommandNames.size(): " << subcommandNames.size()
        << "subcommandCommands.size(): " << subcommandCommands.size()
        << std::endl;
        
        throw std::runtime_error(
            "subcommandNames and subcommandCommands must be the same size"
        );
    }

    // Construct subcommands map

    std::unordered_map<std::string, std::string> subcommands;

    for (int i = 0; i < subcommandNames.size(); i++) {
        subcommands.insert(std::make_pair(
            subcommandNames[i],
            subcommandCommands[i]
        ));
    }

    // Parse command line arguments

    std::vector<std::string> args(argv, argv + argc);

    if (args.size() < 2) {
        std::cout << "No subcommand provided" << std::endl;
        helpCommand(args[0], subcommandNames, subcommandHelp);
        return 1;
    }

    // TODO: check if flags format is correct

    std::string subcommand = args[1];
    
    subcommand = findClosestSubcommand(
        subcommandNames,
        subcommand
    ).onFailHelpCommand(
        args[0],
        subcommandNames,
        subcommandHelp
    ).unwrap("Unknown subcommand: " + subcommand); // TODO: call help subcommand

    // Handle built in subcommands

    // TODO: make builtin commands easier to scale as the project gets bigger
    //       to do this use a map and pass it around
    if (subcommand == "help") {
        helpCommand(args[0], subcommandNames, subcommandHelp);
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
        subcommands[subcommand],
        ss.str()
    );

    result.unwrap("Subcommand failed with exit code: " + std::to_string(result.value));

    return 0;
}