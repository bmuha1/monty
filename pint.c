#include "monty.h"

/**
 * op_pint - Print the value at the top of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
			line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
