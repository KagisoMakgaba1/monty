#include "monty.h"

/**
 * free_all - Frees all allocated memory for arguments.
 */

void free_all(void)
{
	close_stream();
	free_tokens();
	free_args();
}
