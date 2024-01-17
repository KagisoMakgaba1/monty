#define _GNU_SOURCE

#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point
 * @argc: the number of command-line arguments
 * @argv: a pointer to an array of strings containing arguments
 *
 * Return: Always success (0)
 */

int main(int argc, char **argv)
{
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initialize_args();
	get_stream(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != 1)
	{
		printf("%s", arguments->line);
	}

	return (0);
}
