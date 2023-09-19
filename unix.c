#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command)
{
	char *args[MAX_INPUT_SIZE / 2];
	int arg_count = 0;
	char *token = strtok(command, " \n");
	pid_t pid = fork();

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \n");
	}
	args[arg_count] = NULL;
	if (arg_count > 0)
	{
		if (pid < 0)
		{
			perror("Fork failed");
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("Execution failed");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
}
int main()
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		printf(":) ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		execute_command(input);
	}
	return (0);
}
