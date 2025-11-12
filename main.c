#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: exit status
 */
int main(int argc, char **argv)
{
	(void)argc;

	return (shell_loop(argv[0]));
}
