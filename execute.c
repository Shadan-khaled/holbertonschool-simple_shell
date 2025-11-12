#include "shell.h"

/**
 * exec_command - executes a command (only full path in this task)
 * @cmd: command to execute (e.g. /bin/ls)
 * @argv0: program name (for error formatting)
 *
 * Return: exit status (0 on success, 127 if not found, 1 on error)
 */
int exec_command(char *cmd, char *argv0)
{
	struct stat st;
	pid_t pid;
	int status;

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
		char *argv_exec[2];

		argv_exec[0] = cmd;
		argv_exec[1] = NULL;

		execve(cmd, argv_exec, environ);
		dprintf(STDERR_FILENO, "%s: 1: %s: %s\n", argv0, cmd, strerror(errno));
		_exit(126);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
