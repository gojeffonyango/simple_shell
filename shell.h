#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char **args);
char **tokenize_input(char *input, const char *delim);
char *custom_strtok(char *str, const char *delim, char **saveptr);
void trim_whitespace(char *str);

#endif /* SHELL_H */
