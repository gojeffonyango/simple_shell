#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

int main()
{
	char *delim = " \n";
	char *input = NULL;
	char **tokens;
	int i;

	while (1)
	{
		printf(":) ");

		if (input == NULL || strcmp(input, "exit") == 0)
		{
		free(input);
		break;
		}
		tokens = tokenize_input(input, delim);
		execute_command(tokens);
		free(input);
		for (i = 0; tokens[i] != NULL; i++)
		{
		free(tokens[i]);
		}
		free(tokens);
	}
	return (0);
}
