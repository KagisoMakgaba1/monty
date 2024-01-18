#include "monty.h"

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp1, *tmp2;

	(void) stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}

	tmp1 = arguments->head;
	tmp2 = tmp1->next;

	tmp2->n = tmp2->n * tmp1->n;
	tmp = arguments->head;
	arguments->head = tmp->next;
	free(tmp);

	arguments->stack_length -= 1;
}
