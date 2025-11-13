#ifndef SHELL_H
#define SHELL_H

/**
 * File: shell.h
 * Description: Contains prototypes, constants, and global variables
 *              for the simple shell program.
 * Authors: Owen Mousa Algarni, Shadan Khaled Alkharji
 * Date: Nov 2025
 */

#define MAX_TOKENS 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Global variables */
extern char **environ;
extern int last_status;

/* Function prototypes */
int shell_loop(char *argv0);
char *get_command(char *line);
char **split_line(char *line);
int exec_command(char **args, char *argv0);
char *find_in_path(char *cmd);
char *get_env_var(char *name);
int check_builtin(char **args);
int builtin_exit(char **args);
int builtin_env(void);

#endif /* SHELL_H */

