/**
 * File: builtins.c
 * Description: Implements shell built-in commands such as exit and env.
 * Authors: Owen Mousa Algarni, Shadan Khaled Alkharji
 * Date: Nov 2025
 */

#include "shell.h"

/**
 * builtin_exit - exits the shell
 * @args: command arguments
 *
 * Return: -1 to signal shell exit
 */
int builtin_exit(char **args)
{
	(void)args;
	return (-1);
}

/**
 * builtin_env - prints environment variables
 *
 * Return: 0 on success, 1 if environ is NULL
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
 * check_builtin - checks if command is a built-in
 * @args: command arguments
 *
 * Return: -1 for exit, 1 if executed, 0 if not a built-in
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

