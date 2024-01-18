#include "monty.h"

/**
* delete_stack_node - delete node at the head/top
*
*/

void delete_stack_node(void)
{
	stack_t *temp;

	temp = arguments->head;
	arguments->head = temp->next;
	free(temp);
}
