/**
 * file: exec_command.c
 * Auth:  Owen Mousa Algarni Shadan AlKharji 
 * Date: 13 Nov 2025
 * Desc: executes a command using fork and execve in a shell.
 */

#include "shell.h"
#include <errno.h>
#include <string.h>

/**
 * exec_command - executes a command
 * @args: command arguments
 * @argv0: program name for error messages
 *
 * Description: forks a child process and executes the command
 * specified in args. Handles errors and prints messages to stderr.
 *
 * Return: exit status of the command
 */
int exec_command(char **args, char *argv0)
{
    pid_t pid;
    int status;
    char *cmd_path;

    if (!args || !args[0])
        return (1);

    cmd_path = find_in_path(args[0]);
    if (!cmd_path)
    {
        fprintf(stderr, "%s: 1: %s: not found\n",
                argv0, args[0]);
        return (127);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(cmd_path);
        return (1);
    }

    if (pid == 0)
    {
        if (execve(cmd_path, args, environ) == -1)
        {
            fprintf(stderr, "%s: 1: %s: %s\n",
                    argv0, args[0], strerror(errno));
            free(cmd_path);
            _exit(126);
        }
    }

    waitpid(pid, &status, 0);
    free(cmd_path);

    if (WIFEXITED(status))
        return (WEXITSTATUS(status));

    return (1);
}
