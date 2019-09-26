#include "monty.h"

/**
 * op_pchar - Print the char at the top of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pchar, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pchar, value out of range\n",
			line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}
