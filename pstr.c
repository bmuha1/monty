#include "monty.h"

/**
 * op_pstr - Print the string starting at the top of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	while (*stack)
	{
		if ((*stack)->n > 0 && (*stack)->n < 128)
		{
			putchar((*stack)->n);
			*stack = (*stack)->next;
		}
		else
			break;
	}
	printf("\n");
}
