# Plummet

## More Information

[Plummet Language Road-map](https://docs.google.com/document/d/1dmBL6QhTiLT7w80acUJXfOiCMTvuXeIwxsVqcohgmPc/edit?usp=sharing)

[Plummet Language Progress Tracker](https://docs.google.com/spreadsheets/d/18qF8n_Zl2lE_617oXU3gwUYCmysZrsdRO5bC3j8dP9k/edit?usp=sharing)

## Project Notice

This repo is under a large rework. I will be messy for a little bit while I sort things out.

## Dependences

### Compiling

- LLVM 14
- Clang 15.x.x (Not sure what the minimum version is, I am using 15.x.x and would recommend it for best support)

### Developing

- Everything above
- mingw-w64-gcc

## TODO

- [ ] Fix file/class names
- [ ] Write unit tests for all sub functions in compiler/internal/
- [ ] Write log util class
- [ ] Move error class from compiler/internal/ to utils, edit and write unit tests.
- [ ] Define subset of TOML, write unit tests & test files, finish TOML parser
- [ ] Finish tool chain automation
- [ ] Write unit tests for explain and finish writing interface for explain
- [ ] Finish writing help sub command
- [ ] Finish adding symbols to lexer
- [ ] Sketch out ast on paper
- [ ] Move optimization routines from lex to either a new class or parser
- [ ] Update documentation on Google drive
