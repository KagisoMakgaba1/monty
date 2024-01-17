#include "monty.h"

/**
 * free_head - frees the memory allocated for the head and
 * sets it to NULL
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}


/**
 * free_args - frees the memory allocated to argument pointer
 */

void free_args(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}

	free_head();

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}

	free(arguments);
}
