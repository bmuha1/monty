#include "monty.h"

/**
 * op_rotl - Rotate the stack to the top
 * @stack: The stack
 * @line_number: The line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;

	if (*stack && (*stack)->next)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = *stack;
		(*stack)->prev = curr;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
