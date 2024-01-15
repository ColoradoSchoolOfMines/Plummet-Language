#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

#include "jaro.hpp"

template <typename T> struct Result {
    T value;
    bool success;

    // TODO: make this return the result so that the user can call a function on it that may make the program exit rather allways exit the program
    T unwrap(std::string errorMessage) {
        if (success) { return value; }
        throw std::runtime_error(errorMessage);
    }
};

Result<int> executeSubcommand(const std::string& subcommand) {
    int returnCode = system(subcommand.c_str());
    return Result<int>{returnCode, returnCode == 0};
}

// TODO: Make this check for multiple subcommands if there exists two sub commands equadistant from the unrecognized subcommand
Result<std::string> findClosestSubcommand(
    const std::vector<std::string>& subcommandNames,
    const std::string& unrecognizedSubcommand
) {

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

    // Construct subcommands vectors (names and commands)

    const std::vector<std::string> subcommandNames = {
        "compile",
        "explain",
        "help",
        "new",
        "version",
        "pkg",
    };

    const std::vector<std::string> subcommandCommands = {
        "echo 'compile called'",
        "python3 ./explain.py",
        "echo 'help called'",
        "echo 'new called'",
        "echo 'version called'",
        "echo 'pkg called'",
    };

    // Ensure subcommands vectors are the same size

    if (subcommandNames.size() != subcommandCommands.size()) {
        std::cout << "subcommandNames.size(): " << subcommandNames.size() << std::endl;
        std::cout << "subcommandCommands.size(): " << subcommandCommands.size() << std::endl;

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

    // ngl; no clue how this constructor works :/
    std::vector<std::string> args(argv, argv + argc);

    if (args.size() < 2) {
        std::cout << "No subcommand provided" << std::endl;
        // TODO: call help subcommand
        return 1;
    }

    // TODO: check if flags format is correct

    std::string subcommand = args[1];

    if (subcommands.find(subcommand) == subcommands.end()) {

        // Find the closest subcommand to the unrecognized subcommand
        subcommand = findClosestSubcommand(
            subcommandNames,
            subcommand
        ).unwrap("Unknown subcommand: " + subcommand);

        // TODO: call help subcommand
    }

    // TODO: Make a way for this to be able to conditionally print the value so that the exit code can be displayed
    executeSubcommand(subcommands[subcommand]).unwrap(
        "Subcommand failed"
    );

    return 0;
}