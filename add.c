#include "monty.h"

/**
 * op_add - Add the top two elements of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO,
			"L%u: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
