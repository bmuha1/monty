#include "monty.h"

/**
 * op_rotr - Rotate the stack to the bottom
 * @stack: The stack
 * @line_number: The line number
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;

	if (*stack && (*stack)->next != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = *stack;
		(*stack)->prev = curr;
		curr->prev->next = NULL;
		curr->prev = NULL;
		*stack = curr;
	}
}
