#include <stdlib.h>
#include "shell.h"


char **tokenize_input(char *input, const char *delim) {
    char **tokens = malloc(sizeof(char *) * MAX_INPUT_SIZE);
    if (tokens == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    char *token;
    int token_count = 0;
    char *saveptr;

    for (token = custom_strtok(input, delim, &saveptr); token
		    != NULL; token = custom_strtok(NULL, delim, &saveptr)) {
        trim_whitespace(token);
        if (strlen(token) > 0) {
            tokens[token_count] = strdup(token);
            if (tokens[token_count] == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            token_count++;
        }
    }

    tokens[token_count] = NULL;
    return tokens;
}

