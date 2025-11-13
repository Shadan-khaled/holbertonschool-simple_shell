/**
 * file: main.c
 * Auth:  Owen Mousa Algarni Shadan AlKharji 
 * Date: 13 Nov 2025
 * Desc: Entry point for the simple shell program.
 */

#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count (unused)
 * @argv: argument vector
 *
 * Description: starts the shell loop by passing argv[0]
 * to display program name in error messages.
 *
 * Return: exit status from shell_loop
 */
int main(int argc, char **argv)
{
    (void)argc;

    return (shell_loop(argv[0]));
}
