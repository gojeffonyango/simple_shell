#include <stdio.h>
#include <stdlib.h>

char *custom_getline(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t read = getline(&line, &bufsize, stdin);

    if (read == -1)
    {
	    free(line);
	    return NULL;
    }

    return line;
}
