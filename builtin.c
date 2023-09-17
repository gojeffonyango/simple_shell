#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32

void execute_command(char *command, char *args[]) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("execution_error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(command, args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Exited with status %d\n", WEXITSTATUS(status));
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_COUNT];

    while (1) {
        printf("$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        char *token = strtok(input, " ");
        int arg_count = 0;

        while (token != NULL && arg_count < MAX_ARG_COUNT) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }

        args[arg_count] = NULL;

        if (arg_count > 0) {
            if (strcmp(args[0], "exit") == 0) {
                exit(EXIT_SUCCESS);
            } else if (strcmp(args[0], "cd") == 0) {
                if (arg_count >= 2) {
                    if (chdir(args[1]) == -1) {
                        perror("chdir");
                    }
                } else {
                    fprintf(stderr, "Usage: cd <directory>\n");
                }
            } else {
                execute_command(args[0], args);
            }
        }
    }

    return 0;
}
