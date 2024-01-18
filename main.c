#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

arg_t *arguments;

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
	FILE *stream;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initialize_args();
	stream = fopen(argv[1], "r");
	arguments->stream = stream;
	get_stream_fail(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != -1)
	{
		arguments->line_number += 1;
		tokenize();
		get_instruction();
		run_instruction();
		free_tokens();
	}
	close_stream();
	free_args();

	return (0);
}
