#include "shell.h"

/**
 * get_command - returns the first non-space part of a line
 * @line: input line from user
 *
 * Return: pointer to command string or NULL if empty
 */
char *get_command(char *line)
{
	int i = 0;

	if (!line)
		return (NULL);

	while (line[i] == ' ' || line[i] == '\t')
		i++;

	if (line[i] == '\0')
		return (NULL);

	return (line + i);
}

