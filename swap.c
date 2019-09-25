#include "monty.h"

/**
 * op_swap - Swap the top two elements of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		dprintf(STDERR_FILENO,
			"L%u: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
