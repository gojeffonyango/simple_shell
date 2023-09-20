#include <stdlib.h>
#include "shell.h"
#include <string.h>

#define MAX_INPUT_SIZE 1024

char *custom_strtok(char *str, const char *delim, char **saveptr);
void trim_whitespace(char *str);

char **tokenize_input(char *input, const char *delim)
{
    char **tokens = malloc(sizeof(char *) * MAX_INPUT_SIZE);
    char *token;
    int token_count = 0;
    char *saveptr;

    if (tokens == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (token = custom_strtok(input, delim, &saveptr); token
		    != NULL; token = custom_strtok(NULL, delim, &saveptr))
    {
        trim_whitespace(token);
        if (strlen(token) > 0)
	{
            tokens[token_count] = strdup(token);
            if (tokens[token_count] == NULL)
	    {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            token_count++;
        }
    }

    tokens[token_count] = NULL;
    return tokens;
}
