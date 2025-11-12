#include "shell.h"

int last_status = 0;

/**
 * builtin_exit - exits the shell
 * @args: command arguments
 *
 * Return: -1 to signal exit
 */
int builtin_exit(char **args)
{
	(void)args;
	return (-1);
}

/**
 * builtin_env - prints environment variables
 *
 * Return: 0 on success
 */
int builtin_env(void)
{
	int i;

	if (!environ)
		return (1);

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * check_builtin - checks if command is builtin
 * @args: command arguments
 *
 * Return: -1 for exit, 1 if executed, 0 if not builtin
 */
int check_builtin(char **args)
{
	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));

	if (strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}

	return (0);
}
