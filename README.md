# Plummet

## What is plummet?

Plummet is a compiled, statically typed, multi-paradigm, general purpose programming language. The eventual goal for plummet is to be an intermidiate language that can be used to write libraries for other languages that run on the LLVM platform. Eventually, there will be unofficial standard libraries for other languages that will be written in plummet, that way it will be almost trivial to write a program in several languages, and have them all link without having to deal with the hassle of writing bindings or conflicts from different standard libraries.

## More Information

[Plummet Language Road-map](https://docs.google.com/document/d/1dmBL6QhTiLT7w80acUJXfOiCMTvuXeIwxsVqcohgmPc/edit?usp=sharing)

[Plummet Language Progress Tracker](https://docs.google.com/spreadsheets/d/18qF8n_Zl2lE_617oXU3gwUYCmysZrsdRO5bC3j8dP9k/edit?usp=sharing)

## Project Notice

This repo is under a large rework. I will be messy for a little bit while I sort things out.

## Dependences

### Compiling

More to come here soon!

### Developing

If you are a contributor, you know where to reach me. Please send me a message through the discord channel.

## TODO

- [ ] Fix file/class names
- [ ] Write log util class
- [ ] Move error class from compiler/internal/ to utils, edit and write unit tests.
- [ ] Define subset of TOML, write unit tests & test files, finish TOML parser
- [ ] Finish adding symbols to lexer
- [ ] Sketch out ast on paper
- [ ] Move optimization routines from lex to either a new class or parser
- [ ] Update documentation on Google drive [TODO: End of Febuary]

## Plummet Command/Subcommands and Extra Arguments

### Plummet Command and Subcommands

- `plummet`
    - `plummet help` - Display help information
    - `plummet version` - Display version information

- `plummet compile` [Not yet implemented]
    - `plummet compile help` - Display help information for the compile subcommand
    - More to come!

- `plummet explain`
    - `plummet explain help` - Display help information for the explain subcommand
    - `plummet explain <error code>` - Explain an error code given by the compiler

- `plummet new`
    - `plummet new help` - Display help information for the new subcommand
    - `plummet new project program` - Create a new project
    - `plummet new project library` - Create a new library

- `plummet package` [Not yet implemented]
    - `plummet package help` - Display help information for the package subcommand
    - More to come!

- `tests/run_tests.py` This subcommand must be run from the root directory of the project. It also depends on the dev build of the plummet command being in the root directory of the project. It is usually better to invoke this command from the Makefile in the root directory of the project.
    - `python3 tests/run_tests.py help` - Display help information for the run\_tests.py subcommand
    - `python3 tests/run_tests.py example` - Run the example test
    - `python3 tests/run_tests.py <test number>` - Run a specific test

### Extra Arguments

- `PLUMMET_AUTO_CORRECT=0` can be used to disable the suggestion feature of the main command. If a subcommand is incorrectly typed, the program will suggest the correct subcommand.
    - example: `PLUMMET_AUTO_CORRECT=0 plummet mew` will not suggest `plummet new`
