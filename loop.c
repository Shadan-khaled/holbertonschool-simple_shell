#include "shell.h"

/**
 * shell_loop - main shell loop
 * @argv0: program name for error messages
 *
 * Return: 0 on success
 */
int shell_loop(char *argv0)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	char *trimmed;
	int builtin_result;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (last_status);
		}

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		trimmed = get_command(line);
		if (!trimmed || trimmed[0] == '\0')
			continue;

		args = split_line(trimmed);
		if (!args || !args[0])
		{
			free(args);
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
	}
	return (0);
}
