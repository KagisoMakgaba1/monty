#include "monty.h"

/**
 * pop - Deletes the top element in the present stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_stream();
		free_tokens();
		free_args();
		exit(EXIT_FAILURE);
	}
	temp = arguments->head;
	arguments->head = temp->next;
	free(temp);

	arguments->stack_length -= 1;
}
