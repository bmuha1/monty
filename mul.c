#include "monty.h"

/**
 * op_mul - Multiply the second element of the stack by the top element
 * @stack: The stack
 * @line_number: The line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't mul, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
