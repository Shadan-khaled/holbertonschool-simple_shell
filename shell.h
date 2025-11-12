#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int shell_loop(char *argv0);
char *get_command(char *line);
int exec_command(char *cmd, char *argv0);

#endif /* SHELL_H */
