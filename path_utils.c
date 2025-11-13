/**
 * File: path_utils.c
 * Description: Environment and PATH utilities for simple_shell.
 * Authors: Owen Mousa Algarni, Shadan Khaled Alkharji
 * Date: Nov 2025
 */

#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * get_env_var - gets environment variable value
 * @name: variable name
 *
 * Return: value string or NULL
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
 * build_path - builds full path string
 * @dir: directory
 * @cmd: command
 *
 * Return: allocated string with full path
 */
char *build_path(char *dir, char *cmd)
{
	int dir_len = strlen(dir);
	int cmd_len = strlen(cmd);
	char *full_path = malloc(dir_len + cmd_len + 2);

	if (!full_path)
		return (NULL);

	strcpy(full_path, dir);
	full_path[dir_len] = '/';
	strcpy(full_path + dir_len + 1, cmd);

	return (full_path);
}

/**
 * find_in_path - searches for command in PATH
 * @cmd: command name
 *
 * Return: full path string or NULL
 */
char *find_in_path(char *cmd)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

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

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_path(dir, cmd);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

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


