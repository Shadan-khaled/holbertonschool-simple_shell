#include "shell.h"

/**
 * split_line - splits a line into tokens
 * @line: input line
 * Return: NULL-terminated array of strings
 */
char **split_line(char *line)
{
	char **toks = NULL, *tok;
	size_t size = 0;

	tok = strtok(line, " \t");
	while (tok)
	{
		toks = realloc(toks, sizeof(char *) * (size + 2));
		if (!toks)
			return (NULL);
		toks[size++] = tok;
		tok = strtok(NULL, " \t");
	}
	if (toks)
		toks[size] = NULL;
	return (toks);
}
