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

extern char **environ;
extern int last_status;

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

#endif
