#ifndef STD_PLUMMET_H
#define STD_PLUMMET_H

// Plummet IO functions

void print(const char*) asm("_PLUMMET$print");
char* input() asm("_PLUMMET$input");

// Plummet string functions

char** split(char*, char) asm("_PLUMMET$split");
char* join(char**, char) asm("_PLUMMET$join");

#endif // STD_PLUMMET_H
