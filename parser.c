#include "shell.h"

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
