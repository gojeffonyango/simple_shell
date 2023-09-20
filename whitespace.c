#include "shell.h"
#include <ctype.h>

void trim_whitespace(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;
	*(end + 1) = '\0';

	if (str == NULL)
	{
		return;
	}
	while (*start != '\0' && isspace(*start))
	{
		start++;
	}
	while (end >= start && isspace(*end))
	{
		end--;
	}
	if (start != str)
	{
		while (*start != '\0')
		{
			*str = *start;
			str++;
			start++;
		}
		*str = '\0';
	}
}
