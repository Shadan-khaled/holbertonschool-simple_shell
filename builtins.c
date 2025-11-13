/**
 * file: builtin.c
 * Auth: Shadan Khurji <your-email@example.com>
 * Date: 13 Nov 2025
 * Desc: built-in shell commands: exit, env, and builtin checker.
 */

#include "shell.h"

int last_status = 0;

/**
 * builtin_exit - exits the shell
 * @args: command arguments (unused)
 *
 * Description: exits the shell when the user types exit.
 * Return: -1 to signal shell termination.
 */
int builtin_exit(char **args)
{
    (void)args;

    return (-1);
}

/**
 * builtin_env - prints the environment variables
 *
 * Description: loops through the global environ array and prints
 * each environment variable followed by a newline.
 * Return: 0 on success, 1 if environ is NULL.
 */
int builtin_env(void)
{
    int i;

    if (!environ)
        return (1);

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i],
              strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

    return (0);
}

/**
 * check_builtin - checks if a command is a builtin
 * @args: command arguments
 *
 * Description: if the command is "exit" or "env", executes
 * the corresponding builtin. Otherwise returns 0.
 * Return: -1 for exit, 1 if executed, 0 if not builtin.
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
