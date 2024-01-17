#include "monty.h"

/**
 * malloc_fail - handles the malloc error
 */

void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}
