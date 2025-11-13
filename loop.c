/**
 * File: loop.c
 * Description: Implements the main shell loop for reading and executing commands.
 * Authors: Owen Mousa Algarni, Shadan Khaled Alkharji
 * Date: Nov 2025
 */

#include "shell.h"

/**
 * read_command - reads a line from standard input
 *
 * Return: pointer to the line, or NULL on EOF/error
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

/**
 * shell_loop - main shell loop
 * @argv0: program name for error messages
 *
 * Return: 0 on success, last command exit status on exit
 */
int shell_loop(char *argv0)
{
	char *line;
	char **args;
	char *trimmed;
	int builtin_result;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = read_command();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (last_status);
		}

		trimmed = get_command(line);
		if (!trimmed || trimmed[0] == '\0')
		{
			free(line);
			continue;
		}

		args = split_line(trimmed);
		if (!args || !args[0])
		{
			free(args);
			free(line);
			continue;
		}

		builtin_result = check_builtin(args);
		if (builtin_result == -1)
		{
			free(args);
			free(line);
			return (last_status);
		}
		else if (builtin_result == 0)
		{
			last_status = exec_command(args, argv0);
		}

		free(args);
		free(line);
	}

	return (0);
}

