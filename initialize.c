#include "monty.h"

/**
 * initialize_args - initializes a pointer to argument_s struct
 */

void initialize_args(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_fail();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_fail();

	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->head = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
	arguments->stack_length = 0;
	arguments->stack = 1;
}
