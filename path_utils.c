/**
 * file: find_in_path.c
 * Auth: Owen Mousa Algarni,Shadan Alkharji
 * Date: Nov 2025
 * Desc: retrieves environment variable values and searches commands in PATH.
 */

#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * get_env_var - gets environment variable value
 * @name: variable name
 *
 * Description: searches the global environ array for the variable
 * name and returns its value.
 *
 * Return: pointer to value string or NULL if not found
 */
char *get_env_var(char *name)
{
    int i, j, len;

    if (!name || !environ)
        return (NULL);

    len = strlen(name);

    for (i = 0; environ[i]; i++)
    {
        for (j = 0; j < len && environ[i][j] == name[j]; j++)
            ;

        if (j == len && environ[i][j] == '=')
            return (&environ[i][j + 1]);
    }

    return (NULL);
}

/**
 * find_in_path - searches for command in PATH
 * @cmd: command name
 *
 * Description: iterates through each directory in PATH environment
 * variable and checks if the command exists.
 *
 * Return: full path of command or NULL if not found
 */
char *find_in_path(char *cmd)
{
    char *path, *path_copy, *dir, *full_path;
    struct stat st;
    int cmd_len, dir_len;

    if (!cmd)
        return (NULL);

    if (cmd[0] == '/' || cmd[0] == '.')
        return (stat(cmd, &st) == 0 ? strdup(cmd) : NULL);

    path = get_env_var("PATH");
    if (!path)
        return (NULL);

    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    cmd_len = strlen(cmd);
    dir = strtok(path_copy, ":");

    while (dir)
    {
        dir_len = strlen(dir);
        full_path = malloc(dir_len + cmd_len + 2);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        strcpy(full_path, dir);
        full_path[dir_len] = '/';
        strcpy(full_path + dir_len + 1, cmd);

        if (stat(full_path, &st) == 0)
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}

