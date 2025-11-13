/**
 * file: get_command.c
 * Auth: Shadan Khurji <your-email@example.com>
 * Date: 13 Nov 2025
 * Desc: trims whitespace from input and splits command line into tokens.
 */

#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * get_command - trims whitespace from command line
 * @line: input line to trim
 *
 * Description: removes leading and trailing spaces and tabs
 * from the input line.
 *
 * Return: pointer to trimmed string or NULL if empty
 */
char *get_command(char *line)
{
    int start = 0, end;

    if (!line)
        return (NULL);

    while (line[start] == ' ' || line[start] == '\t')
        start++;

    if (line[start] == '\0')
        return (NULL);

    end = strlen(line) - 1;
    while (end > start && (line[end] == ' ' || line[end] == '\t'))
        end--;

    line[end + 1] = '\0';

    return (line + start);
}

/**
 * split_line - splits command line into tokens
 * @line: input line to split
 *
 * Description: uses strtok to split line by space and tab
 * and stores each token in a dynamically allocated array.
 *
 * Return: array of tokens or NULL if malloc fails
 */
char **split_line(char *line)
{
    char **tokens;
    char *token;
    int i;

    if (!line)
        return (NULL);

    i = 0;
    tokens = malloc(sizeof(char *) * MAX_TOKENS);
    if (!tokens)
        return (NULL);
