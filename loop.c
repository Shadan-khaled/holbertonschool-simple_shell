#include "shell.h"

int shell_loop(char *argv0)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	char *trimmed;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (0);
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

		exec_command(args, argv0);
		free(args);
	}
	return (0);
}
