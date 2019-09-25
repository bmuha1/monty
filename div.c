#include "monty.h"

/**
 * op_div - Divide the second element of the stack by the top element
 * @stack: The stack
 * @line_number: The line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't div, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n /= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
