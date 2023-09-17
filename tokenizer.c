#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32

/**
 * programme that will be used to read the symbols and help in execution of the file
 * parsing will also be included
 */
int tokenize_input(char *input, char *args[])
	int tokenize_input(char *input, char *args[]) {
    char *token = strtok(input, " ");
    int arg_count = 0;

    while (token != NULL && arg_count < MAX_ARG_COUNT) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }

    args[arg_count] = NULL;

    if (args[0] != NULL) {
        if (strcmp(args[0], "mycommand") == 0) {
            if (arg_count < 2) {
                fprintf(stderr, "Usage: mycommand <argument>\n");
                return -1;
            }
        }
    }

    return arg_count;
}
