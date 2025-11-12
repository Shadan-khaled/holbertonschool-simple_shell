#include "shell.h"

/**
 * shell_loop - main loop for the simple shell
 * @argv0: program name (for error messages)
 * Return: 0 on success
 */
int shell_loop(char *argv0)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *cmd;

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

		cmd = get_command(line);
		if (!cmd || cmd[0] == '\0')
			continue;

		exec_command(cmd, argv0);
	}
	return (0);
}
