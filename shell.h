/**
 * file: shell.h
 * Auth: Owen Mousa Algarni , Shadan khaled Alkharji
 * Date:  Nov 2025
 * Desc: header file for simple_shell project, contains function
 *      prototypes, constants, and global variables.
 */

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_TOKENS 64

/* Global variables */
extern char **environ;   /* environment variables */
extern int last_status;  /* last command exit status */

/* Main shell loop */
int shell_loop(char *argv0);

/* Parser functions */
char *get_command(char *line);
char **split_line(char *line);

/* Execution */
int exec_command(char **args, char *argv0);

/* Path utilities */
char *find_in_path(char *cmd);
char *get_env_var(char *name);

/* Built-ins */
int check_builtin(char **args);
int builtin_exit(char **args);
int builtin_env(void);

#endif /* SHELL_H */
