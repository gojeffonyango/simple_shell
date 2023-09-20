#include "shell.h"
#include <stddef.h>

char *custom_strtok(char *str, const char *delim, char **saveptr)
{
	char *token_start = str;

	if (str == NULL && *saveptr != NULL)
	{
		str = *saveptr;
	}
	if (str == NULL || *str == '\0')
	{
		*saveptr = NULL;
		return NULL;
	}
	while (*str != '\0' && strchr(delim, *str) != NULL)
	{
		str++;
	}
	if (*str == '\0')
	{
		*saveptr = NULL;
		return NULL;
	}
	while (*str != '\0' && strchr(delim, *str) == NULL)
	{
		str++;
	}
	if (*str == '\0')
	{
		*saveptr = NULL;
	}
	else
	{
		*str = '\0';
		*saveptr = str + 1;
	}
	return token_start;
}
