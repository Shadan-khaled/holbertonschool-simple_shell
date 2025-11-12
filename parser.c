#include "shell.h"

/**
 * get_command - returns the command trimmed of spaces
 * @line: input line from user
 * Return: pointer to trimmed command or NULL if empty
 */
char *get_command(char *line)
{
	int start = 0, end;

	if (!line)
		return (NULL);

	while (line[start] == ' ' || line[start] == '\t')
		start++;

	if (line[start] == '\0')
		return (NULL);

	end = strlen(line) - 1;
	while (end > start && (line[end] == ' ' || line[end] == '\t'))
		end--;

	line[end + 1] = '\0';
	return (line + start);
}
