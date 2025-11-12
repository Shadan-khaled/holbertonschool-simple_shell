#include "shell.h"

int exec_command(char **args, char *argv0)
{
	struct stat st;
	pid_t pid;
	int status;
	char *cmd = args[0];

	if (strchr(cmd, '/') == NULL)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", argv0, cmd);
		return (127);
	}

	if (stat(cmd, &st) == -1 || access(cmd, X_OK) != 0)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n", argv0, cmd);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		execve(cmd, args, environ);
		dprintf(STDERR_FILENO, "%s: 1: %s: %s\n", argv0, cmd, strerror(errno));
		_exit(126);
	}
	else
		waitpid(pid, &status, 0);

	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
