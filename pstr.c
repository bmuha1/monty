#include "monty.h"

/**
 * op_pstr - Print the string starting at the top of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;

	while (curr)
	{
		if (curr->n > 0 && curr->n < 128)
		{
			if (curr->n > 31 && curr->n < 127)
				putchar(curr->n);
			curr = curr->next;
		}
		else
			break;
	}
	printf("\n");
}
