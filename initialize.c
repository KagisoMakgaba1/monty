#include "monty.h"

/**
 * initialize_args - initializes a pointer to argument_s struct
 */

void initialize_args(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_fail();

	arguments->stream = NULL;
	arguments->line = NULL;
}
