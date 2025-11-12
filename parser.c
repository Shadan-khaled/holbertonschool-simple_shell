#include "shell.h"

/**
 * get_command - trims whitespace from command line
 * @line: input line to trim
 *
 * Return: pointer to trimmed string or NULL
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

/**
 * split_line - splits command line into tokens
 * @line: input line to split
 *
 * Return: array of tokens or NULL
 */
char **split_line(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * MAX_TOKENS);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \t");
	while (token && i < MAX_TOKENS - 1)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t");
	}
	tokens[i] = NULL;

	return (tokens);
}
