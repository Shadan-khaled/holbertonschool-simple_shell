/**
 * file: shell_loop.c
 * Auth:  Owen Mousa Algarni Shadan AlKharji 
 * Date: 13 Nov 2025
 * Desc: main shell loop; reads lines, parses, and executes commands.
 */

#include "shell.h"

/**
 * shell_loop - main shell loop
 * @argv0: program name for error messages
 *
 * Description: reads commands from stdin, parses arguments,
 * checks for builtins, and executes commands in a loop.
 * Handles interactive and non-interactive modes.
 *
 * Return: 0 on success or last_status on exit
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
        {
            write(STDOUT_FILENO, "($) ", 4);
        }

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
