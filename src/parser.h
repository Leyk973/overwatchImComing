#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int trim(char *);
int del_doubles_spaces(char *);
int tokenize(char *, char**, size_t);

#endif
